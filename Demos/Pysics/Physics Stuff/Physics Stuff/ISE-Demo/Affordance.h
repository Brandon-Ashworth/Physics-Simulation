
class Affordance
{
public:

	Affordance();
	Affordance(float eat,float drink, float pickup);
	~Affordance(void);

	void setEat(float eat);
	void setDrink(float drink);
	void setPickup(float pickup);

	float getEat();
	float getDrink();
	float getPickup();

private:
	float m_Eat;
	float m_Drink;
	float m_PickUp;
};
