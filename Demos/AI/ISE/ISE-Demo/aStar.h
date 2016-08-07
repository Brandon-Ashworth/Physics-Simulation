#pragma once

#include "NavMesh.h"
#include "Vector2Int.h"
#include <vector>
#include "Component.h"

class aStar :public Component
{
public:
	aStar(void);
	~aStar(void);

	void setSize(int size);
	int getSize();

	void addBlocked(int x, int y);
	void remBlocked(int x, int y);//don't use

	void setGap(float gap);
	float getGap();

	//real
	void genPath();
	int getNodeNum();//number of nodes left

	void getNextNode();//set the next node as the destination
	
	float getDesX();//get the x position of the destination node in the world
	float getDesY();//get the y position of the destination node in the world

	bool nextNodeHit(float x,float y);//check if the next node has been reached
	bool goalNodeHit(float x, float y);//check if the goal node has been reached 

	//set and get the start and goals position
	void setStart(float x, float y);
	void setGoal(float x, float y);

	void setOffSetX(float offset);
	void setOffSetY(float offset);
	


private:
	std::vector<Vector2Int> blockedNodes;
	std::stack<Vector2Int> *nodePathList;

	Vector2Int *destination;
	Vector2Int m_start;
	Vector2Int m_goal;
	float m_gap;
	int m_size;

	float offSetX;
	float offSetY;
	
};

