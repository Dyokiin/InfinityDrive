#version 450 core

// Simplified vertex shader for rendering an infinite plane.
layout(location = 0) in vec4 aVertexPosition;
uniform mat4 uProjModelMatrix = mat4(1);
uniform mat4 uMVPMatrix = mat4(1);
uniform mat4 uNormalMatrix = mat4(1);
vec3 aNormal = vec3(0,1,0);


out vec3 vColor;
out vec3 vPos;
out vec3 vPosL;
out vec3 vNormal;

void main() 
{
    vColor = vec3(0.8,0.1,0.7);
    vPos = (uProjModelMatrix* aVertexPosition).xyz;
    vPosL = (uMVPMatrix * aVertexPosition).xyz;
    vNormal = vec3(uNormalMatrix * vec4(aNormal, 0));
    gl_Position = uMVPMatrix * aVertexPosition;
}