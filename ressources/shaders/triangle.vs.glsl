#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoord;

uniform mat4 uMVPMatrix;

out vec2 texCoords;

void main() {
    texCoords = aVertexTexCoord;
    gl_Position =  uMVPMatrix * vec4(aVertexPosition, 1);
}
