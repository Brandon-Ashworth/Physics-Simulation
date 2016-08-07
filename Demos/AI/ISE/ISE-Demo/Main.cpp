#include "Main.h"

#include "Sound.h"

//Testing Move somewhere else later
float offSetX = 700.f;
float offSetY = 1600.f;

int main()
{
	
	engine.REsetSkyboxTopTexture("Data\\plain_sky_top.jpg");
	engine.REsetSkyboxFrontTexture("Data\\plain_sky_front.jpg");
	engine.REsetSkyboxBackTexture("Data\\plain_sky_back.jpg");
	engine.REsetSkyboxLeftTexture("Data\\plain_sky_right.jpg");
	engine.REsetSkyboxRightTexture("Data\\plain_sky_left.jpg");
	//engine.REsetSkyboxBottomTexture("Data\\Sunny1_down.jpg");

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

	engine.AMloadModel("Data\\SlenderZombie.obj");
	engine.AMloadTexture("Data\\zombieTex.jpg");
	engine.AMloadTexture("Data\\zombieTex(angery).jpg");
	engine.AMloadTexture("Data\\zombieTex(hungery).jpg");
	//add a sad slender zombie

	//--------------------------------
	// Adding New Game Objects and their positions in th world (maybe orientations
	//--------------------------------
		
	engine.AMloadTexture("Data\\black.jpg");
	engine.AMloadTexture("Data\\brown.jpg");
	engine.AMloadTexture("Data\\red.jpg");
	engine.AMloadTexture("Data\\Silver.jpg");

	engine.AMloadModel("Data\\Bench.obj");
	engine.AMloadModel("Data\\bin.obj");
	engine.AMloadModel("Data\\couch.obj");
	engine.AMloadModel("Data\\table.obj");
		


	//--------------------------------
	//
	//--------------------------------



	/*
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
	*/
	/*
	engine.GOaddGameObject();
	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0, 0, "Data\\poles.obj");
	engine.GOsetGameObjectModelTextureName(0, 0, "Data\\metal.jpg");
	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0, 1, "Data\\floor.obj");
	engine.GOsetGameObjectModelTextureName(0, 1, "Data\\stone.jpg");*/

	engine.GOaddGameObject();

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,0, "Data\\floor.obj");
	engine.GOsetGameObjectModelTextureName(0,0, "Data\\stone.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,1, "Data\\pillars.obj");
	engine.GOsetGameObjectModelTextureName(0,1, "Data\\granite.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,2, "Data\\rails.obj");
	engine.GOsetGameObjectModelTextureName(0,2, "Data\\metal.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,3, "Data\\entry_wall.obj");
	engine.GOsetGameObjectModelTextureName(0,3, "Data\\granite.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,4, "Data\\bar.obj");
	engine.GOsetGameObjectModelTextureName(0,4, "Data\\marble.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,5, "Data\\bar_sides.obj");
	engine.GOsetGameObjectModelTextureName(0,5, "Data\\marble.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,6, "Data\\outside_beams.obj");
	engine.GOsetGameObjectModelTextureName(0,6, "Data\\metal.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,7, "Data\\entry_wall.obj");
	engine.GOsetGameObjectModelTextureName(0,7, "Data\\granite.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,8, "Data\\interior_curved.obj");
	engine.GOsetGameObjectModelTextureName(0,8, "Data\\metal.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,9, "Data\\ceiling.obj");
	engine.GOsetGameObjectModelTextureName(0,9, "Data\\wall.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,10, "Data\\outside_walls.obj");
	engine.GOsetGameObjectModelTextureName(0,10, "Data\\wall.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,11, "Data\\window_frames.obj");
	engine.GOsetGameObjectModelTextureName(0,11, "Data\\metal.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,12, "Data\\interior_walls.obj");
	engine.GOsetGameObjectModelTextureName(0,12, "Data\\wood.jpg");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,13, "Data\\roof.obj");

	engine.GOaddComponentToGameObject(0, Component::MODEL);
	engine.GOsetGameObjectModelName(0,14, "Data\\poles.obj");
	engine.GOsetGameObjectModelTextureName(0,14, "Data\\metal.jpg"); 

	// Athlete Zombie
	engine.GOaddGameObject();
	engine.GOaddComponentToGameObject(1, Component::MODEL);
	engine.GOsetGameObjectModelName(1, 0, "Data\\SlenderZombie.obj");
	engine.GOsetGameObjectModelTextureName(1, 0, "Data\\zombieTex.jpg");
	engine.GOsetGameObjectXPos(1, -100.0f);
	engine.GOsetGameObjectYPos(1, 45.0f);
	engine.GOsetGameObjectZPos(1, -300.0f);
	engine.AIaddAI(1);
	engine.AIaddPersonality(1);
	engine.AIenableGameObjectAI(1, true);
	initEmotions(1, 20.0f, 40.0f, 65.0f);

	// Alcoholic Zombie
	engine.GOaddGameObject();
	engine.GOaddComponentToGameObject(2, Component::MODEL);
	engine.GOsetGameObjectModelName(2, 0, "Data\\SlenderZombie.obj");
	engine.GOsetGameObjectModelTextureName(2, 0, "Data\\zombieTex.jpg");
	engine.GOsetGameObjectXPos(2, -700.0f);
	engine.GOsetGameObjectYPos(2, 45.0f);
	engine.GOsetGameObjectZPos(2, -400.0f);
	engine.AIaddAI(2);
	engine.AIaddPersonality(2);
	engine.AIenableGameObjectAI(2, true);
	initEmotions(2, 80.0f, 20.0f, 40.0f);

	// Bartender Zombie
	engine.GOaddGameObject();
	engine.GOaddComponentToGameObject(3, Component::MODEL);
	engine.GOsetGameObjectModelName(3, 0, "Data\\SlenderZombie.obj");
	engine.GOsetGameObjectModelTextureName(3, 0, "Data\\zombieTex.jpg");
	engine.GOsetGameObjectXPos(3, -700.0f);
	engine.GOsetGameObjectYPos(3, 45.0f);
	engine.GOsetGameObjectZPos(3, -400.0f);
	engine.AIaddAI(3);
	engine.AIaddPersonality(3);
	engine.AIenableGameObjectAI(3, true);
	initEmotions(3, 35.0f, 85.0f, 20.0f);
	
	//a star test
	//engine.ASaddAStar(2);
	//engine.ASsetSize(2,26);
	//setBlockedNodes(2);
	//engine.ASsetGap(2,100.f);
	//initTestAStar(2);

	//--------------------------------
	// Adding New Game Objects and their positions in th world (maybe orientations
	//--------------------------------

		int GOcount = 4;

		std::string couchText = "Data\\black.jpg";
		std::string benchText = "Data\\brown.jpg";
		std::string tableText = "Data\\brown.jpg";
		std::string binText = "Data\\black.jpg";
		/*
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"");
		engine.GOsetGameObjectModelTextureName(GOcount,0,"");
		engine.GOsetGameObjectXPos(GOcount,);
		engine.GOsetGameObjectZPos(GOcount,);
		GOcount++;*/

		//Bench 1 - 9.5,-1265
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,0);
		engine.GOsetGameObjectZPos(GOcount,-1265);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;

		//Bench 2 - 112,-1265
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,150);
		engine.GOsetGameObjectZPos(GOcount,-1265);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;

		//Bench 3 197,-1265
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,300);
		engine.GOsetGameObjectZPos(GOcount,-1265);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;

		//Bench 4 315,-1265
		/*engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,450);
		engine.GOsetGameObjectZPos(GOcount,-1265);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;*/

		//Bench 5 - 9.5,-1405
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,0);
		engine.GOsetGameObjectZPos(GOcount,-1405);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;

		//Bench 6 - 112,-1405
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,150);
		engine.GOsetGameObjectZPos(GOcount,-1405);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;

		//Bench 7 197,-1405
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,300);
		engine.GOsetGameObjectZPos(GOcount,-1405);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;

		//Bench 8 315,-1405
		/*engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,450);
		engine.GOsetGameObjectZPos(GOcount,-1405);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,90);
		GOcount++;*/

		//Bench 9 -564,-555
		/*engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,"Data\\black.jpg");
		engine.GOsetGameObjectXPos(GOcount,-564);
		engine.GOsetGameObjectZPos(GOcount,-555);
		GOcount++;*///bad position

		//Bench 10 - -564,-673
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");//typo lol
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,-564);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectZPos(GOcount,-673);
		GOcount++;




		//Bin 1-  393,-1743
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\bin.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,binText);
		engine.GOsetGameObjectXPos(GOcount,393);
		engine.GOsetGameObjectZPos(GOcount,-1713);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-90);
		GOcount++;

		//Bin 2 - 404,-1570
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\bin.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,binText);
		engine.GOsetGameObjectXPos(GOcount,390);
		engine.GOsetGameObjectZPos(GOcount,-1565);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-90);
		GOcount++;

		//bin 3 - -235,-218
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\bin.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,binText);
		engine.GOsetGameObjectXPos(GOcount,-225);
		engine.GOsetGameObjectZPos(GOcount,-218);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-90);
		GOcount++;



		//Couch 1 - (127,-54)
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\couch.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,couchText);
		engine.GOsetGameObjectXPos(GOcount,132);
		engine.GOsetGameObjectZPos(GOcount,-54);
		GOcount++;



		//table 1 - (-144,-1071
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\table.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,tableText);
		engine.GOsetGameObjectXPos(GOcount,-144);
		engine.GOsetGameObjectZPos(GOcount,-1071);
		engine.GOsetGameObjectYPos(GOcount,32);
		GOcount++;

		//table 2 - (-90,-786
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\table.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,tableText);
		engine.GOsetGameObjectXPos(GOcount,-90);
		engine.GOsetGameObjectZPos(GOcount,-786);
		engine.GOsetGameObjectYPos(GOcount,32);
		GOcount++;

		//table 3 - (-118,-384
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\table.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,tableText);
		engine.GOsetGameObjectXPos(GOcount,-118);
		engine.GOsetGameObjectZPos(GOcount,-384);
		engine.GOsetGameObjectYPos(GOcount,32);
		GOcount++;

		//Bench 11 (20,-1684  rot -45 
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,-155);
		engine.GOsetGameObjectZPos(GOcount,-1684);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-22);
		GOcount++;

		//Bench 12 (62,-1777  rot -45
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,-113);
		engine.GOsetGameObjectZPos(GOcount,-1800);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-22);
		GOcount++;

		//Bench 13 (125,-1913  rot -45
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,-50);
		engine.GOsetGameObjectZPos(GOcount,-1950);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-22);
		GOcount++;

		//Bench 14 (23,-1623
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,23);
		engine.GOsetGameObjectZPos(GOcount,-1623);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-26);
		GOcount++;

		//Bench 15 (75,-1729
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,75);
		engine.GOsetGameObjectZPos(GOcount,-1729);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-26);
		GOcount++;

		//Bench 16 (135,-1852
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(GOcount,Component::MODEL);
		engine.GOsetGameObjectModelName(GOcount,0,"Data\\Bench.obj");
		engine.GOsetGameObjectModelTextureName(GOcount,0,benchText);
		engine.GOsetGameObjectXPos(GOcount,135);
		engine.GOsetGameObjectZPos(GOcount,-1852);
		engine.GOsetGameObjectYPos(GOcount,10);
		engine.GOsetGameObjectModelRotationY(GOcount,0,-26);
		GOcount++;



	//--------------------------------
	//
	//--------------------------------
	


	/**/


	/*
	int x = 0;
	int y = 0;

	float gap = 100.f;
	//float offSetX = 0.f;
	float offSetX = 700.f;
	float offSetY = 2250.f;

	

	
	

	int grid = 24;
	int gridSize = pow(grid,2);
	int count = 0;
	for(int i=1; i<gridSize+1;++i)//start at 15 the gameObject thing
	{
		engine.GOaddGameObject();
		engine.GOaddComponentToGameObject(i,Component::MODEL);
		engine.GOsetGameObjectModelName(i,0,"Data\\SlenderZombie.obj");
		engine.GOsetGameObjectModelTextureName(i,0,"Data\\zombieTex.jpg");
		count++;
	}

	for(int i=1; i<gridSize+1;++i)
	{

		engine.GOsetGameObjectXPos(i,(x*gap) - offSetX);
		engine.GOsetGameObjectZPos(i,(y*gap) - offSetY);
		

		y++;
		if(y > grid-1)
		{
			x++;
			y=0;
		}
		
	}

	for(int i=1; i<gridSize+1;++i)
	{
		int posX = (engine.GOgetGameObjectXPos(i)+ offSetX)/gap;
		int posZ = (engine.GOgetGameObjectZPos(i)+offSetY)/gap;

		std::cout << "GO: " << i
			<< " " << posX <<","
			<< posZ <<std::endl;

		if(posX > (grid/2) -1)
		{
			engine.GOsetGameObjectModelName(i,0, "Data\\poles.obj");
			//std::cout <<"Sexy legs" << std::endl;
		}
	}*/



	/**/

	
	engine.REwindowSetSize(winWidth, winHeight);
	engine.IOsetLockMousePosition((int)(winWidth/2), (int)(winHeight/2));
	engine.REcameraMoveUp(30.0f);
	engine.REcameraMoveForward(150.0f);
	engine.REcameraMoveLeft(50.0f);
	engine.REcameraChangeMode(Camera::FPS);
	engine.IOunlockMouse();

	//Input input;
	bool w = false;
	bool d = false;
	int cool = 0;
	//input.setMouseLockPosition(640, 384);

	bool run = true;
	float time = 0.0;
	
	//tes getRid
	int count = 0;

	while(run)
	{
		if(count == 7)
		{
			//std::cout<<"CPBreakyCP destroyah\n";
		}
		float dt = engine.MIgetDeltaTime();
		engine.ISEupdate(dt);
		updateInput(engine, run, dt);
		doTestAI(dt);
		//engine.ASsetGoal(2, engine.REcameraX()+offSetX, engine.REcameraZ()+offSetY);
		//std::cout << "X:" << engine.ASgetDesY(2) << " | Y:" << engine.ASgetDesX(2) << "\n";
		//doTestAStar(2);
		emotionValidation(1);
		emotionValidation(2);
		emotionValidation(3);
		engine.IOlockMouse();
		engine.RErenderGameModels();
		engine.REdisplaySkyboxTop();
		engine.REdisplaySkyboxFront();
		engine.REdisplaySkyboxBack();
		engine.REdisplaySkyboxLeft();
		engine.REdisplaySkyboxRight();
		//engine.REdisplaySkyboxBottom();
		engine.REsystemCycle();

		count++;
	}

	return 0;
}

