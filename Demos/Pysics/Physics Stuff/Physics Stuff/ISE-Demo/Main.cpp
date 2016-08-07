#include "Main.h"

#include "Sound.h"

int main()
{
	ISE engine;


	
	engine.REsetSkyboxTopTexture("Data\\Sunny1_up.jpg");
	engine.REsetSkyboxFrontTexture("Data\\Sunny1_front.jpg");
	engine.REsetSkyboxBackTexture("Data\\Sunny1_back.jpg");
	engine.REsetSkyboxLeftTexture("Data\\Sunny1_left.jpg");
	engine.REsetSkyboxRightTexture("Data\\Sunny1_right.jpg");
	engine.REsetSkyboxBottomTexture("Data\\Sunny1_down.jpg");

	engine.AMloadModel("Data\\SlenderZombie.obj");
	engine.AMloadTexture("Data\\zombieTex.jpg");
	engine.AMloadModel("Data\\Terrain.obj");
	engine.AMloadTexture("Data\\grass.jpg");
	engine.AMloadModel("Data\\tree.obj");
	engine.AMloadTexture("Data\\cannon.bmp");
	engine.AMloadModel("Data\\rock.obj");
	engine.AMloadTexture("Data\\rock.jpg");

	engine.AMloadModel("Data\\roof.obj");

	engine.AMloadModel("Data\\floor.obj");
	engine.AMloadTexture("Data\\stone.jpg");

	engine.AMloadModel("Data\\ceiling.obj");

	engine.AMloadModel("Data\\rails.obj");
	engine.AMloadTexture("Data\\metal.jpg");
	engine.AMloadModel("Data\\interior_curved.obj");

	engine.AMloadModel("Data\\entry_wall.obj");
	engine.AMloadTexture("Data\\granite.jpg");

	engine.AMloadModel("Data\\pillars.obj");
	
	engine.AMloadModel("Data\\bar.obj");
	
	engine.AMloadModel("Data\\bar_sides.obj");
	engine.AMloadTexture("Data\\wood.jpg");
	engine.AMloadModel("Data\\outside_beams.obj");

	engine.AMloadTexture("Data\\wall.jpg");
	engine.AMloadModel("Data\\poles.obj");

	engine.AMloadModel("Data\\outside_walls.obj");
	engine.AMloadModel("Data\\window_frames.obj");

	engine.AMloadModel("Data\\interior_walls.obj");
	engine.AMloadModel("Data\\box1.obj");



	engine.GOcreateGameModel("floor");
	engine.GOsetGameModelLocation(0, "Data\\floor.obj");
	engine.GOsetGameModelTexture(0, "Data\\stone.jpg");

	engine.GOcreateGameModel("pillars");
	engine.GOsetGameModelLocation(1, "Data\\pillars.obj");
	engine.GOsetGameModelTexture(1, "Data\\granite.jpg");

	engine.GOcreateGameModel("rails");
	engine.GOsetGameModelLocation(2, "Data\\rails.obj");
	engine.GOsetGameModelTexture(2, "Data\\metal.jpg");

	engine.GOcreateGameModel("entry_wall");
	engine.GOsetGameModelLocation(3, "Data\\entry_wall.obj");
	engine.GOsetGameModelTexture(3, "Data\\granite.jpg");

		engine.GOcreateGameModel("bar");
	engine.GOsetGameModelLocation(4, "Data\\bar.obj");
	engine.GOsetGameModelTexture(4, "Data\\marble.jpg");

		engine.GOcreateGameModel("bar_sides");
	engine.GOsetGameModelLocation(5, "Data\\bar_sides.obj");
	engine.GOsetGameModelTexture(5, "Data\\marble.jpg");

		engine.GOcreateGameModel("outside_beams");
	engine.GOsetGameModelLocation(6, "Data\\outside_beams.obj");
	engine.GOsetGameModelTexture(6, "Data\\metal.jpg");

		engine.GOcreateGameModel("poles");
	engine.GOsetGameModelLocation(7, "Data\\entry_wall.obj");
	engine.GOsetGameModelTexture(7, "Data\\granite.jpg");

		engine.GOcreateGameModel("interior_curved");
	engine.GOsetGameModelLocation(8, "Data\\interior_curved.obj");
	engine.GOsetGameModelTexture(8, "Data\\metal.jpg");

	engine.GOcreateGameModel("ceiling");
	engine.GOsetGameModelLocation(9, "Data\\ceiling.obj");
	engine.GOsetGameModelTexture(9, "Data\\wall.jpg");

	engine.GOcreateGameModel("outside_walls");
	engine.GOsetGameModelLocation(10, "Data\\outside_walls.obj");
	engine.GOsetGameModelTexture(10, "Data\\wall.jpg");

	engine.GOcreateGameModel("window_frames");
	engine.GOsetGameModelLocation(11, "Data\\window_frames.obj");
	engine.GOsetGameModelTexture(11, "Data\\metal.jpg");

	engine.GOcreateGameModel("interior_walls");
	engine.GOsetGameModelLocation(12, "Data\\interior_walls.obj");
	engine.GOsetGameModelTexture(12, "Data\\wood.jpg");

	engine.GOcreateGameModel("roof");
	engine.GOsetGameModelLocation(13, "Data\\roof.obj");

	engine.GOcreateGameModel("poles");
	engine.GOsetGameModelLocation(14, "Data\\poles.obj");
	engine.GOsetGameModelTexture(14, "Data\\metal.jpg");

	engine.GOcreateGameModel("box1");
	engine.GOsetGameModelLocation(15, "Data\\box1.obj");
	engine.GOsetGameModelTexture(15, "Data\\metal.jpg");

	engine.GOcreateGameModel("box2");
	engine.GOsetGameModelLocation(16, "Data\\box1.obj");
	engine.GOsetGameModelTexture(16, "Data\\metal.jpg");

	
	/*engine.GOcreateGameModel("table");
	engine.GOsetGameModelLocation(16, "Data\\box1.obj");
	engine.GOsetGameModelTexture(16, "Data\\metal.jpg");

	engine.GOcreateGameModel("bench");
	engine.GOsetGameModelLocation(16, "Data\\box1.obj");
	engine.GOsetGameModelTexture(16, "Data\\metal.jpg");*/
	//engine.boxData.push_back(new Box());
	//engine.boxData[0]->setState(Vector3(0,30,0),Quaternion(), Vector3(1,1,1), Vector3(0,1,0));
	//engine.boxData[1].setState(Vector3(0,60,0),Quaternion(), Vector3(1,1,1), Vector3(0,1,0));

	


	//engine.GOsetGameModelPos(15, engine.boxData[0].body->getPosition());
	//engine.GOsetGameModelPos(16, engine.boxData[1].body->getPosition());
	//engine.GOsetGameModelRotation(15, engine.boxData[0].body->getRotation());
	//engine.GOsetGameModelRotation(16, engine.boxData[1].body->getRotation());



	engine.REwindowSetSize(winWidth, winHeight);
	engine.IOsetLockMousePosition((int)(winWidth/2), (int)(winHeight/2));
	engine.REcameraMoveUp(10.0f);
	engine.REcameraChangeMode(Camera::FPS);
	engine.IOunlockMouse();

	setupBoundingVolumes(engine);

	//Input input;
	bool w = false;
	bool d = false;
	int cool = 0;
	//input.setMouseLockPosition(640, 384);

	bool run = true;
	float time = 0.0;
	
	while(run)
	{
		float dt = engine.MIgetDeltaTime();
		engine.ISEupdate();
		updateInput(engine, run, dt);
		engine.IOlockMouse();
		//drawContacts(engine);
		update(engine, dt);
		updateModels(engine, dt);
		engine.RErenderGameModels();
		engine.REdisplaySkyboxTop();
		engine.REdisplaySkyboxFront();
		engine.REdisplaySkyboxBack();
		engine.REdisplaySkyboxLeft();
		engine.REdisplaySkyboxRight();
		engine.REdisplaySkyboxBottom();
		engine.REsystemCycle();
	}

	return 0;
}

