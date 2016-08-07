#pragma once



// ------------------------------ Major systems											#~
#include "AssetMng.h"
#include "OPENGL_Facade.h"
#include "SFML_Clock.h"
#include "SFML_Facade.h"
#include "SFML_Input.h"
#include "SFML_Texture.h"
// #include "GameObjectFactory.h"
#include "Model.h"
#include "TrueGameObject.h"
#include "TrueModel.h"
#include "Component.h"
#include "Personality.h"
#include "AI.h"
#include "NavMesh.h"
#include "as_node.h"
#include "TrueAffordance.h"
#include "Input.h"
#include "RenderEngine.h"
#include "gameScript.h"
#include "SoundEngine.h"
#include "AI.h"



// ------------------------------ Misc systems											#`
#include <stdlib.h>
#include <time.h>

#include "Clock.h"



/**
 * @brief The Inflatable Strawberries Engine Class
 * @details This is the Inflatable Strawberries Engine Class
 * @author Welsley Lui
 */
class ISE
{
public:
// ------------------------------ Inflatable Strawberries Engine						#-----
	/**
	 * @brief Constructor of the Inflatable Strawberries Engine.
	 * @details This is the constructor of the Inflatable Strawberries Engine.
	 */
	ISE();

	/**
	 * @brief Destructor of the Inflatable Strawberries Engine.
	 * @details This is the destructor of the Inflatable Strawberries Engine.
	 */
	~ISE();

	/**
	 * @brief Updates all essential functions and variables in the ISE.
	 * @details Called in the beginning of the program loop to update all the essential functions and variables within the Inflatable Strawberries Engine.
	 */
	void ISEupdate(float deltaTime);


	
// ------------------------------ Misc													#`
	/**
	 * @brief Gets the delta time.
	 * @details Returns the delta time.
	 * @return Float of the delta time.
	 */
	float MIgetDeltaTime();



// ------------------------------ Asset Manager											#I
	/**
	 * @brief Loads in a model.
	 * @details Loads in a model from a given location into the Inflatable Strawberries Engine.
	 * 
	 * @param l String of the location of the model.
	 */
	void AMloadModel(std::string l);

	/**
	 * @brief Loads in a texture.
	 * @details Loads in a texture from a given location into the Inflatable Strawberries Engine.
	 * 
	 * @param l String of the location of the model.
	 */
	void AMloadTexture(std::string l);

	/**
	 * @brief Loads in a sound.
	 * @details Loads in a sound from a given location into the Inflatable Strawberries Engine.
	 * 
	 * @param l String of the location of the model.
	 */
	void AMloadSound(std::string l);



// ------------------------------ Game Object											#II
	/**
	 * @brief Creates a game object.
	 * @details Creates a game object into the Inflatable Strawberries Engine
	 * 
	 * @param name String. The name of the game object.
	 */
	void GOcreateGameModel(std::string name);

	std::string GOgetGameModelName(int index);
	
	std::string GOgetGameModelLocation(int index);

	std::string GOgetGameModelLocation(std::string name);

	/**
	 * @brief Sets the game object's model.
	 * @details Sets the game object's model by location. The game object is denoted by the index.
	 * 
	 * @param index Integer index of the game object.
	 * @param model String of the location of the model.
	 */
	void GOsetGameModelLocation(int index, std::string model);

	std::string GOgetGameModelTexture(int index);

	std::string GOgetGameModelTexture(std::string name);

	/**
	 * @brief Sets the game object's texture.
	 * @details Sets the game object's texture by location. The game object is denoted by the index.
	 * 
	 * @param index Integer index of the game object.
	 * @param texture String of the location of the texture.
	 */
	void GOsetGameModelTexture(int index, std::string texture);

	/**
	 * @brief Enables the game object's visibility.
	 * @details Turns the visibility of the game object on. The game object is denoted by the index.
	 * 
	 * @param index Integer index of the game object.
	 */
	void GOenableGameModel(int index);

	/**
	 * @brief Disables the game object's visibility.
	 * @details Turns the visibility of the game object off. The game object is denoted by the index.
	 * 
	 * @param index Integer index of the game object.
	 */
	void GOdisableGameModel(int index);
	
