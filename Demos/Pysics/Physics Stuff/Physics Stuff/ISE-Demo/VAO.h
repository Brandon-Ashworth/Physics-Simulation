#pragma once

#include <string>

class structure
{

};

class VAO: public structure
{
public:
	float *vertexArray;
	float *normalArray;
	float *uvArray;
	int numVerts;
};


class Error: public structure
{
public:
	std::string error;
};