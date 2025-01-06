#version 330 core

in vec2 texpos;

out vec4 FragColor;

uniform sampler2D textureId_m;

void main() {
    FragColor = texture(textureId_m, texpos);
}