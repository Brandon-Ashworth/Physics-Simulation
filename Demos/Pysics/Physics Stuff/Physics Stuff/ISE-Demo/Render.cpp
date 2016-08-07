#include "Render.h"



Render::Render(void)
{
	 rotX = false;
	 rotY= false;
	 rotZ= false;

	angX = 0;
	angY= 0;
	angZ= 0;

	tran= false;
	tranX= 0;
	tranY= 0;
	tranZ= 0;

	texture = true;

	scaleX = 1;
	scaleY = 1;
	scaleZ = 1;
	isScaled = false;
	
}


Render::~Render(void)
{
}

void Render::translate(float x, float y, float z)
{
	tran = true;
	tranX = x;
	tranY = y;
	tranZ = z;
}

void Render::rotate(Axis axis, float angle)
{
	switch(axis)
	{
	case xAxis:
		angX = angle;
		rotX = true;
		break;
	case yAxis:
		angY = angle;
		rotY = true;
		break;
	case zAxis:
		angZ = angle;
		rotZ =  true;
		break;
	default:
		//error
		break;
	}
}

void Render::setWireFrame(bool enable)
{
	if(enable)
	{
		OPENGL_Facade::enableWire();
	}
	else
	{
		OPENGL_Facade::disableWire();
	}
}

void Render::bindTex(Texture &tex)
{
	//texture = true;
	//OPENGL_Facade::enableTexture();
	
	//tex.bind();
}

void Render::setColour(float R, float G, float B)
{
	//OPENGL_Facade::polyColour(R,G,B);
}

void Render::render(VAO &data)
{
	OPENGL_Facade::enableTexture();
	OPENGL_Facade::pushMatrix();
	
	if(isScaled)
	{
		OPENGL_Facade::Normalize(true);
		OPENGL_Facade::scale(scaleX,scaleY,scaleZ);
	}
	if (tran)
	{
		OPENGL_Facade::transform(tranX,tranY,tranZ);
	}
	if(rotX)
	{
		OPENGL_Facade::rotate(angX,1.f,0.0,0.0);
	}
	if(rotY)
	{
		OPENGL_Facade::rotate(angY,0.f,1.f,0.f);
	}
	if(rotZ)
	{
		OPENGL_Facade::rotate(angZ,0.f,0.f,1.f);
	}
	OPENGL_Facade::render(data);

	//disable things
	OPENGL_Facade::Normalize(false);
	OPENGL_Facade::popMatrix();
	//after pop
	tran = false;
	rotX = false;
	rotY = false;
	rotZ = false;

	scaleDefault();

	texture = false;
	OPENGL_Facade::polyColour(1.f,1.f,1.f);
	//OPENGL_Facade::disableTexture();
}

void Render::scale(float x, float y, float z)
{
	scaleX = x;
	scaleY = y;
	scaleZ = z;

	if(scaleX <= 0)
	{
		scaleX = 1;
	}
	if(scaleY <= 0)
	{
		scaleY = 1;
	}
	if(scaleZ <= 0)
	{
		scaleZ = 1;
	}

	isScaled = true;

}

void Render::scaleDefault()
{
	scaleX = 1;
	scaleY = 1;
	scaleZ = 1;
	isScaled=false;
}