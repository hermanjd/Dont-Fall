#version 330 core

in vec3 position;
in vec3 color;
in vec3 normal;

uniform vec3 ambientlight;
uniform vec3 lightpos;

out vec3 Color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * view * model * vec4(position, 1.0);
	vec3 lightVector = normalize(lightpos - position);
	float bightness = dot(lightVector, normal);
	Color = (color * dot(lightVector, normal)) + ((color * ambientlight)*1.5);
}