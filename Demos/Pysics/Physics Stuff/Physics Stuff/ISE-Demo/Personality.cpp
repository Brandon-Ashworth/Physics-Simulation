#pragma once

#include "Personality.h"

// Class constructor
Personality::Personality()
{
	m_Name = "";
}

// Gets and Sets
// Get name of Personality.
std::string Personality::getName()
{
	return m_Name;
}

// Set name of Personality.
void Personality::setName(std::string name)
{
	m_Name = name;
}

// Get name of indexed case of caseType.
std::string Personality::getName(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getName();
		}
	case MOOD:
		{
			return m_Mood[index]->getName();
		}
	case TRAIT:
		{
			return m_Trait[index]->getName();
		}
	default:
		{
			return "";
		}
	}
}

// Set name of indexed case of caseType.
void Personality::setName(caseType casetype, int index, std::string name)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setName(name);
		}
	case MOOD:
		{
			m_Mood[index]->setName(name);
		}
	case TRAIT:
		{
			m_Trait[index]->setName(name);
		}
	default:
		{
		}
	}
}

// Get amount of indexed case of caseType.
float Personality::getAmount(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getAmount();
		}
	case MOOD:
		{
			return m_Mood[index]->getAmount();
		}
	case TRAIT:
		{
			return m_Trait[index]->getAmount();
		}
	default:
		{
			return 0;
		}
	}
}

// Set amount of indexed case of caseType.
void Personality::setAmount(caseType casetype, int index, float amount)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setAmount(amount);
		}
	case MOOD:
		{
			m_Mood[index]->setAmount(amount);
		}
	case TRAIT:
		{
			m_Trait[index]->setAmount(amount);
		}
	default:
		{
		}
	}
}

// Get positive modifier of indexed case of caseType.
float Personality::getPositiveModifier(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getModifierPositive();
		}
	case MOOD:
		{
			return m_Mood[index]->getModifierPositive();
		}
	case TRAIT:
		{
			return m_Trait[index]->getModifierPositive();
		}
	default:
		{
			return 1;
		}
	}
}

// Set positive modifier of indexed case of caseType.
void Personality::setPositiveModifier(caseType casetype, int index, float positiveModifier)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setModifierPositive(positiveModifier);
		}
	case MOOD:
		{
			m_Mood[index]->setModifierPositive(positiveModifier);
		}
	case TRAIT:
		{
			m_Trait[index]->setModifierPositive(positiveModifier);
		}
	default:
		{
		}
	}
}

// Get negative modifier of indexed case of caseType.
float Personality::getNegativeModifier(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getModifierNegative();
		}
	case MOOD:
		{
			return m_Mood[index]->getModifierNegative();
		}
	case TRAIT:
		{
			return m_Trait[index]->getModifierNegative();
		}
	default:
		{
			return 1;
		}
	}
}

// Set negative modifier of indexed case of caseType.
void Personality::setNegativeModifier(caseType casetype, int index, float negativeModifier)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setModifierNegative(negativeModifier);
		}
	case MOOD:
		{
			m_Mood[index]->setModifierNegative(negativeModifier);
		}
	case TRAIT:
		{
			m_Trait[index]->setModifierNegative(negativeModifier);
		}
	default:
		{
		}
	}
}

// Get interval of indexed case of caseType.
float Personality::getInterval(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getInterval();
		}
	case MOOD:
		{
			return m_Mood[index]->getInterval();
		}
	case TRAIT:
		{
			return m_Trait[index]->getInterval();
		}
	default:
		{
			return 0;
		}
	}
}

// Set interval of indexed case of caseType.
void Personality::setInterval(caseType casetype, int index, float interval)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setInterval(interval);
		}
	case MOOD:
		{
			m_Mood[index]->setInterval(interval);
		}
	case TRAIT:
		{
			m_Trait[index]->setInterval(interval);
		}
	default:
		{
		}
	}
}

