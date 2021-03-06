//  fshader.glsl
//  lab05
//
//  Name: Sophia Lin.
//  Email: sjl81@pitt.edu
//  Date of Submission: 10/17/19.#version 120

varying vec2 texCoord;
varying vec4 color;

uniform sampler2D texture;

void main()
{
    //gl_FragColor = vec4(texCoord.x, texCoord.y, 0.0, 1.0);
    gl_FragColor = texture2D(texture, texCoord);
    //gl_FragColor = color;
}
