#include "ISE.h"



// ------------------------------ Inflatable Strawberries Engine						#-----
ISE::ISE()
{
	m_RenderEngine.create(1600, 900, "Inflatable Strawberries Engine");
	m_RenderEngine.setPerspective(75.0, 1600.0/900.0, 0.1, 7500.0);
	m_RenderEngine.setWinPos(0.0, 0.0);
	m_RenderEngine.setCameraPosition(0.0, 35.0, 0.0);
	m_RenderEngine.setCameraFocus(0.0, 35.0, -50.0);
	m_RenderEngine.setCameraUp(0.0, 1.0, 0.0);
	m_RenderEngine.setCameraMode(Camera::FREECAM);
	m_RenderEngine.setWireFrame(false);
	m_2DLeft = 0.0;
	m_2DRight = 1.0;
	m_2DDown = 0.0;;
	m_2DUp = 1.0;
	m_FOV = 75.0;
	m_Ratio = 1.0;
	m_Near = 0.1;
	m_Far = 5000.0;
	m_Width = 1600.0;
	m_Far = 900.0;
	m_SkyboxSize = 5000.0;
	m_Skybox[0] = "";
	m_Skybox[1] = "";
	m_Skybox[2] = "";
	m_Skybox[3] = "";
	m_Skybox[4] = "";
	m_Skybox[5] = "";
	m_AssetManager.Load(AssetMng::AS_OBJ, "Data\\Roof.obj");
	m_AssetManager.Load(AssetMng::AS_OBJ, "Data\\Wall1.obj");
	m_AssetManager.Load(AssetMng::AS_OBJ, "Data\\wall2.obj");
}

ISE::~ISE()
{
}

void ISE::ISEupdate(float deltaTime)
{
	m_Ratio = m_Width/m_Height;
	m_2DRight = m_Width;
	m_2DUp = m_Height;
	std::vector<Component*> tempComponents2;
	AI* tempAI;

	for (int i = 0; i < m_GameObject.size(); i++)
	{
		tempComponents2 = m_GameObject[i]->getComponents();
		for (int i2 = 0; i2 < tempComponents2.size(); i2++)
		{
			if (tempComponents2[i2]->getComponentType() == Component::AI)
			{
				tempAI = (AI*) tempComponents2[i2];
				if(tempAI->getEnabled())
				{
					tempAI->update(deltaTime);
					m_GameObject[i]->setComponent(i2, tempAI);
				}
				i2 = tempComponents2.size();
			}
		}
	}

	m_RenderEngine.update();
	//m_RenderEngine.setPerspective(m_FOV, m_Ratio, m_Near, m_Far);
	m_Input.mouseUpdate();
}



// ------------------------------ Misc													#`
float ISE::MIgetDeltaTime()
{
	return m_DeltaTime.getElapsed()/1000.0f;
}



// ------------------------------ Asset Manager											#I
void ISE::AMloadModel(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_OBJ, l);
}

void ISE::AMloadTexture(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, l);
}

void ISE::AMloadSound(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_SOUND, l);
}



// ------------------------------ Game Object											#II
void ISE::GOcreateGameModel(std::string name)
{
	m_GameModel.push_back(new Model());
	m_GameModel[m_GameModel.size()-1]->setName(name);
}

std::string ISE::GOgetGameModelName(int index)
{
	return m_GameModel[index]->getName();
}

std::string ISE::GOgetGameModelLocation(int index)
{
	return m_GameModel[index]->getModel();
}

std::string ISE::GOgetGameModelLocation(std::string name)
{
	for (int i = 0; i < m_GameModel.size(); i++)
	{
		if(m_GameModel[i]->getName() == name)
		{
			return m_GameModel[i]->getModel();
		}
	}
}

void ISE::GOsetGameModelLocation(int index, std::string model)
{
	m_GameModel[index]->setModel(model);
}

std::string ISE::GOgetGameModelTexture(int index)
{
	return m_GameModel[index]->getTexture();
}

std::string ISE::GOgetGameModelTexture(std::string name)
{
	for (int i = 0; i < m_GameModel.size(); i++)
	{
		if(m_GameModel[i]->getName() == name)
		{
			return m_GameModel[i]->getTexture();
		}
	}
}

void ISE::GOsetGameModelTexture(int index, std::string model)
{
	m_GameModel[index]->setTexture(model);
}

