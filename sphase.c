#include<stdio.h>
#include<GL/glut.h>
#include<string.h>

double x,y,z,z1,z11,z2,z3,z4,z5;

int scence=0;

void keys(unsigned char key,int x,int y)
{
    if(key=='a'||key=='A')
		scence=1;
	  if(key=='s'||key=='S')
		scence=2;
    if(key=='d'||key=='D')
		scence=3;  
    if(key=='f'||key=='F')
		scence=4;  
    if(key=='g'||key=='G')
		scence=5;
	  if(key=='h'||key=='H')
		scence=6;      
    if(key=='j'||key=='J')
		scence=7;  
    if(key=='k'||key=='K')
		scence=8;
    if(key=='z'||key=='Z')
		scence=9; 
    if(key=='x'||key=='X')
		scence=10;  
    if(key=='c'||key=='C')
		scence=11;   
    if(key=='v'||key=='V')
		scence=12;   
    if(key=='b'||key=='B')
		scence=13;   
    if(key=='n'||key=='N')
		scence=14;                    
}

//////////////////////////timmers///////////////////////////////////////
void timer(int c)
{
  {
   z=z+1;
   glutPostRedisplay();
   glutTimerFunc(200,timer,0); 
  }
}

void timerbus(int a)
{
  if(z11==190)
  { }
  else
  {
   z11=z11+2;
   glutPostRedisplay();
   glutTimerFunc(200,timerbus,0); 
  }
}

void timerbus1(int c)
{
    if(z4==130)
    {  }else    
  { 
   z4=z4+2;
   glutPostRedisplay();
   glutTimerFunc(200,timerbus1,0); 
  }
}

void timerbus2(int c)
{
    if(z5==130)
    {  }else    
  { 
   z5=z5+2;
   glutPostRedisplay();
   glutTimerFunc(200,timerbus1,0); 
  }
}

void timercloud(int c)
{ if(z1==100)
   {   z1=0;
       glutPostRedisplay();
       glutTimerFunc(200,timercloud,0); 
   }else
  {
   z1=z1+2;
   glutPostRedisplay();
   glutTimerFunc(200,timercloud,0); 
  }
}

void timergateleft(int b)
{
 //left gate if
  if(z2==-22)
      {}
  else
      {  
        z2=z2-0.5;
        glutPostRedisplay();
        glutTimerFunc(200,timergateleft,0);   
      } 
}

void timergateright(int a)
{
 //right gate if
  if(z3<=18)
      {
        z3=z3+0.5;
        glutPostRedisplay();
        glutTimerFunc(200,timergateright,0);  
      }
  else
      {}
}

////////////////////////////////////////////////////////////////////////

void init()
{
  glClearColor(0.9,0.9,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();  
  glOrtho(0.0,200.0,0.0,200.0,-200.0,200.0);
}

//name printing 
void output(char s[])
{
  int i;
  for(i=0;i<strlen(s);i++)
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,s[i]);
}

