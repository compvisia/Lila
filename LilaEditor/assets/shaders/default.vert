#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 projection;
uniform mat4 cam;
uniform mat4 model;

out vec4 color;

void main() {
   gl_Position = projection * cam * model * vec4(position, 1.0);
   color = vec4(position, 1.0);
}