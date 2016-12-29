#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include <stdlib.h>
# define M_PI 3.142
int flag=1;
int tx=100;//x movie cordinate of tree
int rtx=0,rty=220;//translate rabbit
float rsx=1,rsy=1;// scale rabbit
int ttx=0,tty=150;//traslate tortoise
float tsx=.25,tsy=.25;//scale tortoise
 void background();
 void tree2();
 void circle1(GLfloat x,GLfloat y,GLfloat radius);
void keys(unsigned char,int,int);
void black_box(int,int);
void white_box(int,int);
void displayfun(void);
void move_rabbit_body();
void move_rabbit_back();
void rabbit_body();
void tort_body();
void rabbit_sleep();
void reset()
{
flag=1;
tx=100;
rtx=0,rty=220;//translate rabbit
rsx=1,rsy=1;// scale rabbit
ttx=0,tty=150;//traslate tortoise
tsx=.25,tsy=.25;
tort_body();
rabbit_body();
glFlush();
glutSwapBuffers();
}

void rabbit_sleep()
{
	rty=rty+50;
}
void tort_body()
{
//body
glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(30*tsx+ttx,137*tsy+tty);
	glVertex2i(56*tsx+ttx,149*tsy+tty);
	glVertex2i(151*tsx+ttx,119*tsy+tty);
	glVertex2i(206*tsx+ttx,114*tsy+tty);
	glVertex2i(252*tsx+ttx,119*tsy+tty);
	glVertex2i(293*tsx+ttx,143*tsy+tty);
	glVertex2i(332*tsx+ttx,169*tsy+tty);
	glVertex2i(364*tsx+ttx,177*tsy+tty);
	glVertex2i(385*tsx+ttx,202*tsy+tty);
	glVertex2i(428*tsx+ttx,206*tsy+tty);
	glVertex2i(427*tsx+ttx,240*tsy+tty);
	glVertex2i(377*tsx+ttx,243*tsy+tty);
	glVertex2i(360*tsx+ttx,224*tsy+tty);
	glVertex2i(337*tsx+ttx,207*tsy+tty);
	glVertex2i(310*tsx+ttx,193*tsy+tty);
	glVertex2i(73*tsx+ttx,180*tsy+tty);
	glEnd();

//shell
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(53*tsx+ttx,189*tsy+tty);
	glVertex2i(98*tsx+ttx,227*tsy+tty);
	glVertex2i(124*tsx+ttx,271*tsy+tty);
	glVertex2i(177*tsx+ttx,293*tsy+tty);
	glVertex2i(224*tsx+ttx,295*tsy+tty);
	glVertex2i(277*tsx+ttx,284*tsy+tty);
	glVertex2i(304*tsx+ttx,249*tsy+tty);
	glVertex2i(341*tsx+ttx,225*tsy+tty);
	glVertex2i(309*tsx+ttx,195*tsy+tty);
	glVertex2i(260*tsx+ttx,167*tsy+tty);
	glVertex2i(204*tsx+ttx,154*tsy+tty);
	glVertex2i(143*tsx+ttx,154*tsy+tty);
	glVertex2i(93*tsx+ttx,170*tsy+tty);
	glEnd();

//front leg
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(310*tsx+ttx,192*tsy+tty);
	glVertex2i(283*tsx+ttx,161*tsy+tty);
	glVertex2i(306*tsx+ttx,112*tsy+tty);
	glVertex2i(337*tsx+ttx,99*tsy+tty);
	glVertex2i(323*tsx+ttx,120*tsy+tty);
	glVertex2i(349*tsx+ttx,105*tsy+tty);
	glVertex2i(335*tsx+ttx,124*tsy+tty);
	glVertex2i(361*tsx+ttx,114*tsy+tty);
	glVertex2i(346*tsx+ttx,129*tsy+tty);
	glVertex2i(335*tsx+ttx,145*tsy+tty);
	glVertex2i(332*tsx+ttx,170*tsy+tty);
	glEnd();

//back leg
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(101*tsx+ttx,165*tsy+tty);
	glVertex2i(85*tsx+ttx,160*tsy+tty);
	glVertex2i(81*tsx+ttx,145*tsy+tty);
	glVertex2i(69*tsx+ttx,126*tsy+tty);
	glVertex2i(65*tsx+ttx,104*tsy+tty);
	glVertex2i(83*tsx+ttx,121*tsy+tty);
	glVertex2i(76*tsx+ttx,103*tsy+tty);
	glVertex2i(98*tsx+ttx,114*tsy+tty);
	glVertex2i(88*tsx+ttx,95*tsy+tty);
	glVertex2i(108*tsx+ttx,110*tsy+tty);
	glVertex2i(113*tsx+ttx,128*tsy+tty);
	glVertex2i(142*tsx+ttx,157*tsy+tty);
	glEnd();
//eye
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(405*tsx+ttx,234*tsy+tty);
	glVertex2i(395*tsx+ttx,224*tsy+tty);
	glVertex2i(405*tsx+ttx,214*tsy+tty);
	glVertex2i(415*tsx+ttx,224*tsy+tty);
	glEnd();
	
}
void move_rabbit_body()
{
	if(rtx<440)
	rtx=rtx+20;
	else
	{
		if(flag==1)
		{
			flag=0;
			rty=rty+90;
			rtx=rtx+10;
			rsx=.5;
			rsy=.5;
			
		}
	}
	
ttx=ttx+10;
tort_body();
rabbit_body();
glFlush();
glutSwapBuffers();
}
void move_rabbit_back()
{
rtx=rtx-20;
ttx=ttx-10;

tort_body();
rabbit_body();
glFlush();
glutSwapBuffers();
}
void rabbit_body()
{
//tail
glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2i(32*rsx+rtx,54*rsy+rty);
	glVertex2i(22*rsx+rtx,54*rsy+rty);
	glVertex2i(23*rsx+rtx,62*rsy+rty);
	glVertex2i(32*rsx+rtx,70*rsy+rty);
	glVertex2i(34*rsx+rtx,65*rsy+rty);
	glEnd();

//ear 1
glColor3f(.5,.50,.50);
	glBegin(GL_POLYGON);
	glVertex2i(97*rsx+rtx,94*rsy+rty);
	glVertex2i(31*rsx+rtx,96*rsy+rty);
	glVertex2i(54*rsx+rtx,108*rsy+rty);
	glVertex2i(88*rsx+rtx,106*rsy+rty);
	glEnd();
	//ear 2
glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex2i(97*rsx+rtx,94*rsy+rty);
	glVertex2i(63*rsx+rtx,125*rsy+rty);
	glVertex2i(48*rsx+rtx,121*rsy+rty);
	glVertex2i(70*rsx+rtx,104*rsy+rty);
	glEnd();
	

//	head
	glColor3f(0.51,.51,.51);
	glBegin(GL_POLYGON);
	glVertex2i(82*rsx+rtx,78*rsy+rty);
	glVertex2i(69*rsx+rtx,86*rsy+rty);
	glVertex2i(71*rsx+rtx,95*rsy+rty);
	glVertex2i(87*rsx+rtx,107*rsy+rty);
	glVertex2i(96*rsx+rtx,94*rsy+rty);
	glVertex2i(94*rsx+rtx,84*rsy+rty);
	glEnd();
	
	//left hand
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_TRIANGLES);
	glVertex2i(66*rsx+rtx,54*rsy+rty);
	glVertex2i(79*rsx+rtx,52*rsy+rty);
	glVertex2i(76*rsx+rtx,67*rsy+rty);
	glEnd();
	//right hand
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_TRIANGLES);
	glVertex2i(73*rsx+rtx,41*rsy+rty);
	glVertex2i(63*rsx+rtx,49*rsy+rty);
	glVertex2i(70*rsx+rtx,59*rsy+rty);
	glEnd();
	// left leg
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_TRIANGLES);
	glVertex2i(58*rsx+rtx,43*rsy+rty);
	glVertex2i(72*rsx+rtx,36*rsy+rty);
	glVertex2i(50*rsx+rtx,31*rsy+rty);
	glEnd();
	
	// right leg
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_TRIANGLES);
	glVertex2i(52*rsx+rtx,37*rsy+rty);
	glVertex2i(40*rsx+rtx,23*rsy+rty);
	glVertex2i(69*rsx+rtx,26*rsy+rty);
	glEnd();
	//body
		glColor3f(.3,.3,.3);
	glBegin(GL_POLYGON);
	glVertex2i(69*rsx+rtx,86*rsy+rty);
	glVertex2i(34*rsx+rtx,66*rsy+rty);
	glVertex2i(29*rsx+rtx,38*rsy+rty);
	glVertex2i(40*rsx+rtx,23*rsy+rty);
	glVertex2i(82*rsx+rtx,75*rsy+rty);
	glEnd();
	
	
}

