#version 330 core
layout (location = 0) in vec4 i_pos;
layout (location = 1) in vec4 i_vertexColor;
layout (location = 2) in vec2 i_texture;

out vec4 vertexColor;
out vec2 texture;

void main()
{
    texture = i_texture;
    vertexColor = i_vertexColor;
    gl_Position = vec4(i_pos.xyz, 1.0);
}
