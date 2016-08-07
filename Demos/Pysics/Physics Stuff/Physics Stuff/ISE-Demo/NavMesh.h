#pragma once

#include "as_node.h"
#include <iostream>
#include <vector>
#include <stack>

/**
 * @brief This class binds the nodes together with the Astar algorithm
 * @details This class handles the grid, and Astar algorithm
 * This is done by making a 2d array of nodes representing their position on the grid
 * 
 * @author Umar Badat
 * 
 * @note: There are many areas where this class could be optimised, notes will be made at the actual function call
 * 
 * @bug: currently there is a bug where the information is dropped after a path is returned, this however does not produce any memory leaks. The reason could be because i don't new properly or don't reset all the values after finish locating the one path
 * @example: A Typical example of how to use the class is below
 * 
 * 	mesh.initMesh();
	as_node *goal = mesh.getNode(0,0);
	as_node *start = mesh.getNode(3,2);
	mesh.blockNode(2,1);
	mesh.blockNode(2,2);
	std::stack<Vector2Int> ret2 = mesh.getPath(start,goal);
	//loop through path
	while(!ret2.empty())
	{
		std::cout<< ret2.top().m_x
			<< ", " << ret2.top().m_y <<std::endl;
		ret2.pop();
		
	}
 * 
 * To obtain its position in the real world, find the gap between each node (K)
 * ret2.top().m_x * k = world position X
 * 
 */
class NavMesh
{
public:
	NavMesh(void);
	~NavMesh(void);

	/**
	 * @brief set the grid size
	 * @details This function sets the size of the grid to be made 
	 * 
	 * @param size an integer value of the size of the map
	 */
	void setNavSize(int size);
	//the world position stuff will be included later
	//setFisrtPos
	//setNodeGap

	/**
	 * @brief get size of grid
	 * @details Allows the user to obtain the size of the grid
	 * @return integer value specifying the size of the grid
	 */
	int getNavSize();
	//get first pos
	//get node gap

	/**
	 * @brief Initialises the Mesh
	 * @details This function creates a node on each spot of the grid and gives each node their position in the grid
	 * @return true if the grid was created if not false will be returned
	 * 
	 * @note: If the grid is not created check the setNavSize and make sure the number is above 0
	 */
	bool initMesh();

	//blocking and unblocking nodes, might be an idea to have an ID as well to speed up finding
	//no out of bounds checking done
	/**
	 * @brief sets a node to the "blocked" state
	 * @details Finds a node on the grid with the x and y positions given and 
	 * sets that node to an inaccessable state so the npc will not try to pass through it
	 * 
	 * 
	 * @param x X position on the grid
	 * @param y Y position on the grid
	 */
	void blockNode(int x, int y);
	/**
	 * @brief sets the node to the "unblocked" state
	 * @details Sets the node specified by its grid position to an unblocked state allowing it 
	 * to be traversed during the pathFinding step
	 * 
	 * @param x X position on the grid
	 * @param y Y position on the grid
	 */
	void unblockNode(int x, int y);

	/**
	 * @brief Get a single node
	 * @details Obtain a single node from the grid, this allows direct access to any node
	 * This is to allow you to pass a start and goal node into the GetPath function
	 * without having a very large function call to obtain the path
	 * 
	 * @param x X position on the grid
	 * @param y Y position on the grid
	 * 
	 * @return Node Pointer with the nodespecifed on the grid
	 */
	as_node *getNode(int x,int y);

	/**
	 * @brief obtian the path
	 * @details This function returns the nodes that need to be traversed in order to reach the goal from the start
	 * 
	 * 
	 * @param start Takes startNode as a pointer 
	 * @param goal takes goalNode as a pointer
	 * 
	 * @return A stack of the points it needs to traverse to get to the end node
	 * 
	 * @note: There are a lot of areas where optimisation can be added, this algorithm 
	 * was written with lots of functions that could be brought into another seperate class
	 * 
	 * @bug: SuccessorNode is an unused Variable
	 * @bug: where we pop the lowest FvaluedNode we search the whole vector, this can be done better by having an std::ordered list
	 * @bug: passing the address of the Adjacent variable should be done like this getAdjacentNodes(currentNode,adjacent);, this makes it easier for the user
	 * @bug: The main algorithm for searching through the nodes should be seperated and needs to be formated better with better inline comments so make it easier to understand what is happening
	 * @bug: lots of inline comments unessesary and commented out code should be removed
	 * @bug: the function to convert the pointer list is very dodgy problems listed below
	 * 			-This section of code not explained
	 * 			-Will through Access Violation error if done any differently
	 * 			-loops until there are no more parents (if there are 2 nodes that point to each other)
	 * 
	 */
	std::stack<Vector2Int>getPath(as_node *start, as_node *goal);

	
private:
	//calcHueristics, calcualte the huristics will be called when the 
	//function to calc the path is called
	/**
	 * @brief The Heuristic algorithm
	 * @details This function calculates the Heuristic values for all the nodes
	 * This is done to allow the estimation process to be attached to every node
	 * The Heuristic algorithm that was used is known as the "Manhatten" algorithm 
	 * 
	 * @param goal Takes the goal position and assigns the distance between that
	 * and all the nodes
	 */
	void calcHue(as_node *goal);

