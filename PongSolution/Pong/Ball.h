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


	/// <summary>
	/// Ball constuctor
	/// </summary>
	/// <param name="x">X position of ball</param>
	/// <param name="y">Y position of ball</param>
	/// <param name="r">Radius of ball</param>
	/// <param name="c">Ball color</param>
	Ball(float x, float y, float r, Color c);

	/// <summary>
	///  Move function
	/// </summary>
	void Move();

	/// <summary>
	///  Sets the balls position
	/// </summary>
	/// <param name="x">X position to set</param>
	/// <param name="y">Y position to set</param>
	void SetPosition(float x, float y);

	/// <summary>
	/// Return the balls position by reference
	/// </summary>
	/// <param name="x">X position of ball</param>
	/// <param name="y">Y position of ball</param>
	void GetPosition(float& x, float& y);

	/// <summary>
	/// Sets the balls directuon
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetDirection(float x, float y);
	void GetDirection(float& x, float& y);
	void ApplyRandomDirection(const float moveSpeed);
	void Draw();
	CollisionBox GetCollisionBox();
};