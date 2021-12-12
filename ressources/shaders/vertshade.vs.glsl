#version 450 core

// Simplified vertex shader for rendering an infinite plane.
layout(location = 0) in vec4 aVertexPosition;
uniform mat4 uProjModelMatrix = mat4(1);
uniform mat4 uMVPMatrix = mat4(1);


out vec3 vColor;
out vec3 aPos;

void main() 
{
    vColor = vec3(0.8,0.1,0.7);
    aPos = (uProjModelMatrix* aVertexPosition).xyz;
    gl_Position = uMVPMatrix * aVertexPosition;
}