void output1(char s[])
{
    int i;
    for(i=0;i<strlen(s);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//name of the bus
void busname(void)
{
  glPushMatrix();
  glColor3f(0.3,0.3,1);
  	glRasterPos3f(-85+z11,45,0);
        output1("MITE School"); 
  glPopMatrix();
}
void bus(void)
{
  glTranslatef(-120+z11,10,0);
  glColor3f(0.9,0.8,0);
  glRectf(5,10,85,105);
  glRectf(85,10,105,60);  
//forent wind 
glBegin(GL_POLYGON);
          glColor3f(0.9,0.8,0);
      		glVertex2f(85,105);
			    glVertex2f(85,60);
		  	  glVertex2f(88,60);
glEnd();    
//backward wind
glBegin(GL_POLYGON);
          glColor3f(0.9,0.8,0);
      		glVertex2f(5,10);
			    glVertex2f(5,105);
		  	  glVertex2f(3,103);
          glVertex2f(3,13);
glEnd(); 
//forent wind
glBegin(GL_POLYGON);
          glColor3f(0.9,0.8,0);
      		glVertex2f(105,10);
			    glVertex2f(105,60);
		  	  glVertex2f(107,58);
          glVertex2f(107,12);
glEnd(); 
//blue tip
  glColor3f(0.3,0.3,1);
  glRectf(3,15,107,25); 
  glRectf(3,28,107,30);   
  glRectf(3,45,107,48);    

//symbol red strips
  glColor3f(0.9,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(22,40);
	glVertex2f(22,35);
	glVertex2f(26,30);	
  glVertex2f(30,35);
  glVertex2f(30,40);
  glVertex2f(26,45);
	glEnd(); 
  //white strips
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(23,40);
		glVertex2f(23,35);
		glVertex2f(26,31);	
    glVertex2f(29,35);
		glVertex2f(29,40);
		glVertex2f(26,44);	
	  glEnd();
    glRectf(29,35,30,37); 

    //strip of betterfly
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(27,33);
		glVertex2f(29,35);
		glVertex2f(28,38);	
	  glEnd();

//forent engine
glBegin(GL_POLYGON);
          glColor3f(0.9,1,0.2);
      		glVertex2f(107,20);
			    glVertex2f(107,50);
		  	  glVertex2f(105,45);
	  		  glVertex2f(105,25);
glEnd();  
//window
for(x=10;x<85;x=x+15)
for(y=70;y<=85;y=y+10)
{
glBegin(GL_POLYGON);
          glColor3f(1.0,1.0,1.0);
      		glVertex2f(x,y);
			    glVertex2f(x,y+15);
		  	  glVertex2f(x+10,y+15);
	  		  glVertex2f(x+10,y);
glEnd();
}
glBegin(GL_POLYGON);
          glColor3f(1.0,1.0,1.0);
      		glVertex2f(80,95);
			    glVertex2f(80,70);
		  	  glVertex2f(83,70);
glEnd();  
//pad ligth
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(1.0,1.0,1.0);
  glTranslatef(-13+z11,50,0); 
  glScalef(1,2.5,0);
  glutSolidSphere(2,200,200);
  glPopMatrix();
//tire backward
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glTranslatef(-90+z11,18,0); 
  glScalef(2,3.4,0);
  glutSolidSphere(4,200,200);
  glPopMatrix();
///tire backward pin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.7,0.7,0.6);
  glTranslatef(-90+z11,18,0); 
  glScalef(2,3.4,0);
  glRotatef(10+z11,1.0,0.0,0.0);
  glutSolidSphere(2,200,200);
  glPopMatrix();
//tire foreward
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glTranslatef(-25+z11,18,0); 
  glScalef(2,3.4,0);
  glutSolidSphere(4,200,200);
  glPopMatrix();
//tire forward pin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.7,0.7,0.6);
  glTranslatef(-25+z11,18,0);
  glScalef(2,3.4,0);
  glRotatef(10+z11,1.0,0.0,0.0);
  glutSolidSphere(2,200,200);
  glPopMatrix();
}

//land
void land(void)
{
    glColor3f(0.8,0.7,0.3);
    glRecti(0,0,200,55);
}
//bus stop view
void busstop(void)
{
    glColor3f(0.3,0.4,0.5);
    glRecti(110,45,112,120);
    glRecti(180,45,182,120);
    glRecti(120,50,122,120);
    glRecti(168,50,170,120);
    glRecti(107,120,185,122);

    glColor3f(0.7,1,0.9);
    glRecti(122,65,168,120);

    glColor3f(0.3,0.4,0.5);
    glRecti(130,50,132,120);
    glRecti(157,50,159,120);
//banch
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.1,0.1); 
    glVertex2i(125,75);
    glVertex2i(127,78);
    glVertex2i(162,78);
    glVertex2i(164,75);
    glEnd();
    
    glRecti(125,73,164,75);

    glColor3f(0.3,0.4,0.5);
    glRecti(107,122,185,125);
   
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.4,0.5); 
    glVertex2i(112,55);
    glVertex2i(112,58);
    glVertex2i(120,67);
    glVertex2i(120,64);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(182,55);
    glVertex2i(182,58);
    glVertex2i(168,67);
    glVertex2i(168,64);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(122,64);
    glVertex2i(122,67);
    glVertex2i(168,67);
    glVertex2i(168,64);
    glEnd();

}
//road top view
void roadtopview(void)
{
    glColor3f(0.5,0.6,0.6);
    glRecti(0,30,200,35);
    glColor3f(0.0,0.0,0.0);
    glRecti(0,0,200,30);
    glColor3f(0.9,1,0.9);
    glRecti(0,24,200,26);
}
//TREES
void tree(void)
{
	//gradan
	glColor3f(0.6,0.8,0);
	glRectf(0,35,200,105);

	for(x=0;x<190;x=x+12)
        {
    glColor3f(0.8,0.5,0.2);
    glRecti(10+x,100,13+x,110);
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.9,0); 
    glVertex2i(7+x,115);
    glVertex2i(11+x,130);
    glVertex2i(16+x,115);
    glEnd();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.7,0.9,0); 
    glTranslatef(11.5+x,113,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();
	}
}
//buliding 
void builing(void)
{
    glColor3f(0.6,0.1,0);
    glRecti(55,155,75,158);
    glColor3f(1,0.7,0.4);
    glRecti(55,138,75,155);
//roof right
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.1,0);
    glVertex2i(70,150);
    glVertex2i(80,160);
    glVertex2i(120,160);
    glVertex2i(130,150);
    glEnd();
//roof left
    glColor3f(0.6,0.1,0);
    glRecti(20,135,70,138);
   
//left block
    glColor3f(1,0.7,0.4);
    glRecti(20,100,70,135);
//shadow block
    glPushMatrix();  
    glColor3f(1,0.6,0.3);
    glRecti(65,100,70,135);
    glPopMatrix();
//left window
    glColor3f(0.9,0.8,1);
    glRecti(25,105,30,115);
    glRecti(32,105,37,115);
    glRecti(55,105,60,115);
    glRecti(62,105,67,115);

    glRecti(25,120,30,130);
    glRecti(32,120,37,130);
    glRecti(40,120,45,130);
    glRecti(47,120,52,130);
    glRecti(55,120,60,130);
    glRecti(62,120,67,130);
//door left block
    glColor3f(0.9,0.8,1);
    glRecti(40,100,50,115);
//door ball   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.7,1); 
   glTranslatef(45,108,0);
   glutSolidSphere(1,100,100);
   glPopMatrix();
//door line
    glColor3f(0.8,0.8,0.6); 
    glBegin(GL_LINE_LOOP);  
    glVertex2i(45,100);
    glVertex2i(45,115);
    glEnd();
//left down wall
    glColor3f(0.6,0.6,0.5);
    glRecti(20,98,70,102);
//right block
    glColor3f(1,0.7,0.4);
    glRecti(70,100,130,150);
//window right block
    glColor3f(0.9,0.8,1);
    glRecti(75,110,80,120);
    glRecti(85,110,90,120);
    glRecti(95,110,100,120);
    glRecti(105,110,110,120);
    glRecti(115,110,120,120);
    glRecti(124,110,128,120);
    glRecti(75,135,80,145);
    glRecti(85,135,90,145);
    glRecti(95,135,100,145);
    glRecti(105,135,110,145);
    glRecti(115,135,120,145);
    glRecti(124,135,128,145);
//right down wall
    glColor3f(0.6,0.6,0.5);
    glRecti(70,125,130,130);
    glRecti(70,95,130,105);
