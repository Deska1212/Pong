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
#include <string>

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

    

    int bottomScore = 0;
    int topScore = 0;

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 550;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    // Initializing Game Objects

    // Init Paddles
    Paddle topPaddle(screenWidth / 2, margin, paddleWidth, paddleHeight, ORANGE, paddleSpeed);
    Paddle bottomPaddle(screenWidth / 2, screenHeight - margin, paddleWidth, paddleHeight, BLUE, paddleSpeed);

    // Init Ball
    Ball ball(screenWidth / 2, screenHeight / 2, ballRadius, GREEN);
    ball.ApplyRandomDirection(ballSpeed); // Set initial ball velocity, goes down randomly left or right

    // Init Ball Collision Box
    CollisionBox ballCollisionBox = ball.GetCollisionBox();
    
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

        ball.Move();
        ballCollisionBox = ball.GetCollisionBox();

        // Get the position of the ball
        float ballX;
        float ballY;

        ball.GetPosition(ballX, ballY);


        // Check collisions on ball and change y delta if the ball hits a paddle
        if (ball.GetCollisionBox().CollidesWith(topPaddle.GetCollisionBox()))
        {
            float xDir;
            float yDir;
            ball.GetDirection(xDir, yDir);

            // Only collide with the paddle if the ball is moving in the direction of it
            // -y direction is going up
            if (yDir < 0)
            {
                ball.SetDirection(xDir, -yDir);
            }
        }
        
        if (ball.GetCollisionBox().CollidesWith(bottomPaddle.GetCollisionBox()))
        {
            float xDir;
            float yDir;
            ball.GetDirection(xDir, yDir);

            // Only collider with paddle if the ball is moving in the direction of it
            // +y direction is going down
            if (yDir > 0)
            {
                ball.SetDirection(xDir, -yDir);
            }
        }



        // UNCOMMENT THIS FOR EASIER ONE PLAYER TESTING 
        // player1.ImpossibleAI(ballX);


        // Check collisions on ball to see if it has hit the sides, if it has invert its X direction
        if (ballX < margin || ballX > screenWidth - margin)
        {
            float xDir;
            float yDir;
            ball.GetDirection(xDir, yDir);
            ball.SetDirection(-xDir, yDir);
        }

        /*
        * Loose/Win conditions:
        *
        * If the balls Y position goes < margin (topPaddle's y position) -> bottomPaddle wins
        * If the balls Y position goes > screenHeight - margin (bottomPaddle's y pos) -> topPaddle wins
        *
        */

        // Check win/loose conditions
        if (ballY < margin)
        {
            // The ball has crossed the top paddles goal area
            // Reset the ball
            ball.SetPosition(screenWidth / 2, screenHeight / 2);
            ball.ApplyRandomDirection(ballSpeed);


            // Point goes to bottom paddle
            bottomScore++;
        }

        if (ballY > screenHeight - margin)
        {
            // The ball has crossed the bottom paddles goal area
            // Reset the ball
            ball.SetPosition(screenWidth / 2, screenHeight / 2);
            ball.ApplyRandomDirection(ballSpeed);

            // Point goes to top paddle
            topScore++;
        }




        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw Paddles
        topPaddle.Draw();
        bottomPaddle.Draw();

        // Draw ball
        ball.Draw();

        std::string tScore;
        tScore = std::to_string(topScore);

        std::string bScore;
        bScore = std::to_string(bottomScore);

        // Draw Score text and centre point
        DrawText(tScore.c_str(), screenWidth / 2, 100, 60, ORANGE);
        DrawText("----------------------------------------------------------------------------", 0, screenHeight / 2, 20, LIGHTGRAY);
        DrawText(bScore.c_str(), screenWidth / 2, screenHeight - 150, 60, BLUE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}