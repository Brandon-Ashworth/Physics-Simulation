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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getName();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getName();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setName(name);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setName(name);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getAmount();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getAmount();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setAmount(amount);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setAmount(amount);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getModifierPositive();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getModifierPositive();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setModifierPositive(positiveModifier);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setModifierPositive(positiveModifier);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getModifierNegative();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getModifierNegative();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setModifierNegative(negativeModifier);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setModifierNegative(negativeModifier);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getInterval();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getInterval();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setInterval(interval);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setInterval(interval);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getIncrement();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getIncrement();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setIncrement(increment);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setIncrement(increment);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getEffectQueue();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getEffectQueue();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setEffectQueue(effectQueue);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setEffectQueue(effectQueue);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			return m_Mood[index]->getAccumulatedTime();
			break;
		}
	case TRAIT:
		{
			return m_Trait[index]->getAccumulatedTime();
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->setAccumulatedTime(accumulatedTime);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->setAccumulatedTime(accumulatedTime);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood.push_back(new EmotionCase);
			break;
		}
	case TRAIT:
		{
			m_Trait.push_back(new EmotionCase);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood.erase(m_Mood.begin() + index);
			break;
		}
	case TRAIT:
		{
			m_Trait.erase(m_Trait.begin() + index);
			break;
		}
	default:
		{
			break;
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
			break;
		}
	case MOOD:
		{
			m_Mood[index]->addToEffectQueue(effect);
			break;
		}
	case TRAIT:
		{
			m_Trait[index]->addToEffectQueue(effect);
			break;
		}
	default:
		{
			break;
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