void updateInput(ISE &engine, bool &run, float dt)
{
	engine.REcameraLookUp(engine.IOgetMouseYVector()*12.5f*dt);
	engine.REcameraLookLeft(engine.IOgetMouseXVector()*20.0f*dt);

	float speed = 500.0f*dt;
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

void doTestAI(float dt)
{
	float tempDist = std::powf(engine.GOgetGameObjectXPos(1) - engine.REcameraX(), 2) + std::powf(engine.GOgetGameObjectZPos(1) - engine.REcameraZ(), 2);

	tempDist = std::sqrtf(tempDist + std::powf(engine.GOgetGameObjectYPos(1) - engine.REcameraY(), 2));
	//std::cout << engine.AIgetPersonalityAmount(1, 0, Personality::EMOTION, 0) << "\n";
	if (tempDist <= 50)
	{
		engine.AIsetPersonalityIncrement(1, 0, Personality::EMOTION, 0, 0.0);
		engine.AIaddToPersonalityEffectQueue(1, 0, Personality::EMOTION, 0, 5*dt);
	}
	else
	{
		if(engine.AIgetPersonalityAmount(1, 0, Personality::EMOTION, 0) <= -25)
		{
			engine.AIsetPersonalityIncrement(1, 0, Personality::EMOTION, 0, 2.5);
		}
		else
		{
			engine.AIsetPersonalityIncrement(1, 0, Personality::EMOTION, 0, -2.5);
		}
	}
	if(engine.AIgetPersonalityAmount(1, 0, Personality::EMOTION, 0) >= 50)
	{
		engine.GOsetGameObjectModelTextureName(1, 0, "Data\\zombieTex(angery).jpg");
	}
	else
	{
		engine.GOsetGameObjectModelTextureName(1, 0, "Data\\zombieTex.jpg");
	}
}

void doAlcAI(float dt)
{
	//check if a source of booze is close (certain item number not sure) or bartender

	//specific item check below (what item no number to specify i think

	//get the position of the bartender
	float hypotenuse = std::powf(engine.GOgetGameObjectXPos(2) - engine.GOgetGameObjectXPos(3),2) + std::powf(engine.GOgetGameObjectZPos(2) - engine.GOgetGameObjectZPos(3),2);
	float barDis = std::sqrtf(hypotenuse + std::powf(engine.GOgetGameObjectYPos(2) - engine.GOgetGameObjectYPos(3),2));

	if(barDis <= 50)
	{
		//if disatnce below 50 become happy (maybe increase this)
	}
	else
	{
		//slowly become upset as he becomes more sober or soemthing
	}
	//there is an if statement to do something with the 


}

void setBlockedNodes(int x)
{
	engine.ASaddBlockedNode(x,0,0);
	engine.ASaddBlockedNode(x,0,1);
	engine.ASaddBlockedNode(x,0,2);
	engine.ASaddBlockedNode(x,0,3);
	engine.ASaddBlockedNode(x,0,4);
	engine.ASaddBlockedNode(x,0,5);
	engine.ASaddBlockedNode(x,0,6);
	engine.ASaddBlockedNode(x,0,7);
	engine.ASaddBlockedNode(x,0,8);
	engine.ASaddBlockedNode(x,0,9);
	engine.ASaddBlockedNode(x,0,10);
	engine.ASaddBlockedNode(x,0,11);
	engine.ASaddBlockedNode(x,0,12);
	engine.ASaddBlockedNode(x,0,13);
	engine.ASaddBlockedNode(x,0,14);
	engine.ASaddBlockedNode(x,0,15);
	engine.ASaddBlockedNode(x,0,16);
	engine.ASaddBlockedNode(x,0,17);
	engine.ASaddBlockedNode(x,0,18);
	engine.ASaddBlockedNode(x,0,19);
	engine.ASaddBlockedNode(x,0,20);
	engine.ASaddBlockedNode(x,0,21);
	engine.ASaddBlockedNode(x,0,22);
	engine.ASaddBlockedNode(x,0,23);
	engine.ASaddBlockedNode(x,0,24);
	engine.ASaddBlockedNode(x,1,0);
	engine.ASaddBlockedNode(x,1,12);
	engine.ASaddBlockedNode(x,1,13);
	engine.ASaddBlockedNode(x,1,14);
	engine.ASaddBlockedNode(x,1,15);
	engine.ASaddBlockedNode(x,1,16);
	engine.ASaddBlockedNode(x,1,17);
	engine.ASaddBlockedNode(x,1,18);
	engine.ASaddBlockedNode(x,1,19);
	engine.ASaddBlockedNode(x,1,20);
	engine.ASaddBlockedNode(x,1,21);
	engine.ASaddBlockedNode(x,1,22);
	engine.ASaddBlockedNode(x,1,23);
	engine.ASaddBlockedNode(x,1,24);
	engine.ASaddBlockedNode(x,2,0);
	engine.ASaddBlockedNode(x,2,12);
	engine.ASaddBlockedNode(x,2,13);
	engine.ASaddBlockedNode(x,2,14);
	engine.ASaddBlockedNode(x,2,15);
	engine.ASaddBlockedNode(x,2,16);
	engine.ASaddBlockedNode(x,2,17);
	engine.ASaddBlockedNode(x,2,18);
	engine.ASaddBlockedNode(x,2,19);
	engine.ASaddBlockedNode(x,2,20);
	engine.ASaddBlockedNode(x,2,21);
	engine.ASaddBlockedNode(x,2,22);
	engine.ASaddBlockedNode(x,2,23);
	engine.ASaddBlockedNode(x,2,24);
	engine.ASaddBlockedNode(x,3,0);
	engine.ASaddBlockedNode(x,3,4);
	engine.ASaddBlockedNode(x,3,12);
	engine.ASaddBlockedNode(x,3,13);
	engine.ASaddBlockedNode(x,3,14);
	engine.ASaddBlockedNode(x,3,15);
	engine.ASaddBlockedNode(x,3,16);
	engine.ASaddBlockedNode(x,3,17);
	engine.ASaddBlockedNode(x,3,18);
	engine.ASaddBlockedNode(x,3,19);
	engine.ASaddBlockedNode(x,3,20);
	engine.ASaddBlockedNode(x,3,21);
	engine.ASaddBlockedNode(x,3,22);
	engine.ASaddBlockedNode(x,3,23);
	engine.ASaddBlockedNode(x,3,24);
	engine.ASaddBlockedNode(x,4,0);
	engine.ASaddBlockedNode(x,4,12);
	engine.ASaddBlockedNode(x,4,13);
	engine.ASaddBlockedNode(x,4,14);
	engine.ASaddBlockedNode(x,4,15);
	engine.ASaddBlockedNode(x,4,16);
	engine.ASaddBlockedNode(x,4,17);
	engine.ASaddBlockedNode(x,4,18);
	engine.ASaddBlockedNode(x,4,19);
	engine.ASaddBlockedNode(x,4,20);
	engine.ASaddBlockedNode(x,4,21);
	engine.ASaddBlockedNode(x,4,22);
	engine.ASaddBlockedNode(x,4,23);
	engine.ASaddBlockedNode(x,4,24);
	engine.ASaddBlockedNode(x,5,0);
	engine.ASaddBlockedNode(x,5,12);
	engine.ASaddBlockedNode(x,5,13);
	engine.ASaddBlockedNode(x,5,14);
	engine.ASaddBlockedNode(x,5,15);
	engine.ASaddBlockedNode(x,5,16);
	engine.ASaddBlockedNode(x,5,17);
	engine.ASaddBlockedNode(x,5,18);
	engine.ASaddBlockedNode(x,5,19);
	engine.ASaddBlockedNode(x,5,20);
	engine.ASaddBlockedNode(x,5,21);
	engine.ASaddBlockedNode(x,5,22);
	engine.ASaddBlockedNode(x,5,23);
	engine.ASaddBlockedNode(x,5,24);
	engine.ASaddBlockedNode(x,6,0);
	engine.ASaddBlockedNode(x,6,3);
	engine.ASaddBlockedNode(x,6,12);
	engine.ASaddBlockedNode(x,6,13);
	engine.ASaddBlockedNode(x,6,14);
	engine.ASaddBlockedNode(x,6,15);
	engine.ASaddBlockedNode(x,6,16);
	engine.ASaddBlockedNode(x,6,17);
	engine.ASaddBlockedNode(x,6,18);
	engine.ASaddBlockedNode(x,6,19);
	engine.ASaddBlockedNode(x,6,20);
	engine.ASaddBlockedNode(x,6,21);
	engine.ASaddBlockedNode(x,6,22);
	engine.ASaddBlockedNode(x,6,23);
	engine.ASaddBlockedNode(x,6,24);
	engine.ASaddBlockedNode(x,7,0);
	engine.ASaddBlockedNode(x,7,12);
	engine.ASaddBlockedNode(x,7,13);
	engine.ASaddBlockedNode(x,7,14);
	engine.ASaddBlockedNode(x,7,15);
	engine.ASaddBlockedNode(x,7,16);
	engine.ASaddBlockedNode(x,7,17);
	engine.ASaddBlockedNode(x,7,18);
	engine.ASaddBlockedNode(x,7,19);
	engine.ASaddBlockedNode(x,7,20);
	engine.ASaddBlockedNode(x,7,21);
	engine.ASaddBlockedNode(x,7,22);
	engine.ASaddBlockedNode(x,7,23);
	engine.ASaddBlockedNode(x,7,24);
	engine.ASaddBlockedNode(x,8,0);
	engine.ASaddBlockedNode(x,8,3);
	engine.ASaddBlockedNode(x,8,12);
	engine.ASaddBlockedNode(x,8,13);
	engine.ASaddBlockedNode(x,8,14);
	engine.ASaddBlockedNode(x,8,15);
	engine.ASaddBlockedNode(x,8,16);
	engine.ASaddBlockedNode(x,8,17);
	engine.ASaddBlockedNode(x,8,18);
	engine.ASaddBlockedNode(x,8,19);
	engine.ASaddBlockedNode(x,8,20);
	engine.ASaddBlockedNode(x,8,21);
	engine.ASaddBlockedNode(x,8,22);
	engine.ASaddBlockedNode(x,8,23);
	engine.ASaddBlockedNode(x,8,24);
	engine.ASaddBlockedNode(x,9,0);
	engine.ASaddBlockedNode(x,9,1);
	engine.ASaddBlockedNode(x,9,12);
	engine.ASaddBlockedNode(x,9,13);
	engine.ASaddBlockedNode(x,9,14);
	engine.ASaddBlockedNode(x,9,15);
	engine.ASaddBlockedNode(x,9,16);
	engine.ASaddBlockedNode(x,9,17);
	engine.ASaddBlockedNode(x,9,18);
	engine.ASaddBlockedNode(x,9,19);
	engine.ASaddBlockedNode(x,9,20);
	engine.ASaddBlockedNode(x,9,21);
	engine.ASaddBlockedNode(x,9,22);
	engine.ASaddBlockedNode(x,9,23);
	engine.ASaddBlockedNode(x,9,24);
	engine.ASaddBlockedNode(x,10,0);
	engine.ASaddBlockedNode(x,10,1);
	engine.ASaddBlockedNode(x,10,12);
	engine.ASaddBlockedNode(x,10,13);
	engine.ASaddBlockedNode(x,10,14);
	engine.ASaddBlockedNode(x,10,15);
	engine.ASaddBlockedNode(x,10,16);
	engine.ASaddBlockedNode(x,10,17);
	engine.ASaddBlockedNode(x,10,18);
	engine.ASaddBlockedNode(x,10,19);
	engine.ASaddBlockedNode(x,10,20);
	engine.ASaddBlockedNode(x,10,21);
	engine.ASaddBlockedNode(x,10,22);
	engine.ASaddBlockedNode(x,10,23);
	engine.ASaddBlockedNode(x,10,24);
	engine.ASaddBlockedNode(x,11,0);
	engine.ASaddBlockedNode(x,11,1);
	engine.ASaddBlockedNode(x,11,12);
	engine.ASaddBlockedNode(x,11,13);
	engine.ASaddBlockedNode(x,11,14);
	engine.ASaddBlockedNode(x,11,15);
	engine.ASaddBlockedNode(x,11,16);
	engine.ASaddBlockedNode(x,11,17);
	engine.ASaddBlockedNode(x,11,18);
	engine.ASaddBlockedNode(x,11,19);
	engine.ASaddBlockedNode(x,11,20);
	engine.ASaddBlockedNode(x,11,21);
	engine.ASaddBlockedNode(x,11,22);
	engine.ASaddBlockedNode(x,11,23);
	engine.ASaddBlockedNode(x,11,24);
	engine.ASaddBlockedNode(x,12,0);
	engine.ASaddBlockedNode(x,12,1);
	engine.ASaddBlockedNode(x,12,5);
	engine.ASaddBlockedNode(x,12,6);
	engine.ASaddBlockedNode(x,12,8);
	engine.ASaddBlockedNode(x,12,9);
	engine.ASaddBlockedNode(x,12,10);
	engine.ASaddBlockedNode(x,12,11);
	engine.ASaddBlockedNode(x,12,12);
	engine.ASaddBlockedNode(x,12,13);
	engine.ASaddBlockedNode(x,12,14);
	engine.ASaddBlockedNode(x,12,15);
	engine.ASaddBlockedNode(x,12,16);
	engine.ASaddBlockedNode(x,12,17);
	engine.ASaddBlockedNode(x,12,18);
	engine.ASaddBlockedNode(x,12,19);
	engine.ASaddBlockedNode(x,12,20);
	engine.ASaddBlockedNode(x,12,21);
	engine.ASaddBlockedNode(x,12,22);
	engine.ASaddBlockedNode(x,12,23);
	engine.ASaddBlockedNode(x,12,24);
	engine.ASaddBlockedNode(x,13,0);
	engine.ASaddBlockedNode(x,13,1);
	engine.ASaddBlockedNode(x,13,5);
	engine.ASaddBlockedNode(x,13,8);
	engine.ASaddBlockedNode(x,13,9);
	engine.ASaddBlockedNode(x,13,10);
	engine.ASaddBlockedNode(x,13,11);
	engine.ASaddBlockedNode(x,13,12);
	engine.ASaddBlockedNode(x,13,13);
	engine.ASaddBlockedNode(x,13,14);
	engine.ASaddBlockedNode(x,13,15);
	engine.ASaddBlockedNode(x,13,16);
	engine.ASaddBlockedNode(x,13,17);
	engine.ASaddBlockedNode(x,13,18);
	engine.ASaddBlockedNode(x,13,19);
	engine.ASaddBlockedNode(x,13,20);
	engine.ASaddBlockedNode(x,13,21);
	engine.ASaddBlockedNode(x,13,22);
	engine.ASaddBlockedNode(x,13,23);
	engine.ASaddBlockedNode(x,13,24);
	engine.ASaddBlockedNode(x,14,0);
	engine.ASaddBlockedNode(x,14,1);
	engine.ASaddBlockedNode(x,14,5);
	engine.ASaddBlockedNode(x,14,8);
	engine.ASaddBlockedNode(x,14,9);
	engine.ASaddBlockedNode(x,14,10);
	engine.ASaddBlockedNode(x,14,11);
	engine.ASaddBlockedNode(x,14,12);
	engine.ASaddBlockedNode(x,14,13);
	engine.ASaddBlockedNode(x,14,14);
	engine.ASaddBlockedNode(x,14,15);
	engine.ASaddBlockedNode(x,14,16);
	engine.ASaddBlockedNode(x,14,17);
	engine.ASaddBlockedNode(x,14,18);
	engine.ASaddBlockedNode(x,14,19);
	engine.ASaddBlockedNode(x,14,20);
	engine.ASaddBlockedNode(x,14,21);
	engine.ASaddBlockedNode(x,14,22);
	engine.ASaddBlockedNode(x,14,23);
	engine.ASaddBlockedNode(x,14,24);
	engine.ASaddBlockedNode(x,15,0);
	engine.ASaddBlockedNode(x,15,8);
	engine.ASaddBlockedNode(x,15,9);
	engine.ASaddBlockedNode(x,15,10);
	engine.ASaddBlockedNode(x,15,11);
	engine.ASaddBlockedNode(x,15,12);
	engine.ASaddBlockedNode(x,15,13);
	engine.ASaddBlockedNode(x,15,14);
	engine.ASaddBlockedNode(x,15,15);
	engine.ASaddBlockedNode(x,15,16);
	engine.ASaddBlockedNode(x,15,17);
	engine.ASaddBlockedNode(x,15,18);
	engine.ASaddBlockedNode(x,15,19);
	engine.ASaddBlockedNode(x,15,20);
	engine.ASaddBlockedNode(x,15,21);
	engine.ASaddBlockedNode(x,15,22);
	engine.ASaddBlockedNode(x,15,23);
	engine.ASaddBlockedNode(x,15,24);
	engine.ASaddBlockedNode(x,16,0);
	engine.ASaddBlockedNode(x,16,5);
	engine.ASaddBlockedNode(x,16,8);
	engine.ASaddBlockedNode(x,16,9);
	engine.ASaddBlockedNode(x,16,10);
	engine.ASaddBlockedNode(x,16,11);
	engine.ASaddBlockedNode(x,16,12);
	engine.ASaddBlockedNode(x,16,13);
	engine.ASaddBlockedNode(x,16,14);
	engine.ASaddBlockedNode(x,16,15);
	engine.ASaddBlockedNode(x,16,16);
	engine.ASaddBlockedNode(x,16,17);
	engine.ASaddBlockedNode(x,16,18);
	engine.ASaddBlockedNode(x,16,19);
	engine.ASaddBlockedNode(x,16,20);
	engine.ASaddBlockedNode(x,16,21);
	engine.ASaddBlockedNode(x,16,22);
	engine.ASaddBlockedNode(x,16,23);
	engine.ASaddBlockedNode(x,16,24);
	engine.ASaddBlockedNode(x,17,0);
	engine.ASaddBlockedNode(x,17,5);
	engine.ASaddBlockedNode(x,17,8);
	engine.ASaddBlockedNode(x,17,9);
	engine.ASaddBlockedNode(x,17,10);
	engine.ASaddBlockedNode(x,17,11);
	engine.ASaddBlockedNode(x,17,12);
	engine.ASaddBlockedNode(x,17,13);
	engine.ASaddBlockedNode(x,17,14);
	engine.ASaddBlockedNode(x,17,15);
	engine.ASaddBlockedNode(x,17,16);
	engine.ASaddBlockedNode(x,17,17);
	engine.ASaddBlockedNode(x,17,18);
	engine.ASaddBlockedNode(x,17,19);
	engine.ASaddBlockedNode(x,17,20);
	engine.ASaddBlockedNode(x,17,21);
	engine.ASaddBlockedNode(x,17,22);
	engine.ASaddBlockedNode(x,17,23);
	engine.ASaddBlockedNode(x,17,24);
	engine.ASaddBlockedNode(x,18,0);
	engine.ASaddBlockedNode(x,18,5);
	engine.ASaddBlockedNode(x,18,8);
	engine.ASaddBlockedNode(x,18,9);
	engine.ASaddBlockedNode(x,18,10);
	engine.ASaddBlockedNode(x,18,11);
	engine.ASaddBlockedNode(x,18,12);
	engine.ASaddBlockedNode(x,18,13);
	engine.ASaddBlockedNode(x,18,14);
	engine.ASaddBlockedNode(x,18,15);
	engine.ASaddBlockedNode(x,18,16);
	engine.ASaddBlockedNode(x,18,17);
	engine.ASaddBlockedNode(x,18,18);
	engine.ASaddBlockedNode(x,18,19);
	engine.ASaddBlockedNode(x,18,20);
	engine.ASaddBlockedNode(x,18,21);
	engine.ASaddBlockedNode(x,18,22);
	engine.ASaddBlockedNode(x,18,23);
	engine.ASaddBlockedNode(x,18,24);
	engine.ASaddBlockedNode(x,19,0);
	engine.ASaddBlockedNode(x,19,1);
	engine.ASaddBlockedNode(x,19,2);
	engine.ASaddBlockedNode(x,19,8);
	engine.ASaddBlockedNode(x,19,9);
	engine.ASaddBlockedNode(x,19,10);
	engine.ASaddBlockedNode(x,19,11);
	engine.ASaddBlockedNode(x,19,12);
	engine.ASaddBlockedNode(x,19,13);
	engine.ASaddBlockedNode(x,19,14);
	engine.ASaddBlockedNode(x,19,15);
	engine.ASaddBlockedNode(x,19,16);
	engine.ASaddBlockedNode(x,19,17);
	engine.ASaddBlockedNode(x,19,18);
	engine.ASaddBlockedNode(x,19,19);
	engine.ASaddBlockedNode(x,19,20);
	engine.ASaddBlockedNode(x,19,21);
	engine.ASaddBlockedNode(x,19,22);
	engine.ASaddBlockedNode(x,19,23);
	engine.ASaddBlockedNode(x,19,24);
	engine.ASaddBlockedNode(x,20,0);
	engine.ASaddBlockedNode(x,20,1);
	engine.ASaddBlockedNode(x,20,2);
	engine.ASaddBlockedNode(x,20,5);
	engine.ASaddBlockedNode(x,20,8);
	engine.ASaddBlockedNode(x,20,9);
	engine.ASaddBlockedNode(x,20,10);
	engine.ASaddBlockedNode(x,20,11);
	engine.ASaddBlockedNode(x,20,12);
	engine.ASaddBlockedNode(x,20,13);
	engine.ASaddBlockedNode(x,20,14);
	engine.ASaddBlockedNode(x,20,15);
	engine.ASaddBlockedNode(x,20,16);
	engine.ASaddBlockedNode(x,20,17);
	engine.ASaddBlockedNode(x,20,18);
	engine.ASaddBlockedNode(x,20,19);
	engine.ASaddBlockedNode(x,20,20);
	engine.ASaddBlockedNode(x,20,21);
	engine.ASaddBlockedNode(x,20,22);
	engine.ASaddBlockedNode(x,20,23);
	engine.ASaddBlockedNode(x,20,24);
	engine.ASaddBlockedNode(x,21,0);
	engine.ASaddBlockedNode(x,21,1);
	engine.ASaddBlockedNode(x,21,2);
	engine.ASaddBlockedNode(x,21,5);
	engine.ASaddBlockedNode(x,21,8);
	engine.ASaddBlockedNode(x,21,9);
	engine.ASaddBlockedNode(x,21,10);
	engine.ASaddBlockedNode(x,21,11);
	engine.ASaddBlockedNode(x,21,12);
	engine.ASaddBlockedNode(x,21,13);
	engine.ASaddBlockedNode(x,21,14);
	engine.ASaddBlockedNode(x,21,15);
	engine.ASaddBlockedNode(x,21,16);
	engine.ASaddBlockedNode(x,21,17);
	engine.ASaddBlockedNode(x,21,18);
	engine.ASaddBlockedNode(x,21,19);
	engine.ASaddBlockedNode(x,21,20);
	engine.ASaddBlockedNode(x,21,21);
	engine.ASaddBlockedNode(x,21,22);
	engine.ASaddBlockedNode(x,21,23);
	engine.ASaddBlockedNode(x,21,24);
	engine.ASaddBlockedNode(x,22,0);
	engine.ASaddBlockedNode(x,22,1);
	engine.ASaddBlockedNode(x,22,2);
	engine.ASaddBlockedNode(x,22,5);
	engine.ASaddBlockedNode(x,22,8);
	engine.ASaddBlockedNode(x,22,9);
	engine.ASaddBlockedNode(x,22,10);
	engine.ASaddBlockedNode(x,22,11);
	engine.ASaddBlockedNode(x,22,12);
	engine.ASaddBlockedNode(x,22,13);
	engine.ASaddBlockedNode(x,22,14);
	engine.ASaddBlockedNode(x,22,15);
	engine.ASaddBlockedNode(x,22,16);
	engine.ASaddBlockedNode(x,22,17);
	engine.ASaddBlockedNode(x,22,18);
	engine.ASaddBlockedNode(x,22,19);
	engine.ASaddBlockedNode(x,22,20);
	engine.ASaddBlockedNode(x,22,21);
	engine.ASaddBlockedNode(x,22,22);
	engine.ASaddBlockedNode(x,22,23);
	engine.ASaddBlockedNode(x,22,24);
	engine.ASaddBlockedNode(x,23,0);
	engine.ASaddBlockedNode(x,23,1);
	engine.ASaddBlockedNode(x,23,2);
	engine.ASaddBlockedNode(x,23,8);
	engine.ASaddBlockedNode(x,23,9);
	engine.ASaddBlockedNode(x,23,10);
	engine.ASaddBlockedNode(x,23,11);
	engine.ASaddBlockedNode(x,23,12);
	engine.ASaddBlockedNode(x,23,13);
	engine.ASaddBlockedNode(x,23,14);
	engine.ASaddBlockedNode(x,23,15);
	engine.ASaddBlockedNode(x,23,16);
	engine.ASaddBlockedNode(x,23,17);
	engine.ASaddBlockedNode(x,23,18);
	engine.ASaddBlockedNode(x,23,19);
	engine.ASaddBlockedNode(x,23,20);
	engine.ASaddBlockedNode(x,23,21);
	engine.ASaddBlockedNode(x,23,22);
	engine.ASaddBlockedNode(x,23,23);
	engine.ASaddBlockedNode(x,23,24);
	engine.ASaddBlockedNode(x,24,0);
	engine.ASaddBlockedNode(x,24,1);
	engine.ASaddBlockedNode(x,24,2);
	engine.ASaddBlockedNode(x,24,3);
	engine.ASaddBlockedNode(x,24,4);
	engine.ASaddBlockedNode(x,24,5);
	engine.ASaddBlockedNode(x,24,6);
	engine.ASaddBlockedNode(x,24,7);
	engine.ASaddBlockedNode(x,24,8);
	engine.ASaddBlockedNode(x,24,9);
	engine.ASaddBlockedNode(x,24,10);
	engine.ASaddBlockedNode(x,24,11);
	engine.ASaddBlockedNode(x,24,12);
	engine.ASaddBlockedNode(x,24,13);
	engine.ASaddBlockedNode(x,24,14);
	engine.ASaddBlockedNode(x,24,15);
	engine.ASaddBlockedNode(x,24,16);
	engine.ASaddBlockedNode(x,24,17);
	engine.ASaddBlockedNode(x,24,18);
	engine.ASaddBlockedNode(x,24,19);
	engine.ASaddBlockedNode(x,24,20);
	engine.ASaddBlockedNode(x,24,21);
	engine.ASaddBlockedNode(x,24,22);
	engine.ASaddBlockedNode(x,24,23);
	engine.ASaddBlockedNode(x,24,24);
}

void initTestAStar(int index)
{
	engine.ASsetStart(index, engine.GOgetGameObjectZPos(index)+offSetX, engine.GOgetGameObjectXPos(index)+offSetY);
	//std::cout << engine.GOgetGameObjectXPos(index) <<" " << engine.GOgetGameObjectZPos(index) <<std::endl;
	engine.ASsetGoal(index, engine.GOgetGameObjectZPos(1)+offSetX, engine.GOgetGameObjectXPos(1)+offSetY);
	engine.ASgenPath(index);
	engine.ASgetNextNode(index);
}

void doTestAStar(int index)
{
	if(!engine.ASgoalNodeHit(index, engine.GOgetGameObjectZPos(index)+offSetX, engine.GOgetGameObjectXPos(index)+offSetY))
	{
		if(!engine.ASnextNodeHit(index, engine.GOgetGameObjectZPos(index)+offSetX, engine.GOgetGameObjectXPos(index)+offSetY))
		{
			float tempX = engine.ASgetDesY(index) - offSetX - engine.GOgetGameObjectXPos(index);
			float tempZ = engine.ASgetDesX(index) - offSetY - engine.GOgetGameObjectZPos(index);
			float tempLength = std::sqrtf(std::powf(tempX, 2) + std::powf(tempZ, 2));
			engine.GOsetGameObjectXPos(index, engine.GOgetGameObjectXPos(index) + ((engine.ASgetDesY(index) - offSetX) / std::abs(tempLength)) * 0.5);
			engine.GOsetGameObjectZPos(index, engine.GOgetGameObjectZPos(index) + ((engine.ASgetDesX(index) - offSetY) / std::abs(tempLength)) * 0.5);
		}
		else
		{
			engine.ASgetNextNode(index);
		}
	}
	else
	{
		// Destination reached.
	}
}

void initEmotions(int index, float sloth, float patience, float stubborness)
{
	
	engine.AIaddPersonalityEmotionCase(index, 0, Personality::TRAIT);
	engine.AIsetPersonalityName(index, 0, Personality::TRAIT, 0, "Sloth");
	engine.AIsetPersonalityAmount(index, 0, Personality::TRAIT, 0, sloth);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::TRAIT, 0, 1.0f);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::TRAIT, 0, 1.0f);
	engine.AIsetPersonalityInterval(index, 0, Personality::TRAIT, 0, 1.0);

	engine.AIaddPersonalityEmotionCase(index, 0, Personality::TRAIT);
	engine.AIsetPersonalityName(index, 0, Personality::TRAIT, 1, "Patience");
	engine.AIsetPersonalityAmount(index, 0, Personality::TRAIT, 1, patience);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::TRAIT, 1, 1.0f);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::TRAIT, 1, 1.0f);
	engine.AIsetPersonalityInterval(index, 0, Personality::TRAIT, 1, 1.0);
	
	engine.AIaddPersonalityEmotionCase(index, 0, Personality::TRAIT);
	engine.AIsetPersonalityName(index, 0, Personality::TRAIT, 2, "Stubborness");
	engine.AIsetPersonalityAmount(index, 0, Personality::TRAIT, 2, stubborness);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::TRAIT, 2, 1.0f);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::TRAIT, 2, 1.0f);
	engine.AIsetPersonalityInterval(index, 0, Personality::TRAIT, 2, 1.0);
	
	engine.AIaddPersonalityEmotionCase(index, 0, Personality::MOOD);
	engine.AIsetPersonalityName(index, 0, Personality::MOOD, 0, "Lathargic");
	engine.AIsetPersonalityAmount(index, 0, Personality::MOOD, 0, 50.0f);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::MOOD, 0, -(((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 0)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::MOOD, 0, (((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 0)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	engine.AIsetPersonalityInterval(index, 0, Personality::MOOD, 0, 1.0);
	
	engine.AIaddPersonalityEmotionCase(index, 0, Personality::MOOD);
	engine.AIsetPersonalityName(index, 0, Personality::MOOD, 1, "Frustration");
	engine.AIsetPersonalityAmount(index, 0, Personality::MOOD, 1, 50.0f);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::MOOD, 1, (((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 1)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::MOOD, 1, -(((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 1)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	engine.AIsetPersonalityInterval(index, 0, Personality::MOOD, 1, 1.0);

	engine.AIaddPersonalityEmotionCase(index, 0, Personality::EMOTION);
	engine.AIsetPersonalityName(index, 0, Personality::EMOTION, 0, "Happiness");
	engine.AIsetPersonalityAmount(index, 0, Personality::EMOTION, 0, 50.0f);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::EMOTION, 0, (engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::EMOTION, 0, -(engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIsetPersonalityInterval(index, 0, Personality::EMOTION, 0, 1.0);

	engine.AIaddPersonalityEmotionCase(index, 0, Personality::EMOTION);
	engine.AIsetPersonalityName(index, 0, Personality::EMOTION, 0, "Anger");
	engine.AIsetPersonalityAmount(index, 0, Personality::EMOTION, 1, 50.0f);
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::EMOTION, 1, -(engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::EMOTION, 1, (engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIsetPersonalityInterval(index, 0, Personality::EMOTION, 1, 1.0);
}

// Make 'em happy, make 'em sad, make 'em angery or not, it's your choice. Call only when making changes to an emotion.
void doEmotions(int index, float happiness, float anger)
{
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::MOOD, 0, -(((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 0)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::MOOD, 0, (((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 0)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::MOOD, 1, (((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 1)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::MOOD, 1, -(((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 1)/50)/4) + ((engine.AIgetPersonalityAmount(1, 0, Personality::TRAIT, 2)/50)/7)));

	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::EMOTION, 0, (engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::EMOTION, 0, -(engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIaddToPersonalityEffectQueue(index, 0, Personality::EMOTION, 0, happiness);
	if (happiness < 0)
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 0, happiness * (1 + engine.AIgetPersonalityNegativeModifier(index,0, Personality::EMOTION, 0)));
	}
	else
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 0, happiness * (1 + engine.AIgetPersonalityPositiveModifier(index,0, Personality::EMOTION, 0)));
	}
	if (-happiness < 0)
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 1, -happiness * (1 + engine.AIgetPersonalityNegativeModifier(index,0, Personality::EMOTION, 0)));
	}
	else
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 1, -happiness * (1 + engine.AIgetPersonalityPositiveModifier(index,0, Personality::EMOTION, 0)));
	}
	
	engine.AIsetPersonalityNegativeModifier(index, 0, Personality::EMOTION, 1, -(engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIsetPersonalityPositiveModifier(index, 0, Personality::EMOTION, 1, (engine.AIgetPersonalityAmount(1, 0, Personality::MOOD, 1)/50)/2);
	engine.AIaddToPersonalityEffectQueue(index, 0, Personality::EMOTION, 01, anger);
	if (-anger < 0)
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 0, -anger * (1 + engine.AIgetPersonalityNegativeModifier(index,0, Personality::EMOTION, 1)));
	}
	else
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 0, -anger * (1 + engine.AIgetPersonalityPositiveModifier(index,0, Personality::EMOTION, 1)));
	}
	if (anger < 0)
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 1, anger * (1 + engine.AIgetPersonalityNegativeModifier(index,0, Personality::EMOTION, 1)));
	}
	else
	{
		engine.AIaddToPersonalityEffectQueue(index, 0, Personality::MOOD, 1, anger * (1 + engine.AIgetPersonalityPositiveModifier(index,0, Personality::EMOTION, 1)));
	}
}

// Must call in main loop. Constrains mood and emotion values to between 0 and 100.
void emotionValidation(int index)
{
	for (int i = 0; i <= 1; ++i)
	{
		if(engine.AIgetPersonalityAmount(index, 0, Personality::MOOD, i) < 0)
		{
			engine.AIsetPersonalityAmount(index, 0, Personality::MOOD, i, 0);
		}
		else if(engine.AIgetPersonalityAmount(index, 0, Personality::MOOD, i) > 100)
		{
			engine.AIsetPersonalityAmount(index, 0, Personality::MOOD, i, 100);
		}
		if(engine.AIgetPersonalityAmount(index, 0, Personality::EMOTION, i) < 0)
		{
			engine.AIsetPersonalityAmount(index, 0, Personality::EMOTION, i, 0);
		}
		else if(engine.AIgetPersonalityAmount(index, 0, Personality::EMOTION, i) > 100)
		{
			engine.AIsetPersonalityAmount(index, 0, Personality::EMOTION, i, 100);
		}
	}
}