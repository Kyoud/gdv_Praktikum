// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //l�dt alles f�r OpenGL
#include "Wuerfel.h"

float fRotation = 315.0;

float savex = 0;
float savez = 0;
float drivingx = 3.5;
float drivingz = 0.4;
float rotatea = 0;

float drivingxb = 2.5;
float drivingzb = 0.4;
float rotateb = 0;
int a = 0;
int b = 0;

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgef�hrt werden m�ssen
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
}

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   //

   glClearColor(0, .5, .8, 1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   gluLookAt(0, 9, 15, 0, 0, 0, 0, 1, 0);
   //glTranslatef(0, 0, -0.5);
   

   glPushMatrix();
  
   glTranslatef(drivingxb, 0.2, drivingzb);
   Wuerfel(0.4);
   glPopMatrix();


   glPushMatrix();
   glTranslatef(drivingx, 0.2, drivingz);
   glRotatef(rotatea, 0, 1, 0);
   Wuerfel(0.4);
   glPopMatrix();


   glPushMatrix();
   glBegin(GL_POLYGON);
   glColor4f(1, 1, 1, 1.0);
   glVertex3f(2, 0.01, -0.2);
   glVertex3f(4, 0.01, -0.2);
   glVertex3f(4, 0.01, 0.2);
   glVertex3f(2, 0.01, 0.2);

   glEnd();

   glBegin(GL_LINE_LOOP);
   glColor4f(1, 1, 1, 1.0);
   glVertex3f(-3, 0.01, -3);
   glVertex3f(3, 0.01, -3);
   glVertex3f(3, 0.01, 3);
   glVertex3f(-3, 0.01, 3);

   glEnd();

   glBegin(GL_LINE_LOOP);
   glColor4f(0, 0, 0, 1.0);
   glVertex3f(-4, 0.01, -4);
   glVertex3f(4, 0.01, -4);
   glVertex3f(4, 0.01, 4);
   glVertex3f(-4, 0.01, 4);

   glEnd();

   glBegin(GL_LINE_LOOP);
   glColor4f(0, 0, 0, 1.0);
   glVertex3f(-2, 0.01, -2);
   glVertex3f(2, 0.01, -2);
   glVertex3f(2, 0.01, 2);
   glVertex3f(-2, 0.01, 2);

   glEnd();

   glBegin(GL_POLYGON);
   glColor4f(0.8, 0.45, 0.25, 1.0);
   glVertex3f(-30, 0, -30);
   glVertex3f(30, 0, -30);
   glVertex3f(30, 0, 30);
   glVertex3f(-30, 0, 30);
   glPopMatrix();
  
  

   glEnd();

   



   

  
   glutSwapBuffers();
}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Ver�nderung der Gr��e des 
   // Graphikfensters statt
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45, 1, 0.1, 30.0);
	//glOrtho(-1, 1, -1, 1, 0., 1.7);
	//glFrustum(-1.0, 1.0, -0.5, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgef�hrt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess l�uft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 

   std::cout << "value=" << value <<"	drivingx: " << drivingx << "	drivingz: " << drivingz << "	Zustand: " << a << std::endl;

   fRotation = fRotation - 1.0;
   if (fRotation <= 0)
   {
	   fRotation = fRotation + 360;
   }

 
   switch (a) {
   case 0:
	   drivingz = drivingz - 0.1;
	   if (drivingz <= -3.5)
	   {
		   rotatea = rotatea + 90;
		   a = a + 1;
		  
	   }
	   
	   break;
   case 1:
	   drivingx = drivingx - 0.1;
	   if (drivingx <= -3.5)
	   {
		   a = a + 1;
		   rotatea = rotatea + 90;
	   }
	   break;
   case 2:
	   drivingz = drivingz + 0.1;
	   if (drivingz >= 3.5)
	   {
		   a = a + 1;
		   rotatea = rotatea + 90;

	   }

	   break;
   case 3:
	   drivingx = drivingx + 0.1;
	   if (drivingx >= 3.5)
	   {
		   a = 0;
		   rotatea = rotatea + 90;
	   }
	   break;
   }

   switch (b) {
   case 0:
	   drivingzb = drivingzb - 0.1;
	   if (drivingzb <= -2.5)
	   {
		   b = b + 1;

	   }

	   break;
   case 1:
	   drivingxb = drivingxb - 0.1;
	   if (drivingxb <= -2.5)
	   {
		   b = b + 1;
	   }
	   break;
   case 2:
	   drivingzb = drivingzb + 0.1;
	   if (drivingzb >= 2.5)
	   {
		   b = b + 1;

	   }

	   break;
   case 3:
	   drivingxb = drivingxb + 0.1;
	   if (drivingxb >= 2.5)
	   {
		   b = 0;
	   }
	   break;

   }


   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
   //glTranslatef(1., 1., -1);
   
   

}

int main(int argc, char **argv)
{
   glutInit( &argc, argv );                // GLUT initialisieren
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
   glutCreateWindow( "Hollenbeck; S�nger" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate,0);
   Init();
   glutMainLoop();
   return 0;
}