// Get increment of indexed case of caseType.
float Personality::getIncrement(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getIncrement();
		}
	case MOOD:
		{
			return m_Mood[index]->getIncrement();
		}
	case TRAIT:
		{
			return m_Trait[index]->getIncrement();
		}
	default:
		{
			return 0;
		}
	}
}

// Set increment of indexed case of caseType.
void Personality::setIncrement(caseType casetype, int index, float increment)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setIncrement(increment);
		}
	case MOOD:
		{
			m_Mood[index]->setIncrement(increment);
		}
	case TRAIT:
		{
			m_Trait[index]->setIncrement(increment);
		}
	default:
		{
		}
	}
}

// Get queue of effects of indexed case of caseType.
float Personality::getEffectQueue(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getEffectQueue();
		}
	case MOOD:
		{
			return m_Mood[index]->getEffectQueue();
		}
	case TRAIT:
		{
			return m_Trait[index]->getEffectQueue();
		}
	default:
		{
			return 0;
		}
	}
}

// Set queue of effects of indexed case of caseType.
void Personality::setEffectQueue(caseType casetype, int index, float effectQueue)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setEffectQueue(effectQueue);
		}
	case MOOD:
		{
			m_Mood[index]->setEffectQueue(effectQueue);
		}
	case TRAIT:
		{
			m_Trait[index]->setEffectQueue(effectQueue);
		}
	default:
		{
		}
	}
}

// Get the time accumulated of indexed case of caseType.
float Personality::getAccumulatedTime(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			return m_Emotion[index]->getAccumulatedTime();
		}
	case MOOD:
		{
			return m_Mood[index]->getAccumulatedTime();
		}
	case TRAIT:
		{
			return m_Trait[index]->getAccumulatedTime();
		}
	default:
		{
			return 0;
		}
	}
}

// Set the time accumulated of indexed case of caseType.
void Personality::setAccumulatedTime(caseType casetype, int index, float accumulatedTime)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->setAccumulatedTime(accumulatedTime);
		}
	case MOOD:
		{
			m_Mood[index]->setAccumulatedTime(accumulatedTime);
		}
	case TRAIT:
		{
			m_Trait[index]->setAccumulatedTime(accumulatedTime);
		}
	default:
		{
		}
	}
}

// Other:
// Add EmotionCase by caseType
void Personality::addEmotionCase(caseType casetype)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion.push_back(new EmotionCase);
		}
	case MOOD:
		{
			m_Mood.push_back(new EmotionCase);
		}
	case TRAIT:
		{
			m_Trait.push_back(new EmotionCase);
		}
	default:
		{
		}
	}
}

// Delets EmotionCase by caseType and by index.
void Personality::deleteEmotionCase(caseType casetype, int index)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion.erase(m_Emotion.begin() + index);
		}
	case MOOD:
		{
			m_Mood.erase(m_Mood.begin() + index);
		}
	case TRAIT:
		{
			m_Trait.erase(m_Trait.begin() + index);
		}
	default:
		{
		}
	}
}

// Adds effect amount to effect queue of indexed case of caseType.
void Personality::addToEffectQueue(caseType casetype, int index, float effect)
{
	switch(casetype)
	{
	case EMOTION:
		{
			m_Emotion[index]->addToEffectQueue(effect);
		}
	case MOOD:
		{
			m_Mood[index]->addToEffectQueue(effect);
		}
	case TRAIT:
		{
			m_Trait[index]->addToEffectQueue(effect);
		}
	default:
		{
		}
	}
}

// Updates the Personality.
void Personality::update(float deltaTime)
{
	int i = 0;
	for (i = 0; i < m_Emotion.size(); i++)
	{
		m_Emotion[i]->update(deltaTime);
	}
	for (i = 0; i < m_Mood.size(); i++)
	{
		m_Mood[i]->update(deltaTime);
	}
	for (i = 0; i < m_Trait.size(); i++)
	{
		m_Trait[i]->update(deltaTime);
	}
}