#include "NavMesh.h"


NavMesh::NavMesh(void)
{
	m_MeshSize = 0;
}


NavMesh::~NavMesh(void)
{
}

void NavMesh::setNavSize(int size)
{
	m_MeshSize = size;
}

int NavMesh::getNavSize()
{
	return(m_MeshSize);
}

bool NavMesh::initMesh()
{
	if(m_MeshSize <=0)
	{
		return(false);
	}
	else
	{
		return(createMap());
	}
}

void NavMesh::blockNode(int x, int y)
{
	m_navMesh[x][y].setNodeBlock(true);
}

void NavMesh::unblockNode(int x, int y)
{
	m_navMesh[x][y].setNodeBlock(false);
}

//getNode
as_node *NavMesh::getNode(int x, int y)
{
	as_node *lol;
	lol = &m_navMesh[x][y];
	return(lol);
}

//optimise needed
std::stack<Vector2Int>* NavMesh::getPath(as_node *start, as_node *goal)
{
	//does nothing for now
	
	resetNodeCreation();
	calcHue(goal);


	std::vector<as_node*> openList;
	std::vector<as_node*> closedList;
	std::vector<as_node*> adjacent;

	start->setParent(NULL);
	start->createdBefore = true;
	start->setFinalCost(0);
	openList.push_back(start);

	as_node *currentNode = start;
	as_node *successorNode;
	//as_node *lastNode;

	int count =-1;
	bool found = false;

	while(openList.size() > 0)
	{
		count++;

		//*********************************
		//pop the lowest fvalued node
		//
		//*********************************
		//use itterators
		int position = 0;//position of the lowest f in the vector
		int lowestF = 999999999;//the actual lowest f value find a better way to do this
		for(int i=0; i<openList.size();++i)
		{
			if((openList[i]->getFinalCost()) <lowestF)
			{
				position = i;
				lowestF = openList[i]->getFinalCost();
			}
		}
		currentNode = openList[position];
		openList.erase(openList.begin()+position);//remove from openList

		//print currentNode
		//std::cout << currentNode->getGridX() << " " << currentNode->getGridY() << std::endl;

		//
		//
		//**************************************


		//**************************************
		//check to see of goal has been reached
		//**************************************
		//the heuristic will be 0 on the goal point
		if(currentNode->getHueristic() == 0)
		{
			//break out of loop currentNode contains the path to trace back
			found = true;
			break;
		}


		//**************************************
		//obtain all nearBy valid nodes (can't be out of the range or the grid
		//**************************************
		getAdjacentNodes(currentNode,&adjacent);

		//**************************************
		//Remove blocked Nodes
		//**************************************
		//if(count == 8)
			//std::cout <<"RemoveBlockedNodes\n";

		removeBlockedNodes(&adjacent);//tested to this point all good

		//**************************************
		//create the successor node, i'm using the existing node
		//**************************************
		
		/*//his algorithm
		//set its x and y to nearby point
		//set its parent to currentNode 
		////set its final cost to givenCost + Hue Cost (function call for that)*/

		//my Algorithm
		for(int i=0; i<adjacent.size();++i)
		{
			if((adjacent.at(i)->getGridX() == 19) && (adjacent.at(i)->getGridY() == 3))
			{
				std::cout <<"FUCK\n";
			}
			if(onList(adjacent.at(i),&closedList))
			{
				//do nothing if its already on thr closed list
			}
			else if(adjacent.at(i)->createdBefore == true)//node created before
			{
				int moveCost = findMoveCost(currentNode,adjacent.at(i));

				int lastCost = adjacent.at(i)->getFinalCost();
				int newCost =  moveCost+ currentNode->getFinalCost();
				//if the path is cheaper then the last path
				if(newCost < lastCost)
				{
					//replace the successorNodes finalCost with the newCost (this nodes finalcost + moveCost)
					adjacent[i]->setFinalCost(newCost);
					//change parent to this node
					adjacent[i]->setParent(currentNode);
					
				}

			}
			else//node has not been created before
				{
					adjacent.at(i)->createdBefore = true;
					adjacent.at(i)->setFinalCost(currentNode->getFinalCost());
					adjacent.at(i)->setParent(currentNode);
					openList.push_back(adjacent.at(i));

				}
		}

		//push currentNode to closed list
		//pop currenNode off openList

		closedList.push_back(currentNode);
		int currentX = currentNode->getGridX();
		int currentY = currentNode->getGridY();
		adjacent.clear();



		/*for(int i=0;i<openList.size();++i)
		{
			int checkX = openList.at(i)->getGridX();
			int checkY = openList.at(i)->getGridY();

			if((checkX == currentX) && (checkY == currentY))
			{
				openList.erase(openList.begin()+i);
			}
		}*/


		//**************************************
		//If node created Before
		//**************************************
		//lastNode = currentNode;
	}

	//**************************************
	//Convert the Path into a 
	//**************************************
	//print node path function
	std::stack<Vector2Int> *ret = new std::stack<Vector2Int>();
	as_node *curNod;
	curNod = currentNode;
	//as_node *par = NULL;
	//*par = curNod->getParent();
	int currX;
	int currY;

	int startX = start->getGridX();
	int startY = start->getGridY();

	bool end = false;
	while(true)//par != NULL
	{
		currX = curNod->getGridX();
		currY = curNod->getGridY();
		if((currX == startX)&&(currY == startY))
		{
			end = true;
		}

		std::cout<< curNod->getGridX() << ", " <<curNod->getGridY() <<std::endl;
		Vector2Int gridPos(curNod->getGridX(),curNod->getGridY());
		ret->push(gridPos);
		if(end)
		{
			break;
		}
		
		*curNod = curNod->getParent();
		
		//*par = curNod->getParent();
		
	}



	//getchar();

	if(found)
	{
		return(ret);
	}
	else
	{
		exit(1);
	}
	
	
}

