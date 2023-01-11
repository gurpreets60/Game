#include <iostream>
#include "Map.h"

using namespace std;

Map::Map() {
	numberOfVertices = 0;
	vertices = new VertexType[20];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
		{
			edges[i][j] = 0;
		}
	}
}

int Map::indexIs(VertexType v) {
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (v.getId() == vertices[i].getId()) { //returns the index where vertex is stored in vertex array.
			return i;
		}
	}
	return -1; //return -1 if not found
}

void Map::addVertex(VertexType v) {
	numberOfVertices++;
	vertices[numberOfVertices - 1] = v;
}
void Map::addEdge(VertexType v1, VertexType v2, int weight) {
	int one = indexIs(v1);
	int two = indexIs(v2);
	edges[one][two] = weight;
}

bool Map::edgeExists(VertexType v1, VertexType v2) {
	int one = indexIs(v1);
	int two = indexIs(v2);
	if (edges[one][two] == 0)
	{
		return false;
	}
	else {
		return true;
	}
	
}
bool Map::vertexExists(VertexType v)const {
	for (int i = 0; i < numberOfVertices; i++)
	{
		if (vertices[i].getItem().getItem()==v.getItem().getItem())
		{
			return true;
		}
	}
	return false;
}

int Map::getWeight(VertexType v1,VertexType v2) {
	int one = indexIs(v1);
	int two = indexIs(v2);
	return edges[one][two];
}

vector<VertexType> Map::getPathways(VertexType v) {//problem`	
	vector<VertexType> neigbors;
	for (int i = 0; i < numberOfVertices; i++) {
		if (edgeExists(v, vertices[i])) {
			neigbors.push_back(vertices[i]);
		}
	}
	return neigbors;
}

int Map::vertexNumb() const {
	return numberOfVertices;
}

string Map::directionOfNeighbor(VertexType v1, VertexType v2, Player p) {
	if (p.getPos() < getWeight(v1, v2))
	{
		if (p.getPos() * 5 <= getWeight(v1, v2)) {
			return "Up";
		}
		else {
			return "Forward";
		}
	}
	else 
	{
		if (p.getPos() / 5 >= getWeight(v1, v2)) {
			return "Down";
		}
		else {
			return "Backward";
		}
	}
}

