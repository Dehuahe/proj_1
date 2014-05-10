#include <iostream>
#include <cmath>

#include <OpenGL/gl.h>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <GLUT/glut.h>

#include "Mouse.h"
#include "Keyboard.h"
#include "Camera.h"
#include "Texture.h"
#include "Math.h"
#import "Vector3f.h"


using namespace std;

static int win;

const int WINDOW_WIDTH=512;
const int WINDOW_HEIGHT=512;

const char * WINDOE_TITLE="3D object";

//const float MOUSE_SENSITIVITY = 0.1;
//const float WALKING_SPEED = 1.0;

float LAST_TIME;
float CURRENT_TIME;
float DELTA_TIME;

void display();
void reshape(int, int);
void inputActions();
void Draw_Axes (void);
void Draw_Teapot (void);


//teapot
float w, h, tip = 0, turn = 0;
float ORG[3] = {0,0,0};
float XP[3] = {1,0,0}, XN[3] = {-1,0,0},
YP[3] = {0,1,0}, YN[3] = {0,-1,0},
ZP[3] = {0,0,1}, ZN[3] = {0,0,-1};


int main (int argc, const char * argv[])
{
    //initialize GLUT and OpenGL
    glutInit(&argc, const_cast<char**>(argv));
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    
    //create window
    glutCreateWindow(WINDOE_TITLE);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    glutKeyboardFunc(Keyboard::keyDown);
    glutKeyboardUpFunc(Keyboard::keyUp);
    
    glutMotionFunc(Mouse::move);
    glutPassiveMotionFunc(Mouse::move);
    
    //Texture tex = *Texture::loadBMP("img1.bpm");
    
    glutMainLoop();

    return 0;
}


void display(){
    
    inputActions();
    /* clear the color buffer (resets everything to black) */
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    //camera transformations
    glTranslatef(-Camera::Position.x, -Camera::Position.y, -Camera::Position.z);
    glRotatef(Camera::Rotation.x, 1, 0, 0);
    glRotatef(Camera::Rotation.y, 0, 1, 0);
    glRotatef(Camera::Rotation.z, 0, 0, 1);
    
    /* start drawing triangles, each triangle takes 3 vertices
    glBegin(GL_TRIANGLES);
    
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1,-3);
    glColor3f(0, 1, 0);
    glVertex3f(0, 1,-3);
    glColor3f(0, 0, 1);
    glVertex3f(1, -1,-3);
    */
    
    glutSolidSphere(0.1,100,100);
    
    Draw_Teapot ();
    Draw_Axes ();
    
    
    /* tell OpenGL we're done drawing triangles */
    glEnd();
    
    /* swap the back and front buffers so we can see what we just drew */
    glutSwapBuffers();
}

void reshape(int width, int height){
    
    if (height==0){
        height=1;
    }
    float ratio= (float) width / height; //float
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    gluPerspective(45, ratio, 0.01, 1000);
    
    glMatrixMode(GL_MODELVIEW);
}


void inputActions() {
    
    //update globals
    CURRENT_TIME = ((float)glutGet(GLUT_ELAPSED_TIME)) / 1000;
    DELTA_TIME = CURRENT_TIME - LAST_TIME;
    LAST_TIME = CURRENT_TIME;
    
    
    //process mouse
    /*
    Mouse::update();
    Camera::Rotation.y += (float)Mouse::deltaX * MOUSE_SENSITIVITY;
    Camera::Rotation.x += (float)Mouse::deltaY * MOUSE_SENSITIVITY;
    */
    
    //process keys
    if (Keyboard::KEYS['w']) {
        //move forward
        Camera::Position.z += 0.01; /*(WALKING_SPEED * DELTA_TIME)  * Math::dsin(Camera::Rotation.y)*/
    }
    if (Keyboard::KEYS['s']) {
        //move backward
        Camera::Position.z -= 0.01; /* (WALKING_SPEED * DELTA_TIME) * Math::dsin(Camera::Rotation.y + 180)*/
    }
    if (Keyboard::KEYS['a']) {
        //move left
        Camera::Position.x += 0.01 ;/*(WALKING_SPEED * DELTA_TIME)  * Math::dsin(Camera::Rotation.y + 270)*/
    }
    if (Keyboard::KEYS['d']) {
        //move right
        Camera::Position.x -= 0.01 ;/* (WALKING_SPEED * DELTA_TIME) * Math::dsin(Camera::Rotation.y + 90)*/
    }
    if (Keyboard::KEYS['q']){
        //quit the window
        glutDestroyWindow(win);
        exit(0);
    }
}


void Draw_Axes (void)
{
    glPushMatrix ();
    
    glTranslatef (-2.4, -1.5, -5);
    glRotatef    (tip , 1,0,0);
    glRotatef    (turn, 0,1,0);
    glScalef     (0.25, 0.25, 0.25);
    
    glLineWidth (2.0);
    
    glBegin (GL_LINES);
    glColor3f (1,0,0);  glVertex3fv (ORG);  glVertex3fv (XP);    // X axis is red.
    glColor3f (0,1,0);  glVertex3fv (ORG);  glVertex3fv (YP);    // Y axis is green.
    glColor3f (0,0,1);  glVertex3fv (ORG);  glVertex3fv (ZP);    // z axis is blue.
    glEnd();
    
    glPopMatrix ();
}

void Draw_Teapot (void)
{
    glPushMatrix ();
    
    glTranslatef (0, 0, -5);
    glRotatef (tip , 1,0,0);
    glRotatef (turn, 0,1,0);
    
    glColor3f (1.0, 0.5, 0.1);
    glutSolidTeapot (1.0);
    
    if (true)  {
        glLineWidth (2.0);
        glColor3f (0.0, 0.2, 0.9);
        glutWireTeapot (1.01);
    }
    
    glPopMatrix ();
}



