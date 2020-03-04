//
//  test.c
//  lab02
//
//  Name: Sophia Lin.
//  Email: sjl81@pitt.edu
//  Date of Submission: 9/13/19.
//
//

#include <stdio.h>
#include "library.h"

int main(void){
    // scalar
    float scalar = 3.0;
    
    //typedef vector
    vec4 v1 = {1, 2, 3, 4};
    vec4 v2 = {5, 6, 7, 8};
    //printf("[%.2f, %.2f, %.2f, %.2f]\n", v1[0], v1[1], v1[2], v1[3]);
    
    //typedef matrix
    mat4 m1 = {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}};
    mat4 m2 = {{4,8,12,16},{3,7,11,15},{2,6,10,14},{1,5,9,13}};
    
// Testing Vectors
    //print_v(&v1);
// s × v1
    vec4 productV = {0, 0, 0, 0};
    svMul(scalar, &v1, &productV);
    printf("s * v1 = ");
    print_v(&productV);
// v1 + v2
    vec4 sumV = {0, 0, 0, 0};
    vAdd(&v1, &v2, &sumV);
    printf("v1 + v2 = ");
    print_v(&sumV);
// v1 − v2
    vec4 subV = {0, 0, 0, 0};
    vSub(&v1, &v2, &subV);
    printf("v1 - v2 = ");
    print_v(&subV);
// |v|
    float magnitude = vMagnitude(&v1);
    printf("|v| = ");
    
    printf("%.2f\n", magnitude);
// vˆ
    vec4 normV = {0, 0, 0, 0};
    normalize(magnitude, &v1, &normV);
    printf("Normalize v1 = ");
    print_v(&normV);
// v1 · v2
    float dProduct = dotProduct(&v1, &v2);
    printf("Dot Product(v1 · v2) = ");
    printf("%.2f\n", dProduct);
// v1 × v2
    vec4 crossProduct = {0, 0, 0, 0};
    cProduct(&v1, &v2, &crossProduct);
    printf("Cross Product(v1 * v2) = ");// w is always 0.0
    print_v(&crossProduct);
    
// Testing Matrix
    //print_m(&m1);
// s × m1
    mat4 productM = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    smMul(scalar, &m1, &productM);
    printf("s * m1 =\n");
    print_m(&productM);
// m1 + m2
    mat4 sumM = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mAdd(&m1, &m2, &sumM);
    printf("m1 + m2 =\n");
    print_m(&sumM);
// m1 − m2
    mat4 subM = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mSub(&m1, &m2, &subM);
    printf("m1 - m2 =\n");
    print_m(&subM);
// m1 × m2
    mat4 prodM = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mMul(&m1, &m2, &prodM);
    printf("m1 * m2 =\n");
    print_m(&prodM);
// (m1)^(−1)
    mat4 inverseM = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mInverse(&m1, &inverseM);
    printf("Inverse of m1 =\n");
    print_m(&inverseM);
// m1^T
    mat4 transM = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mTrans(&m1, &transM);
    printf("Transpose of m1 =\n");
    print_m(&transM);
// m1 × v1
    vec4 productMV = {0,0,0,0};
    mvMul(&m1, &v1, &productMV);
    printf("m1 * v1 = ");
    print_v(&productMV);
    
/*
 //testing for recitation
    mat4 i = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
// (m2)^(−1)
    mat4 inverseM2 = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mInverse(&m2, &inverseM2);
    printf("Inverse of m2 =\n");
    print_m(&inverseM2);
// v1 · (v1 * v2)
    float dProduct2 = dotProduct(&v1, &crossProduct);
    printf("Dot Product(v1 · (v1 * v2)) = ");
    printf("%.2f\n", dProduct2);
// v1 · (v1 + v2)
    float dProduct3 = dotProduct(&v1, &sumV);
    printf("Dot Product(v1 · (v1 + v2)) = ");
    printf("%.2f\n", dProduct3);
//v1 · v1 + v1 · v2
    float dProduct4 = dotProduct(&v1, &v1);
    float dProduct5 = dotProduct(&v1, &v2);
    printf("Dot Product(v1 · v1 + v1 · v2) = ");
    printf("%.2f\n", (dProduct4 + dProduct5));
// i^T
    mat4 transI = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mTrans(&i, &transI);
    printf("Transpose of i =\n");
    print_m(&transI);
// i^(-1)
    mat4 inverseI = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    mInverse(&i, &inverseI);
    printf("Inverse of i =\n");
    print_m(&inverseI);
//v1 - (v1 + v2)
    vec4 subV2 = {0, 0, 0, 0};
    vSub(&v1, &sumV, &subV2);
    printf("v1 - (v1 + v2) = ");
    print_v(&subV2);
//m3 = 2 * m1
    mat4 m3 = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    smMul(2, &m1, &m3);
    smMul(0.5, &m3, &m3);
    print_m(&m3);
 */
}
