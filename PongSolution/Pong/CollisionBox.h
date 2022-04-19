#pragma once
#include <raylib.h>;

class CollisionBox
{
private:
	float minX;
	float minY;
	float maxX;
	float maxY;

public:

	/// <summary>
	/// Constructor Collision Box
	/// </summary>
	/// <param name="mnX">Min X Position (LEFT EDGE)</param>
	/// <param name="mnY">Min Y Position (TOP EDGE)</param>
	/// <param name="mxX">Max X Position (RIGHT EDGE)</param>
	/// <param name="mxY">Max Y Position ( BOTTOM EDGE)</param>
	CollisionBox(float mnX, float mnY, float mxX, float mxY);

	/// <summary>
	/// Checks if this collision box is colliding with another collision box
	/// </summary>
	/// <param name="other">Collision box to compare positions to</param>
	/// <returns>True if is colliding with other collision box</returns>
	bool CollidesWith(const CollisionBox& other);

	/// <summary>
	/// Draws debug lines around this collision box
	/// </summary>
	void DebugDraw();

};
