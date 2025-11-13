#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texcoords;

uniform mat4 view;
uniform mat4 projection;

out vec3 pos;

void main() {
    gl_Position = projection * vec4(position, 1.0);
    pos = position;
}
