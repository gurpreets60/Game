#include <iostream>
#include "Map.h"

using namespace std;

void movement(Player p, Map m, VertexType& v);
//to do list:
//each vertex will be a spot on the map, the map will be a directed graph. Going to multiple differnt areas. 
//create a graphic display of what the map looks like on paint
//each vertex will have one or more edges that leads to another vertex.
//will need to do a ton of checking functions to determine: meaning boolean functions returning true or false for certain scenarios
int main() {
	VertexType v[18];

	int ids = 1000;
	for (int i = 0; i < 18; i++) {
		v[i].setId(++ids);
	}
	
	Map theMap;

	for (int i = 0; i < 18; i++) {
		theMap.addVertex(v[i]);
	}
	theMap.addEdge(v[0], v[1], 10001);
	theMap.addEdge(v[1], v[2], 10002);
	theMap.addEdge(v[2], v[3], 10003);
	theMap.addEdge(v[3], v[4], 10004);
	theMap.addEdge(v[4], v[5], 10005);
	
	theMap.addEdge(v[1], v[0], 10001);
	theMap.addEdge(v[2], v[1], 10002);
	theMap.addEdge(v[3], v[2], 10003);
	theMap.addEdge(v[4], v[3], 10004);
	theMap.addEdge(v[5], v[4], 10005);


	theMap.addEdge(v[5], v[6], 2001);
	theMap.addEdge(v[6], v[7], 400);
	theMap.addEdge(v[7], v[8], 80);
	theMap.addEdge(v[8], v[9], 81);
	theMap.addEdge(v[8], v[10], 16);

	theMap.addEdge(v[6], v[5], 2001);
	theMap.addEdge(v[7], v[6], 400);
	theMap.addEdge(v[8], v[7], 80);
	theMap.addEdge(v[10], v[8], 16);


	theMap.addEdge(v[10], v[11], 15);
	theMap.addEdge(v[11], v[12], 14);
	theMap.addEdge(v[12], v[13], 13);
	theMap.addEdge(v[13], v[14], 65);
	theMap.addEdge(v[14], v[15], 325);
	theMap.addEdge(v[15], v[16], 326);
	theMap.addEdge(v[15], v[17], 1625);

	theMap.addEdge(v[11], v[10], 15);
	theMap.addEdge(v[12], v[11], 14);
	theMap.addEdge(v[13], v[12], 13);
	theMap.addEdge(v[14], v[13], 65);
	theMap.addEdge(v[15], v[14], 325);
	theMap.addEdge(v[16], v[15], 326);
	theMap.addEdge(v[17], v[15], 1625);

	cout << "Welcome to the game:" << endl;
	//d
	Player p;
	movement(p, theMap, v[0]);
}

void movement(Player p, Map m, VertexType& v) {
	string choice;
	int index;
	bool truthVal = false;
	if (!p.reachEnd())
	{
		cout << "Player can move either:";
		vector<VertexType> paths = m.getPathways(v); //allpathways are right-18rights//need to fix
		vector<string> directions;
		for (int i = 0; i < paths.size(); i++) {
			directions.push_back(m.directionOfNeighbor(v, paths.at(i), p));
			cout<<m.directionOfNeighbor(v, paths.at(i),p)<<" ";
		}
		cout << endl << "Which path to choose: ";
		cin >> choice;
		for (int i = 0; i < directions.size(); i++)
		{
			if (choice == directions.at(i)) {
				index = i;
				truthVal = true;
			}
		}
		if (truthVal) {
			p.setPos(m.getWeight(v, paths.at(index)));
			movement(p, m, paths.at(index));
		}
		else {
			cout << "Path chosen is invalid try again."<<endl;
			movement(p, m, v);
		}

	}
	else
	{
		cout << "The end of the game has been reached. Thank you for playing!";
	}
	
}