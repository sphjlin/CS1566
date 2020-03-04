//
//  library.h
//  lab03
///
//  Name: Sophia Lin.
//  Email: sjl81@pitt.edu
//  Date of Submission: 9/27/19.


#ifndef library_h
#define library_h

#include <stdio.h>
#include <math.h>

#ifdef __APPLE__  // include Mac OS X verions of headers
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else // non-Mac OS X operating systems
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#endif  // __APPLE__

typedef struct
{
    float x;
    float y;
    float z;
    float w;
} vec4;

typedef struct
{
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;
} mat4;

void print_v(vec4 *vToPrint);
vec4* svMul(float scalar, vec4 *v, vec4 *productV);
vec4* vAdd(vec4* v1, vec4* v2, vec4 *sumV);
vec4* vSub(vec4* v1, vec4* v2, vec4 *subV);
float vMagnitude(vec4 *v);
vec4* normalize(float magnitude, vec4 *v, vec4 *normV);
float dotProduct(vec4 *v1, vec4 *v2);
vec4* cProduct(vec4 *v1, vec4 *v2, vec4 *crossProduct);


void print_m(mat4 *m);
mat4* smMul(float scalar, mat4 *m, mat4 *productM);
mat4* mAdd(mat4 *m1, mat4 *m2, mat4 *sumM);
mat4* mSub(mat4 *m1, mat4 *m2, mat4 *subM);
mat4* mMul(mat4 *m1, mat4 *m2, mat4 *prodM);
mat4* mInverse(mat4 *m1, mat4 *inverseM);
mat4* mTrans(mat4 *m1, mat4 *transpose);
vec4* mvMul(mat4 *m, vec4 *v, vec4 *productMV);

#endif /* library_h */
