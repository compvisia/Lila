#version 330 core

uniform sampler2D sample;

in vec2 coords;

out vec4 FragColor;

void main() {
    FragColor = texture2D(sample, coords);
}