#version 330 core

in vec2 texCoord;
in vec4 color;

out vec4 FragColor;

uniform sampler2D mTexture;

void main() {
    FragColor = texture(mTexture, texCoord) * color;
}