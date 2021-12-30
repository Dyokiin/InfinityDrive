#version 330

in vec2 texCoords;
in vec3 vNormal;
in vec3 vPos;
uniform sampler2D texture2d;

out vec4 fFragColor;

uniform vec3 uKd;
uniform vec3 uKs;
float uShininess = 10.;

vec3 uLightIntensity = vec3(5,4,1);
vec3 uLightDir_vs = normalize(vec3(0, 0.1,1));

vec3 blinPhong(vec3 Wi, vec3 Li, vec3 Kd, vec3 Ks, vec3 Normal, vec3 vPosition_vs, float Shininess) {
    vec3 Wo = normalize(-vPosition_vs);
    vec3 couleur = Ks * pow(dot(fract(Wo + Wi), Normal), Shininess);
    couleur += Kd * dot(Wi, Normal);
    couleur *= Li;

    return couleur;
}

void main() {
    fFragColor = vec4(blinPhong(uLightDir_vs, uLightIntensity, uKd, uKs, -vNormal, vPos, uShininess),0) + texture(texture2d, texCoords);
    if(fFragColor.a != 0.){
        fFragColor.a = 1;
    }
}
