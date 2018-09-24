#version 330 core
layout (location = 0) in vec4 i_pos;
layout (location=1) in vec4 i_vertexColor;
layout (location=2) in vec2 i_texture;

out vec4 o_vertexColor;
out vec2 o_texture;

void main()
{
    o_texture = i_texture;
    o_vertexColor = i_vertexColor;
    gl_Position = vec4(i_pos.xyz, 1.0);
}