void ISE::GOenableGameModel(int index)
{
	m_GameModel[index]->setStatus(true);
}

void ISE::GOdisableGameModel(int index)
{
	m_GameModel[index]->setStatus(false);
}

float ISE::GOgetGameModelX(int index)
{
	return m_GameModel[index]->getPositionX();
}

float ISE::GOgetGameModelX(std::string name)
{
	for (int i = 0; i < m_GameModel.size(); i++)
	{
		if(m_GameModel[i]->getName() == name)
		{
			return m_GameModel[i]->getPositionX();
		}
	}
}

float ISE::GOgetGameModelY(int index)
{
	return m_GameModel[index]->getPositionY();
}

float ISE::GOgetGameModelY(std::string name)
{
	for (int i = 0; i < m_GameModel.size(); i++)
	{
		if(m_GameModel[i]->getName() == name)
		{
			return m_GameModel[i]->getPositionY();
		}
	}
}

float ISE::GOgetGameModelZ(int index)
{
	return m_GameModel[index]->getPositionZ();
}

float ISE::GOgetGameModelZ(std::string name)
{
	for (int i = 0; i < m_GameModel.size(); i++)
	{
		if(m_GameModel[i]->getName() == name)
		{
			return m_GameModel[i]->getPositionZ();
		}
	}
}

void ISE::GOsetGameModelX(int index, float x)
{
	m_GameModel[index]->setPositionX(x);
}

void ISE::GOsetGameModelY(int index, float y)
{
	m_GameModel[index]->setPositionY(y);
}

void ISE::GOsetGameModelZ(int index, float z)
{
	m_GameModel[index]->setPositionZ(z);
}

void ISE::GOsetGameModelRotation(int index, float x, float y, float z)
{
	m_GameModel[index]->setRotation(Axis::xAxis, x);
	m_GameModel[index]->setRotation(Axis::yAxis, y);
	m_GameModel[index]->setRotation(Axis::zAxis, z);
}