//broad
    glColor3f(0.4,0.1,0.2);
    glRecti(30,138,60,143);
    glPushMatrix();
    glColor3f(1,0.9,0.9);
    glRasterPos3f(40,140,0);
    output("Melon appartment");
    glPopMatrix();
}
//pole of stop
void pole(void)
{
  glColor3f(0.3,0.4,0.5);
  glRecti(190,45,191,105);
  //pole circle
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(190.5,110,0);
  glScalef(2,3.1,0);
  glutSolidSphere(3,200,200);
  glPopMatrix();
  //inside small 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(1.0,1.0,1.0);
  glTranslatef(190.5,110,0);
  glScalef(2,3.1,0);
  glutSolidSphere(2.4,200,200);
  glPopMatrix();

//name of pole
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
          glRasterPos3f(186,108,0);
          output1("STOP"); 
 glPopMatrix();
}
//man in the stop
void person(void)
{
//hair
   glColor3f(0.0,0.0,0.0);  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(133,107,0);
   glutSolidSphere(4,200,200);
   glPopMatrix();  
   glRecti(129,100,137,107);
//face
   glColor3f(0.9,0.8,0.6);  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(130,100,0);
   glutSolidSphere(1,200,200);
   glPopMatrix();

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(136,100,0);
   glutSolidSphere(1,200,200);
   glPopMatrix();
//coat triangle
    glBegin(GL_POLYGON);
    glColor3f( 0.2,0.5,0.5); 
    glVertex2i(126,92);
    glVertex2i(140,92);
    glVertex2i(133,100);
    glEnd();
//dress 
//rectangle
    glColor3f( 0.2,0.5,0.5); 
    glRecti(126,70,140,92);
//button
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.4,0.4,0.5);
   glTranslatef(133,75,0); 
   glScalef(1,1.1,1);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
//hand left 
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f( 0.2,0.5,0.5);
   glTranslatef(125.5,90,0); 
   glScalef(1,1.6,1);
   glutSolidSphere(1.5,200,200);
   glPopMatrix();

   glRecti(124,68,126,90);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.8,0.6);  
   glTranslatef(125,66.5,0);
   glScalef(0.9,1.5,1);
   glutSolidSphere(1.6,200,200);
   glPopMatrix();
//hand right
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f( 0.2,0.5,0.5);
   glTranslatef(140.5,90,0);
   glScalef(1,1.6,1);
   glutSolidSphere(1.5,200,200);
   glPopMatrix();

   glRecti(140,68,142,90);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.8,0.6);  
   glTranslatef(141.5,66.5,0);
   glScalef(0.9,1.5,1);
   glutSolidSphere(1.6,200,200);
   glPopMatrix();
   
   glColor3f(0.0,0.0,0.0); 
   glRecti(140,50,142,66);
//triangle
    glBegin(GL_POLYGON);
    glColor3f(1,1,1); 
    glVertex2i(130,95);
    glVertex2i(136,95);
    glVertex2i(133,80);
    glEnd();
//tie
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.5,0.5);
    glVertex2i(133,95);
    glVertex2i(134,88);
    glVertex2i(133,85);
    glVertex2i(132,88); 
    glEnd();
//face box
   glColor3f(0.9,0.8,0.6);  
   glRecti(130,95,136,105);
//eye bro
  glColor3f(0.0,0.0,0.0);  
  glLineWidth(2.0);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.0);  
  glVertex2f(130.5,103);
  glVertex2f(132,103);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.0);  
  glVertex2f(134,103);
  glVertex2f(135.5,103);
  glEnd();
//eye
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);  
   glTranslatef(135,101.5,0);
   glScalef(0.8,0.9,0.9);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(131.5,101.5,0);
   glScalef(0.9,0.9,0.9);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
//down sphere face
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.8,0.6);  
   glTranslatef(133,96,0);
   glutSolidSphere(3,200,200);
   glPopMatrix();
//mouth
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(133,98,0);
    glScalef(1,0.8,0.9);
    glutSolidSphere(1,200,200);
    glPopMatrix();
//panties
//left
//shoce left
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);
   glTranslatef(128,43,0);
   glScalef(0.9,2,1.5);
   glutSolidSphere(2.5,200,200);
   glPopMatrix();
   glColor3f(0.3,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2i(126,45);
   glVertex2i(126,70);
   glVertex2i(134,70);
   glVertex2i(131,45);
   glEnd();
//right
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);
   glTranslatef(138,43,0);
   glScalef(0.9,2,1);
   glutSolidSphere(2.5,200,200);
   glPopMatrix();
   glColor3f(0.3,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2i(140,45);
   glVertex2i(140,70);
   glVertex2i(133,70);
   glVertex2i(135,45);
   glEnd();
}
void girl(void)
{  
//hair 
    glColor3f(0.0,0.0,0.0);
    glRectf(157,82,165,98);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(161,97,0); 
    glScalef(1.5,2,0);
    glutSolidSphere(3,200,200);
    glPopMatrix();

//shoes left and right
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(159.15,42,0); 
    glScalef(1,2,0);
    glutSolidSphere(1.4,200,200);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(163.15,42,0); 
    glScalef(1,2,0);
    glutSolidSphere(1.4,200,200);
    glPopMatrix();
//leg left and right
    glColor3f(0.9,0.8,0.6);
    glRectf(158,45,160.3,65);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(159.15,44,0); 
    glScalef(1,2,0);
    glutSolidSphere(1.2,200,200);
    glPopMatrix();

   glRectf(162,45,164.3,65);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(163.15,44,0); 
    glScalef(1,2,0);
    glutSolidSphere(1.2,200,200);
    glPopMatrix();
//dress rectangle   
    glColor3f(0.8,0.8,0.5); 
    glRectf(155.8,65,166.2,78);  
//dress shot
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0); 
    glVertex2i(155.9,65);
    glVertex2i(166.3,65);
    glVertex2i(169,58);
    glVertex2i(153.3,58);
    glEnd();     
