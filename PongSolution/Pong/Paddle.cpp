#include <raylib.h>;
#include "Paddle.h";

// Paddle Constructor Definition
Paddle::Paddle(float x, float y, float w, float h, Color c, float s) : 
	xPos{x},
	yPos{y},
	width{w},
	height{h},
	color{c},
	moveSpeed{s}
{

}

// Draw Definition
void Paddle::Draw()
{
	DrawRectangle(xPos - (width / 2), yPos - (height / 2), width, height, color);
}

// Input functions

void Paddle::MoveLeft(int screenWidth)
{
	xPos = xPos - moveSpeed; // Move the paddle
	if (xPos < screenWidth + (width / 2))
	{
		// If we are over the side of the window, cap position
		xPos = screenWidth + (width / 2);
	}
}

void Paddle::MoveRight(int screenWidth)
{
	xPos = xPos + moveSpeed; // Move the paddle
	if (xPos > screenWidth - (width / 2))
	{
		// If we are over the side of the window, cap position
		xPos = screenWidth - (width / 2);
	}
}