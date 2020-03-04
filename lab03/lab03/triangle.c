//
//  library.c
//  lab03
//
//  Name: Sophia Lin.
//  Email: sjl81@pitt.edu
//  Date of Submission: 9/27/19.
//

#include "library.h"

void print_v(vec4 *vToPrint){
    float xComp, yComp, zComp, wComp;
    xComp = vToPrint->x;
    yComp = vToPrint->y;
    zComp = vToPrint->z;
    wComp = vToPrint->w;
    
    printf("[%.2f %.2f %.2f %.2f]\n", xComp,yComp,zComp,wComp);
}

vec4* svMul(float scalar, vec4 *v, vec4 *productV){
    // s*A = {s*a1, s*a2, s*a3, s*a4}
    float xComp, yComp, zComp, wComp;
    xComp = scalar * v->x;
    yComp = scalar * v->y;
    zComp = scalar * v->z;
    wComp = scalar * v->w;
    productV->x = xComp;
    productV->y = yComp;
    productV->z = zComp;
    productV->w = wComp;
    return productV;
}

vec4* vAdd(vec4* v1, vec4* v2, vec4 *sumV){
    //A + B = {a1+b1, a2+b2, a3+b3, a4+b4}
    float xComp, yComp, zComp, wComp;
    xComp = v1->x + v2->x;
    yComp = v1->y + v2->y;
    zComp = v1->z + v2->z;
    wComp = v1->w + v2->w;
    sumV->x = xComp;
    sumV->y = yComp;
    sumV->z = zComp;
    sumV->w = wComp;
    return sumV;
}

vec4* vSub(vec4* v1, vec4* v2, vec4 *subV){
    //A - B = {a1-b1, a2-b2, a3-b3, a4-b4}
    float xComp, yComp, zComp, wComp;
    xComp = v1->x - v2->x;
    yComp = v1->y - v2->y;
    zComp = v1->z - v2->z;
    wComp = v1->w - v2->w;
    subV->x = xComp;
    subV->y = yComp;
    subV->z = zComp;
    subV->w = wComp;
    return subV;
}

float vMagnitude(vec4 *v){
    float xComp, yComp, zComp, wComp;
    xComp = v->x;
    yComp = v->y;
    zComp = v->z;
    wComp = v->w;
    // "^2" does not work for floats
    float magnitude = sqrt(xComp * xComp + yComp * yComp + zComp * zComp + wComp * wComp);
    return magnitude;
}

vec4* normalize(float magnitude, vec4 *v, vec4 *normV){
    svMul(magnitude, v, normV);
    return normV;
}

float dotProduct(vec4 *v1, vec4 *v2){
    // A · B = a1b1 + a2b2 + a3b3 + a4b4
    float product = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z) + (v1->w * v2->w);
    return product;
}

vec4* cProduct(vec4 *v1, vec4 *v2, vec4 *crossProduct){
    //A X B = {a2b3 - a3b2, a3b1 - a1b3, a1b2 - a2b1 , 0.0}
    float xComp, yComp, zComp, wComp;
    xComp = v1->y * v2->z - v1->z * v2->y;
    yComp = v1->z * v2->x - v1->x * v2->z;
    zComp = v1->x * v2->y - v1->y * v2->x;
    wComp = 0.0;
    crossProduct->x = xComp;
    crossProduct->y = yComp;
    crossProduct->z = zComp;
    crossProduct->w = wComp;
    return crossProduct;
}

void print_m(mat4 *m){
    //mat4 = {{a1b1,a2b1,a3b1,a4b1},{a1b2,a2b2,a3b2,a4b2}....}
    printf("| %.2f  %.2f  %.2f  %.2f |\n",m->x.x,m->y.x,m->z.x,m->w.x);
    printf("| %.2f  %.2f  %.2f  %.2f |\n",m->x.y,m->y.y,m->z.y,m->w.y);
    printf("| %.2f  %.2f  %.2f  %.2f |\n",m->x.z,m->y.z,m->z.z,m->w.z);
    printf("| %.2f  %.2f  %.2f  %.2f |\n\n",m->x.w,m->y.w,m->z.w,m->w.w);
}

