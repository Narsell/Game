
#include <iostream>
#include <string>

#include "mob.h"
#include "Random.h"
#include "Weapon.h"
#include "Character.h"


using namespace std;

mob::mob()
{
	nName = "Default";
	nHealth = 1;
	nArmor = 1;
	nWeapon.wName = "Defautl Weapon";
	nWeapon.wRange.Rlow = 0;
	nWeapon.wRange.RHigh =0;
	xpReward = 0;
	
}

mob::mob(string name, string wName, int lowR, int highR, int health, int defense, int reward)
{
	nName = name;
	nWeapon.wName = wName;
	nWeapon.wRange.Rlow = lowR;
	nWeapon.wRange.RHigh = highR;
	nHealth = health;
	nArmor = defense;
	xpReward = reward;
	


}

void mob::nTakeDamage(int dmg)
{
	nHealth -= dmg;

}

bool mob::nIsDead()
{
	if (nHealth <= 0)
		return true;
	else
		return false;

}

void mob::mobAttack(character&player)
{
	int dmg, realDmg;
	
	dmg = Random(nWeapon.wRange.Rlow, nWeapon.wRange.RHigh);
	realDmg = dmg-player.playerArmor();
	player.mTakeDamage(realDmg);
	cout << "You've been hit with " << nWeapon.wName << " for a total of " << realDmg << " damage ( " << player.playerArmor() << " absorbed)" << endl;
	system("pause");
	
}

int mob::mobHealth()
{
	return nHealth;
}

int mob::mobArmor()
{
	return nArmor;
}

int mob::Reward()
{
	return xpReward;
}


std::string mob::mobName()
{
	return nName;
}