void black_box(int px,int py)
{
	glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(px,py);
glVertex2f(px,py-30);
glVertex2f(px+30,py-30);
glVertex2f(px+30,py);
glEnd();
}
void white_box(int px,int py)
{
	glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(px,py);
glVertex2f(px,py-30);
glVertex2f(px+30,py-30);
glVertex2f(px+30,py);
glEnd();
}




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



void tree2()
{
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350+tx,325);
glVertex2f(350+tx,395);
glVertex2f(365+tx,395);
glVertex2f(365+tx,325);
glEnd();

int l;
	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		circle1(340+tx,400,l);
		circle1(380+tx,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		circle1(350+tx,440,l);
		circle1(370+tx,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		circle1(360+tx,465,l);
	}

}

void background()
{


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
		


	glColor3f(0.5,0.5,0.5);//cloud
	circle1(50.0,800.0,20.0);
	circle1(75.0,790.0,30.0);
	circle1(110.0,793.0,40.0);
    circle1(150.0,790.0,30.0);
	


	//road boundary
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,310);
	glVertex2f(0,140);
	glVertex2f(1100,140);
	glVertex2f(1100,310);
	glEnd();

	//road
	glColor3f(0.85,0.50,0.29);
	glBegin(GL_POLYGON);
	glVertex2f(0,150);
	glVertex2f(0,300);
	glVertex2f(1100,300);
	glVertex2f(1100,150);
	glEnd();


	//finish line
	black_box(940,180);
	white_box(940,210);
	black_box(940,240);
	white_box(940,270);
	black_box(940,300);

	white_box(970,180);
	black_box(970,210);
	white_box(970,240);
	black_box(970,270);
	white_box(970,300);

}



void displayfun()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	background();//
	glFlush();
	glutSwapBuffers();

	
	
	
 }
				   
void keys(unsigned char key,int x,int y)
{
	if(key=='b'||key=='B')
	{
		background();
		move_rabbit_body();
	}
	else if(key=='d'||key=='D')
	{
		background();
		move_rabbit_back();
	} 
	else if(key=='r'||key=='R')
	{
		background();
		reset();
	} 
}




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
	glutCreateWindow("my project");
	
	glutDisplayFunc(displayfun);
	glutKeyboardFunc(keys);

	init();
	glutMainLoop();
	return 0;
}
