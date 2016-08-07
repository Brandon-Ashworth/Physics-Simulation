#include "AI.h"

// Class constructor.
AI::AI()
{
	m_Enabled = false;
}

// Gets and Sets.
// Get the status of the AI. Enabled? Disabled?
bool AI::getEnabled()
{
	return m_Enabled;
}

// Change if the AI is enabled or not.
void AI::setEnabled(bool enabled)
{
	m_Enabled = enabled;
}

// Get the Personality by index's name.
std::string AI::getPersonalityName(int index)
{
	return m_Personality[index]->getName();
}

// Get the Personality by index's name.
void AI::setPersonalityName(int index, std::string name)
{
	return m_Personality[index]->setName(name);
}

// Get the Perosnality by index's case's name by case index.
std::string AI::getPersonalityName(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getName(casetype, caseIndex);
}

// Set the Perosnality by index's case's name by case index.
void AI::setPersonalityName(int index, Personality::caseType casetype, int caseIndex, std::string name)
{
	m_Personality[index]->setName(casetype, caseIndex, name);
}

// Get the Perosnality by index's case's amount by case index.
float AI::getPersonalityAmount(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getAmount(casetype, caseIndex);
}

// Set the Perosnality by index's case's amount by case index.
void AI::setPersonalityAmount(int index, Personality::caseType casetype, int caseIndex, float amount)
{
	m_Personality[index]->setAmount(casetype, caseIndex, amount);
}

// Get the Perosnality by index's case's positive modifier by case index.
float AI::getPersonalityPositiveModifier(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getPositiveModifier(casetype, caseIndex);
}

// Set the Perosnality by index's case's positive modifier by case index.
void AI::setPersonalityPositiveModifier(int index, Personality::caseType casetype, int caseIndex, float positiveModifier)
{
	m_Personality[index]->setPositiveModifier(casetype, caseIndex, positiveModifier);
}

// Get the Perosnality by index's case's negative modifier by case index.
float AI::getPersonalityNegativeModifier(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getNegativeModifier(casetype, caseIndex);
}

// Set the Perosnality by index's case's negative modifier by case index.
void AI::setPersonalityNegativeModifier(int index, Personality::caseType casetype, int caseIndex, float negativeModifier)
{
	m_Personality[index]->setNegativeModifier(casetype, caseIndex, negativeModifier);
}

// Get the Perosnality by index's case's interval by case index.
float AI::getPersonalityInterval(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getInterval(casetype, caseIndex);
}

// Set the Perosnality by index's case's interval by case index.
void AI::setPersonalityInterval(int index, Personality::caseType casetype, int caseIndex, float interval)
{
	m_Personality[index]->setInterval(casetype, caseIndex, interval);
}

// Get the Perosnality by index's case's increment by case index.
float AI::getPersonalityIncrement(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getIncrement(casetype, caseIndex);
}

// Set the Perosnality by index's case's interval by case index.
void AI::setPersonalityIncrement(int index, Personality::caseType casetype, int caseIndex, float increment)
{
	m_Personality[index]->setIncrement(casetype, caseIndex, increment);
}

// Get the Perosnality by index's case's effect queue by case index.
float AI::getPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getEffectQueue(casetype, caseIndex);
}

// Set the Perosnality by index's case's effect queue by case index.
void AI::setPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex, float effectQueue)
{
	m_Personality[index]->setEffectQueue(casetype, caseIndex, effectQueue);
}

// Get the Perosnality by index's case's acculumated time by case index.
float AI::getPersonalityAccumulatedTime(int index, Personality::caseType casetype, int caseIndex)
{
	return m_Personality[index]->getAccumulatedTime(casetype, caseIndex);
}

// Set the Perosnality by index's case's acculumated time by case index.
void AI::setPersonalityAccumulatedTime(int index, Personality::caseType casetype, int caseIndex, float accumulatedTime)
{
	m_Personality[index]->setAccumulatedTime(casetype, caseIndex, accumulatedTime);
}

void AI::setNavSize(int size)
{
	m_navMesh.setNavSize(size);
}

int AI::getNavSize()
{
	return m_navMesh.getNavSize();
}

// Other.
// Add a personality.
void AI::addPersonality()
{
	m_Personality.push_back(new Personality);
}

// delete a personality by index.
void AI::deletePersonality(int index)
{
	m_Personality.erase(m_Personality.begin() + index);
}

// Add EmotionCase by caseType to Personality by index.
void AI::addPersonalityEmotionCase(int index, Personality::caseType casetype)
{
	m_Personality[index]->addEmotionCase(casetype);
}

// Delete EmotionCase by caseType to Personality by index.
void AI::deletePersonalityEmotionCase(int index, Personality::caseType casetype, int caseIndex)
{
	m_Personality[index]->deleteEmotionCase(casetype, caseIndex);
}

// Adds effect amount to EmotionCase by caseType to Personality by index.
void AI::addToPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex, float effect)
{
	m_Personality[index]->addToEffectQueue(casetype, caseIndex, effect);
}

void AI::update(float deltaTime)
{
	for (int i = 0; i < m_Personality.size(); i++)
	{
		m_Personality[i]->update(deltaTime);
	}
}

bool AI::initMesh()
{
	return m_navMesh.initMesh();
}

void AI::blockNode(int x, int y)
{
	m_navMesh.blockNode(x, y);
}

void AI::unblockNode(int x, int y)
{
	m_navMesh.unblockNode(x, y);
}

as_node* AI::getNode(int x,int y)
{
	return m_navMesh.getNode(x, y);
}

std::stack<Vector2Int> AI::getPath(as_node *start, as_node *goal)
{
	return m_navMesh.getPath(start, goal);
}