//hand left
  glColor3f(0.8,0.8,0.5); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(156,80,0); 
    glScalef(1.8,1.8,1);
    glutSolidSphere(1,200,200);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.9,0.8,0.6);
    glTranslatef(154.75,66,0); 
    glScalef(1,2,0);
    glutSolidSphere(1,200,200);
    glPopMatrix();

    glColor3f(0.8,0.8,0.5);
    glRectf(154,66,155.8,79);     
//hand right
 glColor3f(0.8,0.8,0.5); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(165.8,79.8,0); 
    glScalef(1.8,1.8,1);
    glutSolidSphere(1,200,200);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.9,0.8,0.6);
    glTranslatef(167.1,66,0); 
    glScalef(1,2,0);
    glutSolidSphere(1,200,200);
    glPopMatrix();

    glColor3f(0.8,0.8,0.5);
    glRectf(166.2,66,167.8,79);     

//shirt button
for(y=65;y<=78;y=y+2)
for(x=161;x<162;x=x+2)
{
    glColor3f(0.0,0.0,0.0); 
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex2f(x,y+3);
    glEnd();
}
//dress triangle
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,0.5); 
    glVertex2i(155.8,78);
    glVertex2i(166.8,78);
    glVertex2i(161,90);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1); 
    glVertex2i(158,90);
    glVertex2i(164,90);
    glVertex2i(161,80);
    glEnd();
//bag
    glColor3f(0.6,0.6,0.5); 
    glRectf(155.8,70,156.8,82);
    glRectf(165.2,70,166.2,82);       

//face  
   glColor3f(0.9,0.8,0.6);
   glRectf(158,85,164,95);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(161,87,0);
   glScalef(1,1.5,0);
   glutSolidSphere(3,200,200);
   glPopMatrix();
//girl eye bro left and right
  glColor3f(0.0,0.0,0.0);  
  glLineWidth(2.0);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.0);  
  glVertex2f(159,92);
  glVertex2f(160.5,92);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.0);  
  glVertex2f(161.5,92);
  glVertex2f(163,92);
  glEnd();
//eyes lift and right
  glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);  
   glTranslatef(159.75,90.5,0);
   glScalef(0.8,0.9,0.9);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(162.25,90.5,0);
   glScalef(0.8,0.9,0.9);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
//mouth
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(1.0,1.0,1.0);  
   glTranslatef(161,86,0);
   glScalef(1,.6,0);
   glutSolidSphere(1,200,200);
   glPopMatrix();
}

//sun 
void sun(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(1,0,0); 
  glTranslatef(100,180,0);
  glScalef(1,1.5,1.5);
  glutSolidSphere(6,100,100);
  glPopMatrix();
}

