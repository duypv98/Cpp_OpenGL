// OpenGLSetup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
}
void RenderScene() 
{
	glutWireTeapot(2.0);
	glFlush();
}
int main()
{
    //Create a Windows to run OpenGL Program
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single Basic-color
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Test");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);

	glutMainLoop();
	return 0;
}