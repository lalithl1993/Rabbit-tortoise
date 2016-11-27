#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include <stdlib.h>
# define M_PI 3.142
 //void border();
 //void tree1();
// void color();
 void tree2();
 void circle1(GLfloat x,GLfloat y,GLfloat radius);
 void semicircle(GLfloat x,GLfloat y,GLfloat radius);
// void moon2();
// void sun1();
// void sun2();

void daycolorchange(void);
// void modifynight();
void circle1(GLfloat x, GLfloat y, GLfloat radius) 
  { 
    float angle;   
    glBegin(GL_POLYGON); 
    for(int i=0;i<100;i++) 
	{ 
        angle = i*2*(M_PI/100); 
        glVertex2f(x+(cos(angle)*radius),y+(sin(angle)*radius)); 
    } 
    glEnd(); 
  }  

void semicircle(GLfloat x, GLfloat y, GLfloat radius) 
  { 
    float angle;   
    glBegin(GL_POLYGON); 
    for(int i=0;i<100;i++) 
	{ 
        angle = i*2*(M_PI/100); 
        glVertex2f(x+(cos(angle)*radius),y+(sin(angle)*radius)); 
    } 
    glEnd(); 
  }  


void tree2()
{

	glColor3f(0.3,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(100,250);
	glVertex2f(175,250);
	glVertex2f(175,75);
	glVertex2f(100,75);
	glEnd();
	glColor3f(0.0,0.3,0.01);

	glBegin(GL_POLYGON);
	glVertex2f(100,250);
	glVertex2f(0,250);
	glVertex2f(75,350);
	glVertex2f(25,350);
	glVertex2f(100,425);
	glVertex2f(50,425);
	glVertex2f(140,500);
	glVertex2f(225,425);
	glVertex2f(175,425);
	glVertex2f(250,350);
	glVertex2f(200,350);
	glVertex2f(275,250);
	glVertex2f(175,250);
	glEnd();
}
void daycolorchange()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);


	/*sky*/
    glColor3f(0.4,0.7,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,400);
	glVertex2f(1000,400);
	glVertex2f(1000,1000);
	glVertex2f(0,1000);
	glEnd();
	/*ground*/
	glColor3f(0.0,0.6,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,400);
	glVertex2f(1000,400);
	glVertex2f(1000,0);
	glVertex2f(0,0);
	glEnd();
	/*hills*/
	glColor3f(0.3,0.1,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-20,400);
	glVertex2f(125,700);
	glVertex2f(270,400);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(230,400);
	glVertex2f(375,700);
	glVertex2f(520,400);
	glEnd();

	glColor3f(0.3,0.1,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(480,400);
	glVertex2f(625,700);
	glVertex2f(770,400);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(730,400);
	glVertex2f(850,700);
	glVertex2f(1020,400);
	glEnd();

	tree2();//tree
	
	glColor3f(1.0,1.0,0.0);
	circle1(50.0,820.0,35.0);//sun


	
	glColor3f(0.5,0.5,0.5);//cloud
	circle1(850.0,800.0,20.0);
	circle1(875.0,790.0,30.0);
	circle1(910.0,793.0,40.0);
    circle1(950.0,790.0,30.0);
	glColor3f(1.0,1.0,0.0);	


	glColor3f(0.5,0.5,0.5);//cloud
	circle1(50.0,800.0,20.0);
	circle1(75.0,790.0,30.0);
	circle1(110.0,793.0,40.0);
    circle1(150.0,790.0,30.0);
	glColor3f(1.0,1.0,0.0);


	// glColor3f(0.3,0.0,0.0);
	// glBegin(GL_POLYGON);
	// glVertex2f(100,250);
	// glVertex2f(175,250);
	// glVertex2f(175,75);
	// glVertex2f(100,75);
	// glEnd();
	// glColor3f(0,0.3,0.01);
	// semicircle(500,370,100);


	glFlush();
	glutSwapBuffers();

	
	
	
 }
				   



// void sun2()
// {
// 	daycolorchange();
// 	glColor3f(1.0,1.0,0.0);
// 	circle1(120.0,700.0,30.0);
// 	glFlush();
// 	glutSwapBuffers();
// }


void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,999.0);
}

int main( int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("day-night color");
	glutDisplayFunc(daycolorchange);
	// glutKeyboardFunc(keys);
	
	// glutCreateMenu(menu);
	// glutAddMenuEntry("quit",1);
	// glutAddMenuEntry("night color change",2);
	// glutAddMenuEntry("day color change",3);
	
	
	// glutAttachMenu(GLUT_RIGHT_BUTTON);
	// menu(GLUT_LEFT_BUTTON);
	init();
	glutMainLoop();
	return 0;
}