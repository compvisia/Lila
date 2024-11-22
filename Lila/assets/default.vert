#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 proj;

out vec3 pos;

void main() {
    gl_Position = proj * vec4(position, 1.0);
    pos = position;
}