#pragma once
#include <iostream>
#include <string>
using namespace std;

class ItemType {
public:
	ItemType() {
		item = "NaN";
	}
	void initializeItem(string newItem)
	{
		item = newItem;
	}
	string getItem() const
	{
		return item;
	}

private:
	string item;
};

class Weapons : ItemType { //weapons: they have a set damage, and durability. Each time it is used, durability goes down by 1.
public:
	void initializeWeapon(string name, double dmg, int dura)
	{
		initializeItem(name);
		damage = dmg;
		durability = dura;
	}
private:
	int damage;
	int durability;
};