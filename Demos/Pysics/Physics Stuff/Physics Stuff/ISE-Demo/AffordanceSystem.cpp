#include "AffordanceSystem.h"


AffordanceSystem::AffordanceSystem(void)
{
}


AffordanceSystem::~AffordanceSystem(void)
{
}

void AffordanceSystem::registerAffordance(int ID,float eat,float drink,float pickup)
{
	Affordance temp(eat,drink,pickup);
	affList[ID] = temp;
}

Affordance AffordanceSystem::getAffordaces(int ID)
{
	std::map<int,Affordance>::iterator it = affList.find(ID);

	if(it != affList.end())
	{
		return(it->second);
	}
	else
	{
		Affordance temp(-1,-1,-1);
		return(temp);
	}
}

bool AffordanceSystem::getAffordanceMeetsEats(int ID, float eat)
{
	std::map<int,Affordance>::iterator it = affList.find(ID);

	if(it != affList.end())
	{
		float m_eat = it->second.getEat();
		if(eat <= m_eat)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else
	{
		return(false);
		
	}
}
bool AffordanceSystem::getAffordanceMeetsDrinks(int ID, float drink)
{
	std::map<int,Affordance>::iterator it = affList.find(ID);

	if(it != affList.end())
	{
		float m_drink = it->second.getDrink();
		if(drink <= m_drink)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else
	{
		return(false);
		
	}
}
bool AffordanceSystem::getAffordanceMeetsPickup(int ID, float pickup)
{
	std::map<int,Affordance>::iterator it = affList.find(ID);

	if(it != affList.end())
	{
		float m_pickup = it->second.getPickup();
		if(pickup <= m_pickup)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else
	{
		return(false);
		
	}
}

bool AffordanceSystem::IdExists(int ID)
{
	std::map<int,Affordance>::iterator it = affList.find(ID);

	if(it != affList.end())
	{
		return(true);
	}
	else
	{
		
		return(false);
	}
}