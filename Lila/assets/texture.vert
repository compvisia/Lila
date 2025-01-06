#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoords;

uniform mat4 proj;
uniform mat4 pos;

out vec2 texpos;

void main() {
    gl_Position = proj * pos * vec4(position, 1.0);
    texpos = texcoords;
}