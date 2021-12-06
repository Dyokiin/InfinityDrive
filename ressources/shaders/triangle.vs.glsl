#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoord;

uniform mat4 uViewMatrix;
uniform mat4 uProjMatrix;
uniform mat4 uNormMatrix;

out vec3 vColor;

void main() {
    vColor = aVertexNormal;
    gl_Position =  uProjMatrix * uViewMatrix * vec4(aVertexPosition, 1);
}
