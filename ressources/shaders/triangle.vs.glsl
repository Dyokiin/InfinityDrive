#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoord;

uniform mat4 uMVPMatrix;
uniform mat4 uNormalMatrix;

out vec2 texCoords;
out vec3 vNormal;
out vec3 vPos;

void main() {
    texCoords = aVertexTexCoord;
    vNormal = normalize(vec3(uNormalMatrix * vec4(aVertexNormal,0)));
    vPos = (uMVPMatrix* vec4(aVertexPosition,1)).xyz;
    gl_Position =  uMVPMatrix * vec4(aVertexPosition, 1);
}
