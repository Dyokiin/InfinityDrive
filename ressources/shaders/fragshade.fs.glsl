#version 450 core

in vec3 vColor;
in vec3 aPos;

out vec4 frag_color;

float color = length(fract(5.0 * aPos));

void main()
{
    frag_color = color * vec4(vColor, 1);
}