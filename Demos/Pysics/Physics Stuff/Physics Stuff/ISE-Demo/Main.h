#pragma once

#include <vector>

#include "ISE.h"
#include "fstream"

int winWidth = 1920;
int winHeight = 1080;
bool gameEnd = false;
//std::vector<Box*> boxes;
int a = 16;
int b = 2;

void updateInput(ISE &engine, bool &run, float &dt);
void updateModels(ISE &engine, float &dt);
void generateContacts(ISE &engine);
void updateObjects(ISE &engine, float &dt);
void update(ISE &engine, float &dt);
void fire(ISE &engine);
void drawContacts(ISE &engine);
void setupBoundingVolumes(ISE &engine);