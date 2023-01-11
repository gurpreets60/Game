#include <iostream>
#include "EnemyType.h"
#include <string>

using namespace std;

//for basic enemy
void EnemyType::initializeEnemy(string typeName, double hp, double dmg)
{
	type = typeName;
	damage = dmg;
	health = hp;
}

string EnemyType::getType() const {
	return type;
}
double EnemyType::getDamage() const {
	return damage;
}
double EnemyType::getHealth() const {
	return health;
}

void EnemyType::subtractHp(double hp) {
	health -= hp;
}


//for boss
void BossType::initializeBoss(string theName, string type, double hp, double dmg) {
	initializeEnemy(type, hp, dmg);
	name = theName;
}

void BossType::initializeReduction(int reduction) {
	damageReduction = double(reduction) / 100.00;
}
void BossType::initializeRegen(double regen) {
	regeneration = regen;
}

string BossType::getName() const{
	return name;
}
double BossType::getReduction() const {
	return damageReduction;
}
double BossType::getRegen() const {
	return regeneration;
}
