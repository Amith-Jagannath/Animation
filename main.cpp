#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <gl/glut.h>
#include <unistd.h>
#include<ctime>
#include<ctime>
#include<math.h>
using namespace std;
int X=0,D=0,L=0,R=0,U=0;
void init() {
   // glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}
void delay(int milliseconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) * 1000 / CLOCKS_PER_SEC < milliseconds) {}
}
void displayString(char* text){

    for (int i = 0; i < strlen(text); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}
void sunFunc(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<=360;i++)
    {
        angle = i*PI /180;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}


void sitting(float humanx,float humany)
{
        //MAN LEFT
//man head
int d=80;
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5,1.5,humanx-80.0+d,humany-20.5);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25+d,humany-19.25);
    glVertex2f(humanx-81.25+d,humany-18);
    glVertex2f(humanx-78.75+d,humany-18);
    glVertex2f(humanx-78.75+d,humany-19.25);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75+d,humany-20);
    glVertex2f(humanx-79.25+d,humany-20);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75,humany-21.5);
    glVertex2f(humanx-79.25,humany-21.5);
    glEnd();

//man chest
   /* glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-77.0,humany-22.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();*/
//man t-shirt
    glColor3f(0.0f, 1.0f, 0.0f); //blue
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0+d,humany-22.0,0);
    glVertex3f(humanx-78.0+d,humany-22.0,0.0);
    glVertex3f(humanx-78.0+d,humany-28.0,0);
    glVertex3f(humanx-82.0+d,humany-28.0,0.0);
    glEnd();

//man hand
 glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-80.5+d,humany-24.0,0);
    glVertex3f(humanx-79.5+d,humany-24.0,0.0);
    glVertex3f(humanx-79.5+d,humany-29.0,0);
    glVertex3f(humanx-80.5+d,humany-29.0,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);
       glColor3f(1.0, 0.0, 0.0);
    glVertex3f(humanx-82.0+d,humany-28.0,0);
    glVertex3f(humanx-76.0+d,humany-28.0,0.0);
    glVertex3f(humanx-76.0+d,humany-30.0,0);
    glVertex3f(humanx-82.0+d,humany-30.0,0.0);
    glEnd();
    //pant down
     glBegin(GL_QUADS);
  glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-77.0+d,humany-30.0,0.0);
    glVertex3f(humanx-77.0+d,humany-35.0,0);
    glVertex3f(humanx-76.0+d,humany-35.0,0);
    glVertex3f(humanx-76.0+d,humany-30.0,0.0);
    glEnd();


//man leg divider

}
void servingFunc(float humanx,float humany)
{
        //MAN LEFT
//man head
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5,1.5,humanx-80.0,humany-20.5);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25,humany-19.25);
    glVertex2f(humanx-81.25,humany-18);
    glVertex2f(humanx-78.75,humany-18);
    glVertex2f(humanx-78.75,humany-19.25);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75,humany-20);
    glVertex2f(humanx-79.25,humany-20);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75,humany-21.5);
    glVertex2f(humanx-79.25,humany-21.5);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-77.0,humany-22.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();
//man t-shirt
    glColor3f(1.0f, 1.0f, 1.0f); //blue
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-28.0,0);
    glVertex3f(humanx-82.0,humany-28.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-82.0,humany-22.0,0.0);
    glVertex3f(humanx-82.0,humany-24.0,0);
    glVertex3f(humanx-83.0,humany-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-24.0,0);
    glVertex3f(humanx-77.0,humany-24.0,0.0);
    glEnd();
    //tray
    glColor3f(1,0,0);
   glBegin(GL_QUADS);
    glVertex3f(humanx-83.0,humany-26.0,0);
    glVertex3f(humanx-77.0,humany-26.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);
       glColor3f(0.0, 0.0, 0.0);
    glVertex3f(humanx-82.0,humany-28.0,0);
    glVertex3f(humanx-78.0,humany-28.0,0.0);
    glVertex3f(humanx-78.0,humany-35.0,0);
    glVertex3f(humanx-82.0,humany-35.0,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-81.5,humany-35.0,0);
    glVertex3f(humanx-78.5,humany-35.0,0.0);
    glVertex3f(humanx-78.5,humany-38.0,0);
    glVertex3f(humanx-81.5,humany-38.0,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);
       glColor3f(0.0, 0.0, 0);
    glVertex3f(humanx-80.0,humany-32.0,0);
    glVertex3f(humanx-80.0,humany-38.0,0.0);
    glEnd();
}




