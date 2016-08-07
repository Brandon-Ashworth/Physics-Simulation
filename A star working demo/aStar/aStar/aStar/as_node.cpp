#include "as_node.h"


as_node::as_node(void)
{
	m_x =0;
	m_y = 0;
	parent = NULL;
	hue = 0;
	finalCost =0;
	blocked = false;
	createdBefore = false;
}


as_node::~as_node(void)
{
}

void as_node::setNodeBlock(bool isBlocked)
{
	blocked = isBlocked;
}

bool as_node::getNodeBlock()
{
	return(blocked);
}

void as_node::setGridPos(Vector2Int newPos)
{
	m_x = newPos.m_x;
	m_y = newPos.m_y;
}
Vector2Int as_node::getGridPos()
{
	Vector2Int ret(m_x,m_y);
	return(ret);
}

void as_node::setGridX(int x)
{
	m_x = x;
}
int as_node::getGridX()
{
	return(m_x);
}

void as_node::setGridY(int y)
{
	m_y = y;
}
int as_node::getGridY()
{
	return(m_y);
}

//the parent node functions
void as_node::setParent(as_node *newParent)
{
	parent = newParent;
}
as_node &as_node::getParent()
{
	return(*parent);
}

//setting the heuristic information
void as_node::setHueristic(int newHue)
{
	hue = newHue;
}

int as_node::getHueristic()
{
	return(hue);
}

//lastly the final cost values
void as_node::setFinalCost(int givenCost)
{
	finalCost = givenCost + hue;
	//final cost is given cost (the cost so far)
	//plus the heuristic cost
}
int as_node::getFinalCost()
{
	return(finalCost);
}