//cloud
void cloud(void)
{
  glColor3f(0.9,0.8,1); 
//cloud 1
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(10+z1,180,0);
  glRotatef(10+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(10+z1,190,0);
  glRotatef(10+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(23+z1,185,0);
  glRotatef(10+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(3+z1,185,0);
  glRotatef(10+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  //cloud2
   glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(100+z1,180,0);
  glRotatef(11+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(120+z1,180,0);
  glRotatef(11+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(110+z1,190,0);
  glRotatef(11+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(110+z1,180,0);
  glRotatef(11+z1,1.0,0.0,0.0);
  glutSolidSphere(8,200,200);
  glPopMatrix();
}

void schoolname(void)
{
  glPushMatrix();
  glColor3f(0.3,0.3,1);
          glRasterPos3f(90,146,0);
          output1("MITE School");
  glPopMatrix();
}

//school building
void schoolblock(void)
{
	//back block
	glColor3f(1,0,0);
	glRectf(40,80,160,150);

	//top strip
	glColor3f(0.9,1,0.1);
	glRectf(40,145,160,152);

	// back strips
	glColor3f(0.9,1,0.1);
	glRectf(40,80,160,95);

	//back block window
	for(x=42.5;x<160;x=x+10)
	for(y=90;y<100;y=y+10)
	{
		glBegin(GL_POLYGON);
		glColor3f(0,0,0);
      		glVertex2f(x,y);
		glVertex2f(x,y+15);
		glVertex2f(x+5,y+15);
	  	glVertex2f(x+5,y);
		glEnd();	
	}
	for(x=42.5;x<160;x=x+10)
	for(y=120;y<130;y=y+10)
	{
		glBegin(GL_POLYGON);
		glColor3f(0,0,0);
      		glVertex2f(x,y);
		glVertex2f(x,y+15);
		glVertex2f(x+5,y+15);
	  	glVertex2f(x+5,y);
		glEnd();
	
	}

	//front block
	glColor3f(0.9,0,0);
	glRectf(90,75,110,120);

	//top script
	glColor3f(0.9,1,0.1);
	glRectf(90,118,110,120);

	//opening door
	glColor3f(1,1,1);
	glRectf(96,75,104,100);

}

void compound(void)
{
	//left compound & right compound
	glColor3f(0.8,0.8,0.6);
	glRectf(0,40,80,86);
	glRectf(120,40,200,86);
	glColor3f(0.8,0.7,0.5);
	glRectf(120,40,125,89);glRectf(75,40,80,89);
}

void gate(void)
{ 
//leftside gate chain moving part

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(0+z2,2,0);

//leftside gate chain
  glColor3f(0.0,0.0,0.0); 
  glRectf(80,42,100,44);
  glRectf(80,88,100,90);
  glRectf(80,92,100,94);

//contiouns chain of gate left

  for(x=80;x<=100;x=x+4)
	  for(y=42;y<90;y=y+4)
      glRectf(x,y,x+2,y+8);
 glPopMatrix();

//rightside gate chain moving part
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glTranslatef(0+z3,2,0);
 
  //rightside gate chain

  glRectf(100,42,120,44);
  glRectf(100,88,120,90);
  glRectf(100,92,120,94);

//contiouns chain of gate right

  for(x=100;x<=120;x=x+4)
	  for(y=42;y<90;y=y+4)
      glRectf(x,y,x+2,y+8);

  glPopMatrix();
}

//written in the broad
void broadname(void)
{
  glPushMatrix();
  glColor3f(1.0,1.0,1.0);
	glRasterPos3f(90,140,0);
        output1("Solve 5 % 10 = ?"); 
  glPopMatrix();
}

// table of the sir
void table(void)
{
    glColor3f(0.8,0.8,0.6);
    glRectf(110,60,155,65); 
    glColor3f(0.8,0.8,0.7);
    glRectf(112,30,153,60); 

    //symbol red strips
    glColor3f(0.9,0,0);
    glBegin(GL_POLYGON);
      	glVertex2f(128,40);
		glVertex2f(132,35);
		glVertex2f(136,40);	
        glVertex2f(136,45);
        glVertex2f(132,50);
        glVertex2f(128,45);
	glEnd(); 

    //white strips
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
      	glVertex2f(129,45);
		glVertex2f(129,40);
		glVertex2f(132,36);	
        glVertex2f(135,40);
		glVertex2f(135,45);
		glVertex2f(132,49);	
	glEnd();
    glRectf(133,41,136,43); 

    //strip of betterfly
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
      	glVertex2f(133.5,40);
		glVertex2f(134,44);
		glVertex2f(136,42);	
	glEnd();
}

void walls(void)
{
    glColor3f(0.9,0.6,0.2); 
    //left wall
    glBegin(GL_POLYGON);
      	glVertex2f(0,0);
		glVertex2f(30,0);
		glVertex2f(30,170);
	  	glVertex2f(0,200);
	glEnd();

    //right wall
    glBegin(GL_POLYGON);
      	glVertex2f(170,0);
		glVertex2f(170,170);
		glVertex2f(200,200);
	  	glVertex2f(200,0);
	glEnd();
  //upper wall
    glColor3f(0.9,0.7,0.3);
    glBegin(GL_POLYGON);
      	glVertex2f(30,170);
		glVertex2f(170,170);
		glVertex2f(200,200);
	  	glVertex2f(0,200);
	glEnd();
//inner wall
    glColor3f(0.9,0.6,0.4);
    glRectf(30,0,170,170);
//broard white back   
    glColor3f(1,1,1);
    glRectf(40,85,160,155);
//green broad inside white
    glColor3f(0.7,0.8,0.4);
    glRectf(42,87,158,153);
//down wakers
   glColor3f(0.7,0.7,0.5);
    glBegin(GL_POLYGON);
      	glVertex2f(0,0);
		glVertex2f(30,20);
		glVertex2f(170,20);
	  	glVertex2f(200,0);
	glEnd();
//down box 
    glColor3f(0.8,0.8,0.7);
    glRectf(20,10,180,27);  
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
      	glVertex2f(20,27);
		glVertex2f(180,27);
		glVertex2f(170,40);
	  	glVertex2f(30,40);
	glEnd();

}

//leature in class
void person1(void)
{
    glTranslatef(0,10,0);
//hair
   glColor3f(0.0,0.0,0.0);  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(133,107,0);
   glutSolidSphere(4,200,200);
   glPopMatrix();  
   glRecti(129,100,137,107);
//face
   glColor3f(0.9,0.8,0.6);  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(130,100,0);
   glutSolidSphere(1,200,200);
   glPopMatrix();

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(136,100,0);
   glutSolidSphere(1,200,200);
   glPopMatrix();
//coat triangle
    glBegin(GL_POLYGON);
    glColor3f( 0.2,0.5,0.5); 
    glVertex2i(126,92);
    glVertex2i(140,92);
    glVertex2i(133,100);
    glEnd();
//dress 
//rectangle
    glColor3f( 0.2,0.5,0.5); 
    glRecti(126,70,140,92);
//button
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.4,0.4,0.5);
   glTranslatef(133,75,0); 
   glScalef(1,1.1,1);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
//hand left 
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f( 0.2,0.5,0.5);
   glTranslatef(125.5,90,0); 
   glScalef(1,1.6,1);
   glutSolidSphere(1.5,200,200);
   glPopMatrix();

   glRecti(124,68,126,90);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.8,0.6);  
   glTranslatef(125,66.5,0);
   glScalef(0.9,1.5,1);
   glutSolidSphere(1.6,200,200);
   glPopMatrix();
//hand right
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f( 0.2,0.5,0.5);
   glTranslatef(140.5,90,0);
   glScalef(1,1.6,1);
   glutSolidSphere(1.5,200,200);
   glPopMatrix();

   glRecti(140,68,142,90);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.8,0.6);  
   glTranslatef(141.5,66.5,0);
   glScalef(0.9,1.5,1);
   glutSolidSphere(1.6,200,200);
   glPopMatrix();
//triangle
    glBegin(GL_POLYGON);
    glColor3f(1,1,1); 
    glVertex2i(130,95);
    glVertex2i(136,95);
    glVertex2i(133,80);
    glEnd();
//tie
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.5,0.5);
    glVertex2i(133,95);
    glVertex2i(134,88);
    glVertex2i(133,85);
    glVertex2i(132,88); 
    glEnd();
//face box
   glColor3f(0.9,0.8,0.6);  
   glRecti(130,95,136,105);
//eye bro
  glColor3f(0.0,0.0,0.0);  
  glLineWidth(2.0);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.0);  
  glVertex2f(130.5,103);
  glVertex2f(132,103);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0.0,0.0);  
  glVertex2f(134,103);
  glVertex2f(135.5,103);
  glEnd();
//eye
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);  
   glTranslatef(135,101.5,0);
   glScalef(0.8,0.9,0.9);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(131.5,101.5,0);
   glScalef(0.9,0.9,0.9);
   glutSolidSphere(0.8,200,200);
   glPopMatrix();
//down sphere face
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.9,0.8,0.6);  
   glTranslatef(133,96,0);
   glutSolidSphere(3,200,200);
   glPopMatrix();
