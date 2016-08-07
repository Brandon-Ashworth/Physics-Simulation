#pragma once

#include "as_node.h"
#include <iostream>
#include <vector>
#include <stack>

class NavMesh
{
public:
	NavMesh(void);
	~NavMesh(void);

	//precalls, must be called before init call
	void setNavSize(int size);
	//the world position stuff will be included later
	//setFisrtPos
	//setNodeGap

	//precall gets
	int getNavSize();
	//get first pos
	//get node gap

	//initialise the mesh create the mesh variable ect
	bool initMesh();

	//blocking and unblocking nodes, might be an idea to have an ID as well to speed up finding
	//no out of bounds checking done
	void blockNode(int x, int y);
	void unblockNode(int x, int y);

	as_node *getNode(int x,int y);

	std::stack<Vector2Int>getPath(as_node *start, as_node *goal);

	
private:
	//calcHueristics, calcualte the huristics will be called when the 
	//function to calc the path is called
	void calcHue(as_node *goal);

	//variables
	as_node **m_navMesh;
	int m_MeshSize;//the size of the nav mesh
	bool createMap();
	void cleanMap();

	//some calculation things to make it easier to finc values
	int difference(int num1,int num2);// find the absolute difference between 2 numbers
		//find the move cost of the current node to the node we might move to
	int findMoveCost(as_node *currentNode, as_node *movingToNode);

	//obtain the adjacent nodes
	void getAdjacentNodes(as_node *currentNode, std::vector<as_node*> *adjacent);
	void removeBlockedNodes(std::vector<as_node*> *adjacent);

	//others
	void resetNodeCreation();
	bool checkValidNode(int x, int y);

	bool onList(as_node *node,std::vector<as_node*> *nodeList);
};