// -------------------------------------------------- NEW BEGIN -------------------------------------------------- //
	// Adds a GameObject.
	void ISE::GOaddGameObject()
	{
		m_GameObject.push_back(new TrueGameObject);
	}

	// Delets a GameObject by index.
	void ISE::GOdeleteGameObject(int index)
	{
		m_GameObject.erase(m_GameObject.begin() + index);
	}

	// Add a Component to a GameObject by index.
	void ISE::GOaddComponentToGameObject(int index, Component::componentType componenttype)
	{
		m_GameObject[index]->addComponent(componenttype);
	}

	std::string ISE::GOgetGameObjectModelName(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				tempComponent = (TrueModel*) tempComponents[i];
				if (m == modelIndex)
				{
					return tempComponent->getModel();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelName(int index, int modelIndex, std::string name)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setModel(name);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}

	std::string ISE::GOgetGameObjectModelTextureName(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getTexture();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelTextureName(int index, int modelIndex, std::string name)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setTexture(name);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}

	// Gets the X position of the Model by the model's index of a GameObject by index.
	float ISE::GOgetGameObjectModelXPos(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getPositionX();
				}
				m++;
			}
		}
		return 0;
	}

	// Sets the X position of the Model by the model's index of a GameObject by index.
	void ISE::GOsetGameObjectModelXPos(int index, int modelIndex, float x)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setPositionX(x);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}

	// Gets the Y position of the Model by the model's index of a GameObject by index.
	float ISE::GOgetGameObjectModelYPos(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getPositionY();
				}
				m++;
			}
		}
		return 0;
	}

	// Sets the Y position of the Model by the model's index of a GameObject by index.
	void ISE::GOsetGameObjectModelYPos(int index, int modelIndex, float y)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setPositionY(y);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}

	// Gets the Z position of the Model by the model's index of a GameObject by index.
	float ISE::GOgetGameObjectModelZPos(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getPositionZ();
				}
				m++;
			}
		}
		return 0;
	}

	// Sets the Z position of the Model by the model's index of a GameObject by index.
	void ISE::GOsetGameObjectModelZPos(int index, int modelIndex, float z)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setPositionZ(z);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}
	
	float ISE::GOgetGameObjectModelRotationX(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getRotationX();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelRotationX(int index, int modelIndex, float x)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setRotation(Axis::xAxis, x);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}
	
	float ISE::GOgetGameObjectModelRotationY(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getRotationY();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelRotationY(int index, int modelIndex, float y)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setRotation(Axis::yAxis, y);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}
	
	float ISE::GOgetGameObjectModelRotationZ(int index, int modelIndex)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					return tempComponent->getRotationZ();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelRotationZ(int index, int modelIndex, float z)
	{
		TrueModel* tempComponent;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (tempComponents[i]->getComponentType() == Component::MODEL)
			{
				if (m == modelIndex)
				{
					tempComponent = (TrueModel*) tempComponents[i];
					tempComponent->setRotation(Axis::zAxis, z);
					m_GameObject[index]->setComponent(i, tempComponent);
					i = tempComponents.size();
				}
				m++;
			}
		}
	}

	// Gets the X position of a GameObject by index.
	float ISE::GOgetGameObjectXPos(int index)
	{
		return m_GameObject[index]->getPositionX();
	}

	// Sets the X position of a GameObject by index.
	void ISE::GOsetGameObjectXPos(int index, float x)
	{
		m_GameObject[index]->setPositionX(x);
	}

	// Gets the Y position of a GameObject by index.
	float ISE::GOgetGameObjectYPos(int index)
	{
		return m_GameObject[index]->getPositionY();
	}

	// Sets the Y position of a GameObject by index.
	void ISE::GOsetGameObjectYPos(int index, float y)
	{
		m_GameObject[index]->setPositionY(y);
	}

	// Gets the Z position of a GameObject by index.
	float ISE::GOgetGameObjectZPos(int index)
	{
		return m_GameObject[index]->getPositionZ();
	}

	// Sets the Z position of a GameObject by index.
	void ISE::GOsetGameObjectZPos(int index, float z)
	{
		m_GameObject[index]->setPositionZ(z);
	}

	// Gets the X rotation of a GameObject by index.
	float ISE::GOgetGameObjectRotationX(int index)
	{
		return m_GameObject[index]->getRotationX();
	}

	// Sets the X rotation of a GameObject by index.
	void ISE::GOsetGameObjectRotationX(int index, float x)
	{
		m_GameObject[index]->setRotation(Axis::xAxis, x);
	}

	// Gets the Y rotation of a GameObject by index.
	float ISE::GOgetGameObjectRotationY(int index)
	{
		return m_GameObject[index]->getRotationY();
	}

	// Sets the Y rotation of a GameObject by index.
	void ISE::GOsetGameObjectRotationY(int index, float y)
	{
		m_GameObject[index]->setRotation(Axis::yAxis, y);
	}

	// Gets the Z rotation of a GameObject by index.
	float ISE::GOgetGameObjectRotationZ(int index)
	{
		return m_GameObject[index]->getRotationZ();
	}

	// Sets the Z rotation of a GameObject by index.
	void ISE::GOsetGameObjectRotationZ(int index, float z)
	{
		m_GameObject[index]->setRotation(Axis::zAxis, z);
	}

	// Gets the name of a GameObject by index.
	std::string ISE::GOgetGameObjectName(int index)
	{
		return m_GameObject[index]->getName();
	}

	// Sets the name of a GameObject by index.
	void ISE::GOSetGameObjectName(int index, std::string name)
	{
		m_GameObject[index]->setName(name);
	}
	// -------------------------------------------------- NEW END -------------------------------------------------- //



// ------------------------------ Input													#III
bool ISE::IOisKeyPressed(Keyboard::Key k)
{
	return m_Input.isPress(k);
}

bool ISE::IOisKeyReleased(Keyboard::Key k)
{
	return m_Input.isReleased(k);
}

bool ISE::IOisMousePressed(Mouse::Button m)
{
	return m_Input.isMousePress(m);
}

bool ISE::IOisMouseReleased(Mouse::Button m)
{
	return m_Input.isMouseReleased(m);
}

void ISE::IOlockMouse()
{
	m_Input.lockMouse();
}

void ISE::IOunlockMouse()
{
	m_Input.releaseMouse();
}

void ISE::IOsetLockMousePosition(int x, int y)
{
	m_Input.setMouseLockPosition(x, y);
}

int ISE::IOgetMouseXPosition()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseLocation(x, y);

	return x;
}

int ISE::IOgetMouseYPosition()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseLocation(x, y);

	return y;
}

