#pragma once
#include <raylib.h>
#include "CollisionBox.h"

class Ball
{
private:
	float xPos;
	float yPos;
	float radius;

	float deltaX;
	float deltaY;

	Color color;
public:

	// TODO: Comment this section with summaries

	Ball(float x, float y, float r, Color c);
	void Move();
	void SetPosition(float x, float y);
	void GetPosition(float& x, float& y);
	void SetDirection(float x, float y);
	void GetDirection(float& x, float& y);
	void ApplyRandomDirection(const float moveSpeed);
	void Draw();
	CollisionBox GetCollisionBox();
};