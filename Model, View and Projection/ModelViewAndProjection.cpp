#include "pch.h"
#include <iostream>

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	//glFrustum(-10.0, 10.0, -10, 10, 1.0, 8.0);
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
	gluLookAt(15.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	DrawCoordinate();
	glColor3f(1.0, 1.0, 1.0);
	glutWireTeapot(2.0);
	glPopMatrix();
	glFlush();
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Model_View And Projection");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);
	glutMainLoop();

	return 0;
}