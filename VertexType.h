#pragma once
#include <iostream>
#include <string>
#include "ItemType.h"
#include "EnemyType.h"
class VertexType { 
public:
	VertexType();
	void initializeItem(ItemType theItem,Weapons theWeapon); //some vertexes will have no items or enemies. If this is the case, 
	void initializeEnemy(EnemyType enemies[], int enemyCount, BossType theBoss); //represent via naming them no item, no enemy, no boss etc.
	ItemType getItem() const;
	Weapons getWeapon() const;
	EnemyType getEnemy(string name) const; //get enemy via finding with name or index.
	BossType getBoss() const;
	int getECount() const;

	void setId(int i);
	int getId() const;
	

	//void initializeN();
	//void initializeNeigbor(VertexType v);


private:
	ItemType item; //if you want more than one enemy, more than one item, make the private data members arrays.
	Weapons weapon;
	EnemyType enemy[3];
	int enemyCount;
	BossType boss;
	int id;
	
	//int numbNeigbors;
	//VertexType* neigbors;
};