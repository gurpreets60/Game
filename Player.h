#pragma once
#include <iostream>
#include <string>
#include "ItemType.h"
#include "Map.h"
using namespace std;
class Player {
public:
	//member functions like get health, add item, delete item, subtract health, add health. Similar functiosn should be added to enemy
	Player() {
		currentPos = 10000;
		health = 100;
		itemCount = 0;
		items = new ItemType[10];
	}
	int getPos() const {
		return currentPos;
	}
	void setPos(int p) {
		currentPos = p;
	}

	bool reachEnd() {
		if (currentPos == 81)
			return true;
		else
			return false;
	}

	void subtractHp(double hp) {
		health -= hp;
	}
	void addHp(double hp) {
		health += hp;
	}
	void addItem(ItemType i) {
		itemCount++;
		items[itemCount - 1] = i;
	}
	void deleteItem(ItemType item) {
		for (int i = 0; i < itemCount; i++) {
			if (item.getItem() == items[i].getItem()) {
				items[i] = items[itemCount - 1];
				itemCount--;
			}
		}
	}
	void equipWeapon(Weapons w) {
		weapon = w;
	}
private:
	double health;
	ItemType* items;
	Weapons weapon;
	int itemCount;
	int currentPos;
};