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




void ButtonCallBack(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        //if(y <= 380 && y>=310 && x>=530 && x>=580)
       // if(x>=630 && x<=750 )

        moving();

    glutPostRedisplay();


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

void keyboardCallback(unsigned char key, int x, int y) {
    if (key == 32) {
            // ASCII code for space key
 humanFuncRemove(80-L+R,90-D+U);
 D++;
 humanFunc(80-L+R,90-D+U);
    }
    if(key == 13){
        humanFuncRemove(80-L+R,90-D+U);
        L++;
        humanFunc(80-L+R,90-D+U);
    }    if(key == 9){
        humanFuncRemove(80-L+R,90-D+U);
        R++;
        humanFunc(80-L+R,90-D+U);
    }if(key == 8){
        humanFuncRemove(80-L+R,90-D+U);
        U++;
        humanFunc(80-L+R,90-D+U);
    }
}

void Line(float x0,float y0,float x1,float y1){

 glColor3f(0.0, 0.0, 0.0); // set color to red
    glBegin(GL_LINES); // enable line drawing mode
  glVertex2f(x0,y0);
  glVertex2f(x1, y1);
    glEnd();}

void Display()
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

waiterFunc(100,60);


    glFlush();
    glutPostRedisplay();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);
    glutCreateWindow("TEXT_DISPLAY");
    glClearColor(223.0f/255.0f, 255.0f/255.0f, 216.0f/255.0f,1.0);
    glMatrixMode(GLUT_SINGLE|GLUT_RGB);
    glLoadIdentity();
    glOrtho(-90.0,100.0,-15.0,100.0,0.0,1.0);

    glutDisplayFunc(Display);
    glutMouseFunc(ButtonCallBack);
    glutKeyboardFunc(keyboardCallback);
    glutMainLoop();
}