void waiterFunc(float humanx,float humany)
{
        //MAN LEFT
//man head
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5,1.5,humanx-80.0,humany-20.5);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25,humany-19.25);
    glVertex2f(humanx-81.25,humany-18);
    glVertex2f(humanx-78.75,humany-18);
    glVertex2f(humanx-78.75,humany-19.25);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75,humany-20);
    glVertex2f(humanx-79.25,humany-20);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75,humany-21.5);
    glVertex2f(humanx-79.25,humany-21.5);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-77.0,humany-22.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();
//man t-shirt
    glColor3f(1.0f, 1.0f, 1.0f); //blue
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-28.0,0);
    glVertex3f(humanx-82.0,humany-28.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-82.0,humany-22.0,0.0);
    glVertex3f(humanx-82.0,humany-24.0,0);
    glVertex3f(humanx-83.0,humany-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-24.0,0);
    glVertex3f(humanx-77.0,humany-24.0,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);
       glColor3f(0.0, 0.0, 0.0);
    glVertex3f(humanx-82.0,humany-28.0,0);
    glVertex3f(humanx-78.0,humany-28.0,0.0);
    glVertex3f(humanx-78.0,humany-35.0,0);
    glVertex3f(humanx-82.0,humany-35.0,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-81.5,humany-35.0,0);
    glVertex3f(humanx-78.5,humany-35.0,0.0);
    glVertex3f(humanx-78.5,humany-38.0,0);
    glVertex3f(humanx-81.5,humany-38.0,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);
       glColor3f(0.0, 0.0, 0);
    glVertex3f(humanx-80.0,humany-32.0,0);
    glVertex3f(humanx-80.0,humany-38.0,0.0);
    glEnd();
}
void humanFunc(float humanx,float humany)
{
        //MAN LEFT
//man head
       glColor3f(1, 0.76, 0.41);
    sunFunc(1.5,1.5,humanx-80.0,humany-20.5);

//main hair
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25,humany-19.25);
    glVertex2f(humanx-81.25,humany-18);
    glVertex2f(humanx-78.75,humany-18);
    glVertex2f(humanx-78.75,humany-19.25);
    glEnd();

//man eyes
    glColor3f(0,0,0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75,humany-20);
    glVertex2f(humanx-79.25,humany-20);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75,humany-21.5);
    glVertex2f(humanx-79.25,humany-21.5);
    glEnd();

//man chest
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-77.0,humany-22.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();
//man t-shirt
    glColor3f(0.0f, 1.0f, 0.0f); //blue
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-28.0,0);
    glVertex3f(humanx-82.0,humany-28.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-82.0,humany-22.0,0.0);
    glVertex3f(humanx-82.0,humany-24.0,0);
    glVertex3f(humanx-83.0,humany-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-24.0,0);
    glVertex3f(humanx-77.0,humany-24.0,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);
       glColor3f(1.0, 0.0, 0.0);
    glVertex3f(humanx-82.0,humany-28.0,0);
    glVertex3f(humanx-78.0,humany-28.0,0.0);
    glVertex3f(humanx-78.0,humany-35.0,0);
    glVertex3f(humanx-82.0,humany-35.0,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);
       glColor3f(1, 0.76, 0.41);
    glVertex3f(humanx-81.5,humany-35.0,0);
    glVertex3f(humanx-78.5,humany-35.0,0.0);
    glVertex3f(humanx-78.5,humany-38.0,0);
    glVertex3f(humanx-81.5,humany-38.0,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);
       glColor3f(0.0, 0.0, 0);
    glVertex3f(humanx-80.0,humany-32.0,0);
    glVertex3f(humanx-80.0,humany-38.0,0.0);
    glEnd();
}

