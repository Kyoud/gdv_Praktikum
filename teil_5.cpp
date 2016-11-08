// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL auf Rechnern in d15
//#include <Z:\Downloads\OpenGL_SoSe_15\GL\freeglut.h>
#include "Wuerfel.h"
#include "Flugzeug.h"
#include <GL\SOIL.h>
float fRotation = 315.0;

float savex = 0;
float savez = 0;
float drivingx = 3.5;
float drivingz = 0.4;
float rotatea = 0;

float drivingxb = 2.5;
float drivingzb = 0.4;
float rotateb = 0;
float baumrotate = 0;
int a = 0;
int b = 0;
int wait_msec = 10;

float rotateprop = 0;
int changespeed = 1;
void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgeführt werden müssen
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	GLuint tex_2d = SOIL_load_OGL_texture
		(
		"Z:/Downloads/OpenGL_SoSe_15/TREE1.PNG",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	// check for an error during the load process
	if (0 == tex_2d)
	{
		printf("SOIL loading error: '%s'\n", SOIL_last_result());
	}
	glBindTexture(GL_TEXTURE_2D, tex_2d);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RenderScene() //Zeichenfunktion
{
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   //

   glClearColor(0, .5, .8, 1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   gluLookAt(0, 10, 15, 0, 0, 0, 0, 1, 0);

   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHTING);
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0};
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glEnable(GL_COLOR_MATERIAL);
   // z-Buffer
   glEnable(GL_DEPTH_TEST);
   glClearDepth(1.0);
   // Normalen fuer korrekte Beleuchtungs-Berechnung normalisieren
   glEnable(GL_NORMALIZE);
   glPushMatrix();
   glTranslatef(0, 1, -14);
   glEnable(GL_TEXTURE_2D);

   glBegin(GL_QUADS);
   glColor4f(1, 1, 1, 1);
   glTexCoord2f(0.0f, 0.0f);   glVertex3f(-1.0f, -1.0f, 0.0f);
   glTexCoord2f(1.0f, 0.0f);   glVertex3f(1.0f, -1.0f, 0.0f);
   glTexCoord2f(1.0f, 1.0f);   glVertex3f(1.0f, 1.0f, 0.0f);
   glTexCoord2f(0.0f, 1.0f);   glVertex3f(-1.0f, 1.0f, 0.0f);
   glEnd();
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();

   
   glPushMatrix();
   glTranslatef(drivingx, 1.5, drivingz);
   glRotatef(rotatea, 0, 1, 0);
   Flugzeug(1, 0, 0, rotateprop);
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

void MouseFunc(int button, int state, int x, int y)
// Maus-Tasten und -Bewegung abfragen
{
	GLfloat xMousePos = float(x);
	GLfloat yMousePos = float(y);

	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			std::cout << "linke Maustaste gedrueckt " << xMousePos << ", " << yMousePos << std::endl;
			wait_msec = wait_msec *2;
		}
		else
			std::cout << "linke Maustaste losgelassen " << xMousePos << ", " << yMousePos << std::endl;
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN){
			std::cout << "rechte Maustaste gedrueckt " << xMousePos << ", " << yMousePos << std::endl;
			wait_msec = wait_msec/2;
			if (wait_msec < 1)
				wait_msec = 1;
		}
		else
			std::cout << "rechte Maustaste losgelassen " << xMousePos << ", " << yMousePos << std::endl;
		break;
	}
}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Veränderung der Größe des 
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
   // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 

   //std::cout << "value=" << value <<"	drivingx: " << drivingx << "	drivingz: " << drivingz << "	Zustand: " << a << std::endl;
	

	baumrotate = baumrotate - 5.0;
	if (baumrotate <= 0)
	{
		baumrotate = baumrotate + 360;
	}
	fRotation = fRotation - 1.0;
   if (fRotation <= 0)
   {
	   fRotation = fRotation + 360;
   }

   rotateprop = rotateprop - 20.0;
   if (rotateprop <= 0)
   {
	   rotateprop = rotateprop + 360;
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

   glutTimerFunc(wait_msec, Animate, ++value);
   //glTranslatef(1., 1., -1);
   
   

}

int main(int argc, char **argv)
{

   glutInit( &argc, argv );                // GLUT initialisieren
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
   glutCreateWindow( "Hollenbeck; Sänger" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   glutMouseFunc(MouseFunc);
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate,0);
   Init();
   glutMainLoop();
   return 0;
}
