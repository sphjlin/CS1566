//  fshader.glsl
//  lab05
//
//  Name: Sophia Lin.
//  Email: sjl81@pitt.edu
//  Date of Submission: 10/17/19.
#version 120

attribute vec4 vPosition;
attribute vec4 vColor;
attribute vec2 vTexCoord;
varying vec2 texCoord;
varying vec4 color;

void main()
{
    texCoord = vTexCoord;
    gl_Position = vPosition;
    color = vColor;
}