mat4* smMul(float scalar, mat4 *m, mat4 *productM){
    //column 1
    productM->x.x = scalar * m->x.x;
    productM->y.x = scalar * m->y.x;
    productM->z.x = scalar * m->z.x;
    productM->w.x = scalar * m->w.x;
    //column 2
    productM->x.y = scalar * m->x.y;
    productM->y.y = scalar * m->y.y;
    productM->z.y = scalar * m->z.y;
    productM->w.y = scalar * m->w.y;
    //column 3
    productM->x.z = scalar * m->x.z;
    productM->y.z = scalar * m->y.z;
    productM->z.z = scalar * m->z.z;
    productM->w.z = scalar * m->w.z;
    //column 4
    productM->x.w = scalar * m->x.w;
    productM->y.w = scalar * m->y.w;
    productM->z.w = scalar * m->z.w;
    productM->w.w = scalar * m->w.w;
    return productM;
}

mat4* mAdd(mat4 *m1, mat4 *m2, mat4 *sumM){
    //column 1
    sumM->x.x = m1->x.x + m2->x.x;
    sumM->y.x = m1->y.x + m2->y.x;
    sumM->z.x = m1->z.x + m2->z.x;
    sumM->w.x = m1->w.x + m2->w.x;
    //column 2
    sumM->x.y = m1->x.y + m2->x.y;
    sumM->y.y = m1->y.y + m2->y.y;
    sumM->z.y = m1->z.y + m2->z.y;
    sumM->w.y = m1->w.y + m2->w.y;
    //column 3
    sumM->x.z = m1->x.z + m2->x.z;
    sumM->y.z = m1->y.z + m2->y.z;
    sumM->z.z = m1->z.z + m2->z.z;
    sumM->w.z = m1->w.z + m2->w.z;
    //column 4
    sumM->x.w = m1->x.w + m2->x.w;
    sumM->y.w = m1->y.w + m2->y.w;
    sumM->z.w = m1->z.w + m2->z.w;
    sumM->w.w = m1->w.w + m2->w.w;
    return sumM;
}

mat4* mSub(mat4 *m1, mat4 *m2, mat4 *subM){
    //column 1
    subM->x.x = m1->x.x - m2->x.x;
    subM->y.x = m1->y.x - m2->y.x;
    subM->z.x = m1->z.x - m2->z.x;
    subM->w.x = m1->w.x - m2->w.x;
    //column 2
    subM->x.y = m1->x.y - m2->x.y;
    subM->y.y = m1->y.y - m2->y.y;
    subM->z.y = m1->z.y - m2->z.y;
    subM->w.y = m1->w.y - m2->w.y;
    //column 3
    subM->x.z = m1->x.z - m2->x.z;
    subM->y.z = m1->y.z - m2->y.z;
    subM->z.z = m1->z.z - m2->z.z;
    subM->w.z = m1->w.z - m2->w.z;
    //column 4
    subM->x.w = m1->x.w - m2->x.w;
    subM->y.w = m1->y.w - m2->y.w;
    subM->z.w = m1->z.w - m2->z.w;
    subM->w.w = m1->w.w - m2->w.w;
    return subM;
}

