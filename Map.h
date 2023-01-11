#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "VertexType.h"
#include "Player.h"

using namespace std; 
//map is a graph, draw illustration with all edges first before creating this class
class Map {
public:

	Map();
	bool edgeExists(VertexType v1, VertexType v2);
	bool vertexExists(VertexType v) const;

	void addVertex(VertexType v);
	void addEdge(VertexType v1, VertexType v2, int weight);		//might add a delete vertex function incase for example game takes place in a cave where that area of the map collasped and is unaccessible

	vector<VertexType> getPathways(VertexType v); //the pathways the player can take given the vertex they are at.
	
	int getWeight(VertexType v1, VertexType v2);
	int vertexNumb() const;

	//VertexType getVertex(string direction);

	string directionOfNeighbor(VertexType v1, VertexType v2, Player p);
	//determine direction via weights??? going more east, weight increases by 1. Going west, weight decreases by 1. going north, weight multiplies by 5, going south wiehgt divides by 5.

private:
	int numberOfVertices;
	VertexType* vertices;
	int indexIs(VertexType v);
	int edges[20][20]; //change this value based on how many vertices there are.
};