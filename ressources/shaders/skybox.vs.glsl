#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 texCoords;

uniform mat4 uProjMatrix;
uniform mat4 uViewMatrix;

void main()
{
    vec4 pos = uProjMatrix * uViewMatrix * vec4(aPos, 0.f);
    gl_Position = vec4(pos.x, pos.y, pos.w, pos.w);

    texCoords = aPos;
}