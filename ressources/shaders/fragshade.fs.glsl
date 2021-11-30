#version 450 core

in vec4 point;  // in view space
in vec4 uhat;
in vec4 vhat;
in vec4 ndc;

out vec4 frag_color;

void main()
{
    // simple but expensive 2: discard pixels not on the plane
    if (point.w > 0)
        discard;

    float u = dot(uhat.xyz, point.xyz/point.w) + uhat.w;
    float v = dot(vhat.xyz, point.xyz/point.w) + vhat.w;

    // Simple procedural texture test
    frag_color = vec4(fract(u), fract(v), 0.2, 1);

    gl_FragDepth = (ndc.z / ndc.w + 1.0) / 2.0;
}