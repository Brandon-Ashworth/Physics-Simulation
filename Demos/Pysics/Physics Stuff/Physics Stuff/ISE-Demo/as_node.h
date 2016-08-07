#pragma once

#include <iostream>
#include "Vector2Int.h"

/**
 * @brief Contains the grid node items
 * @details This class holds the varaibles needed for the grid information
 * @author: Umar Badat
 * 
 * @bug: There is a varaible called createdBefore that is public, needs to be changed to private
 */
class as_node
{
public:
	as_node(void);
	~as_node(void);
	
	/**
	 * @brief set the node to a blocked or non blocked state
	 * @details Enter a boolean to select if a node is accessable by the NPC or not
	 * 
	 * @param isBlocked enter True if you want to block the node, false if you want it unblocked
	 */
	void setNodeBlock(bool isBlocked);//seting the node blocking
	/**
	 * @brief gets if the node is blocked or not
	 * @details returns true if the node is blocked false if it is not
	 * @return read above
	 */
	bool getNodeBlock();

	
	/**
	 * @brief set node position in the grid
	 * @details set the Position of this node within the grid, this allows it to know where 
	 * itself is located in the wolrd and in the grid. helps with finding the adjacent nodes
	 * 
	 * @param newPos sets the position of the node to the vector position
	 */
	void setGridPos(Vector2Int newPos);//setting the node position in the grid
	/**
	 * @brief gets the grid position
	 * @details gets the position of this node within the grid
	 * @return see above
	 */
	Vector2Int getGridPos();

	/**
	 * @brief set the x position on the grid
	 * 
	 * @details Specifically sets the X position
	 * 
	 * @param x X position on grid
	 */
	void setGridX(int x);
	/**
	 * @brief gets the X position
	 * @details gets the X position
	 * @return gets the X position
	 */
	int getGridX();

	/**
	 * @brief sets the Y position on the grid
	 * @details sets the Y position on the grid
	 * 
	 * @param y sets the Y position on the grid
	 */
	void setGridY(int y);
	/**
	 * @brief gets the Y position on the grid
	 * @details gets the Y position on the grid
	 * @return gets the Y position on the grid
	 */
	int getGridY();

	/**
	 * @brief sets the parent
	 * @details Sets the parent of this node to another node
	 * 
	 * @param newParent the parent we want this node to point to
	 */
	void setParent(as_node *newParent);//setting the parent node
	/**
	 * @brief get the parent
	 * @details Gets the parent node of this node
	 * @return read above
	 */
	as_node &getParent();

	//setting the heuristic cost
	/**
	 * @brief sets the Hueristic cost
	 * @details sets the estimated distance from the goal position
	 * 
	 * @param newHue sets the heuristic
	 */
	void setHueristic(int newHue);
	/**
	 * @brief get the heuristic value
	 * @details Retrive the heuristic value of the node to the desination point
	 * @return read above
	 */
	int getHueristic();

	//setting the finalcost
	/**
	 * @brief set the finalCost
	 * @details sets the final cost of the path to this node, it already adds the Heuristic value to
	 * the finalCost. this is standard see the cpp file for details
	 * 
	 * @param givenCost The cost of the path taken so far
	 */
	void setFinalCost(int givenCost);
	/**
	 * @brief get finalCost
	 * @details get the final cost of the path to this node
	 * @return see above
	 */
	int getFinalCost();

	/**
	 * @bug: This should be private
	 */
	bool createdBefore;


private:
	int m_x;
	int m_y;
	as_node *parent;
	int hue;
	int finalCost;
	bool blocked;
	
};

