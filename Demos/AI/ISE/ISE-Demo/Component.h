#pragma once

#include "Personality.h"
#include "Axis.h"
#include "as_node.h"
#include <stack>

class Component
{
public:
	enum componentType
	{
		EMPTY = 0, MODEL, AI, AFFORDANCE,ASTAR
	};

	Component();

	// virtual ~Component() {};

	componentType getComponentType();

	/*virtual bool getEnabled(){return false;};
	// Change if the AI is enabled or not.
	virtual void setEnabled(bool enabled){};
	// Get the Personality by index's name.
	virtual std::string getPersonalityName(int index){return "";};
	// Set the Personality by index's name.
	virtual void setPersonalityName(int index, std::string name){};
	// Get the Perosnality by index's case's name by case index.
	virtual std::string getPersonalityName(int index, Personality::caseType casetype, int caseIndex){return "";};
	// Set the Perosnality by index's case's name by case index.
	virtual void setPersonalityName(int index, Personality::caseType casetype, int caseIndex, std::string name){};
	// Get the Perosnality by index's case's amount by case index.
	virtual float getPersonalityAmount(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's amount by case index.
	virtual void setPersonalityAmount(int index, Personality::caseType casetype, int caseIndex, float amount){};
	// Get the Perosnality by index's case's positive modifier by case index.
	virtual float getPersonalityPositiveModifier(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's positive modifier by case index.
	virtual void setPersonalityPositiveModifier(int index, Personality::caseType casetype, int caseIndex, float positiveModifier){};
	// Get the Perosnality by index's case's negative modifier by case index.
	virtual float getPersonalityNegativeModifier(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's negative modifier by case index.
	virtual void setPersonalityNegativeModifier(int index, Personality::caseType casetype, int caseIndex, float negativeModifier){};
	// Get the Perosnality by index's case's interval by case index.
	virtual float getPersonalityInterval(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's interval by case index.
	virtual void setPersonalityInterval(int index, Personality::caseType casetype, int caseIndex, float interval){};
	// Get the Perosnality by index's case's increment by case index.
	virtual float getPersonalityIncrement(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's increment by case index.
	virtual void setPersonalityIncrement(int index, Personality::caseType casetype, int caseIndex, float increment){};
	// Get the Perosnality by index's case's effect queue by case index.
	virtual float getPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's effect queue by case index.
	virtual void setPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex, float effectQueue){};
	// Get the Perosnality by index's case's acculumated time by case index.
	virtual float getPersonalityAccumulatedTime(int index, Personality::caseType casetype, int caseIndex){return 0;};
	// Set the Perosnality by index's case's acculumated time by case index.
	virtual void setPersonalityAccumulatedTime(int index, Personality::caseType casetype, int caseIndex, float accumulatedTime){};

	virtual void setNavSize(int size){};
	virtual int getNavSize(){return 0;};

	// Other:
	// Add a personality.
	virtual void addPersonality(){};
	// delete a personality by index.
	virtual void deletePersonality(int index){};
	// Add EmotionCase by caseType to Personality by index.
	virtual void addPersonalityEmotionCase(int index, Personality::caseType casetype){};
	// Delete EmotionCase by caseType to Personality by index.
	virtual void deletePersonalityEmotionCase(int index, Personality::caseType casetype, int caseIndex){};
	// Adds effect amount to EmotionCase by caseType to Personality by index.
	virtual void addToPersonalityEffectQueue(int index, Personality::caseType casetype, int caseIndex, float effect){};
	// Updates AI.
	virtual void update(float deltaTime){};

	virtual bool initMesh(){return false;};
	virtual void blockNode(int x, int y){};
	virtual void unblockNode(int x, int y){};
	virtual as_node* getNode(int x,int y){return NULL;};
	virtual std::stack<Vector2Int> getPath(as_node *start, as_node *goal){std::stack<Vector2Int> a; return a;};



	virtual float getPositionX(){return 0;};
	virtual void setPositionX(float x){};
	virtual float getPositionY(){return 0;};
	virtual void setPositionY(float y){};
	virtual float getPositionZ(){return 0;};
	virtual void setPositionZ(float z){};
	virtual float getRotationX(){return 0;};
	virtual float getRotationY(){return 0;};
	virtual float getRotationZ(){return 0;};
	virtual void setRotation(Axis axis, float angle){};
	virtual std::string getTexture(){return "";};
	virtual void setTexture(std::string t){};
	virtual std::string getModel(){return "";};
	virtual void setModel(std::string m){};
	virtual bool getStatus(){return false;};
	virtual void setStatus(bool s){};*/

protected:
	componentType m_ComponentType;
};