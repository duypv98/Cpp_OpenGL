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

	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	glMatrixMode(GL_MODELVIEW);
}
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	/*
	// Drawing Points
	glBegin(GL_POINTS);
	glPointSize(3.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 0.0, 0.0);
	glEnd();
	//Drawing Lines
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);
	glEnd();
	//Drawing Triangles
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-5.0, 0.0, 0.0);
	glVertex3f(-5.0, 5.0, 0.0);
	glEnd(); 
	//Drawing Line Strip
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, 1.0, 0.0);
	glVertex3f(1.0, 2.0, 0.0);
	glEnd();
	//Drawing Line Loop with Color
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.5, 0.5);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, 1.0, 0.0);
	glVertex3f(1.0, 2.0, 0.0);
	glEnd();*/
	//Example OpenGL Model
	glColor3f(1.0, 0.0, 0.0);
	//glutSolidCube(2.0);
	//glutWireTeapot(3.0);
	//glutWireTorus(2.0, 4.0, 16, 16);
	glutWireCone(3.0, 5.0, 12, 12);
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