	//variables
	/**
	 * @brief double pointer
	 * @details This double pointer allows us to store a 2d array with a dynamic size
	 * 
	 */
	as_node **m_navMesh;
	/**
	 * @brief size of grid
	 * @details This number stores the size of the grid
	 * 
	 */
	int m_MeshSize;//the size of the nav mesh

	/**
	 * @brief creates the grid
	 * @details Loops through the 2d array and creates all the nodes
	 * @return true if grid created, flase if failed
	 * 
	 * @bug: nodes are being dropped after the Path has been found, this could have something to do with the way i am newing them
	 */
	bool createMap();
	/**
	 * @brief destroys the grid
	 * @details destroys all the nodes in the grid (they were new'ed)
	 * 
	 * @bug: i don't think the map cleaning is working properly, but the nodes are dropped when the program ends 
	 */
	void cleanMap();

	//some calculation things to make it easier to finc values
	/**
	 * @brief Find the absolute difference
	 * @details Works exactly how the math.h abs() function in that it finds the 
	 * absolute difference between two numbers. it will return a number that is
	 * the distance between the two numbers. e.g. -5 and 5 will have an absolute
	 * difference of 10
	 * 
	 * @param num1 The first number
	 * @param num2 The second number
	 * 
	 * @return The absolute difference between the two numbers
	 */
	int difference(int num1,int num2);// find the absolute difference between 2 numbers //find the move cost of the current node to the node we might move to
	
	/**
	 * @brief Find the cost to move 
	 * @details Find the cost to move the NPC from one node to the next, if the movement is 
	 * a diagonal one the moveCost is 14 while the movecost of a straight line is 10.The reason these
	 * numbers are used is because if we take a right angle triangle with a height of 1 and a length of 1 
	 * the hypotinuse will be 1.4141. 
	 * 
	 * @param currentNode The node we are currently at
	 * @param movingToNode The node we will more to 
	 * 
	 * @return The move cost from the currentNode to the MovingToNode
	 */
	int findMoveCost(as_node *currentNode, as_node *movingToNode);

	/**
	 * @brief obtain the adjacent nodes
	 * @details Obtain the nodes that are around the currentNode
	 * 
	 * @param currentNode The node we want to find the nodes around
	 * @param adjacent The list we will write the nearby nodes into
	 */
	void getAdjacentNodes(as_node *currentNode, std::vector<as_node*> *adjacent);//obtain the adjacent nodes
	/**
	 * @brief Remove Blocked Nodes
	 * @details This function removes the nodes that are unaccessable by the NPC
	 * 
	 * @param adjacent The node list we want to remove the blocked nodes from
	 */
	void removeBlockedNodes(std::vector<as_node*> *adjacent);

	//others
	/**
	 * @brief reset the nodes creation bool
	 * 
	 * @details This function resets the boolean that checks if the node has
	 * been created before, sets all the nodes to false
	 */
	void resetNodeCreation();
	/**
	 * @brief checks if a node position is valid
	 * @details Checks if the position given is a valid node in the grid, it does
	 * bounds checking basically
	 * 
	 * @param x X position is grid
	 * @param y Y position in grid
	 * 
	 * @return true if it is a valid node, else false
	 */
	bool checkValidNode(int x, int y);

	/**
	 * @brief check if a node is present in a list
	 * @details Takes in a node to find in a list of nodes
	 * 
	 * @param node The node we want to find
	 * @param nodeList The list of nodes we are checking against
	 * 
	 * @return true if the node was found in the list, else false
	 */
	bool onList(as_node *node,std::vector<as_node*> *nodeList);
};

