#version 330 core
in vec4 i_vertexColor;
out vec4 o_fragColor;

void main()
{
    o_fragColor = i_vertexColor;
}