void fire(ISE &engine)
{
	a++;
	b++;
	
	engine.GOcreateGameModel("box");
	engine.GOsetGameModelLocation(a, "Data\\box1.obj");
	engine.GOsetGameModelTexture(a, "Data\\metal.jpg");
	engine.GOsetGameModelPos(a, ((engine.REcameraFocus() - engine.REcameraPos()) * 100) + engine.REcameraPos());
	Vector3 force = engine.REcameraFocus() - engine.REcameraPos();
	force.normalise();

	engine.boxData.push_back(new Box());
	engine.boxData[b]->setState(engine.GOgetGameModelPos(a)-Vector3(2,0,2),Quaternion(),Vector3(20.0f,20.0f,20.0f),Vector3(0,-10,0));
	engine.boxData[b]->body->addForce(force*3000000.0f);
	//engine.boxData[b]->body->addTorque(force + Vector3(200,100,200) * 999999999);

	//engine.boxData[j+2].setState(engine.REcameraPos(),Quaternion(), Vector3(0.5,0.5,0.5),Vector3(0,1,0));
	//engine.boxData[j+2].body->addForce(engine.REcameraFocus() * 20.0f);
}


void updateInput(ISE &engine, bool &run, float &dt)
{
	engine.REcameraLookUp(engine.IOgetMouseYVector()*12.5f*dt);
	engine.REcameraLookLeft(engine.IOgetMouseXVector()*20.0f*dt);

	float speed = 500.0f*dt;

	if(engine.IOisKeyReleased(Keyboard::E))
	{
		fire(engine);
	}
	if(engine.IOisKeyReleased(Keyboard::F))
	{
		std::cout << "X: " << engine.REcameraX() << " Y: " << engine.REcameraY() << " Z: " << engine.REcameraZ() << std::endl;
	}
	if(engine.IOisKeyPressed(Keyboard::W))
	{
		engine.REcameraMoveForward(speed);
		//std::cout << cool << " W" << std::endl;
		//std::cout<<"W" <<std::endl;
	}
	else if(engine.IOisKeyPressed(Keyboard::S))
	{
		engine.REcameraMoveBackward(speed);
		//std::cout<<"S" <<std::endl;
		//std::cout << cool << " S" << std::endl;
	}
	if(engine.IOisKeyPressed(Keyboard::A))
	{
		engine.REcameraMoveLeft(speed);
		//std::cout<<"A" <<std::endl;
		//std::cout << cool << " A" << std::endl;
	}
	else if(engine.IOisKeyPressed(Keyboard::D))
	{
		engine.REcameraMoveRight(speed);
		//std::cout<<"D" <<std::endl;
		//std::cout << cool << " D" << std::endl;
	}
	if(engine.IOisKeyReleased(Keyboard::K))
	{
		engine.REenableWireframe(!engine.REwireframeState());
	}
	if(engine.IOisKeyPressed(Keyboard::Escape))
	{
		run = false;
	}
	if(engine.IOisKeyPressed(Keyboard::L))
	{
		engine.IOlockMouse();
	}
	if(engine.IOisKeyPressed(Keyboard::U))
	{
		engine.IOunlockMouse();
	}
}