mat4* mMul(mat4 *m1, mat4 *m2, mat4 *prodM){
    // c11 = (a11 × b11) + (a12 × b21) + (a13 × b31) + (a14 × b41)
    //column 1
    prodM->x.x = (m1->x.x * m2->x.x) + (m1->x.y * m2->y.x) + (m1->x.z * m2->z.x) + (m1->x.w * m2->w.x);
    prodM->y.x = (m1->y.x * m2->x.x) + (m1->y.y * m2->y.x) + (m1->y.z * m2->z.x) + (m1->y.w * m2->w.x);
    prodM->z.x = (m1->z.x * m2->x.x) + (m1->z.y * m2->y.x) + (m1->z.y * m2->z.x) + (m1->z.w * m2->w.x);
    prodM->w.x = (m1->w.x + m2->x.x) + (m1->w.y * m2->y.x) + (m1->w.y * m2->z.x) + (m1->w.w * m2->w.x);
    //column 2
    prodM->x.y = (m1->x.x * m2->x.y) + (m1->x.y * m2->y.y) + (m1->x.z * m2->z.y) + (m1->x.w * m2->w.y);
    prodM->y.y = (m1->y.x * m2->x.y) + (m1->y.y * m2->y.y) + (m1->y.z * m2->z.y) + (m1->y.w * m2->w.y);
    prodM->z.y = (m1->z.x * m2->x.y) + (m1->z.y * m2->y.y) + (m1->z.y * m2->z.y) + (m1->z.w * m2->w.y);
    prodM->w.y = (m1->w.x + m2->x.y) + (m1->w.y * m2->y.y) + (m1->w.y * m2->z.y) + (m1->w.w * m2->w.y);
    //column 3
    prodM->x.z = (m1->x.x * m2->x.z) + (m1->x.y * m2->y.z) + (m1->x.z * m2->z.z) + (m1->x.w * m2->w.z);
    prodM->y.z = (m1->y.x * m2->x.z) + (m1->y.y * m2->y.z) + (m1->y.z * m2->z.z) + (m1->y.w * m2->w.z);
    prodM->z.z = (m1->z.x * m2->x.z) + (m1->z.y * m2->y.z) + (m1->z.y * m2->z.z) + (m1->z.w * m2->w.z);
    prodM->w.z = (m1->w.x + m2->x.z) + (m1->w.y * m2->y.z) + (m1->w.y * m2->z.z) + (m1->w.w * m2->w.z);
    //column 4
    prodM->x.w = (m1->x.x * m2->x.w) + (m1->x.y * m2->y.w) + (m1->x.z * m2->z.w) + (m1->x.w * m2->w.w);
    prodM->y.w = (m1->y.x * m2->x.w) + (m1->y.y * m2->y.w) + (m1->y.z * m2->z.w) + (m1->y.w * m2->w.w);
    prodM->z.w = (m1->z.x * m2->x.w) + (m1->z.y * m2->y.w) + (m1->z.y * m2->z.w) + (m1->z.w * m2->w.w);
    prodM->w.w = (m1->w.x + m2->x.w) + (m1->w.y * m2->y.w) + (m1->w.y * m2->z.w) + (m1->w.w * m2->w.w);
    return prodM;
}

