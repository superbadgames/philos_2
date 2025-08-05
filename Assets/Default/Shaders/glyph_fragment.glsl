#version 330 core

out vec4 outputColor;

in vec2 texture_uvs;


uniform vec4 glyph_color;
uniform sampler2D glyph_texture;

void main()
{
  vec4 sampled = vec4(1.0, 1.0, 1.0, texture(glyph_texture, texture_uvs).r);
  outputColor = vec4(glyph_color) * sampled;
}