int ISE::IOgetMouseXVector()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseVec(x, y);

	return x;
}

int ISE::IOgetMouseYVector()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseVec(x, y);

	return y;
}



// ------------------------------ Render Engine											#IV
void ISE::REwindowSetSize(int w, int h)
{
	m_Width = w;
	m_Height = h;
	m_RenderEngine.setWidth(m_Width);
	m_RenderEngine.setHeight(m_Height);
}

int ISE::REwindowGetWidth()
{
	return m_RenderEngine.getWidth();
}

int ISE::REwindowGetHeight()
{
	return m_RenderEngine.getHeight();
}

void ISE::REwindowSetTitle(std::string t)
{
	m_RenderEngine.setTitle(t);
}

void ISE::RErenderGameModels()
{
	VAO tempVAO;
	//Texture tempTex;
	/*for(int i = 0; i < m_GameModel.size(); i++)
	{
		if(m_GameModel[i]->getStatus())
		{
			m_AssetManager.getData(m_GameModel[i]->getModel(), tempVAO);
			//m_AssetManager.getData(m_GameObject[i]->getTexture(), tempTex);
			m_AssetManager.getData(m_GameModel[i]->getTexture());
			m_RenderEngine.translate(m_GameModel[i]->getPositionX(), m_GameModel[i]->getPositionY(), m_GameModel[i]->getPositionZ());
			m_RenderEngine.rotate(Axis::xAxis, m_GameModel[i]->getRotationX());
			m_RenderEngine.rotate(Axis::yAxis, m_GameModel[i]->getRotationY());
			m_RenderEngine.rotate(Axis::zAxis, m_GameModel[i]->getRotationZ());
			//m_RenderEngine.bindTex(tempTex);
			m_RenderEngine.renderV(tempVAO);
		}
	}*/
	/*
	m_RenderEngine.setOrtho2D(m_2DLeft, m_2DRight, m_2DDown, m_2DUp);
	m_RenderEngine.Ortho2DBegin();
	if(m_GameModel[i]->getType() == GameObject2::HUD)
	{
		//m_RenderEngine.renderV(tempVAO);
	}
	m_RenderEngine.Ortho2DEnd();
	*/

	// -------------------------------------------------- NEW BEGIN -------------------------------------------------- //
	std::vector<Component*> tempComponents2;
	TrueModel* tempComponent;
	for (int i = 0; i < m_GameObject.size(); i++)
	{
		tempComponents2 = m_GameObject[i]->getComponents();
		for (int i2 = 0; i2 < tempComponents2.size(); i2++)
		{
			if (tempComponents2[i2]->getComponentType() == Component::MODEL)
			{
				tempComponent = (TrueModel*) tempComponents2[i2];
				if(tempComponent->getStatus())
				{
					m_AssetManager.getData(tempComponent->getModel(), tempVAO);
					m_AssetManager.getData(tempComponent->getTexture());
					m_RenderEngine.translate(m_GameObject[i]->getPositionX() + tempComponent->getPositionX(), m_GameObject[i]->getPositionY() + tempComponent->getPositionY(), m_GameObject[i]->getPositionZ() + tempComponent->getPositionZ());
					m_RenderEngine.rotate(Axis::xAxis, tempComponent->getRotationX());
					m_RenderEngine.rotate(Axis::yAxis, tempComponent->getRotationY());
					m_RenderEngine.rotate(Axis::zAxis, tempComponent->getRotationZ());
					m_RenderEngine.renderV(tempVAO);
				}
			}
		}
	}
	// -------------------------------------------------- NEW END -------------------------------------------------- //
}

void ISE::REsystemCycle()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	m_RenderEngine.display();
}