void humanFuncRemove(float humanx,float humany)
{
        //MAN LEFT
//man head
     glColor3f(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f);
    sunFunc(1.5,1.5,humanx-80.0,humany-20.5);

//main hair
    //glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(humanx-81.25,humany-19.25);
    glVertex2f(humanx-81.25,humany-18);
    glVertex2f(humanx-78.75,humany-18);
    glVertex2f(humanx-78.75,humany-19.25);
    glEnd();

//man eyes
    // glColor3f(1,1,1);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(humanx-80.75,humany-20);
    glVertex2f(humanx-79.25,humany-20);
    glEnd();

//mans  mouth
    glLineWidth(0.5f);
    glBegin(GL_LINES);
    glVertex2f(humanx-80.75,humany-21.5);
    glVertex2f(humanx-79.25,humany-21.5);
    glEnd();

//man chest
    glBegin(GL_QUADS);

    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-77.0,humany-22.0,0.0);
    glVertex3f(humanx-77.0,humany-28.0,0);
    glVertex3f(humanx-83.0,humany-28.0,0.0);
    glEnd();
//man t-shirt
   //red
    glBegin(GL_QUADS);
    glVertex3f(humanx-82.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-28.0,0);
    glVertex3f(humanx-82.0,humany-28.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-83.0,humany-22.0,0);
    glVertex3f(humanx-82.0,humany-22.0,0.0);
    glVertex3f(humanx-82.0,humany-24.0,0);
    glVertex3f(humanx-83.0,humany-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(humanx-77.0,humany-22.0,0);
    glVertex3f(humanx-78.0,humany-22.0,0.0);
    glVertex3f(humanx-78.0,humany-24.0,0);
    glVertex3f(humanx-77.0,humany-24.0,0.0);
    glEnd();

//man pant
    glBegin(GL_QUADS);

    glVertex3f(humanx-82.0,humany-28.0,0);
    glVertex3f(humanx-78.0,humany-28.0,0.0);
    glVertex3f(humanx-78.0,humany-35.0,0);
    glVertex3f(humanx-82.0,humany-35.0,0.0);
    glEnd();
//man legs
    glBegin(GL_QUADS);

    glVertex3f(humanx-81.5,humany-35.0,0);
    glVertex3f(humanx-78.5,humany-35.0,0.0);
    glVertex3f(humanx-78.5,humany-38.0,0);
    glVertex3f(humanx-81.5,humany-38.0,0.0);
    glEnd();
//man leg divider
    glBegin(GL_LINES);

    glVertex3f(humanx-80.0,humany-32.0,0);
    glVertex3f(humanx-80.0,humany-38.0,0.0);
    glEnd();
}
int i=0,j=0,i1=0,j11=0;
void motion2(int value){




 humanFuncRemove(80+j11,90-j);
 if(j>=30 && j11<=15)
    j11++;
 if(j<30)
j++;
 humanFunc(80+j11,90-j);

            glutTimerFunc(100,motion2,0);
            glutPostRedisplay();
            }
void motion1(int value){




 humanFuncRemove(80-i1,90-i);


if(i>=52 &&i1<=10 )
    i1++;
if(i<52)
    i++;


 humanFunc(80-i1,90-i);


if(i==40) motion2(1000);
            glutTimerFunc(100,motion1,0);

            glutPostRedisplay();
            }

