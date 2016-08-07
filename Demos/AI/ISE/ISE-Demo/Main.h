#pragma once

#include "ISE.h"
#include "fstream"
#include <math.h>

int winWidth = 1600;
int winHeight = 900;
bool gameEnd = false;

void updateInput(ISE &engine, bool &run, float dt);
void doTestAI(float dt);
void setBlockedNodes(int x);
void initTestAStar(int index);
void doTestAStar(int index);
void initEmotions(int index, float sloth, float patience, float stubborness);
void doEmotions(int index, float happiness, float anger);
void emotionValidation(int index);

ISE engine;