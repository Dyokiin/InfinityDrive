#version 450 core

// Simplified vertex shader for rendering an infinite plane.

uniform mat4 uProjMatrix = mat4(1);
uniform mat4 uViewMatrix = mat4(1);
uniform mat4 model = mat4(
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0.3, 0, 1);

// simple but expensive 1: vertices cover the entire screen
// projected screen quad - this is our hard-coded "vertex buffer"
const vec4 screen_quad[4] = vec4[4](
    vec4(-1, -1, 1, 1),
    vec4( 1, -1, 1, 1),
    vec4( 1,  1, 1, 1),
    vec4(-1,  1, 1, 1));
const int triangle_strip[4] = int[4](
    0, 1, 3, 2);

// Output coordinates of view/plane intersection in view space
out vec4 point;
out vec4 uhat;
out vec4 vhat;
out vec4 ndc;

vec3 dehomog(vec4 v)
{
    return v.xyz/v.w;
}

void main()
{
    vec4 corner_ndc = screen_quad[triangle_strip[gl_VertexID]];
    // Screen-quad corner coordinates arrive dirctly in clip-space. Pass them through unchanged.
    gl_Position = corner_ndc;

    vec3 plane_translation_eye = dehomog(uViewMatrix * model * vec4(0, 0, 0, 1));

    // Basis vectors for texture coordinates
    uhat = uViewMatrix * model * vec4(1, 0, 0, 0);
    vhat = uViewMatrix * model * vec4(0, 0, 1, 0);
    // Pack uv translation into w-component of texture axes
    uhat.w = -dot(plane_translation_eye, uhat.xyz);
    vhat.w = -dot(plane_translation_eye, vhat.xyz);

    // Notation from OpenGL super bible ray tracing section
    vec4 D = inverse(uProjMatrix) * corner_ndc;
    vec4 N = uViewMatrix * model * vec4(0, 1, 0, 0);
    float d = -dot(N.xyz, plane_translation_eye);

    point = vec4(
        -d * D.xyz,  // xyz, numerator
        dot(D.xyz, N.xyz)  // w, denominator
    );

    ndc = uProjMatrix * point;
}