#pragma once
#include "Ball.h";

Ball::Ball(float x, float y, float r, Color c) :
	xPos{ x },
	yPos{ y },
	radius{ r },
	color{ c },
	deltaX{ 0 },
	deltaY{ 0 }
{}


void Ball::SetPosition(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Ball::GetPosition(float& x, float& y)
{
	x = xPos;
	y = yPos;
}

void Ball::SetDirection(float x, float y)
{
	deltaX = x;
	deltaY = y;
}

void Ball::GetDirection(float& x, float& y)
{
	x = deltaX;
	y = deltaY;
}

void Ball::ApplyRandomDirection(const float moveSpeed)
{

	int rand = GetRandomValue(0, 3);
	if (rand == 0)
	{
		SetDirection(1, -moveSpeed);
	}
	else if (rand == 1)
	{
		SetDirection(1, moveSpeed);
	}
	else if (rand == 2)
	{
		SetDirection(-1, moveSpeed);
	}
	else if (rand == 3)
	{
		SetDirection(-1, -moveSpeed);
	}
}

void Ball::Move()
{
	xPos = xPos + deltaX;
	yPos = yPos + deltaY;
}

void Ball::Draw()
{
	DrawCircle(xPos, yPos, radius, color);
}

CollisionBox Ball::GetCollisionBox()
{
	return CollisionBox(xPos - radius, yPos - radius, xPos + radius, yPos + radius);
}



