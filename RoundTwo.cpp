#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <windows.h>


 /*Spiller rotasjon*/
float rotation = 0.0;

/*Spiller Posisjon*/
glm::vec3 playerPosition = glm::vec3(0.0f, 0.0f, 0.0f);

/*Vertecies*/
float verticies[] = {
		-5.0f,  5.0f, 0.0f, 1.0f, 0.0f, 0.3f,
		-5.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.3f,
		 5.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.3f,

		-5.0f,  5.0f, 0.0f, 1.0f, 0.0f, 0.3f,
		 5.0f,  5.0f, 0.0f, 1.0f, 0.0f, 0.3f,
		 5.0f, -5.0f, 0.0f, 1.0f, 0.0f, 0.3f,

		-5.0f,  5.0f, 0.5f, 1.0f, 0.4f, 0.0f,
		-5.0f, -5.0f, 0.5f, 1.0f, 0.4f, 0.0f,
		-5.0f,  5.0f, 0.0f, 1.0f, 0.4f, 0.0f,

		-5.0f, -5.0f, 0.0f, 1.0f, 0.4f, 0.0f,
		-5.0f, -5.0f, 0.5f, 1.0f, 0.4f, 0.0f,
		-5.0f,  5.0f, 0.5f, 1.0f, 0.4f, 0.0f,

		5.0f, -5.0f, 0.0f, 1.0f, 0.4f, 0.0f,
		5.0f, -5.0f, 0.5f, 1.0f, 0.4f, 0.0f,
		5.0f,  5.0f, 0.5f, 1.0f, 0.4f, 0.0f,

		5.0f,  5.0f, 0.5f, 1.0f, 0.4f, 0.0f,
		5.0f, -5.0f, 0.5f, 1.0f, 0.4f, 0.0f,
		5.0f,  5.0f, 0.0f, 1.0f, 0.4f, 0.0f,

		5.0f,  -5.0f, 0.0f, 1.0f, 0.2f, 0.0f,
	 	5.0f,  -5.0f, 0.5f, 1.0f, 0.2f, 0.0f,
		-5.0f, -5.0f, 0.5f, 1.0f, 0.2f, 0.0f,

		-5.0f, -5.0f, 0.0f, 1.0f, 0.2f, 0.0f,
		-5.0f, -5.0f, 0.5f, 1.0f, 0.2f, 0.0f,
		5.0f,  -5.0f, 5.0f, 1.0f, 0.2f, 0.0f

};


/*Klokke*/
auto t_start = std::chrono::high_resolution_clock::now();

/*Program*/
GLuint shaderProgram;

/*-------------SHADER FUNKSJONER---------------*/
/*Opretter en vertex shader*/
GLuint createVS() {

	const char* vs = R"glsl(
		#version 330 core

		in vec3 position;
		in vec3 color;

		uniform vec3 ambientlight;

		out vec3 Color;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		void main()
		{
			Color = color * ambientlight;
			gl_Position = proj * view * model * vec4(position, 1.0);
		}
	)glsl";
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vs, NULL);
	glCompileShader(vertexShader);
	return vertexShader;
}


/*Opretter en fragmentshader*/
GLuint createFS() {
	const char* fs = R"glsl(
		#version 330 core

		in vec3 Color;

		out vec4 outColor;

		void main()
		{
			outColor = vec4(Color, 1.0);
		}
	)glsl";

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fs, NULL);
	glCompileShader(fragmentShader);
	return fragmentShader;
}

/*-----------Lager program--------------*/
void createProgram() {
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, createVS());
	glAttachShader(shaderProgram, createFS());
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

}
void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*Position posisjon i Vertex*/
	GLint pos = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);

	/*Color posisjon i vertex*/
	GLint col = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(col);
	glVertexAttribPointer(col, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));


	/*Lys*/
	GLint ambient = glGetUniformLocation(shaderProgram, "ambientlight");
	const GLfloat ambientVector[] = { 0.7f, 0.7f, 0.7f };
	glUniform3fv(ambient,1, ambientVector);


	glm::mat4 trans = glm::mat4(1.0f);
	if (GetAsyncKeyState(VK_RIGHT))
	{
		rotation += 0.005;
		if (rotation > 180) {
			rotation = -180.0;
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		rotation -= 0.005;
		if (rotation < -180) {
			rotation = 180.0;
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		float x = cos(rotation);
		float y = sin(rotation);
		playerPosition += glm::vec3(0.01 *y,0.01 *x,0.0);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		float x = cos(rotation);
		float y = sin(rotation);
		playerPosition -= glm::vec3(0.01 *y, 0.01 *x, 0.0);
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		playerPosition -= glm::vec3(0.0, 0.0, 0.01);
	}
	if (GetAsyncKeyState(VK_LSHIFT))
	{
		playerPosition += glm::vec3(0.0, 0.0, 0.01);
	}

	float tull = -0.75;
	trans = glm::rotate(trans, tull, glm::vec3(0.0f, 0.0f, 1.0f));

	trans = glm::rotate(trans, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::translate(trans, playerPosition);

	GLint uniTrans = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

	/*VIEW MATRISE*/
	glm::mat4 view = glm::lookAt(
		glm::vec3(0.1f, 0.1f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);
	GLint uniView = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	/*Projection Matrise*/
	glm::mat4 proj = glm::perspective(glm::radians(60.0f), 800.0f / 600.0f, 1.0f, 100.0f);
	GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));


	glDrawArrays(GL_TRIANGLES, 0, 36);
}




/*-------------END OF SHADERS---------------*/



/*--------Main funksjon-------*/
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1100, 800, "Herman's spinnende firkant", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	if (glewInit() != GLEW_OK)
		std::cout << "GlewInit error" << std::endl;
	

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticies), verticies);
	glEnable(GL_DEPTH_TEST);


	/*Enable ett eller annet, funksjonen tar imot en index som her er satt til null*/
	glEnableVertexAttribArray(0);

	createProgram();
	glClearColor(0.13,0.13,0.13,1);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		drawScene();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}