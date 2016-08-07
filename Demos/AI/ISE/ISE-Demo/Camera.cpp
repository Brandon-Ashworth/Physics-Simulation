#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	camMode = FREECAM;
	reset();
	setPerspective();
	m_vecArray = new float[16];
}

Camera::~Camera()
{
}

void Camera::reset()
{
	m_Position.x = 0.0;
	m_Position.y = 0.0;
	m_Position.z = 0.0;
	m_Focus.x = 100.0;
	m_Focus.y = 0.0;
	m_Focus.z = 0.0;
	m_Up.x = 0.0;
	m_Up.y = 1.0;
	m_Up.z = 0.0;
	m_VertRotation = 0.0;
	m_VertRotFootPrint = 0.0;
	m_HorRotation = 0.0;
	m_FOV = 75.0;
	m_Ratio = 1.0;
	m_Near = 0.1;
	m_Far = 7500.0;
}

Vector3 Camera::getPos()
{
	return m_Position;
}

float Camera::getPosX()
{
	return m_Position.x;
}

float Camera::getPosY()
{
	return m_Position.y;
}

float Camera::getPosZ()
{
	return m_Position.z;
}

void Camera::setPos(Vector3 v)
{
	m_Position.x = v.x;
	m_Position.y = v.y;
	m_Position.z = v.z;
}

void Camera::setPos(float x, float y, float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
}

Vector3 Camera::getFocus()
{
	return m_Focus;
}

float Camera::getFocusX()
{
	return m_Position.x;
}

float Camera::getFocusY()
{
	return m_Position.y;
}

float Camera::getFocusZ()
{
	return m_Position.z;
}

void Camera::setFocus(Vector3 v)
{
	m_Focus.x = v.x;
	m_Focus.y = v.y;
	m_Focus.z = v.z;
}

void Camera::setFocus(float x, float y, float z)
{
	m_Focus.x = x;
	m_Focus.y = y;
	m_Focus.z = z;
}

Vector3 Camera::getUp()
{
	return m_Up;
}

float Camera::getUpX()
{
	return m_Up.x;
}

float Camera::getUpY()
{
	return m_Up.y;
}

float Camera::getUpZ()
{
	return m_Up.z;
}

void Camera::setUp(Vector3 v)
{
	m_Up.x = v.x;
	m_Up.y = v.y;
	m_Up.z = v.z;
}

void Camera::setUp(float x, float y, float z)
{
	m_Up.x = x;
	m_Up.y = y;
	m_Up.z = z;
}

void Camera::setCamMode(cameraMode m)
{
	camMode = m;
}

void Camera::updateCamera()
{
	//glEnable(GL_NORMALIZE);
	glGetFloatv(GL_MODELVIEW_MATRIX, m_vecArray);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_Position.x, m_Position.y, m_Position.z,
			  m_Focus.x   , m_Focus.y   , m_Focus.z,
			  m_Up.x      , m_Up.y      , m_Up.z);
	//glDisable(GL_NORMALIZE);
}

void Camera::moveForward(float amount)
{
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamMoveForward(amount);
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			FPSCamMoveForward(amount);
			break;
		}
	}
}

void Camera::moveRight(float amount)
{
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamMoveRight(amount);
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			FPSCamMoveRight(amount);
			break;
		}
	}
}

void Camera::moveUp(float amount)
{
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamMoveUp(amount);
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			break;
		}
	}
}

void Camera::rotateDown(float amount)
{
	m_VertRotation -= amount*((float)M_PI/180.0);
	//m_HorRotation = 0;
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamRotate();
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			//m_VertRotFootPrint += m_VertRotation;
			if(m_VertRotation > 84.0*((float)M_PI/180.0))
			{
				//m_VertRotFootPrint = 89.99*(M_PI/180);
				m_VertRotation = 84.0*((float)M_PI/180.0);
			}
			if(m_VertRotation < -84.0*((float)M_PI/180.0))
			{
				//m_VertRotFootPrint = -89.99*(M_PI/180);
				m_VertRotation = -84.0*((float)M_PI/180.0);
			}
			freeCamRotate();
			break;
		}
	}
}

void Camera::rotateRight(float amount)
{
	//m_VertRotation = 0;
	m_HorRotation += amount*((float)M_PI/180.0);
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamRotate();
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			freeCamRotate();
			break;
		}
	}
}

void Camera::freeCamMoveForward(float amount)
{
	m_Position.x += -m_vecArray[2] * amount;
	m_Position.y += -m_vecArray[6] * amount;
	m_Position.z += -m_vecArray[10] * amount;
	m_Focus.x += -m_vecArray[2] * amount;
	m_Focus.y += -m_vecArray[6] * amount;
	m_Focus.z += -m_vecArray[10] * amount;
}

void Camera::freeCamMoveRight(float amount)
{
	m_Position.x += m_vecArray[0] * amount;
	m_Position.y += m_vecArray[4] * amount;
	m_Position.z += m_vecArray[8] * amount;
	m_Focus.x += m_vecArray[0] * amount;
	m_Focus.y += m_vecArray[4] * amount;
	m_Focus.z += m_vecArray[8] * amount;
}

