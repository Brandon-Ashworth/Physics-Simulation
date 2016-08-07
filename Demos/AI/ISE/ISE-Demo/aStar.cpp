#include "aStar.h"


aStar::aStar(void)
{
	m_ComponentType = Component::ASTAR;
	destination = NULL;
	m_gap = 0.f;
	m_size = 0;
	offSetX = 0.f;
	offSetY = 0.f;
}


aStar::~aStar(void)
{
}

//set the square size of the grid
void aStar::setSize(int size)
{
	m_size = size;
}

//get the square size of the grid
int aStar::getSize()
{
	return(m_size);
}

//add a node to block
void aStar::addBlocked(int x, int y)
{
	blockedNodes.push_back(Vector2Int(x,y));//create a new Vector2Int places the grid positions and blocks those nodes
}

//remove blocked node (jk i didn't do this)
void aStar::remBlocked(int x, int y)
{

}

//set the gap between each node (in float points)
void aStar::setGap(float gap)
{
	m_gap = gap;
}

//return the gap
float aStar::getGap()
{
	return(m_gap);
}

//generate the path, no error checking done  
void aStar::genPath()
{
	NavMesh mesh;//the nav mesh
	mesh.setNavSize(m_size);
	mesh.initMesh();

	//for loop to block nodes
	for(int i=0; i<blockedNodes.size();++i)
	{
		mesh.blockNode(blockedNodes[i].m_x,blockedNodes[i].m_y);
	}

	nodePathList = (mesh.getPath(									//get the path
							mesh.getNode(m_start.m_x,m_start.m_y),	//start node
							mesh.getNode(m_goal.m_x,m_goal.m_y)));	//goal node



	return;

	
}

//get the size of the node list path thing
int aStar::getNodeNum()
{
	return(nodePathList->size());
}

//sets the destination node to the next node, use this when nextnodeHit is true
void aStar::getNextNode()
{
	if(destination == NULL)//destination node not created before
	{
		destination = new Vector2Int(nodePathList->top().m_x,nodePathList->top().m_y);
		nodePathList->pop();//pop the destination node off the list
	}
	else
	{
		delete destination;
		destination = new Vector2Int(nodePathList->top().m_x,nodePathList->top().m_y);
		nodePathList->pop();
	}

	//may need to place a thing to see of the node thing is empty

}

float aStar::getDesX()
{
	return(m_gap * destination->m_x);
}

float aStar::getDesY()
{
	return(m_gap * destination->m_y);
}

bool aStar::nextNodeHit(float x, float y)
{
	float desX = destination->m_x * m_gap;
	float desY = destination->m_y * m_gap;//the x and y position in real world

	if((x >= desX - m_gap/2) && (x <= desX + m_gap/2) && (y >= desY - m_gap/2) && (y <= desY + m_gap/2))
	{
		return(true);
	}
	else
	{
		return(false);
	}

}

bool aStar::goalNodeHit(float x, float y)
{
	float goX = m_goal.m_x * m_gap;
	float goY = m_goal.m_y * m_gap;//the x and y position in real world

	if((x >= goX - m_gap/2) && (x <= goX + m_gap/2) && (y >= goY - m_gap/2) && (y <= goY + m_gap/2))//if the goal world position == NPC's world position
	{
		return(true);
	}
	else
	{
		return(false);
	}
}


//set the positions of start and goal
void aStar::setStart(float x, float y)
{
	int newX = x/m_gap;
	int newY = y/m_gap;
	m_start = Vector2Int(newX,newY);
	
}

void aStar::setGoal(float x, float y)
{
	int newX = x/m_gap;
	int newY = y/m_gap;
	m_goal = Vector2Int(newX,newY);//the float 
}


void aStar::setOffSetX(float offset)
{
	offSetX = offset;
}

void aStar::setOffSetY(float offset)
{
	offSetY = offset;
}


