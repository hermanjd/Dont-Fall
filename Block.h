#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
	Block(int nx, int ny, int nz);

private:
	/*float model = {
		0.0f,0.0f,0.0f, 0.7f,0.7f,0.7f, 0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f, 0.7f,0.7f,0.7f, 0.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f, 0.7f,0.7f,0.7f, 0.0f,0.0f,0.0f,

		1.0f,0.0f,0.0f, 0.7f,0.7f,0.7f, 0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f, 0.7f,0.7f,0.7f, 0.0f,0.0f,0.0f,
		1.0f,1.0f,0.0f, 0.7f,0.7f,0.7f, 0.0f,0.0f,0.0f 
	};*/
	int x;
	int y;
	int z;

};


#endif