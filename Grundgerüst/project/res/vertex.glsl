#version 330

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 color;
layout(location = 2) in vec3 normal;

out vec3 outColor;

void main(){

	outColor = color;
	gl_Position = vec4(pos, 1.0);

}