mat4* mInverse(mat4 *m, mat4 *inverseM){
    // if determinant = 0 or adjoint = 0, inverse does not exist.
    
    /* for self-need:
     | x.x  y.x  z.x  w.x |
     | x.y  y.y  z.y  w.y |
     | x.z  y.z  z.z  w.z |
     | x.w  y.w  z.w  w.w |
     */
    float determinant;
    determinant = m->x.x * ((m->y.y * m->z.z * m->w.w) + (m->z.y * m->w.z * m->y.w) + (m->w.y * m->y.z * m->z.w)
                            - (m->y.y * m->w.z * m->z.w) - (m->z.y * m->y.z * m->w.w) - (m->w.y * m->z.z * m->y.w))
    + m->y.x * ((m->x.y * m->w.z * m->z.w) + (m->z.y * m->x.z * m->w.w) + (m->w.y * m->z.z * m->x.w)
                - (m->x.y * m->z.z * m->w.w) - (m->z.y * m->w.z * m->x.w) - (m->w.y * m->x.z * m->z.w))
    + m->z.x * ((m->x.y * m->y.z * m->w.w) + (m->y.y * m->w.z * m->x.w) + (m->w.y * m->x.z * m->y.w)
                - (m->x.y * m->w.z * m->y.w) - (m->y.y * m->x.z * m->w.w) - (m->w.y * m->y.z * m->x.w))
    + m->w.x * ((m->x.y * m->z.z * m->y.w) + (m->y.y * m->x.z * m->z.w) + (m->z.y * m->y.z * m->x.w)
                - (m->x.y * m->y.z * m->z.w) - (m->y.y * m->z.z * m->x.w) - (m->z.y * m->x.z * m->y.w));
    //printf("determinant = %f \n", determinant);
    if(determinant == 0){
        printf("The inverse of this matrix does not exist!!\n");
        return inverseM;
    }
    
    mat4 adjoin = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    
    //row 1
    adjoin.x.x = (m->y.y * m->z.z * m->w.w) + (m->z.y * m->w.z * m->y.w) + (m->w.y * m->y.z * m->z.w)
    - (m->y.y * m->w.z * m->z.w) - (m->z.y * m->y.z * m->w.w) - (m->w.y * m->z.z * m->y.w);
    adjoin.x.y = -((m->y.x * m->z.z * m->w.w) + (m->z.x * m->w.z * m->y.w) + (m->w.x * m->y.z * m->z.w)
                   - (m->y.x * m->w.z * m->z.w) - (m->z.x * m->y.z * m->w.w) - (m->w.x * m->z.z * m->y.w));
    adjoin.x.z = (m->y.x * m->z.y * m->w.w) + (m->z.x * m->w.y * m->y.w) + (m->w.x * m->y.y * m->z.w)
    - (m->y.x * m->w.y * m->z.w) - (m->z.x * m->y.y * m->w.w) - (m->w.x * m->z.y * m->y.w);
    adjoin.x.w = - ((m->y.x * m->z.y * m->w.z) + (m->z.x * m->w.y * m->y.z) + (m->w.x * m->y.y * m->z.z)
                    - (m->y.x * m->w.y * m->z.z) - (m->z.x * m->y.y * m->w.z) - (m->w.x * m->z.y * m->y.z));
    //row 2
    adjoin.y.x = - ((m->x.y * m->z.z * m->w.w) + (m->z.y * m->w.z * m->x.w) + (m->w.y * m->x.z * m->z.w)
                    - (m->x.y * m->w.z * m->z.w) - (m->z.y * m->x.z * m->w.w) - (m->w.y * m->z.z * m->x.w));
    adjoin.y.y = (m->x.x * m->z.z * m->w.w) + (m->z.x * m->w.z * m->x.w) + (m->w.x * m->x.z * m->z.w)
    - (m->x.x * m->w.z * m->z.w) - (m->z.x * m->x.z * m->w.w) - (m->w.x * m->z.z * m->x.w);
    adjoin.y.z = - ((m->x.x * m->z.y * m->w.w) + (m->z.x * m->w.y * m->x.w) + (m->w.x * m->x.y * m->z.w)
                    - (m->x.x * m->w.y * m->z.w) - (m->z.x * m->x.y * m->w.w) - (m->w.x * m->z.y * m->x.w));
    adjoin.y.w = (m->x.x * m->z.y * m->w.z) + (m->z.x * m->w.y * m->x.z) + (m->w.x * m->x.y * m->z.z)
    - (m->x.x * m->w.y * m->z.z) - (m->z.x * m->x.y * m->w.z) - (m->w.x * m->z.y * m->x.z);
    //row 3
    adjoin.z.x = (m->x.y * m->y.z * m->w.w) + (m->y.y * m->w.z * m->x.w) + (m->w.y * m->x.z * m->y.w)
    - (m->x.y * m->w.z * m->y.w) - (m->y.y * m->x.z * m->w.w) - (m->w.y * m->y.z * m->x.w);
    adjoin.z.y = - ((m->x.x * m->y.z * m->w.w) + (m->y.x * m->w.z * m->x.w) + (m->w.x * m->x.z * m->y.w)
                    - (m->x.x * m->w.z * m->y.w) - (m->y.x * m->x.z * m->w.w) - (m->w.x * m->y.z * m->x.w));
    adjoin.z.z = (m->x.x * m->y.y * m->w.w) + (m->y.x * m->w.y * m->x.w) + (m->w.x * m->x.y * m->y.w)
    - (m->x.x * m->w.y * m->y.w) - (m->y.x * m->x.y * m->w.w) - (m->w.x * m->y.y * m->x.w);
    adjoin.z.w = - ((m->x.x * m->y.y * m->w.z) + (m->y.x * m->w.y * m->x.z) + (m->w.x * m->x.y * m->y.z)
                    - (m->x.x * m->w.y * m->y.z) - (m->y.x * m->x.y * m->w.z) - (m->w.x * m->y.y * m->x.z));
    //row 4
    adjoin.w.x = - ((m->x.y * m->y.z * m->z.w) + (m->y.y * m->z.z * m->x.w) + (m->z.y * m->x.z * m->y.w)
                    - (m->x.y * m->y.w * m->z.z) - (m->y.y * m->x.z * m->z.w) - (m->z.y * m->y.z * m->x.w));
    adjoin.w.y = (m->x.x * m->y.z * m->z.w) + (m->y.x * m->z.z * m->x.w) + (m->z.x * m->x.z * m->y.w)
    - (m->x.x * m->z.z * m->y.w) - (m->y.x * m->x.z * m->z.w) - (m->z.x * m->y.z * m->x.w);
    adjoin.w.z = - ((m->x.x * m->y.y * m->z.w) + (m->y.x * m->z.y * m->x.w) + (m->z.x * m->x.y * m->y.w)
                    - (m->x.x * m->z.y * m->y.w) - (m->y.x * m->x.y * m->z.w) - (m->z.x * m->y.y * m->x.w));
    adjoin.w.w = (m->x.x * m->y.y * m->z.z) + (m->y.x * m->z.y * m->x.z) + (m->z.x * m->x.y * m->y.z)
    - (m->x.x * m->z.y * m->y.z) - (m->y.x * m->x.y * m->z.z) - (m->z.x * m->y.y * m->x.z);
    
    // Transpose!!!
    mTrans(&adjoin, &adjoin);
    // Now it is right.
    inverseM = smMul((1/determinant),&adjoin,inverseM);
    return inverseM;
}

