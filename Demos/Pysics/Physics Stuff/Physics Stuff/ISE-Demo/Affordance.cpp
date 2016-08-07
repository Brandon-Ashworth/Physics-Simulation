#include "Affordance.h"

Affordance::Affordance()
{
	m_Eat = 0.0f;
	m_Drink = 0.0f;
	m_PickUp = 0.0f;
}

Affordance::Affordance(float eat,float drink, float pickup)
{
	m_Eat = eat;
	m_Drink = drink;
	m_PickUp = pickup;
}


Affordance::~Affordance(void)
{
}

void Affordance::setEat(float eat)
{
	m_Eat = eat;
}
void Affordance::setDrink(float drink)
{
	m_Drink = drink;
}
void Affordance::setPickup(float pickup)
{
	m_PickUp = pickup;
}

float Affordance::getEat()
{
	return(m_Eat);
}
float Affordance::getDrink()
{
	return(m_Drink);
}
float Affordance::getPickup()
{
	return(m_PickUp);
}