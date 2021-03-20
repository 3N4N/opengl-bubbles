#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#include <GL/glut.h>

#include "point.h"
#include "bubble.h"
#include "glutshapes.h"

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawaxes;
double angle;

double squareSide = 150;
double circleRadius = 100;
double bubbleRadius = 10;

bubble bubbles[5];


void keyboardListener(unsigned char key, int x,int y){
    switch(key){

        case '1':
            break;

        default:
            break;
    }
}


void specialKeyListener(int key, int x,int y){
    switch(key){
        case GLUT_KEY_DOWN:     //down arrow key
            cameraHeight -= 3.0;
            break;
        case GLUT_KEY_UP:       // up arrow key
            cameraHeight += 3.0;
            break;

        case GLUT_KEY_RIGHT:
            cameraAngle += 0.03;
            break;
        case GLUT_KEY_LEFT:
            cameraAngle -= 0.03;
            break;

        case GLUT_KEY_PAGE_UP:
            break;
        case GLUT_KEY_PAGE_DOWN:
            break;

        case GLUT_KEY_INSERT:
            break;

        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;

        default:
            break;
    }
}


void mouseListener(int button, int state, int x, int y){    //x, y is the x-y of the screen (2D)
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){     // 2 times?? in ONE click? -- solution is checking DOWN or UP
                drawaxes=1-drawaxes;
            }
            break;

        case GLUT_RIGHT_BUTTON:
            //........
            break;

        case GLUT_MIDDLE_BUTTON:
            //........
            break;

        default:
            break;
    }
}



void display(){

    //clear the display
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);  //color black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /********************
    / set-up camera here
    ********************/
    //load the correct matrix -- MODEL-VIEW matrix
    glMatrixMode(GL_MODELVIEW);

    //initialize the matrix
    glLoadIdentity();

    //now give three info
    //1. where is the camera (viewer)?
    //2. where is the camera looking?
    //3. Which direction is the camera's UP direction?

    //gluLookAt(100,100,100,    0,0,0,  0,0,1);
    //gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,       0,0,0,      0,0,1);
    gluLookAt(0,0,200,  0,0,0,  0,1,0);


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);


    /****************************
    / Add your objects from here
    ****************************/
    //add objects

    drawAxes(drawaxes);

    glColor3f(0,1,0);
    drawSquare(squareSide);

    glColor3f(1,0,0);
    drawCircle(circleRadius,50);

    for (int i = 0; i < 5; i++) {
        if (bubbles[i].pos.x - bubbleRadius >= -1*squareSide
            && bubbles[i].pos.y - bubbleRadius >= -1*squareSide
            && bubbles[i].pos.x + bubbleRadius <= squareSide
            && bubbles[i].pos.y + bubbleRadius <= squareSide) {
            glTranslatef(bubbles[i].pos.x, bubbles[i].pos.y,0);
            drawCircle(bubbleRadius,20);
            glTranslatef(-1*bubbles[i].pos.x, -1*bubbles[i].pos.y,0);
        }
    }



    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}


void animate(){
    angle+=0.05;
    for (int i = 0; i < 5; i++) {
        bubbles[i].pos.x += bubbles[i].speed.x;
        bubbles[i].pos.y += bubbles[i].speed.y;

        if (bubbles[i].pos.x + bubbleRadius >= squareSide
            && bubbles[i].pos.y + bubbleRadius >= squareSide) {
            bubbles[i].speed.x *= -1;
            bubbles[i].speed.y *= -1;
        }
        else if (bubbles[i].pos.x + bubbleRadius >= squareSide
                 && bubbles[i].pos.y - bubbleRadius <= -1*squareSide) {
            bubbles[i].speed.x *= -1;
            bubbles[i].speed.y *= -1;
        }
        else if (bubbles[i].pos.x - bubbleRadius <= -1*squareSide
                 && bubbles[i].pos.y - bubbleRadius <= -1*squareSide) {
            bubbles[i].speed.x *= -1;
            bubbles[i].speed.y *= -1;
        }
        else if (bubbles[i].pos.x - bubbleRadius <= -1*squareSide
                 && bubbles[i].pos.y + bubbleRadius >= squareSide) {
            bubbles[i].speed.x *= -1;
            bubbles[i].speed.y *= -1;
        }
        // if (bubbles[i].pos.x + bubbleRadius >= squareSide) {
        else if (bubbles[i].pos.x + bubbleRadius >= squareSide) {
            bubbles[i].speed.x *= -1;
            // bubbles[i].speed.y *= -1;
        }
        else if (bubbles[i].pos.x - bubbleRadius <= -1*squareSide) {
            bubbles[i].speed.x *= -1;
            // bubbles[i].speed.y *= -1;
        }
        else if (bubbles[i].pos.y + bubbleRadius >= squareSide) {
            // bubbles[i].speed.x *= -1;
            bubbles[i].speed.y *= -1;
        }
        else if (bubbles[i].pos.y - bubbleRadius <= -1*squareSide) {
            // bubbles[i].speed.x *= -1;
            bubbles[i].speed.y *= -1;
        }


    }
    //codes for any changes in Models, Camera
    glutPostRedisplay();
}

void init(){
    //codes for initialization
    drawaxes=0;
    cameraHeight=150.0;
    cameraAngle=1.0;
    angle=0;

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        bubbles[i].pos.x = -1*squareSide + bubbleRadius;
        bubbles[i].pos.y = -1*squareSide + bubbleRadius;
        bubbles[i].speed.x = (double) rand() / RAND_MAX;
        bubbles[i].speed.y = (double) rand() / RAND_MAX;
        printf("%f,%f\n",bubbles[i].speed.x,bubbles[i].speed.y);
    }

    //clear the screen
    glClearColor(0,0,0,0);

    /************************
    / set-up projection here
    ************************/
    //load the PROJECTION matrix
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    //give PERSPECTIVE parameters
    gluPerspective(80,  1,  1,  1000.0);
    //field of view in the Y (vertically)
    //aspect ratio that determines the field of view in the X direction (horizontally)
    //near distance
    //far distance
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);   //Depth, Double buffer, RGB color

    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);    //enable Depth Testing

    glutDisplayFunc(display);   //display callback function
    glutIdleFunc(animate);      //what you want to do in the idle time (when no drawing is occuring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);

    glutMainLoop();     //The main loop of OpenGL

    return 0;
}
