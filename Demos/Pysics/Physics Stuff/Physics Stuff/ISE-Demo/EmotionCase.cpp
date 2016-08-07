#include "EmotionCase.h"

// Class constructor
// Initialise values.
EmotionCase::EmotionCase()
{
	m_Name = "";
	m_Amount = 0;
	m_ModifierPositive = 1;
	m_ModifierNegative = 1;
	m_Interval = 1;
	m_Increment = 0;
	m_EffectQueue = 0;
}

// Gets and Sets:
// Gets EmotionCase name.
std::string EmotionCase::getName()
{
	return m_Name;
}

// Sets EmotionCase name.
void EmotionCase::setName(std::string name)
{
	m_Name = name;
}

// Gets EmotionCase amount.
float EmotionCase::getAmount()
{
	return m_Amount;
}

// Sets EmotionCase amount.
void EmotionCase::setAmount(float amount)
{
	m_Amount = amount;
}

// Gets EmotionCase positive modifier.
float EmotionCase::getModifierPositive()
{
	return m_ModifierPositive;
}

// Sets EmotionCase positive modifier.
void EmotionCase::setModifierPositive(float modifier)
{
	m_ModifierPositive = modifier;
}

// Gets EmotionCase negative modifier.
float EmotionCase::getModifierNegative()
{
	return m_ModifierNegative;
}

// Sets EmotionCase negative modifier.
void EmotionCase::setModifierNegative(float modifier)
{
	m_ModifierNegative = modifier;
}

// Gets EmotionCase interval.
float EmotionCase::getInterval()
{
	return m_Interval;
}

// Sets EmotionCase interval.
void EmotionCase::setInterval(float interval)
{
	m_Interval = interval;
}

// Gets EmotionCase increment.
float EmotionCase::getIncrement()
{
	return m_Increment;
}

// Sets EmotionCase .
void EmotionCase::setIncrement(float increment)
{
	m_Increment = increment;
}

// Gets EmotionCase effect queue.
float EmotionCase::getEffectQueue()
{
	return m_EffectQueue;
}

// Sets EmotionCase effect queue.
void EmotionCase::setEffectQueue(float effectQueue)
{
	m_EffectQueue = effectQueue;
}


// Gets EmotionCase accumulated time.
float EmotionCase::getAccumulatedTime()
{
	return m_AccumulatedTime;
}

// Sets EmotionCase accumulated time.
void EmotionCase::setAccumulatedTime(float accumulatedTime)
{
	m_AccumulatedTime = accumulatedTime;
}

// Other:
// Adds effect amount to effect queue.
void EmotionCase::addToEffectQueue(float effect)
{
	m_EffectQueue += effect;
}

// Updates the EmotionCase.
void EmotionCase::update(float deltaTime)
{
	m_AccumulatedTime += deltaTime;
	// Apply effects first.
	if (m_EffectQueue > 0)
	{
		m_Amount += m_EffectQueue * m_ModifierPositive;
	}
	else if (m_EffectQueue < 0)
	{
		m_Amount += m_EffectQueue * m_ModifierNegative;
	}
	// Apply incremental effects second.
	while (m_AccumulatedTime > m_Interval)
	{
		m_AccumulatedTime -= m_Interval;
		if (m_EffectQueue > 0)
		{
			m_Amount += m_Increment * m_ModifierPositive;
		}
		else if (m_EffectQueue < 0)
		{
			m_Amount += m_Increment * m_ModifierNegative;
		}
	}
}