mat4* mTrans(mat4 *m, mat4 *transM){
    mat4 temp[16];
    for (int i = 0; i < 16; ++i)
        temp[i] = m[i];
    //column 1
    transM->x.x = temp->x.x;
    transM->y.x = temp->x.y;
    transM->z.x = temp->x.z;
    transM->w.x = temp->x.w;
    //column 2
    transM->x.y = temp->y.x;
    transM->y.y = temp->y.y;
    transM->z.y = temp->y.z;
    transM->w.y = temp->y.w;
    //column 3
    transM->x.z = temp->z.x;
    transM->y.z = temp->z.y;
    transM->z.z = temp->z.z;
    transM->w.z = temp->z.w;
    //column 4
    transM->x.w = temp->w.x;
    transM->y.w = temp->w.y;
    transM->z.w = temp->w.z;
    transM->w.w = temp->w.w;
    return transM;
}
vec4* mvMul(mat4 *m, vec4 *v, vec4 *productMV){
    float xComp, yComp, zComp, wComp;
    xComp = (m->x.x * v->x) + (m->y.x * v->x) + (m->z.x * v->x) + (m->w.x * v->x);
    yComp = (m->x.y * v->y) + (m->y.y * v->y) + (m->z.y * v->y) + (m->w.y * v->y);
    zComp = (m->x.z * v->z) + (m->y.z * v->z) + (m->z.z * v->z) + (m->w.z * v->z);
    wComp = (m->x.w * v->w) + (m->y.w * v->w) + (m->z.w * v->w) + (m->w.w * v->w);
    productMV->x = xComp;
    productMV->y = yComp;
    productMV->z = zComp;
    productMV->w = wComp;
    return productMV;
}

