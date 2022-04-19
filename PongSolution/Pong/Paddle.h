#pragma once
#include <raylib.h>
#include "CollisionBox.h"

class Paddle
{
private:
	// Centre positions for the paddle
	float xPos;
	float yPos;

	// Width and height of paddle in px
	float width;
	float height;

	// Paddle movement speed in px per frm
	float moveSpeed;

	// Paddle Color
	Color color;

public: 
	/// <summary>
	/// Paddle Constructor
	/// </summary>
	/// <param name = "x"> X center position of paddle</param>
	/// <param name = "y"> Y center position of paddle</param>
	/// <param name = "w"> Width of paddle</param>
	/// <param name = "h"> Height of paddle</param>
	/// <param name = "c"> Color of paddle</param>
	/// <param name = "spd"> Speed of paddle</param>
	Paddle(float x, float y, float w, float h, Color c, float spd);

	/// <summary>
	/// Moves paddle to the left by paddle speed
	/// </summary>
	/// <param name="screenWidth">Pass in screen width to clamp position on screen</param>
	void MoveLeft(int screenWidth);

	/// <summary>
	/// Moves paddle to the right by paddle speed
	/// </summary>
	/// <param name="screenWidth">Pass in screen width to clamp position on screen</param>
	void MoveRight(int screenWidth);

	/// <summary>
	/// Paddle Draw Method
	/// </summary>
	void Draw();
	
	/// <summary>
	/// Returns collision box based on this paddles size and position
	/// </summary>
	/// <returns>The Collision Box detailed by this paddle</returns>
	CollisionBox GetCollisionBox();

};