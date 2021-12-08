#version 450 core

in vec3 vColor;
in vec3 aPos;

out vec4 frag_color;



void main()
{
    float cond = 0;

    if(abs(0.05*aPos.x - int(0.05*aPos.x)) <= 0.02 || abs(0.05*aPos.z - int(0.05*aPos.z)) <= 0.02){
        cond = 1;
    }

    frag_color = vec4(cond * vColor,1) ;
}