#pragma once
#include "Component.h"
#include "Affordance.h"
#include <map>

/**
 * @brief The simple affordance system
 * @details This is a somple affordance system, it contains a static number of 
 * affordances and all three must be given to all objects. this is a very bad
 * way of doing affordances. a dynamic solution would be better
 * @return [description]
 */
class AffordanceSystem : public virtual Component
{
public:
	AffordanceSystem(void);
	~AffordanceSystem(void);
	/**
	 * @brief register an object ID to an affordance 
	 * @details Registers an objects ID to corresponding eat drink and pickup values
	 * 
	 * @param ID The ID of the Game Object
	 * @param eat the eat value of the Game Object
	 * @param drink the drink value of the Game Object
	 * @param pickup the pickup value of the Game Object
	 */
	void registerAffordance(int ID, float eat, float drink, float pickup);
	/**
	 * @brief retrive the entire affordance variable list
	 * @details Get the whole affordance structure so you can access all the values
	 * 
	 * @param ID The ID of the game object you want to check
	 * @return affordance containing the whole data structure 
	 * @bug this is very bad people should not have access to this
	 */
	Affordance getAffordaces(int ID);

	/**
	 * @brief check if it is eatable
	 * @details Check the objectID and sees if it meets the requrements to be eaten
	 * 
	 * @param ID ID of the game object
	 * @param eat the minimum requirements to be eaten
	 * 
	 * @return true if it is eatable, false if not
	 */
	bool getAffordanceMeetsEats(int ID, float eat);
	/**
	 * @brief check if it is drinkable
	 * @details Check the objectID and sees if it meets the requrements to be drunk
	 * 
	 * @param ID ID of the game object
	 * @param eat the minimum requirements to be drunk
	 * 
	 * @return true if it is drinkable, false if not
	 */
	bool getAffordanceMeetsDrinks(int ID, float drink);
	/**
	 * @brief check if it is pickupable
	 * @details Check the objectID and sees if it meets the requrements to be picked up
	 * 
	 * @param ID ID of the game object
	 * @param eat the minimum requirements to be picked up
	 * 
	 * @return true if it is pickupable, false if not
	 */
	bool getAffordanceMeetsPickup(int ID, float pickup);

	/**
	 * @brief check if a Game object exists
	 * @details Checks if the GameObject ID has been registers within the affordance system yet
	 * 
	 * @param ID ID of the game object
	 * @return true if exists, else false
	 */
	bool IdExists(int ID);

	//bool removeAffordance(int ID);


private:
	std::map<int,Affordance> affList;
	
	//best way to store this would be a boot bimap explination below
	/*
	int m_HighestEatID;
	int m_HighestDrinkID;
	int m_HighestPickupID;
	*/
	/*
	Okay so what i want to acheive is a list of items with the highest to lowest eat value.
	to do this we need a structure where the position is sorted by a value within the tree then the ID.
	reason is so we can have fast lookup times when searching the other structtures for the same ID.

	so if we have a buger with a eat of 0.5, drink of 0.2 and pickup of 0.3, another entity comes along and says i want to through something.
	so he looks for the item within the list with the highest throw value. he claims thta item by removing it from the other affordance lists
	and his action will most likely destroy the item (hopefully) if its destroyed do nothing if still okay place back into affordance system (maybe with less eat).

	to make removing from the other lists easy we need to have the lists sorted by their values then ID's

	Alternative:
		Using pointers we hold the all the information in one structure 

		We hold all the items within a structure and we have a sorted list for each affordance, 
		eg. eat will have a sorted list containing the eat value and objectID. it pops the highest eatValue off the top 
		and searches for it within the structure that contains all the information. if it finds the item remove it and let the NPC claim it. if it is not found that means
		it has been removed by another enitity so go pop the next item off until it finds and item

		stl::map you can send a functin pointer into it to do comparisons, that should solve the problem above


	*/
};