void ISE::REdisplaySkyboxTop()
{
	VAO tempVAO;
	
	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[0].data());
	m_RenderEngine.translate(REcameraX(), REcameraY() + m_SkyboxSize/2, REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, 0.0);
	m_RenderEngine.rotate(Axis::yAxis, 0.0);
	m_RenderEngine.rotate(Axis::zAxis, -90.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxFront()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[1].data());
	//m_AssetManager.getData("Data\\Sunny1_front.jpg");
	m_RenderEngine.translate(REcameraX(), REcameraY(), REcameraZ() - m_SkyboxSize/2);
	m_RenderEngine.rotate(Axis::xAxis, -90.0);
	m_RenderEngine.rotate(Axis::yAxis, 0.0);
	m_RenderEngine.rotate(Axis::zAxis, -90.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxBack()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[2].data());
	m_RenderEngine.translate(REcameraX(), REcameraY(), REcameraZ() + m_SkyboxSize/2);
	m_RenderEngine.rotate(Axis::xAxis, -90.f);
	m_RenderEngine.rotate(Axis::yAxis, 0.f);
	m_RenderEngine.rotate(Axis::zAxis, 90.f);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxLeft()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[3].data());
	m_RenderEngine.translate(REcameraX() - m_SkyboxSize/2, REcameraY(), REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, -90.0);
	m_RenderEngine.rotate(Axis::yAxis, 0.0);
	m_RenderEngine.rotate(Axis::zAxis, 0.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxRight()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[4].data());
	m_RenderEngine.translate(REcameraX() + m_SkyboxSize/2, REcameraY(), REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, 90.0);
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
	m_RenderEngine.rotate(Axis::zAxis, 0.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxBottom()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[5].data());
	m_RenderEngine.translate(REcameraX(), REcameraY() - m_SkyboxSize/2, REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, 0.0);
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
	m_RenderEngine.rotate(Axis::zAxis, 90.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REcameraSetPerspective(float fov, float cnear, float cfar)
{
	m_FOV = fov;
	m_Near = cnear;
	m_Far = cfar;
}

void ISE::REcameraMoveForward(float x)
{
	m_RenderEngine.moveCameraForward(x);
}

void ISE::REcameraMoveBackward(float x)
{
	m_RenderEngine.moveCameraForward(-x);
}

void ISE::REcameraMoveLeft(float x)
{
	m_RenderEngine.moveCameraLeft(-x);
}

void ISE::REcameraMoveRight(float x)
{
	m_RenderEngine.moveCameraLeft(x);
}

void ISE::REcameraMoveUp(float x)
{
	m_RenderEngine.moveCameraUp(x);
}

void ISE::REcameraMoveDown(float x)
{
	m_RenderEngine.moveCameraUp(-x);
}

void ISE::REcameraChangeMode(Camera::cameraMode m)
{
	m_RenderEngine.setCameraMode(m);
}

void ISE::REcameraLookUp(float x)
{
	m_RenderEngine.rotateCameraUp(x);
}

void ISE::REcameraLookDown(float x)
{
	m_RenderEngine.rotateCameraUp(-x);
}

void ISE::REcameraLookLeft(float x)
{
	m_RenderEngine.rotateCameraLeft(x);
}

void ISE::REcameraLookRight(float x)
{
	m_RenderEngine.rotateCameraLeft(-x);
}

float ISE::REcameraX()
{
	return m_RenderEngine.getCameraPositionX();
}

float ISE::REcameraY()
{
	return m_RenderEngine.getCameraPositionY();
}

float ISE::REcameraZ()
{
	return m_RenderEngine.getCameraPositionZ();
}

void ISE::REenableWireframe(bool e)
{
	m_RenderEngine.setWireFrame(e);
}

bool ISE::REwireframeState()
{
	return m_RenderEngine.getWireFrame();
}

void ISE::REloadTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
}

void ISE::REsetSkyboxTopTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[0].assign(t);
}

void ISE::REsetSkyboxFrontTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[1].assign(t);
}

void ISE::REsetSkyboxBackTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[2].assign(t);
}

void ISE::REsetSkyboxLeftTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[3].assign(t);
}

void ISE::REsetSkyboxRightTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[4].assign(t);
}

void ISE::REsetSkyboxBottomTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[5].assign(t);
}



// ------------------------------ Sound													#V
void ISE::SEplaySoundOnce(std::string s)
{
	m_SoundEngine.playOnce(*m_AssetManager.getData(s, AssetMng::AS_SOUND));
}

void ISE::SEplaySoundLoop(std::string s)
{
	m_SoundEngine.playWithLoop(*m_AssetManager.getData(s, AssetMng::AS_SOUND));
}

void ISE::SEsetSoundVolume(std::string s, float v)
{
	m_SoundEngine.setVolume(*m_AssetManager.getData(s, AssetMng::AS_SOUND), v);
}