void updateModels(ISE &engine, float &dt)
{
	int x, y;

	if(b == 2)
	{
		return;
	}



	y = 3;
	for(x=17; x <= a; x++)
	{
		engine.GOsetGameModelRotation(x, engine.boxData[y]->body->getRotation()*10);
		engine.GOsetGameModelPos(x, engine.boxData[y]->body->getPosition());
		y++;
	}
}

void generateContacts(ISE &engine)
{
	Box *box, *other, *box2;
	int i, j, k;

	CollisionPlane plane;
	plane.direction = Vector3(0,1,0);
	plane.offset = 0;

	engine.cData.reset(512);
	engine.cData.friction = 0.9;
	engine.cData.restitution = 0.6;
	engine.cData.tolerance = 0.1;

	for(i=0; i < engine.boxData.size(); i++)
	{
		box = engine.boxData[i];
		if(!engine.cData.hasMoreContacts())
		{
			return;
		}
		CollisionDetector::boxAndHalfSpace(*box, plane, &engine.cData);
	}

	if(engine.boxData.size() == 1)
	{
		return;
	}

	for(j=0; j < engine.boxData.size(); j++)
	{
		if(!engine.cData.hasMoreContacts())
		{
			return;
		}
		for(k=j+1; k < engine.boxData.size(); k++)
		{
			other = engine.boxData[j];
			box2 = engine.boxData[k];

			CollisionDetector::boxAndBox(*other, *box2, &engine.cData);
			if(IntersectionTests::boxAndBox(*other, *box2))
			{
				engine.boxData[j]->isOverlapping = engine.boxData[k]->isOverlapping = true;
			}
		}
	}
}

void updateObjects(ISE &engine, float &dt)
{
	for(int i=0; i < engine.boxData.size();i++)
	{
		engine.boxData[i]->body->integrate(dt);
		engine.boxData[i]->calculateInternals();
		engine.boxData[i]->isOverlapping = false;
	}
}

void update(ISE &engine, float &dt)
{
	if(dt <= 0.0f)
	{
		return;
	}
	else
		if(dt > 0.05f)
		{
			dt = 0.05f;
		}

	updateObjects(engine, dt);
	generateContacts(engine);

	engine.resolver.resolveContacts(engine.cData.contactArray,engine.cData.contactCount,dt);
}

void setupBoundingVolumes(ISE &engine)
{
	engine.boxData.push_back(new Box());
	engine.boxData[0]->setState(Vector3(-200, 60, -280),Quaternion(), Vector3(5,60,100),Vector3(0,0,0));
	engine.boxData[0]->body->setInverseMass(0);

	engine.boxData.push_back(new Box());
	engine.boxData[1]->setState(Vector3(150, 60, -400),Quaternion(), Vector3(5,60,760),Vector3(0,0,0));
	engine.boxData[1]->body->setInverseMass(0);

	engine.boxData.push_back(new Box());
	engine.boxData[2]->setState(Vector3(112.5, 170, -524), Quaternion(), Vector3(312.5, 2, 594),Vector3(0,0,0));
	engine.boxData[2]->body->setInverseMass(0);
}