//mouth
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(133,98,0);
    glScalef(1,0.8,0.9);
    glutSolidSphere(1,200,200);
    glPopMatrix();
//panties
//left
//shoce left
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);
   glTranslatef(128,43,0);
   glScalef(0.9,2,1.5);
   glutSolidSphere(2.5,200,200);
   glPopMatrix();
   glColor3f(0.3,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2i(126,45);
   glVertex2i(126,70);
   glVertex2i(134,70);
   glVertex2i(131,45);
   glEnd();
//right
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glColor3f(0.0,0.0,0.0);
   glTranslatef(138,43,0);
   glScalef(0.9,2,1);
   glutSolidSphere(2.5,200,200);
   glPopMatrix();
   glColor3f(0.3,0.5,0.5);
   glBegin(GL_POLYGON);
   glVertex2i(140,45);
   glVertex2i(140,70);
   glVertex2i(133,70);
   glVertex2i(135,45);
   glEnd();
}

//name of the bus
void busname1(void)
{
  glPushMatrix();
  glColor3f(0.3,0.3,1);
	glRasterPos3f(238-z4,45,0);
        output1("MITE School"); 
  glPopMatrix();
}

void bus1(void)
{
  glTranslatef(110-z4,10,0);

  glColor3f(0.9,0.8,0);
  glRectf(115,10,195,105);
  glRectf(95,10,115,60);
  //forent wind 
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.8,0);
      	glVertex2f(115,105);
		glVertex2f(115,60);
		glVertex2f(112,60);
    glEnd();  
    //backward wind
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.8,0);
      	glVertex2f(195,10);
		glVertex2f(195,105);
		glVertex2f(198,103);
        glVertex2f(198,13);
    glEnd();   
    //forent wind
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.8,0);
      	glVertex2f(95,10);
		glVertex2f(95,60);
		glVertex2f(93,58);
        glVertex2f(93,12);
    glEnd();  
  //blue tip
  glColor3f(0.3,0.3,1);
  glRectf(93,15,198,25); 
  glRectf(93,28,198,30);   
  glRectf(93,45,198,48); 

//symbol red strips
    glColor3f(0.9,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(178,40);
    glVertex2f(178,35);
	glVertex2f(174,30);	
    glVertex2f(170,35);
    glVertex2f(170,40);
    glVertex2f(174,45);
	glEnd(); 

    //white strips
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(177,40);
	glVertex2f(177,35);
	glVertex2f(174,31);	
    glVertex2f(171,35);
	glVertex2f(171,40);
	glVertex2f(174,44);	
	glEnd();
    glRectf(171,35,170,37); 

    //strip of betterfly
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(173,33);
	glVertex2f(171,35);
	glVertex2f(172,38);	
	glEnd();

    //forent engine
    glBegin(GL_POLYGON);
        glColor3f(0.9,1,0.2);
      	glVertex2f(93,20);
		glVertex2f(93,50);
		glVertex2f(95,45);
	  	glVertex2f(95,25);
    glEnd();
    //window
    for(x=120;x<195;x=x+15)
    for(y=70;y<=85;y=y+10)
        {
            glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,1.0);
      		glVertex2f(x,y);
			glVertex2f(x,y+15);
		  	glVertex2f(x+10,y+15);
	  		glVertex2f(x+10,y);
            glEnd();
        }
        glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
      	glVertex2f(120,95);
		glVertex2f(120,70);
	    glVertex2f(118,70);
        glEnd();  
    //pad ligth
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(204-z4,50,0); 
    glScalef(1,2.5,0);
    glutSolidSphere(2,200,200);
    glPopMatrix();
    //tire backward
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(224-z4,18,0); 
    glScalef(2,3.4,0);
    glutSolidSphere(4,200,200);
    glPopMatrix();
    ///tire backward pin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.7,0.7,0.6);
  glTranslatef(224-z4,18,0); 
  glScalef(2,3.4,0);
  glRotatef(10-z4,1.0,0.0,0.0);
  glutSolidSphere(2,200,200);
  glPopMatrix();
  //tire foreward
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glTranslatef(280-z4,18,0); 
  glScalef(2,3.4,0);
  glutSolidSphere(4,200,200);
  glPopMatrix();
//tire forward pin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.7,0.7,0.6);
  glTranslatef(280-z4,18,0);
  glScalef(2,3.4,0);
  glRotatef(10-z4,1.0,0.0,0.0);
  glutSolidSphere(2,200,200);
  glPopMatrix();  
}

//rep
//name of the bus
void busname2(void)
{
  glPushMatrix();
  glColor3f(0.3,0.3,1);
  	glRasterPos3f(238-z5,45,0);
        output1("MITE School"); 
  glPopMatrix();
}

void bus2(void)
{
  glTranslatef(110-z5,10,0);

  glColor3f(0.9,0.8,0);
  glRectf(115,10,195,105);
  glRectf(95,10,115,60);
  //forent wind 
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.8,0);
      	glVertex2f(115,105);
		glVertex2f(115,60);
		glVertex2f(112,60);
    glEnd();  
    //backward wind
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.8,0);
      	glVertex2f(195,10);
		glVertex2f(195,105);
		glVertex2f(198,103);
        glVertex2f(198,13);
    glEnd();   
    //forent wind
    glBegin(GL_POLYGON);
        glColor3f(0.9,0.8,0);
      	glVertex2f(95,10);
		glVertex2f(95,60);
		glVertex2f(93,58);
        glVertex2f(93,12);
    glEnd();  
  //blue tip
  glColor3f(0.3,0.3,1);
  glRectf(93,15,198,25); 
  glRectf(93,28,198,30);   
  glRectf(93,45,198,48); 