void moving(){

X=X+1;


    glColor3f(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f);
     glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(X, 50);
        glVertex2f(X, 75);
        glVertex2f(0, 75);
        glVertex2f(0, 50);
    glEnd();

     glColor3f(158.0f/255.0f, 118.0f/255.0f, 118.0f/255.0f);
     glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(X, 50);
        glVertex2f(X, 75);
        glVertex2f(15, 75);
        glVertex2f(15, 50);
    glEnd();
     glColor3f(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f);
     glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(-15-X, 50);
        glVertex2f(-15-X, 75);
        glVertex2f(0, 75);
        glVertex2f(0, 50);
    glEnd();

     glColor3f(158.0f/255.0f, 118.0f/255.0f, 118.0f/255.0f);
     glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(-15, 50);
        glVertex2f(-15, 75);
        glVertex2f(0-X, 75);
        glVertex2f(0-X, 50);
     glEnd();



}
int ser =0;
void servingDisplay(int value){
humanFuncRemove(ser,41);
ser++;
   servingFunc(ser,41);
   if(ser<120){
   glutTimerFunc(100,servingDisplay,0);

            glutPostRedisplay();

   }


}



void ButtonCallBack(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        //if(y <= 380 && y>=310 && x>=530 && x>=580)
       // if(x>=630 && x<=750 )

        moving();

    glutPostRedisplay();
    if(y>=50){
       servingDisplay(10);
    }


    }



}
void table(float tx,float ty){
glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(-55+tx, 5+ty);
        glVertex2f(-55+tx, 7+ty);
        glVertex2f(-20+tx, 7+ty);
        glVertex2f(-20+tx, 5+ty);
    glEnd();
    glBegin(GL_QUADS);             // draw a quadrilateral

        glVertex2f(-55+tx, 7+ty);
        glVertex2f(-45+tx, 12+ty);
        glVertex2f(-14+tx, 12+ty);
         glVertex2f(-20+tx, 7+ty);
    glEnd();
     glBegin(GL_QUADS);             // draw a quadrilateral

         glVertex2f(-20+tx, 5+ty);
         glVertex2f(-20+tx, 7+ty);
         glVertex2f(-14+tx, 12+ty);
         glVertex2f(-14+tx, 10+ty);
    glEnd();
    //legs
      glBegin(GL_QUADS);             // draw a quadrilateral

         glVertex2f(-50+tx, -5+ty);
         glVertex2f(-50+tx, 7+ty);
         glVertex2f(-48+tx, 7+ty);
         glVertex2f(-48+tx, -5+ty);
     glEnd();
     glBegin(GL_QUADS);             // draw a quadrilateral

         glVertex2f(-45+tx, -2+ty);
         glVertex2f(-45+tx, 7+ty);
         glVertex2f(-43+tx, 7+ty);
         glVertex2f(-43+tx, -2+ty);
    glEnd();
    glBegin(GL_QUADS);             // draw a quadrilateral

         glVertex2f(-24+tx, -5+ty);
         glVertex2f(-24+tx, 7+ty);
         glVertex2f(-22+tx, 7+ty);
         glVertex2f(-22+tx, -5+ty);
    glEnd();
    glBegin(GL_QUADS);             // draw a quadrilateral

         glVertex2f(-17+tx, -1+ty);
         glVertex2f(-17+tx, 9+ty);
         glVertex2f(-19+tx, 9+ty);
         glVertex2f(-19+tx, -1+ty);
    glEnd();

}
void endConvo(int value){
   // glColor3f(1,1,1);
glColor3f(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f);

char* conv1 = "Your order pls!";
     char* conv2 = "I need coffee";
    glRasterPos2i(30.0f,19.0f);
    displayString(conv1);
    Sleep(1000);
    glRasterPos2i(5.0f,19.0f);
    displayString(conv2);
}
void convo2(int value){
    glColor3f(1,0,0);
    char* convo="I need a coffe";
 glRasterPos2i(5.0f,19.0f);
    displayString(convo);
    glutTimerFunc(1000,endConvo,0);
    glutPostRedisplay();
}
void conversation(){


/*glBegin(GL_QUADS);
glColor3f(1,0,0);
           glVertex2f(-45, 25);
        glVertex2f(-45, 15);
        glVertex2f(-25, 15);
        glVertex2f(-25, 25);
    glEnd();*/
    glColor3f(0,1,0);
    char* conv1 = "Your order pls!";

    glRasterPos2i(30.0f,19.0f);
    displayString(conv1);


    glutTimerFunc(1000,convo2,0);
    glutPostRedisplay();


}

