#include "ISE.h"



// ------------------------------ Inflatable Strawberries Engine						#-----
ISE::ISE()
{
	m_RenderEngine.create(1920, 1080, "Inflatable Strawberries Engine");
	m_RenderEngine.setPerspective(75.0, 1280.0/768.0, 0.1, 7500.0);
	m_RenderEngine.setWinPos(0.0, 0.0);
	m_RenderEngine.setCameraPosition(0.0, 35.0, 0.0);
	m_RenderEngine.setCameraFocus(10.0, -10.0, -100.0);
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
	m_Width = 1280.0;
	m_Far = 768.0;
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
	//boxData[0].setState(Vector3(0,30,0),Quaternion(), Vector3(1,1,1), Vector3(0,1,0));
	//boxData[1].setState(Vector3(0,60,1),Quaternion(1.0,0.1,0.05,0.01),Vector3(1,1,1),Vector3(0,0,0));
	cData.contactArray = contacts;
	cData.contactCount = 0;
	resolver.setEpsilon(0.02,0.02);
}

ISE::~ISE()
{
}

void ISE::ISEupdate()
{
	m_Ratio = m_Width/m_Height;
	m_2DRight = m_Width;
	m_2DUp = m_Height;

	std::vector<Component*> tempComponents;
	AI* tempAI;
	for (int i = 0; i < m_GameObject.size(); i++)
	{
		tempComponents = m_GameObject[i]->getComponents();
		for (int i2 = 0; i2 < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i2]).name() == "AI")
			{
				tempAI = dynamic_cast<AI*>(tempComponents[i2]);
				if(tempAI->getEnabled())
				{
					tempAI->update(MIgetDeltaTime());
					m_GameObject[i]->setComponent(i2, tempAI);
					i = tempComponents.size();
				}
				else
				{
					i2 = tempComponents.size();
				}
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

void ISE::GOsetGameModelPos(int index, Vector3 pos)
{
	m_GameModel[index]->setPosition(pos);
}

Vector3 ISE::GOgetGameModelPos(int index)
{
	return m_GameModel[index]->getPosition();
}

void ISE::GOsetGameModelRotation(int index, Vector3 rot)
{
	m_GameModel[index]->setRotation(rot);
}

void ISE::GOaddGameModelRotation(int index, Vector3 rot)
{
	m_GameModel[index]->addRotation(rot);
}

void ISE::GOaddGameModelPosition(int index, float x, float y, float z)
{
	m_GameModel[index]->addPosition(x,y,z);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
					return tempComponent->getModel();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelName(int index, int modelIndex, std::string name)
	{
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
					return tempComponent->getTexture();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelTextureName(int index, int modelIndex, std::string name)
	{
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
					return tempComponent->getRotationX();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelRotationX(int index, int modelIndex, float x)
	{
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
					return tempComponent->getRotationY();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelRotationY(int index, int modelIndex, float y)
	{
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
					return tempComponent->getRotationZ();
				}
				m++;
			}
		}
		return 0;
	}

	void ISE::GOsetGameObjectModelRotationZ(int index, int modelIndex, float z)
	{
		TrueModel* tempComponent = new TrueModel;
		std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
		int m = 0;
		for (int i = 0; i < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i]).name() == "TrueModel")
			{
				if (m == modelIndex)
				{
					tempComponent = dynamic_cast<TrueModel*>(tempComponents[i]);
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
	void ISE::GOsetGameObjectXPos(int index, int x)
	{
		m_GameObject[index]->setPositionX(x);
	}

	// Gets the Y position of a GameObject by index.
	float ISE::GOgetGameObjectYPos(int index)
	{
		return m_GameObject[index]->getPositionY();
	}

	// Sets the Y position of a GameObject by index.
	void ISE::GOsetGameObjectYPos(int index, int y)
	{
		m_GameObject[index]->setPositionY(y);
	}

	// Gets the Z position of a GameObject by index.
	float ISE::GOgetGameObjectZPos(int index)
	{
		return m_GameObject[index]->getPositionZ();
	}

	// Sets the Z position of a GameObject by index.
	void ISE::GOsetGameObjectZPos(int index, int z)
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
	for(int i = 0; i < m_GameModel.size(); i++)
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
	}
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
	/*std::vector<Component*> tempComponents;
	TrueModel* tempModel;
	for (int i = 0; i < m_GameObject.size(); i++)
	{
		tempComponents = m_GameObject[i]->getComponents();
		for (int i2 = 0; i2 < tempComponents.size(); i++)
		{
			if (typeid(tempComponents[i2]).name() == "TrueModel")
			{
				tempModel = dynamic_cast<TrueModel*>(tempComponents[i2]);
				if(tempModel->getStatus())
				{
					m_AssetManager.getData(tempModel->getModel(), tempVAO);
					m_AssetManager.getData(tempModel->getTexture());
					m_RenderEngine.translate(m_GameObject[i]->getPositionX() + tempModel->getPositionX(), m_GameObject[i]->getPositionY() + tempModel->getPositionY(), m_GameObject[i]->getPositionZ() + tempModel->getPositionZ());
					m_RenderEngine.rotate(Axis::xAxis, m_GameObject[i]->getRotationX() + tempModel->getRotationX());
					m_RenderEngine.rotate(Axis::yAxis, m_GameObject[i]->getRotationY() + tempModel->getRotationY());
					m_RenderEngine.rotate(Axis::zAxis, m_GameObject[i]->getRotationZ() + tempModel->getRotationZ());
					m_RenderEngine.renderV(tempVAO);
				}
			}
		}
	}*/
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
	
	m_AssetManager.getData("Data\\Roof.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[0].data());
	m_RenderEngine.translate(REcameraX(), REcameraY() + m_SkyboxSize/2, REcameraZ());
	m_RenderEngine.rotate(Axis::zAxis, 180.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxFront()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\wall2.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[1].data());
	//m_AssetManager.getData("Data\\Sunny1_front.jpg");
	m_RenderEngine.translate(REcameraX(), REcameraY(), REcameraZ() - m_SkyboxSize/2);
	m_RenderEngine.rotate(Axis::zAxis, 180.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxBack()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\wall2.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[2].data());
	m_RenderEngine.translate(REcameraX(), REcameraY(), REcameraZ() + m_SkyboxSize/2);
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
	m_RenderEngine.rotate(Axis::zAxis, 180.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxLeft()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[3].data());
	m_RenderEngine.translate(REcameraX() - m_SkyboxSize/2, REcameraY(), REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, -90.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxRight()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[4].data());
	m_RenderEngine.translate(REcameraX() + m_SkyboxSize/2, REcameraY(), REcameraZ());
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
	m_RenderEngine.rotate(Axis::xAxis, 90.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxBottom()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Roof.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[5].data());
	m_RenderEngine.translate(REcameraX(), REcameraY() - m_SkyboxSize/2, REcameraZ());
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
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

Vector3 ISE::REcameraPos()
{
	return m_RenderEngine.getCameraPosition();
}

Vector3 ISE::REcameraFocus()
{
	return m_RenderEngine.getCameraFocus();
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
		if (typeid(tempComponents[i]).name() == "AI")
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
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempComponents[i] = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setEnabled(enable);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

// Add a Personality component to a GameObject by index
void ISE::AIaddPersonality(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->addPersonality();
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

// Delete a Personality component by index to a GameObject by index
void ISE::AIdeletePersonality(int index, int personalityIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->deletePersonality(personalityIndex);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

void ISE::AIaddPersonalityEmotionCase(int index, int personalityIndex, Personality::caseType casetype)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->addPersonalityEmotionCase(personalityIndex, casetype);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

void ISE::AIdeletePersonalityEmotionCase(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->deletePersonalityEmotionCase(personalityIndex, casetype, caseIndex);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

std::string ISE::AIgetPersonalityName(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityName(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityName(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, std::string name)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityName(personalityIndex, casetype, caseIndex, name);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityAmount(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityAmount(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityAmount(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float amount)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityAmount(personalityIndex, casetype, caseIndex, amount);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityPositiveModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityPositiveModifier(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityPositiveModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float positiveModifier)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityPositiveModifier(personalityIndex, casetype, caseIndex, positiveModifier);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityNegativeModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityNegativeModifier(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityNegativeModifier(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float negativeModifier)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityNegativeModifier(personalityIndex, casetype, caseIndex, negativeModifier);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityInterval(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityInterval(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityInterval(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float interval)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityInterval(personalityIndex, casetype, caseIndex, interval);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityIncrement(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityIncrement(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityIncrement(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float increment)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityIncrement(personalityIndex, casetype, caseIndex, increment);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityEffectQueue(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float effectQueue)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityEffectQueue(personalityIndex, casetype, caseIndex, effectQueue);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

float ISE::AIgetPersonalityAccumulatedTime(int index, int personalityIndex, Personality::caseType casetype, int caseIndex)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPersonalityAccumulatedTime(personalityIndex, casetype, caseIndex);
		}
	}
}

void ISE::AIsetPersonalityAccumulatedTime(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float accumulatedTime)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setPersonalityAccumulatedTime(personalityIndex, casetype, caseIndex, accumulatedTime);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

void ISE::AIaddToPersonalityEffectQueue(int index, int personalityIndex, Personality::caseType casetype, int caseIndex, float effect)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->addToPersonalityEffectQueue(personalityIndex, casetype, caseIndex, effect);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

void ISE::AIsetNavSize(int index, int size)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->setNavSize(size);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

int ISE::AIgetNavSize(int index)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getNavSize();
		}
	}
}

bool ISE::AIinitMesh(int index)
{
	bool tempBool = false;
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempBool = tempAI->initMesh();
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
	return tempBool;
}

void ISE::AIblockNode(int index, int x, int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->blockNode(x, y);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

void ISE::AIunblockNode(int index, int x, int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			tempAI->unblockNode(x, y);
			m_GameObject[index]->setComponent(i, tempAI);
			i = tempComponents.size();
		}
	}
}

as_node* ISE::AIgetNode(int index, int x,int y)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getNode(x, y);
		}
	}
}

std::stack<Vector2Int> ISE::AIgetPath(int index, as_node *start, as_node *goal)
{
	std::vector<Component*> tempComponents = m_GameObject[index]->getComponents();
	for (int i = 0; i < tempComponents.size(); i++)
	{
		if (typeid(tempComponents[i]).name() == "AI")
		{
			AI* tempAI;
			tempAI = dynamic_cast<AI*>(tempComponents[i]);
			return tempAI->getPath(start, goal);
		}
	}
}