	/*
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param index [description]
	 */
	float GOgetGameModelX(int index);

	float GOgetGameModelX(std::string name);
	
	/*
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param index [description]
	 */
	float GOgetGameModelY(int index);

	float GOgetGameModelY(std::string name);
	
	/*
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param index [description]
	 */
	float GOgetGameModelZ(int index);

	float GOgetGameModelZ(std::string name);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param index [description]
	 * @param x [description]
	 */
	void GOsetGameModelX(int index, float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param index [description]
	 * @param y [description]
	 */
	void GOsetGameModelY(int index, float y);
	
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param index [description]
	 * @param z [description]
	 */
	void GOsetGameModelZ(int index, float z);

	/**
	 * @brief 
	 * @details [long description]
	 * 
	 * @param index [description]
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void GOsetGameModelRotation(int index, float x, float y, float z);

	// -------------------------------------------------- NEW BEGIN -------------------------------------------------- //
	// Adds a GameObject.
	void GOaddGameObject();

	// Delets a GameObject by index.
	void GOdeleteGameObject(int index);

	// Add a Component to a GameObject by index.
	void GOaddComponentToGameObject(int index, Component::componentType componenttype);

	std::string GOgetGameObjectModelName(int index, int modelIndex);

	void GOsetGameObjectModelName(int index, int modelIndex, std::string name);

	std::string GOgetGameObjectModelTextureName(int index, int modelIndex);

	void GOsetGameObjectModelTextureName(int index, int modelIndex, std::string name);

	// Gets the X position of the Model by the model's index of a GameObject by index.
	float GOgetGameObjectModelXPos(int index, int modelIndex);

	// Sets the X position of the Model by the model's index of a GameObject by index.
	void GOsetGameObjectModelXPos(int index, int modelIndex, float x);

	// Gets the Y position of the Model by the model's index of a GameObject by index.
	float GOgetGameObjectModelYPos(int index, int modelIndex);

	// Sets the Y position of the Model by the model's index of a GameObject by index.
	void GOsetGameObjectModelYPos(int index, int modelIndex, float y);

	// Gets the Z position of the Model by the model's index of a GameObject by index.
	float GOgetGameObjectModelZPos(int index, int modelIndex);

	// Sets the Z position of the Model by the model's index of a GameObject by index.
	void GOsetGameObjectModelZPos(int index, int modelIndex, float z);

	float GOgetGameObjectModelRotationX(int index, int modelIndex);

	void GOsetGameObjectModelRotationX(int index, int modelIndex, float x);

	float GOgetGameObjectModelRotationY(int index, int modelIndex);

	void GOsetGameObjectModelRotationY(int index, int modelIndex, float y);

	float GOgetGameObjectModelRotationZ(int index, int modelIndex);

	void GOsetGameObjectModelRotationZ(int index, int modelIndex, float z);

	// Gets the X position of a GameObject by index.
	float GOgetGameObjectXPos(int index);

	// Sets the X position of a GameObject by index.
	void GOsetGameObjectXPos(int index, float x);

	// Gets the Y position of a GameObject by index.
	float GOgetGameObjectYPos(int index);

	// Sets the Y position of a GameObject by index.
	void GOsetGameObjectYPos(int index, float y);

	// Gets the Z position of a GameObject by index.
	float GOgetGameObjectZPos(int index);

	// Sets the Z position of a GameObject by index.
	void GOsetGameObjectZPos(int index, float z);

	// Gets the X rotation of a GameObject by index.
	float GOgetGameObjectRotationX(int index);

	// Sets the X rotation of a GameObject by index.
	void GOsetGameObjectRotationX(int index, float x);

	// Gets the Y rotation of a GameObject by index.
	float GOgetGameObjectRotationY(int index);

	// Sets the Y rotation of a GameObject by index.
	void GOsetGameObjectRotationY(int index, float y);

	// Gets the Z rotation of a GameObject by index.
	float GOgetGameObjectRotationZ(int index);

	// Sets the Z rotation of a GameObject by index.
	void GOsetGameObjectRotationZ(int index, float z);

	// Gets the name of a GameObject by index.
	std::string GOgetGameObjectName(int index);

	// Sets the name of a GameObject by index.
	void GOSetGameObjectName(int index, std::string name);
	// -------------------------------------------------- NEW END -------------------------------------------------- //
	

	
// ------------------------------ Input													#III
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param k [description]
	 * @return [description]
	 */
	bool IOisKeyPressed(Keyboard::Key k);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param k [description]
	 * @return [description]
	 */
	bool IOisKeyReleased(Keyboard::Key k);
	
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @return [description]
	 */
	bool IOisMousePressed(Mouse::Button m);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @return [description]
	 */
	bool IOisMouseReleased(Mouse::Button m);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void IOlockMouse();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void IOunlockMouse();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 */
	void IOsetLockMousePosition(int x, int y);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseXPosition();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseYPosition();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseXVector();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseYVector();



// ------------------------------ Render Engine											#IV
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param w [description]
	 * @param h [description]
	 */
	void REwindowSetSize(int w, int h);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int REwindowGetWidth();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int REwindowGetHeight();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param t [description]
	 */
	void REwindowSetTitle(std::string t);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void RErenderGameModels();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void REsystemCycle();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param fov [description]
	 * @param cnear [description]
	 * @param cfar [description]
	 */
	void REcameraSetPerspective(float fov, float cnear, float cfar);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveForward(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveBackward(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveLeft(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveRight(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveUp(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveDown(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 */
	void REcameraChangeMode(Camera::cameraMode m);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookUp(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookDown(float x);

	/**
	 * @brief 
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookLeft(float x);

	/**
	 * @brief 
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookRight(float x);

	float REcameraX();

	float REcameraY();

	float REcameraZ();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param e [description]
	 */
	void REenableWireframe(bool e);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	bool REwireframeState();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param t [description]
	 */
	void REloadTexture(std::string t);

	void REsetSkyboxTopTexture(std::string t);

	void REsetSkyboxFrontTexture(std::string t);

	void REsetSkyboxBackTexture(std::string t);

	void REsetSkyboxLeftTexture(std::string t);

	void REsetSkyboxRightTexture(std::string t);

	void REsetSkyboxBottomTexture(std::string t);

	void REdisplaySkyboxTop();

	void REdisplaySkyboxFront();

	void REdisplaySkyboxBack();

	void REdisplaySkyboxLeft();

	void REdisplaySkyboxRight();

	void REdisplaySkyboxBottom();



// ------------------------------ Sound													#V
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void SEplaySoundOnce(std::string s);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void SEplaySoundLoop(std::string s);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void SEsetSoundVolume(std::string s, float v);



// ------------------------------ AI													#VI
	// Add an AI component to a GameObject by index.
	void AIaddAI(int index);

	// Delete an AI component to a GameObject by index.
	void AIdeleteAI(int index);

	// Enable/Disable a GameObject by index's AI.
	void AIenableGameObjectAI(int index, bool enable);

	// Add a Personality in a GameObject by index's AI.
	void AIaddPersonality(int index);

	// Delete a Personality by index in a GameObject by index's AI.
	void AIdeletePersonality(int index, int personalityIndex);

	void AIaddPersonalityEmotionCase(int index, int personalityIndex, Personality::caseType casetype);

	void AIdeletePersonalityEmotionCase(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	std::string AIgetPersonalityName(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityName(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, std::string name);

	float AIgetPersonalityAmount(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityAmount(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float amount);

	float AIgetPersonalityPositiveModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityPositiveModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float positiveModifier);

	float AIgetPersonalityNegativeModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityNegativeModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float negativeModifier);

	float AIgetPersonalityInterval(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityInterval(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float interval);

	float AIgetPersonalityIncrement(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityIncrement(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float increment);

	float AIgetPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float effectQueue);

	float AIgetPersonalityAccumulatedTime(int index, int personalityIndex, Personality::caseType casetype, int caseIndex);

	void AIsetPersonalityAccumulatedTime(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float accumulatedTime);

	void AIaddToPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float effect);

	/*void AIsetNavSize(int index, int size);//

	int AIgetNavSize(int index);

	bool AIinitMesh(int index);

	void AIblockNode(int index, int x, int y);

	void AIunblockNode(int index, int x, int y);

	as_node* AIgetNode(int index, int x,int y);

	std::stack<Vector2Int> AIgetPath(int index, as_node *start, as_node *goal);//*/



// ------------------------------ Affordance											#VII
	void AFaddAffordance(int index);

	void AFdeleteAffordance(int index, int afIndex);

	void AFdeleteAffordance(int index, std::string name);

	std::string AFgetAffordanceName(int index, int afIndex);

	void AFsetAffordanceName(int index, int afIndex, std::string name);

	int AFgetAffordanceIndex(int index, std::string name);

	float AFgetAffordanceMinValue(int index, int afIndex);

	void AFsetAffordanceMinValue(int index, int afIndex, float minValue);

	float AFgetAffordanceMaxValue(int index, int afIndex);

	void AFsetAffordanceMaxValue(int index, int afIndex, float maxValue);

	float AFgetAffordanceValue(int index, int afIndex);

	void AFsetAffordanceValue(int index, int afIndex, float value);

	// The afIndex is the index of the affordance you want to test the value against.
	bool AFhasWithinInclusive(int index, int afIndex, float value);

	// The afIndex is the index of the affordance you want to test the value against.
	bool AFhasWithinExclusive(int index, int afIndex, float value);

	bool AFhasAffordance(int index, std::string name);



// ------------------------------ A Star											#VIII
	void ASaddAStar(int index);
	void ASdeleteAStar(int index);

	void ASsetSize(int index, int size);					//set the grid size
	int ASgetSize(int index);							//get the grid size

	void ASaddBlockedNode(int index, int x, int y);		//set a node to blocked
	void ASremBlockedNode(int index, int x, int y);		//unblock a node (not working)

	void ASsetGap(int index, float gap);					//set the gap between each node
	float ASgetGap(int index);							//get the gap between each node

	//functions that matter
	void ASgenPath(int index);							//generate the node list to traverse to get to goal
	int ASgetNodeNum(int index);							//get the number of nodes left to traverse

	void ASgetNextNode(int index);						//get next node and set it as the destination node

	float ASgetDesX(int index);							//get the X position of the destination node in the world
	float ASgetDesY(int index);							//get the Y position of the destination node in the world

	bool ASnextNodeHit(int index, float x, float y);		//check if the destination node has been reached
	bool ASgoalNodeHit(int index, float x, float y);		//check if the goal node has been reached

	void ASsetStart(int index, float x, float y);			//set the start point of the NPC
	void ASsetGoal(int index, float x, float y);			//set the goal point of the  NPC



private:
// ------------------------------ Misc													#`
	Clock								m_DeltaTime;
	SFML_Clock							m_DeltaTime2;



// ------------------------------ Inflatable Strawberries Engine						#-----
	float								m_2DLeft;
	float								m_2DRight;
	float								m_2DDown;
	float								m_2DUp;
	float								m_Width;
	float								m_Height;
	float								m_FOV;
	float								m_Ratio;
	float								m_Near;
	float								m_Far;



// ------------------------------ Asset Manager											#I
	AssetMng							m_AssetManager;



// ------------------------------ Game Object											#II
/*	std::vector<GameObject*>			m_GameObject;
	GameObjectFactory					m_GameObjectFactory;
	std::vector<gameScript*>			m_GameScript;
	std::vector<AI*>					m_AI;*/
	std::vector<Model*>					m_GameModel;
	std::vector<TrueGameObject*>		m_GameObject;



// ------------------------------ Input													#III
	Input								m_Input;
	


// ------------------------------ Render Engine											#IV
	RenderEngine						m_RenderEngine;
	std::string							m_Skybox[6];
	float								m_SkyboxSize;



// ------------------------------ Sound													#V
	SoundEngine							m_SoundEngine;
	



	
};