bool move1=false;
void keyboardCallback(unsigned char key, int x, int y) {
    if (key == 32) {
            // ASCII code for space key
           if(move1==false){
           motion1(1000);
           move1=true;
           }
           if(move1==true){
            humanFuncRemove(30-L+R,85-D+U);
            D++;
            waiterFunc(30-L+R,85-D+U);
           }

    }

    if(key == 13){
        humanFuncRemove(30-L+R,85-D+U);
        L++;
        waiterFunc(30-L+R,85-D+U);
    }    if(key == 9){
        humanFuncRemove(30-L+R,85-D+U);
        R++;
        waiterFunc(30-L+R,85-D+U);
    }if(key == 8){
        humanFuncRemove(30-L+R,85-D+U);
        U++;
        waiterFunc(30-L+R,85-D+U);
    }
    if(key == 8){

    }
    if(R==70){
        conversation();
    }



}


void Line(float x0,float y0,float x1,float y1){

 glColor3f(0.0, 0.0, 0.0); // set color to red
    glBegin(GL_LINES); // enable line drawing mode
  glVertex2f(x0,y0);
  glVertex2f(x1, y1);
    glEnd();}
void chair(float x0,float y0,int flag){
    int c=0;
    if(flag==1) c=-6.5;
      glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(-8+x0, 2+y0);
        glVertex2f(-6.5+x0, 6+y0);
        glVertex2f(0+x0, 6+y0);
        glVertex2f(-1.5+x0, 2+y0);
    glEnd();
     glBegin(GL_QUADS);           // draw a quadrilateral
        glVertex2f(0+x0+c, 6+y0);
        glVertex2f(-1.5+x0+c, 2+y0);
         glVertex2f(-1.5+x0+c, 10+y0);
        glVertex2f(0+x0+c, 13+y0);

    glEnd();
    glColor3f(0.0, 0.0, 0.0); // set color to green
    glLineWidth(5.0); // set line width to 5 pixels
    glBegin(GL_LINES);
        glVertex3f(-7+x0, 2.0+y0, 0.0); // start point
        glVertex3f(-7+x0, -4.0+y0, 0.0); // end point
    glEnd();
        glBegin(GL_LINES);
        glVertex3f(-5+x0, 6.0+y0, 0.0); // start point
        glVertex3f(-5+x0, -2.0+y0, 0.0); // end point
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-.5+x0, 6.0+y0, 0.0); // start point
        glVertex3f(-.5+x0, -2.0+y0, 0.0); // end point
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(-2.5+x0, 2.0+y0, 0.0); // start point
        glVertex3f(-2.5+x0, -4.0+y0, 0.0); // end point
    glEnd();}