// ------------------------------ AI													#VI
// Add an AI component to a GameObject by index.
void ISE::AIaddAI(int index)
{
	m_GameObject[index]->addComponent(Component::AI);
}

// Delete an AI component to a GameObject by index.
void ISE::AIdeleteAI(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			m_GameObject[index]->deleteComponent(i);
			i = tempComponents.size();
		}
	}
}

// Enable/Disable a GameObject by index's AI.
void ISE::AIenableGameObjectAI(int index, bool enable)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setEnabled(enable);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

// Add a Personality component to a GameObject by index
void ISE::AIaddPersonality(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->addPersonality();
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

// Delete a Personality component by index to a GameObject by index
void ISE::AIdeletePersonality(int index, int personalityIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->deletePersonality(personalityIndex);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

void ISE::AIaddPersonalityEmotionCase(int index, int personalityIndex, Personality::caseType casetype)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->addPersonalityEmotionCase(personalityIndex, casetype);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

void ISE::AIdeletePersonalityEmotionCase(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->deletePersonalityEmotionCase(personalityIndex, casetype, caseIndex);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

std::string ISE::AIgetPersonalityName(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityName(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityName(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, std::string name)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityName(personalityIndex, casetype, caseIndex, name);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityAmount(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityAmount(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityAmount(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float amount)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityAmount(personalityIndex, casetype, caseIndex, amount);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityPositiveModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityPositiveModifier(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityPositiveModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float positiveModifier)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityPositiveModifier(personalityIndex, casetype, caseIndex, positiveModifier);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityNegativeModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityNegativeModifier(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityNegativeModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float negativeModifier)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityNegativeModifier(personalityIndex, casetype, caseIndex, negativeModifier);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityInterval(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityInterval(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityInterval(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float interval)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityInterval(personalityIndex, casetype, caseIndex, interval);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityIncrement(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityIncrement(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityIncrement(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float increment)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityIncrement(personalityIndex, casetype, caseIndex, increment);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityEffectQueue(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float effectQueue)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityEffectQueue(personalityIndex, casetype, caseIndex, effectQueue);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityAccumulatedTime(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPersonalityAccumulatedTime(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityAccumulatedTime(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float accumulatedTime)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setPersonalityAccumulatedTime(personalityIndex, casetype, caseIndex, accumulatedTime);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

void ISE::AIaddToPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float effect)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->addToPersonalityEffectQueue(personalityIndex, casetype, caseIndex, effect);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}
/*
void ISE::AIsetNavSize(int index, int size)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->setNavSize(size);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

int ISE::AIgetNavSize(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getNavSize();
		}
	}
}

bool ISE::AIinitMesh(int index)
{
	bool tempBool = false;
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempBool = tempComponent->initMesh();
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
	return tempBool;
}

void ISE::AIblockNode(int index, int x, int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->blockNode(x, y);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

void ISE::AIunblockNode(int index, int x, int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			tempComponent->unblockNode(x, y);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

as_node* ISE::AIgetNode(int index, int x,int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getNode(x, y);
		}
	}
}

std::stack<Vector2Int> ISE::AIgetPath(int index, as_node *start, as_node *goal)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	AI* tempComponent;
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (tempComponents[i]->getComponentType() == Component::AI)
		{
			tempComponent = (AI*) tempComponents[i];
			return tempComponent->getPath(start, goal);
		}
	}
}*/




// ------------------------------ Affordance											#VII
void ISE::AFaddAffordance(int index)
{
	m_GameObject[index]->addComponent(Component::AFFORDANCE);
}

void ISE::AFdeleteAffordance(int index, int afIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				m_GameObject[index]->deleteComponent(i);
				i = tempComponents.size();
			}
			tempIndex++;
		}
	}
}

void ISE::AFdeleteAffordance(int index, std::string name)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			tempComponent = (TrueAffordance*) tempComponents[i];
			if(tempComponent->getName() == name)
			{
				m_GameObject[index]->deleteComponent(i);
				i = tempComponents.size();
			}
		}
	}
}

std::string ISE::AFgetAffordanceName(int index, int afIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				return tempComponent->getName();
			}
			tempIndex++;
		}
	}
}

void ISE::AFsetAffordanceName(int index, int afIndex, std::string name)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				tempComponent->setName(name);
				m_GameObject[index]->setComponent(i, tempComponent);
			}
			tempIndex++;
		}
	}
}

