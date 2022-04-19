/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>

#include "Paddle.h"
#include "Ball.h"

int main(int argc, char* argv[])
{
    // Constants
    const int margin = 20;
    const int paddleWidth = 100;
    const int paddleHeight = 20;
    const int ballRadius = 15;
    const int ballSpeed = 4.5;
    const int paddleSpeed = 5;

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 550;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    // Initializing Game Objects

    // Init Paddles
    Paddle topPaddle(screenWidth / 2, margin, paddleWidth, paddleHeight, BLUE, paddleSpeed);
    Paddle bottomPaddle(screenWidth / 2, screenHeight - margin, paddleWidth, paddleHeight, BLUE, paddleSpeed);

    // Init Ball
    Ball ball(screenWidth / 2, screenHeight / 2, ballRadius, RED);
    ball.ApplyRandomDirection(ballSpeed); // Set initial ball velocity, goes down randomly left or right

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Update/Detect Player Input and move paddles
        if (IsKeyDown(KEY_LEFT))
        {
            topPaddle.MoveLeft(margin);
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            topPaddle.MoveRight(screenWidth - margin);
        }

        if (IsKeyDown(KEY_A))
        {
            bottomPaddle.MoveLeft(margin);
        }

        if (IsKeyDown(KEY_D))
        {
            bottomPaddle.MoveRight(screenWidth - margin);
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw Paddles
        topPaddle.Draw();
        bottomPaddle.Draw();

        DrawText("----------------------------------------------------------------------------", 0, screenHeight / 2, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}