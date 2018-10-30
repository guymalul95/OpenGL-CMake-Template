#version 330 core
out vec4 o_fragColor;

in vec4 vertexColor;
in vec2 textureCoords;

uniform sampler2D texture0;

void main()
{
    o_fragColor = texture(texture0, textureCoords) * vertexColor;
}