void display()
{
   glColor3f(1.0f, 1.0f, 1.0f);  // Set the text color

   /*glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(-135, -100);
        glVertex2f(-55, 50);
        glVertex2f(60, 50);
        glVertex2f(155, -100);
    glEnd();*/
    //left wall
    glColor3f(158.0f/255.0f, 118.0f/255.0f, 118.0f/255.0f);
     glBegin(GL_QUADS);             // draw a quadrilateral
        glVertex2f(-135, -100);
        glVertex2f(-135, 100);
        glVertex2f(-55, 100);
        glVertex2f(-55, 50);
    glEnd();
    //right wall
      glColor3f(158.0f/255.0f, 118.0f/255.0f, 118.0f/255.0f);
     glBegin(GL_QUADS);
      glVertex2f(60, 50);
       glVertex2f(60, 100);           // draw a quadrilateral
        glVertex2f(155, 100);
        glVertex2f(155, -100);
    glEnd();
   glColor3f(164.0f/255.0f, 47.0f/255.0f, 29.0f/255.0f);
//left door
glBegin(GL_QUADS);
//glColor3f(0.0,0,0);
           glVertex2f(-65, 31);
        glVertex2f(-65, 60);
        glVertex2f(-75, 55);
        glVertex2f(-75, 12);
    glEnd();
     //************************************TABLES**************************//
     table(0,0);
     table(80,0);
     table(0,30);
     table(80,30);

    //******************Border********************/
    Line(-135,-100,-55,50);
    Line(-55,50,-55,100);
    Line(-55,50,-55,100);
    Line(-55,50,60,50);
    Line(60,50,60,100);
    Line(60,50,155,-100);
    //door borders
    Line(-15,75,15,75);
    Line(-15,75,-15,50);
    Line(15,75,15,50);


   chair(0,0,0);
   chair(-60,0,1);
   chair(80,0,0);
   chair(20,0,1);
   chair(-5,30,0);
   //chair(-60,30,1);
   chair(28,28,1);



                 // draw a quadrilateral




waiterFunc(150,45);

sitting(17,35);

    glFlush();

    glutPostRedisplay();
}





void newdisp()
{ char* message="Welcome to our restaurant";







    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);
    glutCreateWindow("TEXT_DISPLAY");
    glClearColor(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f,1.0);
    glMatrixMode(GLUT_SINGLE|GLUT_RGB);
    glLoadIdentity();
    glOrtho(-90.0,100.0,-15.0,100.0,0.0,1.0);

    glutDisplayFunc(display);
    glutMouseFunc(ButtonCallBack);
    glutKeyboardFunc(keyboardCallback);
    glutMainLoop();

}

void ButtonCallBack1(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        //if(y <= 380 && y>=310 && x>=530 && x>=580)
       // if(x>=630 && x<=750 )
       if(y>=430 && y<=500)
        {
        glutCreateWindow("NEW_WINDOW");
        glutDisplayFunc(newdisp);
        }
    glutPostRedisplay();
    }
}



void Display()
{
    glColor3f(0.0f, 0.0f, 0.0f);  // Set the text color

   char* rest = "THE IMPERIAL";
    char* name="Name";
    char* usn="USN";
    char* amith="Amith Jagannath Soorenji";
    char* adarsh="Adarsh J Shetty";
    char* usn23="4NM20CS023";
    char* usn10="4NM20CS010";
    char* next ="Next";
    char* under="Under the guidance of";
    char* pra="Dr Pradeep Kanchan";
    char* pu="Mr Puneet RP";

         glRasterPos2f(-9.0f, 75.0f);
          displayString(rest);



    glRasterPos2i(-55.0f,62.0f);
    displayString(amith);
    glRasterPos2i(-55.0f,54.0f);
    displayString(adarsh);
     glRasterPos2i(34.0f,62.0f);
   displayString(usn23);
     glRasterPos2i(34.0f,54.0f);
    displayString(usn10);
    glRasterPos2i(-13.0f,46.0f);
    displayString(under);
     glRasterPos2i(-55.0f,38.0f);
    displayString(pra);
     glRasterPos2i(34.0f,38.0f);
    displayString(pu);
    glColor3f(0.6f, 9.0f, 8.0f);
    glPushMatrix();
    glRectf(-10,35,5,28);
   glColor3f(0.0f, 0.0f, 0.4f);//Text color of "NEXT"

    glRasterPos2f(-6.0f, 30.0f);
    for (int i = 0; i < strlen(next); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, next[i]);
    }


    glEnd();
    glFlush();
    glutPostRedisplay();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1500,1500);
    glutCreateWindow("TEXT_DISPLAY");
    glClearColor(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f,1.0);
    glMatrixMode(GLUT_SINGLE|GLUT_RGB);
    glLoadIdentity();
    glOrtho(-90.0,100.0,-15.0,100.0,0.0,1.0);
    glutDisplayFunc(Display);
    glutMouseFunc(ButtonCallBack1);
    glutMainLoop();
}
