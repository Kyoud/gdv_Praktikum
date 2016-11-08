#include "Flugzeug.h"
void Flugzeug(int r, int g, int b, float rotatepropeller){
	glColor4f(r, g, b, 1.0);
	glPushMatrix();
	gluCylinder(gluNewQuadric(),0.3,0.3,1,12,4);

	glPushMatrix();
	glColor4f(r, g, b, 1.0);
	glTranslatef(0, 0, -0.7);
	gluCylinder(gluNewQuadric(), 0, 0.3, 0.7, 12, 4);
	glPopMatrix();

	glPushMatrix();
	glColor4f(r, g, b, 1.0);
	glTranslatef(0, 0, 1);
	gluCylinder(gluNewQuadric(), 0.3, 0, 0, 12, 4);
	glPopMatrix();


	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(r, g, b, 1.0);
	glVertex3f(0.3, 0, -0);
	glVertex3f(1, 0, 0.5);
	glVertex3f(1, 0, 0.7);
	glVertex3f(0.3, 0, 0.5);

	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(r, g, b, 1.0);
	glVertex3f(-0.3, 0, -0);
	glVertex3f(-1, 0, 0.5);
	glVertex3f(-1, 0, 0.7);
	glVertex3f(-0.3, 0, 0.5);

	glEnd();
	glPushMatrix();
	glScalef(1, 0.8, 0.8);
	glRotatef(-90, 0, 0, 1);
	glTranslatef(0, 0, 0.6);

	glBegin(GL_POLYGON);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glColor4f(r, g, b, 1.0);
	glVertex3f(-0.3, 0, -0);
	glVertex3f(-1, 0, 0.5);
	glVertex3f(-1, 0, 0.7);
	glVertex3f(-0.3, 0, 0.5);

	glEnd();
	glPopMatrix();

	glPushMatrix();//propeller
	glRotatef(rotatepropeller, 0, 0, 1);
	glTranslatef(0, 0, -0.7);
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glColor4f(r, g, b, 1.0);
	glVertex3f(-0.5, 0.05, 0);
	glVertex3f(0.5, 0.05, 0);
	glVertex3f(0.5, -0.05, 0);
	glVertex3f(-0.5, -0.05, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}
