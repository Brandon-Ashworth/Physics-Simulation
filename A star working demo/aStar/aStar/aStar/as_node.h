#pragma once

#include <iostream>
#include "Vector2Int.h"

class as_node
{
public:
	as_node(void);
	~as_node(void);
	
	//seting the node blocking
	void setNodeBlock(bool isBlocked);
	bool getNodeBlock();

	//setting the node position in the grid
	void setGridPos(Vector2Int newPos);
	Vector2Int getGridPos();

	void setGridX(int x);
	int getGridX();

	void setGridY(int y);
	int getGridY();

	//setting the parent node
	void setParent(as_node *newParent);
	as_node &getParent();

	//setting the heuristic cost
	void setHueristic(int newHue);
	int getHueristic();

	//setting the finalcost
	void setFinalCost(int givenCost);
	int getFinalCost();

	bool createdBefore;


private:
	int m_x;
	int m_y;
	as_node *parent;
	int hue;
	int finalCost;
	bool blocked;
	
};

