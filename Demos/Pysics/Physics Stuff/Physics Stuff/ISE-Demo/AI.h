#pragma once

#include "Component.h"
#include "Personality.h"
#include "NavMesh.h"
#include "as_node.h"
#include <string>
#include <vector>
#include <stack>

class AI : public virtual Component
{
public:
	// Class constructor.
	AI();

	// Gets and Sets.
	// Get the status of the AI. Enabled? Disabled?
	bool getEnabled();
	// Change if the AI is enabled or not.
	void setEnabled(bool enabled);
	// Get the Personality by index's name.
	std::string getPersonalityName(int index);
	// Set the Personality by index's name.
	void setPersonalityName(int index, std::string name);
	// Get the Perosnality by index's case's name by case index.
	std::string getPersonalityName(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's name by case index.
	void setPersonalityName(int index, Personality::caseType casetype, int caseIndex, std::string name);
	// Get the Perosnality by index's case's amount by case index.
	float getPersonalityAmount(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's amount by case index.
	void setPersonalityAmount(int index, Personality::caseType casetype, int caseIndex, float amount);
	// Get the Perosnality by index's case's positive modifier by case index.
	float getPersonalityPositiveModifier(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's positive modifier by case index.
	void setPersonalityPositiveModifier(int index, Personality::caseType casetype, int caseIndex, float positiveModifier);
	// Get the Perosnality by index's case's negative modifier by case index.
	float getPersonalityNegativeModifier(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's negative modifier by case index.
	void setPersonalityNegativeModifier(int index, Personality::caseType casetype, int caseIndex, float negativeModifier);
	// Get the Perosnality by index's case's interval by case index.
	float getPersonalityInterval(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's interval by case index.
	void setPersonalityInterval(int index, Personality::caseType casetype, int caseIndex, float interval);
	// Get the Perosnality by index's case's increment by case index.
	float getPersonalityIncrement(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's increment by case index.
	void setPersonalityIncrement(int index, Personality::caseType casetype, int caseIndex, float increment);
	// Get the Perosnality by index's case's effect queue by case index.
	float getPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's effect queue by case index.
	void setPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex, float effectQueue);
	// Get the Perosnality by index's case's acculumated time by case index.
	float getPersonalityAccumulatedTime(int index, Personality::caseType casetype, int caseIndex);
	// Set the Perosnality by index's case's acculumated time by case index.
	void setPersonalityAccumulatedTime(int index, Personality::caseType casetype, int caseIndex, float accumulatedTime);

	void setNavSize(int size);
	int getNavSize();

	// Other:
	// Add a personality.
	void addPersonality();
	// delete a personality by index.
	void deletePersonality(int index);
	// Add EmotionCase by caseType to Personality by index.
	void addPersonalityEmotionCase(int index, Personality::caseType casetype);
	// Delete EmotionCase by caseType to Personality by index.
	void deletePersonalityEmotionCase(int index, Personality::caseType casetype, int caseIndex);
	// Adds effect amount to EmotionCase by caseType to Personality by index.
	void addToPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex, float effect);
	// Updates AI.
	void update(float deltaTime);

	bool initMesh();
	void blockNode(int x, int y);
	void unblockNode(int x, int y);
	as_node* getNode(int x,int y);
	std::stack<Vector2Int> getPath(as_node *start, as_node *goal);

private:
	std::vector<Personality*> m_Personality;
	NavMesh m_navMesh;
	bool m_Enabled;
};