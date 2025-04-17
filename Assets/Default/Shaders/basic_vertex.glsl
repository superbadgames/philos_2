#version 330 core

layout (location=0) in vec3 position;
layout (location=1) in vec3 normal;
layout (location=2) in vec2 uvs;

uniform mat4 model;
uniform mat4 view;

out vec3 vertex_normal;
out vec2 vertex_uvs;

void main()
{
    gl_Position = view * model * vec4(position, 1.0);

    vertex_normal = normal;
    vertex_uvs = uvs;
}