#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 coord;

uniform mat4 projection;
uniform mat4 cam;
uniform mat4 model;

out vec2 texCoord;
out vec4 color;

void main() {
   gl_Position = projection * cam * model * vec4(position, 1.0);
   color = vec4(position, 1.0);
   texCoord = coord;
}