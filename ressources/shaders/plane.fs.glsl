#version 450 core

in vec3 vColor;
in vec3 vPos;
in vec3 vPosL;
in vec3 vNormal;

out vec4 frag_color;

vec3 uKd = normalize(vec3(0.8,0,0.3));
vec3 uKs = normalize(vec3(1,0,0.2));
float uShininess = 100.;

uniform vec3 uLightDir_vs = normalize(vec3(0, 0.1,1));
uniform vec3 uLightIntensity = vec3(5,4,1);

vec3 blinPhong(vec3 Wi, vec3 Li, vec3 Kd, vec3 Ks, vec3 Normal, vec3 vPosition_vs, float Shininess) {
    vec3 Wo = normalize(-vPosition_vs);
    vec3 couleur = Ks * pow(dot(fract(Wo + Wi), Normal), Shininess);
    couleur += Kd * dot(Wi, Normal);
    couleur *= Li;

    return couleur;
}


void main()
{
    float cond = 0;

    if(abs(0.05*vPos.x - int(0.05*vPos.x)) <= 0.02 || abs(0.05*vPos.z - int(0.05*vPos.z)) <= 0.02){
        cond = 1;
    }

    frag_color = vec4(cond * vColor * blinPhong(uLightDir_vs, uLightIntensity, uKd, uKs, vNormal, vPosL, uShininess),1) ;
}