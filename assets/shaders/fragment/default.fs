#version 330 core
out vec4 o_fragColor;
in vec4 vertexColor;
in vec2 texture;

void main()
{
    o_fragColor = vertexColor;
}
