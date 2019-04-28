#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <windows.h>
#include <string>
#include "Vertex.h"
#include "ShapeGenerator.h"
#include "stb_image.h"



/*Spiller Posisjon*/
glm::vec3 playerPosition = glm::vec3(1.0f, 0.0f, 0.0f);


/*Creates the map*/
ShapeData worldModelList[]{
	ShapeGenerator::makePlayer(playerPosition.x, playerPosition.y, playerPosition.z),
	ShapeGenerator::makeTerrain(-40.0, -16.0, -5.0),
	ShapeGenerator::makeCube(1.0, 3.0, 0.0),
	ShapeGenerator::makePlayer(30.0, 0.0f, 6.1f),
	ShapeGenerator::makeCube(24.0, -8.0, 3.0),
	ShapeGenerator::makeCube(8.0, -10.0, -3.0),
	ShapeGenerator::makeCube(14.0, -4.0, 3.0),
	ShapeGenerator::makeCube(10.0, -8.0, 3.0),
	ShapeGenerator::makeLedge(0.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(1.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(2.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(4.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(6.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(8.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(10.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(11.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(12.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(13.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(15.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(16.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(17.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(18.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(20.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(21.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(23.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(24.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(25.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(27.0, 0.0, 0.0),
	ShapeGenerator::makeFloor(28.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(29.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(32.0, 0.0, 0.0),
	ShapeGenerator::makeGoal(33.0, 0.0, 0.0),
	ShapeGenerator::makeLedge(34.0, 0.0, 0.0)
};

 /*Spiller rotasjon*/
float rotation = 4.65;

/*Størrelse på buffer*/
GLsizeiptr combinedBufferSize = 0;

/*Klokke*/
auto t_start = std::chrono::high_resolution_clock::now();

/*Program*/
GLuint shaderProgram;

/*Gravity*/
float gravityV = 0.0;

/*-------------SHADER FUNKSJONER---------------*/
std::string readShaderFile(const char* name) {
	std::ifstream meInput(name);
	if (!meInput) {
		std::cout << "Oh shit it did not read" << name;
		exit(1);
	}

	return std::string(
		std::istreambuf_iterator<char>(meInput),
		std::istreambuf_iterator<char>());

}

/*Opretter en vertex shader*/
GLuint createVS() {
	std::string vsString = readShaderFile("vertexshader.vs");
	const char* vs = vsString.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vs, NULL);
	glCompileShader(vertexShader);
	return vertexShader;
}

/*Opretter en fragmentshader*/
GLuint createFS() {
	std::string fsString = readShaderFile("fragmentshader.fs");
	const char* fs = fsString.c_str();
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

	auto realtime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(realtime - t_start);

	if (time_span.count() > 0.007) {
		
		if (GetAsyncKeyState(VK_RIGHT))
		{
			rotation += 0.015;
			if (rotation > 180) {
				rotation = -180.0;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			rotation -= 0.015;
			if (rotation < -180) {
				rotation = 180.0;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			float x = cos(rotation);
			float y = sin(rotation);
			playerPosition += glm::vec3(0.05 *y, 0.05 *x, 0.0);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			float x = cos(rotation);
			float y = sin(rotation);
			playerPosition -= glm::vec3(0.03 *y, 0.03 *x, 0.0);
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (playerPosition.z > -0.02) {
				gravityV += 0.06;
			}

		}

		gravityV -= 0.0015;
		if (playerPosition.z > 0.01) {
			playerPosition.z = 0.01;
			gravityV = 0.0;
			if (playerPosition.x * -1 > 11.1 && playerPosition.x * -1 < 11.8) {
				exit(0);
			}
			if (playerPosition.x * -1 > 16.1 && playerPosition.x * -1 < 16.8) {
				exit(0);
			}
			if (playerPosition.x * -1 > 21.1 && playerPosition.x * -1 < 22.8) {
				exit(0);
			}
			if (playerPosition.x * -1 > 25.1 && playerPosition.x * -1 < 26.8) {
				exit(0);
			}
			if (playerPosition.x * -1 > 29.1 && playerPosition.x * -1 < 31.8) {
				exit(0);
			}
			if (playerPosition.x * -1 > 31.8) {
				glClearColor(0.3, 0.1, 0.1, 1);
			}
		}
		playerPosition.z -= gravityV;
		
		/*Map Restrictions*/
		if (playerPosition.y > 1.0) {
			playerPosition.y = 1.0;
		}
		if (playerPosition.y < -0.8) {
			playerPosition.y = -0.8;
		}
		if (playerPosition.x > 0.0) {
			playerPosition.x = 0.0;
		}
		if (playerPosition.x < -33.8) {
			playerPosition.x = -33.8;
		}
		
		worldModelList[0] = ShapeGenerator::makePlayer(playerPosition.x * -1, playerPosition.y * -1, playerPosition.z * -1);
		glBufferSubData(GL_ARRAY_BUFFER, 0, worldModelList[0].vertexBufferSize(), worldModelList[0].vertices);
		
		t_start = std::chrono::high_resolution_clock::now();
	}

	glm::mat4 trans = glm::mat4(1.0f);

	float tull = -0.75;
	trans = glm::rotate(trans, tull, glm::vec3(0.0f, 0.0f, 1.0f));

	trans = glm::rotate(trans, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::translate(trans, playerPosition);

	GLint uniTrans = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

	/*VIEW MATRISE*/
	glm::mat4 view = glm::lookAt(
		glm::vec3(2.2f, 2.2f, 2.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);
	GLint uniView = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	/*Projection Matrise*/
	glm::mat4 proj = glm::perspective(glm::radians(60.0f), 800.0f / 600.0f, 1.0f, 100.0f);
	GLint uniProj = glGetUniformLocation(shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));


	glDrawArrays(GL_TRIANGLES, 0, combinedBufferSize / 9);
}



/*--------Main funksjon-------*/
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1600, 900, "Avoid The Hole", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	if (glewInit() != GLEW_OK)
		std::cout << "GlewInit error" << std::endl;


	for (int i = 0; i < (sizeof(worldModelList) / sizeof(*worldModelList));i++) {
		combinedBufferSize += worldModelList[i].vertexBufferSize();
	}

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, combinedBufferSize, 0, GL_STATIC_DRAW);
	
	GLsizeiptr currentSizeHolder = 0;
	for (int i = 0; i < (sizeof(worldModelList) / sizeof(*worldModelList)); i++) {
		glBufferSubData(GL_ARRAY_BUFFER, currentSizeHolder, worldModelList[i].vertexBufferSize(), worldModelList[i].vertices);
		currentSizeHolder += worldModelList[i].vertexBufferSize();
	}
	glEnable(GL_DEPTH_TEST);
	glEnableVertexAttribArray(0);


	createProgram();

	glClearColor(0.15, 0.05, 0.05, 1);


	/*Position posisjon i Vertex*/
	GLint pos = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), 0);

	/*Color posisjon i vertex*/
	GLint col = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(col);
	glVertexAttribPointer(col, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));

	/*Normal posisjon i vertex*/
	GLint normal = glGetAttribLocation(shaderProgram, "normal");
	glEnableVertexAttribArray(normal);
	glVertexAttribPointer(normal, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));


	/*Lys*/
	GLint ambient = glGetUniformLocation(shaderProgram, "ambientlight");
	const GLfloat ambientVector[] = { 0.2f, 0.2f, 0.2f };
	glUniform3fv(ambient, 1, ambientVector);

	GLint lightPos = glGetUniformLocation(shaderProgram, "lightpos");
	GLfloat lightPosvector[] = { 30.0, 0.0f, 6.0f };
	glUniform3fv(lightPos, 1, lightPosvector);




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