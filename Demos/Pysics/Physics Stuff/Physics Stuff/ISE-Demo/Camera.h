#pragma once
#include "Vector3.h"
#include <SFML\OpenGL.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include "OPENGL_Facade.h"

/**
 *  \brief The Camera class
 *  
 *  \bug
 *  \note
 *  \author Welsley Gai-Yeen Lui
 *  \date 
 */
class Camera
{
public:
	enum cameraMode
	{
		FREECAM, ORBIT, FPS
	};

	/**
	 * \brief Default constructor of Camera class
	 */
	Camera();
	
	/**
	 * \brief Default destructor of Camera class
	 */
	~Camera();
	
	/**
	 * \brief The reset function for the Camera class
	 */
	void reset();
	
	/**
	 * \brief Get camera positions by Vector3
	 */
	Vector3 getPos();

	/**
	 * \brief Get camera x position as a float
	 */
	float getPosX();

	/**
	 * \brief Get camera y position as a float
	 */
	float getPosY();

	/**
	 * \brief Get camera z position as a float
	 */
	float getPosZ();

	/**
	 * \brief Set camera positions with a Vector3
	 */
	void setPos(Vector3 v);

	/**
	 * \brief Set camera positions with three floats
	 */
	void setPos(float x, float y, float z);

	/**
	 * \brief Get camera focus positions by Vector3
	 */
	Vector3 getFocus();

	/**
	 * \brief Get camera x focus position as a float
	 */
	float getFocusX();

	/**
	 * \brief Get camera y focus position as a float
	 */
	float getFocusY();

	/**
	 * \brief Get camera z focus position as a float
	 */
	float getFocusZ();

	/**
	 * \brief Set camera focus positions with a Vector3
	 */
	void setFocus(Vector3 v);

	/**
	 * \brief Set camera focus positions with three floats
	 */
	void setFocus(float x, float y, float z);

	/**
	 * \brief Get camera up positions by Vector3
	 */
	Vector3 getUp();

	/**
	 * \brief Get camera x up position as a float
	 */
	float getUpX();

	/**
	 * \brief Get camera y up position as a float
	 */
	float getUpY();

	/**
	 * \brief Get camera z up position as a float
	 */
	float getUpZ();

	/**
	 * \brief Set camera up positions with a Vector3
	 */
	void setUp(Vector3 v);

	/**
	 * \brief Set camera up positions with three floats
	 */
	void setUp(float x, float y, float z);
	
	/**
	 * \brief Set camera mode
	 */
	void setCamMode(cameraMode m);

	/**
	 * \brief Function for updating the camera
	 */
	void updateCamera();
	
	/**
	 * \brief Function for moving the camera forward
	 */
	void moveForward(float amount);
	
	/**
	 * \brief Function for moving the camera to the right
	 */
	void moveRight(float amount);
	
	/**
	 * \brief Function for rotating the camera down
	 */
	void rotateDown(float amount);
	
	/**
	 * \brief Function for rotating the camera to the right
	 */
	void rotateRight(float amount);
	
	/**
	 * \brief Function for moving the camera up
	 */
	void moveUp(float amount);

	/**
	 * \brief Function for setting the camera perspective
	 */
	void setCamPerspectives(float fov, float ratio, float cnear, float cfar);
	
	/**
	 * \brief Function for setting the camera Field Of Vision
	 */
	void setFOV(float fov);
	
	/**
	 * \brief Function for setting the camera perspective ratio
	 */
	void setRatio(float ratio);
	
	/**
	 * \brief Function for setting the camera near clipping (has to be a positive number!)
	 */
	void setNear(float near);
	
	/**
	 * \brief Function for setting the camera far clipping (has to be a positive number!)
	 */
	void setFar(float Far);

	void setCamOrtho2D(float left, float right, float down, float up);
	void setOrtho2DBegin();
	void setOrtho2DEnd();



private:
	void freeCamMoveForward(float amount);
	void freeCamMoveRight(float amount);
	void freeCamRotate();
	void freeCamMoveUp(float amount);
	void FPSCamMoveForward(float amount);
	void FPSCamMoveRight(float amount);
	void setPerspective();

	Vector3 m_Position;
	Vector3 m_Focus;
	Vector3 m_Up;
	cameraMode camMode;
	float m_VertRotation;
	float m_VertRotFootPrint;
	float m_HorRotation;
	float m_FOV;
	float m_Ratio;
	float m_Near;
	float m_Far;
	float m_Left;
	float m_Right;
	float m_Down;
	float m_Top;
	float *m_vecArray;
};