//symbol red strips
    glColor3f(0.9,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(178,40);
    glVertex2f(178,35);
	glVertex2f(174,30);	
    glVertex2f(170,35);
    glVertex2f(170,40);
    glVertex2f(174,45);
	glEnd(); 

    //white strips
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(177,40);
	glVertex2f(177,35);
	glVertex2f(174,31);	
    glVertex2f(171,35);
	glVertex2f(171,40);
	glVertex2f(174,44);	
	glEnd();
    glRectf(171,35,170,37); 

    //strip of betterfly
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(173,33);
	glVertex2f(171,35);
	glVertex2f(172,38);	
	glEnd();

    //forent engine
    glBegin(GL_POLYGON);
        glColor3f(0.9,1,0.2);
      	glVertex2f(93,20);
		glVertex2f(93,50);
		glVertex2f(95,45);
	  	glVertex2f(95,25);
    glEnd();
    //window
    for(x=120;x<195;x=x+15)
    for(y=70;y<=85;y=y+10)
        {
            glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,1.0);
      		glVertex2f(x,y);
			glVertex2f(x,y+15);
		  	glVertex2f(x+10,y+15);
	  		glVertex2f(x+10,y);
            glEnd();
        }
        glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
      	glVertex2f(120,95);
		glVertex2f(120,70);
	    glVertex2f(118,70);
        glEnd();  
    //pad ligth
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(204-z5,50,0); 
    glScalef(1,2.5,0);
    glutSolidSphere(2,200,200);
    glPopMatrix();
    //tire backward
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(224-z5,18,0); 
    glScalef(2,3.4,0);
    glutSolidSphere(4,200,200);
    glPopMatrix();
    ///tire backward pin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.7,0.7,0.6);
  glTranslatef(224-z5,18,0); 
  glScalef(2,3.4,0);
  glRotatef(10-z5,1.0,0.0,0.0);
  glutSolidSphere(2,200,200);
  glPopMatrix();
  //tire foreward
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.0,0.0,0.0);
  glTranslatef(280-z5,18,0); 
  glScalef(2,3.4,0);
  glutSolidSphere(4,200,200);
  glPopMatrix();
//tire forward pin
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glColor3f(0.7,0.7,0.6);
  glTranslatef(280-z5,18,0);
  glScalef(2,3.4,0);
  glRotatef(10-z5,1.0,0.0,0.0);
  glutSolidSphere(2,200,200);
  glPopMatrix();  
}

/////////////////////////phases////////////////////////////////
void phase1(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);   
      glColor3f(0.9,0.5,0);
      glRectf(0,50,120,200); 
      glColor3f(0.8,0.4,0.4);
      glRectf(0,0,120,50); 
      glColor3f(0.9,0.8,0);
      glRectf(120,0,200,150); 
      glColor3f(1,0.6,0.6);
      glRectf(120,150,200,200); 
            //clg name
            glPushMatrix();
            glColor3f(0,0,1);
            glRasterPos3f(45,185,0); 
            output1("MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING ");
 	    //dp name
            glRasterPos3f(50,175,0); 
            output1("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
            glPopMatrix();
            // mini pp
            glRasterPos3f(85,165,0); 
            output1("MINI PROJECT ON");
            glPopMatrix();
            // COURCE NAME
            glRasterPos3f(54,155,0);
            output1("COMPUTER GRAPHCIS VISUALIZATION OF SCHOOL");
            glPopMatrix();
            // STUDENTS NAME
            glRasterPos3f(10,125,0);
            output1("BY:");
            
            glRasterPos3f(10,114,0);
            output1("KARTHIK R (4MT17CS046)");
           
            glRasterPos3f(10,106,0);
            output1("MD NOORUZAMAN (4MT17CS056)");
            // LECTURES
            glRasterPos3f(150,125,0);
            output1("GUIDED BY:");
      
            glRasterPos3f(150,114,0);
            output1("MRS.JEEVITHA SAMPATH");
          
            glRasterPos3f(150,106,0);
            output1("MS.SUHASINI");
            glPopMatrix();
            //scence name
            glPushMatrix();
            glColor3f(0,0,1);                
            	glRasterPos3f(80,15,0);
                output1("Press a for first scence"); 
	    glPopMatrix();
    glFlush();
}

void phase2(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        tree();
        builing();
        land();
        busstop();
        pole();
        person();
        girl();
        roadtopview();  
        sun();
        cloud();

          glPushMatrix();
          glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press s for next scence"); 
          glPopMatrix();
    glFlush();
}
//moving bus from 0
void move11()
{
  if(z11<190)
  {
    z11=z11+1;
  } 
}
void phase3(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
       tree();
        builing();
        land();
        busstop();
        pole();
        person();
        girl();
        roadtopview();  
        sun();
        cloud();
        bus();
        busname();

          glPushMatrix();
          glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press d for next scence"); 
          glPopMatrix();
    glFlush();
}
//moving bus form 190
void move()
{
    if(z11>=190)
    {
        z11=z11+1;
    } 
}

void phase4(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        tree();
        builing();
        land();
        busstop();
        pole();
        roadtopview();  
        sun();
        cloud();
        bus();
        busname();

    glPushMatrix();
          glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press f for next scence"); 
          glPopMatrix();
    glFlush();
}