int ISE::AFgetAffordanceIndex(int index, std::string name)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			tempComponent = (TrueAffordance*) tempComponents[i];
			if(tempComponent->getName() == name)
			{
				return i;
			}
		}
	}
}

float ISE::AFgetAffordanceMinValue(int index, int afIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				return tempComponent->getMinValue();
			}
			tempIndex++;
		}
	}
}

void ISE::AFsetAffordanceMinValue(int index, int afIndex, float minValue)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				tempComponent->setMinValue(minValue);
				m_GameObject[index]->setComponent(i, tempComponent);
			}
			tempIndex++;
		}
	}
}

float ISE::AFgetAffordanceMaxValue(int index, int afIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				return tempComponent->getMaxValue();
			}
			tempIndex++;
		}
	}
}

void ISE::AFsetAffordanceMaxValue(int index, int afIndex, float maxValue)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				tempComponent->setMaxValue(maxValue);
				m_GameObject[index]->setComponent(i, tempComponent);
			}
			tempIndex++;
		}
	}
}

float ISE::AFgetAffordanceValue(int index, int afIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				return tempComponent->getValue();
			}
			tempIndex++;
		}
	}
}

void ISE::AFsetAffordanceValue(int index, int afIndex, float value)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				tempComponent->setValue(value);
				m_GameObject[index]->setComponent(i, tempComponent);
			}
			tempIndex++;
		}
	}
}

// The afIndex is the index of the affordance you want to test the value against.
bool ISE::AFhasWithinInclusive(int index, int afIndex, float value)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				return tempComponent->hasWithinInclusive(value);
			}
			tempIndex++;
		}
	}
}

// The afIndex is the index of the affordance you want to test the value against.
bool ISE::AFhasWithinExclusive(int index, int afIndex, float value)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	int tempIndex = 0;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			if(tempIndex == afIndex)
			{
				tempComponent = (TrueAffordance*) tempComponents[i];
				return tempComponent->hasWithinExclusive(value);
			}
			tempIndex++;
		}
	}
}

bool ISE::AFhasAffordance(int index, std::string name)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	TrueAffordance* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::AFFORDANCE)
		{
			tempComponent = (TrueAffordance*) tempComponents[i];
			if (tempComponent->getName() == name)
			{
				return true;
			}
		}
	}
	return false;
}



// ------------------------------ A Star											#VIII
void ISE::ASaddAStar(int index)
{
	m_GameObject[index]->addComponent(Component::ASTAR);
}

void ISE::ASdeleteAStar(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			m_GameObject[index]->deleteComponent(i);
			i = tempComponents.size();
		}
	}
}

void ISE::ASsetSize(int index, int size)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->setSize(size);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}
int ISE::ASgetSize(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->getSize();
		}
	}
}

void ISE::ASaddBlockedNode(int index, int x, int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->addBlocked(x, y);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}
void ISE::ASremBlockedNode(int index, int x, int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->remBlocked(x, y);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}

void ISE::ASsetGap(int index, float gap)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->setGap(gap);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}
float ISE::ASgetGap(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->getGap();
		}
	}
}

//functions that matter
void ISE::ASgenPath(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->genPath();
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}
int ISE::ASgetNodeNum(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->getNodeNum();
		}
	}
}

void ISE::ASgetNextNode(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->getNextNode();
		}
	}
}

float ISE::ASgetDesX(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->getDesX();
		}
	}
}
float ISE::ASgetDesY(int index)	
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->getDesY();
		}
	}
}

bool ISE::ASnextNodeHit(int index, float x, float y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->nextNodeHit(x, y);
		}
	}
}
bool ISE::ASgoalNodeHit(int index, float x, float y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			return tempComponent->goalNodeHit(x, y);
		}
	}
}

void ISE::ASsetStart(int index, float x, float y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->setStart(x, y);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}
void ISE::ASsetGoal(int index, float x, float y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	aStar* tempComponent;
	for(int i = 0; i < tempComponents.size(); i++)
	{
		if(tempComponents[i]->getComponentType() == Component::ASTAR)
		{
			tempComponent = (aStar*) tempComponents[i];
			tempComponent->setGoal(x, y);
			m_GameObject[index]->setComponent(i, tempComponent);
			i = tempComponents.size();
		}
	}
}