void Camera::freeCamRotate()
{
	Vector3 tempVec;
	Vector3 tempVec2;
	/*
	tempVec.z = m_Focus.z-m_Position.z;
	tempVec.x = ((m_Focus.x-m_Position.x)*(float)cos(m_VertRotation*M_PI/180)) + ((m_Focus.y-m_Position.y)*(float)sin(m_VertRotation*M_PI/180));
	tempVec.y = ((m_Focus.x-m_Position.x)*(float)-sin(m_VertRotation*M_PI/180)) + ((m_Focus.y-m_Position.y)*(float)cos(m_VertRotation*M_PI/180));

	m_Focus.z = (tempVec.z*(float)cos(m_HorRotation*M_PI/180) + (tempVec.x*(float)sin(m_HorRotation*M_PI/180))) + m_Position.z;
	m_Focus.x = (tempVec.z*(float)-sin(m_HorRotation*M_PI/180)) + (tempVec.x*(float)cos(m_HorRotation*M_PI/180)) + m_Position.x;
	m_Focus.y = tempVec.y + m_Position.y;
	*/

	m_Focus.y = m_Position.y+(float)(sin(m_VertRotation));
	m_Focus.x = m_Position.x+(float)(cos(m_VertRotation)*cos(m_HorRotation));
	m_Focus.z = m_Position.z+(float)(cos(m_VertRotation)*sin(m_HorRotation));

	m_Up.x = m_Position.x-m_Focus.x;
	m_Up.y = abs(m_Position.y+(float)(100*sin(m_VertRotation+M_PI/2))) ;
	m_Up.z = m_Position.z-m_Focus.z;

	/*
	tempVec.z = ((m_Focus.z-m_Position.z)*(float)cos(m_HorRotation*M_PI/180)) + ((m_Focus.x-m_Position.x)*(float)sin(m_HorRotation*M_PI/180));
	tempVec.x = ((m_Focus.z-m_Position.z)*(float)(-sin(m_HorRotation*M_PI/180))) + ((m_Focus.x-m_Position.x)*(float)cos(m_HorRotation*M_PI/180));
	tempVec.y = m_Focus.y - m_Position.y;

	tempVec2.z = (tempVec.z*(float)cos(m_VertRotation*M_PI/180)) + (tempVec.y*(float)(-sin(m_VertRotation*M_PI/180)));
	tempVec2.x = tempVec.x;
	tempVec2.y = (tempVec.z*(float)sin(m_VertRotation*M_PI/180)) + (tempVec.y*(float)cos(m_VertRotation*M_PI/180));

	m_Focus.z = tempVec2.z + m_Position.z;
	m_Focus.x = (tempVec2.x*(float)cos(m_VertRotation*M_PI/180) + (tempVec2.y*(float)sin(m_VertRotation*M_PI/180))) + m_Position.x;
	m_Focus.y = (tempVec2.x*(float)(-sin(m_VertRotation*M_PI/180)) + (tempVec2.y*(float)cos(m_VertRotation*M_PI/180))) + m_Position.y;
	*/
}

void Camera::freeCamMoveUp(float amount)
{
	m_Position.x += m_vecArray[1] * amount;
	m_Position.y += m_vecArray[5] * amount;
	m_Position.z += m_vecArray[9] * amount;
	m_Focus.x += m_vecArray[1] * amount;
	m_Focus.y += m_vecArray[5] * amount;
	m_Focus.z += m_vecArray[9] * amount;
}

void Camera::FPSCamMoveForward(float amount)
{
	float tempFloat = 1/(sqrt(pow(-m_vecArray[10], 2) + pow(-m_vecArray[2], 2) + pow(-m_vecArray[6], 2)));

	Vector3 tempVec;
	tempVec.x = -m_vecArray[2] * tempFloat;
	tempVec.z = -m_vecArray[10] * tempFloat;

	m_Position.x += tempVec.x * amount;
	m_Position.z += tempVec.z * amount;
	m_Focus.x += tempVec.x * amount;
	m_Focus.z += tempVec.z * amount;
}

void Camera::FPSCamMoveRight(float amount)
{
	m_Position.x += m_vecArray[0] * amount;
	m_Position.z += m_vecArray[8] * amount;
	m_Focus.x += m_vecArray[0] * amount;
	m_Focus.z += m_vecArray[8] * amount;
}

void Camera::setCamPerspectives(float fov, float ratio, float cnear, float cfar)
{
	m_FOV = fov;
	m_Ratio = ratio;
	m_Near = cnear;
	m_Far = cfar;
	setPerspective();
}

void Camera::setCamOrtho2D(float left, float right, float down, float up)
{
	m_Left = left;
	m_Right = right;
	m_Down = down;
	m_Top = up;
}

void Camera::setFOV(float fov)
{
	m_FOV = fov;
	setPerspective();
}

void Camera::setRatio(float ratio)
{
	m_Ratio = ratio;
	setPerspective();
}

void Camera::setNear(float cnear)
{
	m_Near = cnear;
	setPerspective();
}

void Camera::setFar(float cfar)
{
	m_Far = cfar;
	setPerspective();
}

void Camera::setPerspective()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(m_FOV, m_Ratio, m_Near, m_Far);
}

void Camera::setOrtho2DBegin()
{
	//glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		OPENGL_Facade::ortho2DRender(m_Left, m_Right, m_Down, m_Top);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			glTranslatef(0, 0, 0);
}

void Camera::setOrtho2DEnd()
{
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}