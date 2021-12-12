#version 330

in vec2 texCoords;
uniform sampler2D texture2d;

out vec3 fFragColor;

void main() {
    fFragColor = texture(texture2d, texCoords).xyz;
    //fFragColor = vec3(texCoords, 0);
}
