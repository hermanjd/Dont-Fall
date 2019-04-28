#include "ShapeData.h"

class ShapeGenerator
{
public:
	static ShapeData makeFloor(double x, double y, double z);
	static ShapeData makeLedge(double x, double y, double z);
	static ShapeData makeCube(double x, double y, double z);
	static ShapeData makePlayer(double x, double y, double z);
	static ShapeData makeGoal(double x, double y, double z);
	static ShapeData makeTerrain(double x, double y, double z);
};
