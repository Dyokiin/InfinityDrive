#version 450 core

// Simplified vertex shader for rendering an infinite plane.
layout(location = 0) in vec4 aVertexPosition;
uniform mat4 uProjMatrix = mat4(1);
uniform mat4 uViewMatrix = mat4(1);
uniform mat4 model ;

out vec3 vColor;
out vec3 nearPoint;
out vec3 farPoint;
out vec3 aPos;

vec3 UnprojectPoint(float x, float y, float z, mat4 view, mat4 projection) {
    mat4 viewInv = inverse(view);
    mat4 projInv = inverse(projection);
    vec4 unprojectedPoint =  viewInv * projInv * vec4(x, y, z, 1.0);
    return unprojectedPoint.xyz / unprojectedPoint.w;
}

void main() 
{
    vec3 p = aVertexPosition.xyz;
    vColor = vec3(1,1,1);
    aPos = aVertexPosition.xyz;
    nearPoint = UnprojectPoint(p.x, p.y, 0.0, uViewMatrix, uProjMatrix).xyz;
    farPoint = UnprojectPoint(p.x, p.y, 1.0, uViewMatrix, uProjMatrix).xyz;
    gl_Position = vec4(p, 1.0);
}