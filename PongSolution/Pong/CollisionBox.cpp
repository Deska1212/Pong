#include <raylib.h>;
#include "CollisionBox.h";


CollisionBox::CollisionBox(float mnX, float mnY, float mxX, float mxY) :
	minX{ mnX },
	minY{ mnY },
	maxX{ mxX },
	maxY{ mxY }
{

}

bool CollisionBox::CollidesWith(const CollisionBox& other)
{
	if (
		minX > other.maxX ||
		maxX < other.minX ||
		minY > other.maxY ||
		maxY < other.minY
		)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void CollisionBox::DebugDraw()
{
	DrawRectangleLines(minX, minY, maxX - minX, maxY - minY, GREEN);
}