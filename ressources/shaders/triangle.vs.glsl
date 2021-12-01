#version 330

layout(location = 3) in vec3 aVertexPosition;
layout(location = 8) in vec3 aVertexColor;

uniform mat4 uViewMatrix;
uniform mat4 uProjMatrix;
uniform mat4 uNormMatrix;

out vec3 vColor;

void main() {
    vColor = aVertexColor;
    gl_Position =  uProjMatrix * uViewMatrix * vec4(aVertexPosition, 1);
}
