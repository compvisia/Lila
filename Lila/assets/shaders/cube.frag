#version 330 core
out vec4 FragColor;

void main() {

    FragColor = vec4(pow(vec3(1.0f, 1.0f, 0.0f), vec3(0.454545454545454545f)), 1.0f);
}