#pragma once

#include "EmotionCase.h"
#include <vector>

class Personality
{
public:
	// Enumerations
	enum caseType
	{
		EMOTION = 0, MOOD, TRAIT
	};

	// Class constructor
	Personality();

	// Gets and Sets
	// Get name of Personality.
	std::string getName();
	// Set name of Personality.
	void setName(std::string name);
	// Get name of indexed case of caseType.
	std::string getName(caseType casetype, int index);
	// Set name of indexed case of caseType.
	void setName(caseType casetype, int index, std::string name);
	// Get amount of indexed case of caseType.
	float getAmount(caseType casetype, int index);
	// Set amount of indexed case of caseType.
	void setAmount(caseType casetype, int index, float amount);
	// Get positive modifier of indexed case of caseType.
	float getPositiveModifier(caseType casetype, int index);
	// Set positive modifier of indexed case of caseType.
	void setPositiveModifier(caseType casetype, int index, float positiveModifier);
	// Get negative modifier of indexed case of caseType.
	float getNegativeModifier(caseType casetype, int index);
	// Set negative modifier of indexed case of caseType.
	void setNegativeModifier(caseType casetype, int index, float negativeModifier);
	// Get interval of indexed case of caseType.
	float getInterval(caseType casetype, int index);
	// Set interval of indexed case of caseType.
	void setInterval(caseType casetype, int index, float interval);
	// Get increment of indexed case of caseType.
	float getIncrement(caseType casetype, int index);
	// Set increment of indexed case of caseType.
	void setIncrement(caseType casetype, int index, float increment);
	// Get queue of effects of indexed case of caseType.
	float getEffectQueue(caseType casetype, int index);
	// Set queue of effects of indexed case of caseType.
	void setEffectQueue(caseType casetype, int index, float effectQueue);
	// Get the time accumulated of indexed case of caseType.
	float getAccumulatedTime(caseType casetype, int index);
	// Set the time accumulated of indexed case of caseType.
	void setAccumulatedTime(caseType casetype, int index, float accumulatedTime);

	// Other:
	// Add EmotionCase by caseType.
	void addEmotionCase(caseType casetype);
	// Delets EmotionCase by caseType and by index.
	void deleteEmotionCase(caseType casetype, int index);
	// Adds effect amount to effect queue of indexed case of caseType.
	void addToEffectQueue(caseType casetype, int index, float effect);
	// Updates the Personality.
	void update(float deltaTime);

private:
	std::string m_Name;
	std::vector<EmotionCase*> m_Trait;
	std::vector<EmotionCase*> m_Mood;
	std::vector<EmotionCase*> m_Emotion;
};