#include "pch.h"
#include <iostream>
void Init() // Initiating the initial selection for the graphical environment
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void ReShape(int width, int height) // Setting View Mode
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
void DrawCoordinate()
{
	//Ox
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();
	//Oy
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();
	//Oz
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();
}
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//Camera
	gluLookAt(15.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//Move
	/*glPushMatrix();
	DrawCoordinate();
	glTranslatef(5.0, 0.0, 0.0);
		glPushMatrix();
			glTranslatef(0.0, 0.0, 3.0);
			glColor3f(1.0, 1.0, 0.0);
			glutWireTeapot(1.0);
		glPopMatrix();
		glColor3f(1.0, 0.0, 1.0);
		glutWireTeapot(2.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, -3.0);
		glColor3f(1.0, 0.0, 0.0);
		glutWireTeapot(1.0);
	glPopMatrix();*/

	//Rotate
	glPushMatrix();
	DrawCoordinate();
	glRotatef(45.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 0.0); // Yellow
	glutWireTeapot(1.0);
	glPopMatrix();
	glFlush();
}
int main()
{
	//Create a Windows to run OpenGL Program
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single Basic-color
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Drawing Basic Shapes");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);

	glutMainLoop();
	return 0;
}