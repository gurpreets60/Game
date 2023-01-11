#pragma once
#include <iostream>
#include <string>

using namespace std;

class EnemyType { //in the future, maybe make different enemies by creating subclasses of enemies/ for example enemies that can regen
public:
	void initializeEnemy(string typeName, double hp, double dmg);
	string getType() const;
	double getHealth() const;
	double getDamage() const;
	
	void subtractHp(double hp);
private:
	string type; //bandit, monster, animal
	double health;
	double damage;
};

class BossType : EnemyType {
public:
	void initializeBoss(string theName, string type, double hp, double dmg);
	void initializeReduction(int reduction); //divide the percetage by 100 to get double. will get incoming damage by multiplying it with (1- this val)
	void initializeRegen(double regen);
	string getName() const;
	double getRegen() const;
	double getReduction() const;
private:
	string name;
	double regeneration;
	double damageReduction;
};