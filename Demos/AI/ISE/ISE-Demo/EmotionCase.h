#pragma once

#include <string>

class EmotionCase
{
public:
	// Class constructor
	EmotionCase();

	// Gets and Sets:
	// Gets EmotionCase name.
	std::string getName();
	// Sets EmotionCase name.
	void setName(std::string name);
	// Gets EmotionCase amount.
	float getAmount();
	// Sets EmotionCase amount.
	void setAmount(float amount);
	// Gets EmotionCase positive modifier.
	float getModifierPositive();
	// Sets EmotionCase positive modifier.
	void setModifierPositive(float modifier);
	// Gets EmotionCase negative modifier.
	float getModifierNegative();
	// Sets EmotionCase negative modifier.
	void setModifierNegative(float modifier);
	// Gets EmotionCase interval.
	float getInterval();
	// Sets EmotionCase interval.
	void setInterval(float interval);
	// Gets EmotionCase increment.
	float getIncrement();
	// Sets EmotionCase .
	void setIncrement(float increment);
	// Gets EmotionCase effect queue.
	float getEffectQueue();
	// Sets EmotionCase effect queue.
	void setEffectQueue(float effectQueue);
	// Gets EmotionCase accumulated time.
	float getAccumulatedTime();
	// Sets EmotionCase accumulated time.
	void setAccumulatedTime(float accumulatedTime);

	// Other:
	// Adds effect amount to effect queue.
	void addToEffectQueue(float effect);
	// Updates the EmotionCase.
	void update(float deltaTime);

private:
	std::string m_Name;
	float m_Amount;
	float m_ModifierPositive;
	float m_ModifierNegative;
	float m_Interval;
	float m_Increment;
	float m_EffectQueue;
	float m_AccumulatedTime;
};