#version 330

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoord;

uniform sampler2D uTexture;

out vec3 fFragColor;

void main() {
    fFragColor = texture(uTexture, vTexCoord).xyz;
}