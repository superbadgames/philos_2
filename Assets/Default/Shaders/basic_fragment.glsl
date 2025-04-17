#version 330 core

out vec4 outputColor;

in vec3 vertex_normal;
in vec2 vertex_uvs;


uniform sampler2D spriteTexture;

void main()
{
  outputColor = texture(spriteTexture, vertex_uvs);
}