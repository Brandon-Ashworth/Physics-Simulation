#include "RenderEngine.h"


RenderEngine::RenderEngine(void)
{
}


RenderEngine::~RenderEngine(void)
{
}

void RenderEngine::create(int width, int height, std::string name)
{
	window.create(width, height, name);
	window.active();
	window.colourDepth();
	window.enableDepth();
	//window.disableLighting();
	depth = true;
	Light = false;
	focus = false;
	update();
}

void RenderEngine::display()
{
	window.display();
}

int RenderEngine::getWidth()
{
	return(window.getWidth());
}

void RenderEngine::setWidth(int w)
{
	window.setWidth(w);
}

int RenderEngine::getHeight()
{
	return(window.getHeight());
}

void RenderEngine::setHeight(int h)
{
	window.setHeight(h);
}

void RenderEngine::setTitle(std::string t)
{
	window.setTitle(t);
}

void RenderEngine::setWinPos(int x, int y)
{
	window.setWindowPos(x,y);
}

void RenderEngine::getWinPos(int &x, int &y)
{
	window.getWindowPos(x,y);
}

void RenderEngine::setDepth(bool on)
{
	depth = on;
	if (on)
		window.enableDepth();
	else
		window.disableDepth();
}

bool RenderEngine::getDepth()
{
	return(depth);
}

void RenderEngine::setLighting(bool on)
{
	Light = on;
	if(on)
		window.enableLighting();
	//else
		//window.disableLighting();
}

bool RenderEngine::getLighting()
{
	return(Light);
}

bool RenderEngine::getFocus()
{
	update();
	//return (focus);
	return(true);
}

void RenderEngine::update()
{
	window.update();
	camera.updateCamera();
	//window.display();
	//focus = window.getFocus();
}

void RenderEngine::translate(float x, float y, float z)
{
	render.translate(x,y,z);
}

void RenderEngine::rotate(Axis axis, float angle)
{
	render.rotate(axis,angle);
}

void RenderEngine::setWireFrame(bool enable)
{
	wireframe = enable;
	render.setWireFrame(enable);
}

bool RenderEngine::getWireFrame()
{
	return wireframe;
}

void RenderEngine::renderV(VAO &data)
{
	render.render(data);
}

void RenderEngine::bindTex(Texture &tex)
{
	render.bindTex(tex);
}

void RenderEngine::setCameraPosition(float x, float y, float z)
{
	camera.setPos(x, y, z);
}

float RenderEngine::getCameraPositionX()
{
	return camera.getPosX();
}

float RenderEngine::getCameraPositionY()
{
	return camera.getPosY();
}

float RenderEngine::getCameraPositionZ()
{
	return camera.getPosZ();
}

void RenderEngine::setCameraFocus(float x, float y, float z)
{
	camera.setFocus(x, y, z);
}

float RenderEngine::getCameraFocusX()
{
	return camera.getFocusX();
}

float RenderEngine::getCameraFocusY()
{
	return camera.getFocusY();
}

float RenderEngine::getCameraFocusZ()
{
	return camera.getFocusZ();
}

void RenderEngine::setCameraUp(float x, float y, float z)
{
	camera.setUp(x, y, z);
}

float RenderEngine::getCameraUpX()
{
	return camera.getUpX();
}

float RenderEngine::getCameraUpY()
{
	return camera.getUpY();
}

float RenderEngine::getCameraUpZ()
{
	return camera.getUpZ();
}

void RenderEngine::setCameraMode(Camera::cameraMode m)
{
	camera.setCamMode(m);
}

void RenderEngine::moveCameraForward(float x)
{
	camera.moveForward(x);
}

void RenderEngine::moveCameraLeft(float x)
{
	camera.moveRight(x);
}

void RenderEngine::moveCameraUp(float x)
{
	camera.moveUp(x);
}

void RenderEngine::rotateCameraUp(float x)
{
	camera.rotateDown(-x);
}

void RenderEngine::rotateCameraLeft(float x)
{
	camera.rotateRight(-x);
}

void RenderEngine::setPerspective(float fov, float ratio, float cnear, float cfar)
{
	camera.setCamPerspectives(fov, ratio, cnear, cfar);
}

void RenderEngine::setOrtho2D(float left, float right, float down, float up)
{
	camera.setCamOrtho2D(left, right, down, up);
}

void RenderEngine::Ortho2DBegin()
{
	camera.setOrtho2DBegin();
}

void RenderEngine::Ortho2DEnd()
{
	camera.setOrtho2DEnd();
}

void RenderEngine::scale(float x, float y, float z)
{
	render.scale(x,y,z);
}