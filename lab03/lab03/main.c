/*
 *  lab03.c
 *
 *  Created on: Sept 26, 2019
 *      Author: Sophia Lin
 */


#ifdef __APPLE__  // include Mac OS X verions of headers
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>

#else // non-Mac OS X operating systems

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

#endif  // __APPLE__

#include "initShader.h"
#include <stdio.h>
#include "library.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

const float DegreesToRadians = M_PI / 180.0; // M_PI = 3.14159...

// Create 3D object verticies
vec4 vertices[222];

void initVertices()
{
    int k = 0;
    // phi = degree of angle

    for (float phi = -180; phi <= 180.0; phi += 10.0){
        // the <math.h>'s sin, cos, and tan work with radians only.
        // in each loop, draw two triangle
        float phiR = phi * DegreesToRadians;
        float phiR10 = (phi + 10) * DegreesToRadians;
        
        //printf("%f",sin(phi));
        //printf("%f",sin(phiR));
        
        // bottom
        vertices[k].x = 0;
        vertices[k].y = 0;
        vertices[k].z = 0;
        vertices[k].w = 1.0;
        k++;
        
        vertices[k].x = 0.45 * cos(phiR);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(phiR);
        vertices[k].w = 1.0;
        k++;
        
        vertices[k].x = 0.45 * cos(phiR10);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(phiR10);
        vertices[k].w = 1.0;
        k++;
        
        // top
        vertices[k].x = 0;
        vertices[k].y = 0.9;
        vertices[k].z = 0;
        vertices[k].w = 1.0;
        k++;
        
        vertices[k].x = 0.45 * cos(phiR);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(phiR);
        vertices[k].w = 1.0;
        k++;
        
        vertices[k].x = 0.45 * cos(phiR10);
        vertices[k].y = 0;
        vertices[k].z = 0.45 * sin(phiR10);
        vertices[k].w = 1.0;
        k++;
    }
    printf("actual number of vertices: %i\n",k);
}


// Color each face of object
vec4 colors[222];
void initColors()
{
    for(int i = 0; i < 222; i=i+3)
    {
        colors[i].x = colors[i+1].x = colors[i+2].x = rand() / (float)RAND_MAX;
        colors[i].y = colors[i+1].y = colors[i+2].y = rand() / (float)RAND_MAX;
        colors[i].z = colors[i+1].z = colors[i+2].z = rand() / (float)RAND_MAX;
        colors[i].w = 1.0;
    }
}

// Declare number of verticies
int num_vertices = 222;
/*void spin(){
    for(int i = 0; i < 222; i++)
    {
        float thetaR = 45 * DegreesToRadians;
        vertices[i].x = (vertices[i].x)*(vertices[i].x);
        vertices[i].y = vertices[i].y * cos(thetaR);
        vertices[i].z = vertices[i].z * cos(thetaR);
        vertices[i].w = 1.0;
        
    }
}*/

//-------------------------remains the same:---------------------------

void init(void)// same one as lab01
{
    GLuint program = initShader("./vshader.glsl", "./fshader.glsl");
    glUseProgram(program);
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);
    
    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    
    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) sizeof(vertices));
    
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDepthRange(1,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, num_vertices);
    
    glutSwapBuffers();
}

void keyboard(unsigned char key, int mousex, int mousey)
{
    if(key == 'q')
        exit(0);
    
    glutPostRedisplay();
}

int main(int argc, char **argv)// same one as lab01
{
    // new
    initVertices();
    initColors();
    //spin();
    // original
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Lab3 Sphere");
    //glewInit();
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}




