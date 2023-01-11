#include <iostream>
#include <string>
#include "VertexType.h"

using namespace std;

VertexType::VertexType() {
	item.initializeItem("NaN");
	weapon.initializeWeapon("NaN", 0.0, 0);
	for (int i = 0; i < 3; i++) {
		enemy[i].initializeEnemy("NaNE", 0.0, 0.0);
	}
	enemyCount = 0;
	boss.initializeBoss("NaNB", "n", 0.0, 0.0);

	id = 0000;
}

void VertexType::setId(int i) {
	id = i;
}
int VertexType::getId() const {
	return id;
}

void VertexType::initializeItem(ItemType theItem, Weapons theWeapon) {
	item = theItem;
	weapon = theWeapon;
}
void VertexType::initializeEnemy(EnemyType enemies[],int enemyCount, BossType theBoss) {
	for (int i = 0; i < enemyCount; i++)
	{
		enemy[i] = enemies[i];
	}
	boss = theBoss;
}

ItemType VertexType::getItem() const {
	return item;
}
Weapons VertexType::getWeapon() const {
	return weapon;
}
int VertexType::getECount() const {
	return enemyCount;
}
EnemyType VertexType::getEnemy(string name) const { //might change this function soon if doesnt statisfy criteria: like if I want to get enemy through his index, his hp or his other criteria instead of name
	EnemyType gotEnemy;
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemy[i].getType() == name) {
			gotEnemy = enemy[i];
		}
	}
	return gotEnemy;
}
BossType VertexType::getBoss() const {
	return boss;
}

/*void VertexType::initializeN() {
	numbNeigbors = 0;
}*/

/*void VertexType::initializeNeigbor(VertexType v) {
	numbNeigbors++;
	neigbors[numbNeigbors-1] = v;
}*/


