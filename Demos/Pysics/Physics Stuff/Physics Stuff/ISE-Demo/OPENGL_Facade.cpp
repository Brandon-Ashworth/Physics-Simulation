#include "OPENGL_Facade.h"


OPENGL_Facade::OPENGL_Facade(void)
{
	//call the init and set the modelview matrix
}


OPENGL_Facade::~OPENGL_Facade(void)
{
}

bool OPENGL_Facade::colour(float R, float G, float B)
{
	glClearColor(R,G,B,0.f);;
	return (true);
}


bool OPENGL_Facade::Depth(float Depth)
{
	glClearDepth(Depth);
	return (true);
}


bool OPENGL_Facade::colourDepth()
{
	glClearDepth(1.f);
	glClearColor(0.f,0.f,0.f,0.f);
	return (true);
}


bool OPENGL_Facade::enableDepth()
{
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE); // ebable writing to the depth buffer
	return (true);
}


bool OPENGL_Facade::disableDepth()
{
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);// disable writing to the depth buffer
	return (true);
}


bool OPENGL_Facade::enableLighting()
{
	glEnable(GL_LIGHTING);
	return (true);
}


bool OPENGL_Facade::disableLighting()
{
	glDisable(GL_LIGHTING);
	return (true);
}


bool OPENGL_Facade::ModelMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	return (true);
}


bool OPENGL_Facade::ProjectionMatrix()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	return (true);
}

bool OPENGL_Facade::perspective(float fov, float aspect, float zNear, float zFar)
{
	pushMatrix(); // push the current matrix probably specified by the user
	ProjectionMatrix(); // set to Projection matrix and load the identity
	gluPerspective(fov,aspect,zNear,zFar); // set the perspective
	ModelMatrix(); // the default should be left on model view matrix
	popMatrix(); // pop the user matrix perspective back
	return (true);
}


bool OPENGL_Facade::viewport(int width, int height)
{
	//the default matrix should be model view
	pushMatrix();
	glViewport(0,0,width,height);
	popMatrix();
	return (true);
}

bool OPENGL_Facade::pushMatrix()
{
	glPushMatrix();
	return (true);
}

bool OPENGL_Facade::popMatrix()
{
	glPopMatrix();
	return (true);
}

bool OPENGL_Facade::rotate(float angle, float xAxis, float yAxis, float zAxis)
{
	glRotatef(angle,xAxis,yAxis,zAxis);
	return (true);
}

bool OPENGL_Facade::transform(float xAxis, float yAxis, float zAxis)
{
	glTranslatef(xAxis,yAxis,zAxis);
	return (true);
}

bool OPENGL_Facade::scale(float xAxis, float yAxis, float zAxis)
{
	glScalef(xAxis,yAxis,zAxis);
	return (true);
}

void OPENGL_Facade::enableWire()
{
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

void OPENGL_Facade::disableWire()
{
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void OPENGL_Facade::render(VAO &data)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3,GL_FLOAT,0,data.vertexArray);
	glNormalPointer(GL_FLOAT,0,data.normalArray);
	glTexCoordPointer(2,GL_FLOAT,0,data.uvArray);

	glDrawArrays(GL_TRIANGLES,0,data.numVerts);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void OPENGL_Facade::polyColour(float R, float G, float B)
{
	glColor3f(R,G,B);
}

void OPENGL_Facade::enableTexture()
{
	glEnable(GL_TEXTURE_2D);
}
void OPENGL_Facade::disableTexture()
{
	glDisable(GL_TEXTURE_2D);
}

void OPENGL_Facade::update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ModelMatrix();
}

void OPENGL_Facade::ortho2DRender(int left, int right,int bottom, int top)
{
	gluOrtho2D(left,right,bottom,top);
}

void OPENGL_Facade::ortho2DRender(int width, int height)
{
	gluOrtho2D(0,width,0,height);
}

void OPENGL_Facade::Normalize(bool norm)
{
	if(norm)
	{
		glEnable(GL_NORMALIZE);
	}
	else
	{
		glDisable(GL_NORMALIZE);
	}
}