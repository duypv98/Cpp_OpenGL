#include "pch.h"
#include <iostream>

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Switch on the light
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	//Choose the light source position
	GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	//Object Material
	GLfloat ambient[] = { 1.0, 1.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	
	GLfloat diff_use[] = { 0.5, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
}
	
void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (GLfloat)width / (GLfloat)height;
	gluPerspective(45.0, ratio, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
void DrawCoordinate()
{
	glDisable(GL_LIGHTING);
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
	glEnable(GL_LIGHTING);
}
void RenderScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	DrawCoordinate();
	glColor3f(1.0, 1.0, 0.0);
	glutSolidTeapot(2.5);
	glPopMatrix();
	glFlush();
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lightning");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);
	glutMainLoop();

	return 0;
}