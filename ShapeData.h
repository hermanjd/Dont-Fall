#pragma once
#include <GL/glew.h>
#include "Vertex.h"

struct ShapeData {

	ShapeData() :
		vertices(0), numbVerticies(0), indices(0), numbIndices(0){}

	Vertex* vertices;
	GLuint numbVerticies;
	GLushort* indices;
	GLuint numbIndices;
	GLsizeiptr vertexBufferSize() const {
		return numbVerticies * sizeof(Vertex);
	}

	~ShapeData() {
		vertices = 0;
		indices = 0;
		delete [] vertices;
		delete [] indices;
		numbIndices = numbVerticies = 0;
	}
};