//optimising can be done, see other commesnt for details
void NavMesh::calcHue(as_node *goal)
{
	//bounds checking lol no
	int i =0;
	int j = 0;

	//the heuristic values
	int xH;
	int yH;

	//the goal values
	int goalX = goal->getGridX();
	int goalY = goal->getGridY();

	for(i=0;i<m_MeshSize;i++)
	{
		for(j=0;j<m_MeshSize;j++)
		{
			//the xH value should be calculated once in the loop above
			xH = difference(goalX,i);
			yH = difference(goalY,j);
			m_navMesh[i][j].setHueristic(xH+yH);
		}
	}

}

//no checking done, optimisation see comments
bool NavMesh::createMap()
{
	m_navMesh = new as_node*[m_MeshSize];
	for(int i = 0;i<=m_MeshSize;i++)
	{
		m_navMesh[i] = new as_node[m_MeshSize];
	}

	int i;
	int j;
	//give the nodes their grid positions
	for (i = 0; i < m_MeshSize; ++i)
	{
		for (j = 0; j<m_MeshSize; ++j)
		{
			//this should create the variable vector2Int and send that one call = less work
			m_navMesh[i][j].setGridX(i);
			m_navMesh[i][j].setGridY(j);
		}
	}
	return(true);
}

//i don't think this actually cleans the memoery properly
void NavMesh::cleanMap()
{
	//for(int i=0;i<m_sizeOfMesh;i++)
	{
		//delete[] m_mesh[i];
		delete[] m_navMesh;
	}
	delete[] m_navMesh;
}

int NavMesh::difference(int num1, int num2)
{
	int ret;

	if(num1>num2)
	{
		ret = num1 - num2;
	}
	else if(num1<num2)
	{
		ret = num2 - num1;
	}
	else
	{
		ret = 0;
	}
	return(ret);
}

int NavMesh::findMoveCost(as_node *currentNode, as_node *movingToNode)
{
	

	int x = difference(currentNode->getGridX(),movingToNode->getGridX());
	int y = difference(currentNode->getGridY(),movingToNode->getGridY());
	
	int ang = x+y;

	//the function above will make ang result in 2 if a diagonal movement (14)
	//and a 1 for a straight movement (10)
	if(ang == 1)
	{
		return(10);
	}
	else if(ang == 2)
	{
		return(14);
	}
}

void NavMesh::getAdjacentNodes(as_node *currentNode, std::vector<as_node*> *adjacent)
{
	// [-1,-1][0,-1][1,-1]
	// [-1, 0][0, 0][1, 0]
	// [-1, 1][0, 1][1, 1]

	int currentX = currentNode->getGridX();
	int currentY = currentNode->getGridY();

	int checkNodeX;
	int checkNodeY;

	//top_left
	checkNodeX = currentX -1;
	checkNodeY = currentY -1;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}

	//top
	checkNodeX = currentX +0;
	checkNodeY = currentY -1;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}
//top_right
	checkNodeX = currentX +1;
	checkNodeY = currentY -1;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}
//mid_left
	checkNodeX = currentX -1;
	checkNodeY = currentY + 0;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}
//mid we can skip

//mid_right
	checkNodeX = currentX +1;
	checkNodeY = currentY +0;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}
//bot_left
	checkNodeX = currentX -1;
	checkNodeY = currentY +1;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}
//bot
	checkNodeX = currentX +0;
	checkNodeY = currentY +1;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}
//bot_right
	checkNodeX = currentX +1;
	checkNodeY = currentY +1;

	if(checkValidNode(checkNodeX,checkNodeY))
	{
		as_node *node;
		node = getNode(checkNodeX,checkNodeY);
		adjacent->push_back(node);
	}








}

bool NavMesh::checkValidNode(int x, int y)
{
	if(x <0)
		return(false);
	if(y<0)
		return(false);
	if(x>=m_MeshSize)
		return(false);
	if(y>=m_MeshSize)
		return(false);

	return(true);
}

void NavMesh::resetNodeCreation()
{
	for(int i=0; i<m_MeshSize;++i)
	{
		for(int j =0;j<m_MeshSize;++j)
		{
			m_navMesh[i][j].createdBefore = false;
			m_navMesh[i][j].setParent(NULL);
			
		}
	}
}

void NavMesh::removeBlockedNodes(std::vector<as_node*> *adjacent)
{
	//loop through remove all blocked nodes
	for(int i=0;i<adjacent->size();++i)
	{
		if(adjacent->at(i)->getNodeBlock() == true)
		{
			adjacent->erase(adjacent->begin()+i);
			i=-1;
		}
	}
}

bool NavMesh::onList(as_node *node,std::vector<as_node*> *nodeList)
{
	int currentX = node->getGridX();
	int currentY = node->getGridY();

	int checkX;
	int checkY;

	for(int i=0;i<nodeList->size();++i)
	{
		checkX = nodeList->at(i)->getGridX();
		checkY = nodeList->at(i)->getGridY();

		if((checkX == currentX) && (checkY == checkY))
		{
			return(true);
		}
	}
	return(false);
}