void phase5(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        tree();
        cloud();
        schoolblock();
        schoolname();
        land();
        roadtopview();  
	      compound();
        gate();
	    
          glPushMatrix();
          glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press g for next scence"); 
          glPopMatrix();
    glFlush();
}
//moving gate
void move1()
{ if(z2!=-22 && z3<=20)
  {
    z2=z2-0.5;
    z3=z3+0.5;
  }
}

void phase6(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
          tree();
          cloud();
          schoolblock();
          schoolname();
          land();
          roadtopview();  
          gate();
	        compound();
            glPushMatrix();
          glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press h for next scence"); 
          glPopMatrix();
    glFlush();
}

void phase7(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
          tree();
          cloud();
          schoolblock();
          schoolname();
          land();
          roadtopview();  
          gate();
	        compound();
          bus();
          busname();  
          
            glPushMatrix();
            glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press j for next scence"); 
            glPopMatrix();
    glFlush();
}

void phase8(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
          tree();
          cloud();
          schoolblock();
          schoolname();
          land();
          roadtopview();  
          gate();
	        compound();
          person();
          girl();
          bus();
          busname();  
            glPushMatrix();
              glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press k for next scence"); 
          glPopMatrix();
        
    glFlush();
}

void phase9(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    walls(); 
    broadname();
    person1();
    table();

    glPushMatrix();
            glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press z for next scence"); 
            glPopMatrix();
    glFlush();
}

void phase10(void)
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
          tree();
          cloud();
          schoolblock();
          schoolname();
          land();
          roadtopview();  
          gate();
	        compound();
          person();
          girl();
          bus();
          busname();  
            glPushMatrix();
              glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press x for next scence"); 
          glPopMatrix(); 
     glFlush();     
}

void move2()
{
    if(z4<=130)
    { z4=z4+1; }
}
void phase11(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     tree();
          cloud();
          schoolblock();
          schoolname();
          land();
          roadtopview();  
          gate();
	        compound();
          person();
          girl();
    bus1();
    busname1(); 

    glPushMatrix();
            glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press c for next scence"); 
            glPopMatrix();
    glFlush();
}

void move3()
{
    if(z4>=130)
    { z4=z4+1; }
}
void phase12(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     tree();
          cloud();
          schoolblock();
          schoolname();
          land();
          roadtopview();  
          gate();
	        compound();
    bus1();
    busname1(); 

    glPushMatrix();
            glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press v for next scence"); 
            glPopMatrix();
    glFlush();
}

void move4()
{
  if(z5<130)
    { z5=z5+1; }
}
void phase13(void)
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        tree();
        builing();
        land();
        busstop();
        pole();
        roadtopview();  
        sun();
        cloud();
    bus2();
    busname2(); 

    glPushMatrix();
            glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press b for next scence"); 
            glPopMatrix();
    glFlush();
}

void move5()
{
    if(z5>=130)
    { z5=z5+1; }
}
void phase14(void)
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
       tree();
        builing();
        land();
        busstop();
        pole();
        person();
        girl();
        roadtopview();  
        sun();
        cloud(); 
         bus2();
    busname2();

          glPushMatrix();
          glColor3f(0,0,1);
		glRasterPos3f(80,15,0);
                output1("Press n for next scence"); 
          glPopMatrix();
    glFlush();
}

//////////////////////////////////////////////////////////////

///////////////////////displays///////////////////////////////

void display(void)
{
if(scence==0)
		{      
            phase1();
			glutPostRedisplay();
		}      
if(scence==1)
		{
            z11=0;
            phase2();
			glutPostRedisplay();
		}    
if(scence==2)
		{       move11();
            phase3();
			glutPostRedisplay();
		}      
if(scence==3)
		{
            move();
            phase4();
			glutPostRedisplay();
		}  
if(scence==4)
		{
             z2=0;z3=0;
            phase5();
			glutPostRedisplay();
		}
if(scence==5)
        {   z11=0;
            move1();
            phase6();
			glutPostRedisplay();
        }      
if(scence==6)
        {   move11();
            phase7();
			glutPostRedisplay();
        }      
if(scence==7)
        {  
            move();
            phase8();
			glutPostRedisplay();
        }       
if(scence==8)
        {   
            phase9();
			glutPostRedisplay();
        }      
if(scence==9)
        {  z4=0;
          move();
          phase10();
			glutPostRedisplay();
        }   
if(scence==10)
        { 
          move2();   
          phase11();
			glutPostRedisplay();
        }  
if(scence==11)
        {  z5=0;
          move3();   
          phase12();
			glutPostRedisplay();
        }           
if(scence==12)
        { 
          move4();   
          phase13();
			glutPostRedisplay();
        }  
if(scence==13)
        { 
          move5();   
          phase14();
			glutPostRedisplay();
        }  
if(scence==14)
        { 
          glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
          glColor3f(0.9,0.5,0);
      glRectf(0,50,120,200); 
      glColor3f(0.8,0.4,0.4);
      glRectf(0,0,120,50); 
      glColor3f(0.9,0.8,0);
      glRectf(120,0,200,150); 
      glColor3f(1,0.6,0.6);
      glRectf(120,150,200,200); 
          glPushMatrix();
          glColor3f(0,0,1);
          glRasterPos3f(90,100,0);
          output1("THANK YOU");
          glPopMatrix();
          glFlush();
      glutPostRedisplay();
        }                   
                                  
}

/////////////////////////////////////////////////////////////
int main(int argc,char **argv)
{
    printf("the school project\n");
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("phase 1\n");
    init();
  	glMatrixMode(GL_MODELVIEW);
      glutDisplayFunc(display);
    	glutKeyboardFunc(keys);
	  timer(0);
    timercloud(0);
    timerbus(0);
    timerbus1(0);
    timerbus2(0);
	  timergateleft(0);
	  timergateright(0);
    glutMainLoop();
	return(0);
}
