#include "ShapeGenerator.h"
#include "Vertex.h"
#include <glm/glm.hpp>

#include <iostream>
#include <stdio.h>
#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

ShapeData ShapeGenerator::makeFloor(double x, double y, double z) {
	
	ShapeData data;

	Vertex verticies[] = {
		glm::vec3(-1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(-1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		glm::vec3(-1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),




		/*SIDES*/
		glm::vec3(-1.0f + x,  1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x,  1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),


		glm::vec3(-1.0f + x,  1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(-1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),



		/*rightSide*/

		glm::vec3(-1.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),


		glm::vec3(-1.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(-1.0f + x,  -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	};
	data.numbVerticies = NUM_ARRAY_ELEMENTS(verticies);
	data.vertices = new Vertex[data.numbVerticies];
	memcpy(data.vertices, verticies, sizeof(verticies));

	GLushort indices[] = { 0,1,2 };
	data.numbIndices = NUM_ARRAY_ELEMENTS(indices);
	data.indices = new GLushort[data.numbIndices];
	memcpy(data.indices, indices, sizeof(indices));

	return data;


}

ShapeData ShapeGenerator::makeLedge(double x, double y, double z) {

	ShapeData data;

	Vertex verticies[] = {
		glm::vec3(0.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(0.7f, 0.0f, 0.2f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.0f + x, -1.0f + y, -1.0f + z),
		glm::vec3(0.7f, 0.0f, 0.2f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(0.7f, 0.0f, 0.2f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		glm::vec3(0.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(0.7f, 0.0f, 0.2f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(0.7f, 0.0f, 0.2f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.0f + x, 1.0f + y, -1.0f + z),
		glm::vec3(0.7f, 0.0f, 0.2f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	};
	data.numbVerticies = NUM_ARRAY_ELEMENTS(verticies);
	data.vertices = new Vertex[data.numbVerticies];
	memcpy(data.vertices, verticies, sizeof(verticies));
	/*
	GLushort indices[] = { 0,1,2 };
	data.numbIndices = NUM_ARRAY_ELEMENTS(indices);
	data.indices = new GLushort[data.numbIndices];
	memcpy(data.indices, indices, sizeof(indices));
	*/
	return data;
}




/*-----------CUBE--------------*/
ShapeData ShapeGenerator::makeCube(double x, double y, double z) {

	ShapeData data;

	Vertex verticies[] = {
		/*BOTTOM*/
		glm::vec3(0.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(1.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, -1.0f),


		glm::vec3(0.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(1.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, -1.0f),
		


		/*TOP*/
		glm::vec3(0.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		glm::vec3(0.0f + x,  1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x,  1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		/*Front*/
		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(0.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),


		glm::vec3(0.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),


		/*left-side*/
		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(-1.0f, 0.0f, 0.0f),


		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(-1.0f, 0.0f, 0.0f),


		/*RightSide*/
		glm::vec3(1.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(1.0f, 0.0f, 0.0f),


		glm::vec3(1.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(1.0f + x, 0.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(1.0f, 0.0f, 0.0f),


		/*BackSide*/
		glm::vec3(0.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(0.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),


		glm::vec3(0.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	};
	data.numbVerticies = NUM_ARRAY_ELEMENTS(verticies);
	data.vertices = new Vertex[data.numbVerticies];
	memcpy(data.vertices, verticies, sizeof(verticies));
	/*
	GLushort indices[] = { 0,1,2 };
	data.numbIndices = NUM_ARRAY_ELEMENTS(indices);
	data.indices = new GLushort[data.numbIndices];
	memcpy(data.indices, indices, sizeof(indices));
	*/
	return data;
}
ShapeData ShapeGenerator::makePlayer(double x, double y, double z) {

	ShapeData data;

	Vertex verticies[] = {
		/*BOTTOM*/
		glm::vec3(0.0f + x, 0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),


		glm::vec3(0.0f + x,  0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(0.2f + x,  0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, -1.0f),



		/*TOP*/
		glm::vec3(0.0f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.0f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		glm::vec3(0.0f + x,  0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.2f + x,  0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		/*Front*/
		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(0.0f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),


		glm::vec3(0.0f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),


		/*left-side*/
		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),


		glm::vec3(0.0f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),

		glm::vec3(0.0f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),


		/*RightSide*/
		glm::vec3(0.2f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(0.2f + x, 0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(0.2f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),


		glm::vec3(0.2f + x, 0.0f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(0.2f + x, 0.0f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),

		glm::vec3(0.2f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),


		/*BackSide*/
		glm::vec3(0.0f + x, 0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(0.0f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(0.2f + x, 0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),


		glm::vec3(0.0f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(0.2f + x, 0.2f + y, 0.2f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(0.2f + x, 0.2f + y, 0.0f + z),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	};
	data.numbVerticies = NUM_ARRAY_ELEMENTS(verticies);
	data.vertices = new Vertex[data.numbVerticies];
	memcpy(data.vertices, verticies, sizeof(verticies));
	/*
	GLushort indices[] = { 0,1,2 };
	data.numbIndices = NUM_ARRAY_ELEMENTS(indices);
	data.indices = new GLushort[data.numbIndices];
	memcpy(data.indices, indices, sizeof(indices));
	*/
	return data;
}


ShapeData ShapeGenerator::makeGoal(double x, double y, double z) {

	ShapeData data;

	Vertex verticies[] = {
		glm::vec3(-1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.6f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(-1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.6f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.6f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		glm::vec3(-1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.6f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.6f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.6f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),


		glm::vec3(-1.0f + x,  1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x,  1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),


		glm::vec3(-1.0f + x,  1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(-1.0f + x,  1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),

		glm::vec3(1.0f + x, 1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, -1.0f, 0.0f),



		/*rightSide*/

		glm::vec3(-1.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),


		glm::vec3(-1.0f + x,  -1.0f + y, -1.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(-1.0f + x,  -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f),

		glm::vec3(1.0f + x, -1.0f + y, 0.0f + z),
		glm::vec3(1.0f, 0.0f, 0.3f),
		glm::vec3(0.0f, 1.0f, 0.0f)

	};
	data.numbVerticies = NUM_ARRAY_ELEMENTS(verticies);
	data.vertices = new Vertex[data.numbVerticies];
	memcpy(data.vertices, verticies, sizeof(verticies));

	GLushort indices[] = { 0,1,2 };
	data.numbIndices = NUM_ARRAY_ELEMENTS(indices);
	data.indices = new GLushort[data.numbIndices];
	memcpy(data.indices, indices, sizeof(indices));

	return data;
}


ShapeData ShapeGenerator::makeTerrain(double x, double y, double z) {

	ShapeData data;
	
	int i;
	
	FILE* f;

	errno_t errorCode = fopen_s(&f, "heightmap.bmp", "rb");


	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	int width = *(int*)&info[18];
	int height = *(int*)&info[22];

	int size = 3 * width * height;
	unsigned char* imgdata = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(imgdata, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);
	
	float imgflo[4096];
	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = imgdata[i];
		imgdata[i] = imgdata[i + 2];
		imgdata[i + 2] = tmp;
	};

	int t = 0;
	/*Cast to float*/
	for (i = 0; i < size; i += 3)
	{
		unsigned char c = imgdata[i];
		float fs = (float)(c);
		float fc = c;
		imgflo[t] = c;
		t++;
	};

	Vertex verty[18144];
	int sixtick = 0;
	int xtick =  0;
	int ytick = 0;
	int pos;
	for (t = 0; t < 16; t++)
	{
		for (i = 0; i < 384; i += 6)
		{
			pos = (384 * t) + i;
			verty[pos].position = glm::vec3(0.0f + x + ytick, 0.0f + y + (t * 2), (imgflo[xtick] / 30) + z);
			verty[pos].color = glm::vec3(1.0f, 0.4f, 0.0f);
			verty[pos].model = glm::vec3(0.1f, 0.1f, 1.0f);

			verty[pos + 1].position = glm::vec3(2.0f + x + ytick, 0.0f + y + (t*2), (imgflo[xtick + 1] / 30) + z);
			verty[pos + 1].color = glm::vec3(1.0f, 0.4f, 0.0f);
			verty[pos + 1].model = glm::vec3(0.1f, 0.1f, 1.0f);

			verty[pos + 2].position = glm::vec3(0.0f + x + ytick, 2.0f + y + (t * 2), (imgflo[xtick + 64] / 30) + z);
			verty[pos + 2].color = glm::vec3(1.0f, 0.4f, 0.0f);
			verty[pos + 2].model = glm::vec3(0.1f, 0.1f, 1.0f);

			

			verty[pos + 3].position = glm::vec3(2.0f + x + ytick, 0.0f + y + (t * 2), (imgflo[xtick + 1] / 30) + z);
			verty[pos + 3].color = glm::vec3(1.0f, 0.4f, 0.0f);
			verty[pos + 3].model = glm::vec3(0.0f, 0.0f, 1.0f);

			verty[pos + 4].position = glm::vec3(2.0f + x + ytick, 2.0f + y + (t * 2), (imgflo[xtick + 65] / 30) + z);
			verty[pos + 4].color = glm::vec3(1.0f, 0.4f, 0.0f);
			verty[pos + 4].model = glm::vec3(0.0f, 0.0f, 1.0f);

			verty[pos + 5].position = glm::vec3(0.0f + x + ytick, 2.0f + y + (t * 2), (imgflo[xtick + 64] / 30) + z);
			verty[pos + 5].color = glm::vec3(1.0f, 0.4f, 0.0f);
			verty[pos + 5].model = glm::vec3(0.0f, 0.0f, 1.0f);
			ytick++;
			ytick++;
			xtick++;

		}
		ytick = 0;
	};


	data.numbVerticies = NUM_ARRAY_ELEMENTS(verty);
	data.vertices = new Vertex[data.numbVerticies];
	memcpy(data.vertices, verty, sizeof(verty));
	return data;
}

