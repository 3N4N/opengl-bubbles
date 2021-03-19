#include "glutshapes.h"
#include "point.h"

#include<math.h>

#define pi (2*acos(0.0))

void drawAxes(int drawaxes)
{
    if(drawaxes==1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);{
            glVertex2f( 100,0);
            glVertex2f(-100,0);

            glVertex2f(0,-100);
            glVertex2f(0, 100);
        }glEnd();
    }
}


void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);{
        glVertex2f( a, a);
        glVertex2f( a,-a);
        glVertex2f(-a,-a);
        glVertex2f(-a, a);

        glVertex2f(-a, a);
        glVertex2f( a, a);
        glVertex2f( a,-a);
        glVertex2f(-a,-a);
    }glEnd();
}


void drawCircle(double radius,int segments)
{
    int i;
    struct point points[100];
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
            glVertex2f(points[i].x,points[i].y);
            glVertex2f(points[i+1].x,points[i+1].y);
        }
        glEnd();
    }
}

