#include "cook.h"

void DrawCookingStation() {
   // Stove
   const int stoveX = 200;
   const int stoveY = 200;
   const int stoveSize = 400;

   DrawRectangle(stoveX, stoveY, stoveSize, stoveSize, DARKGRAY);
   DrawRectangleLines(stoveX, stoveY, stoveSize, stoveSize, BLACK);

   // Pizza
   Vector2 center = {
    stoveX + stoveSize / 2.0f,
    stoveY + stoveSize / 2.0f
   };
   float radius = 140.0f;

   DrawCircleV(center, radius, BEIGE);
   DrawCircleLines((int)center.x, (int)center.y, radius, BROWN);

   // Timer
   const float cookTime = 6.0f;

   static float startTime = -1.0f;
   static bool hideBox = false;

   if(startTime < 0.0f) startTime = (float)GetTime();

   float elapsed = (float)GetTime() - startTime;
   float remaining = cookTime - elapsed;

   if(remaining < 0.0f) remaining = 0.0f;

   // Draw timer box
   int boxW = 140;
   int boxH = 70;
   int boxX = 800 - boxW - 20;
   int boxY = 20;

   Rectangle boxRect = {(float)boxX, (float)boxY, (float)boxW, (float)boxH};

   if(!hideBox) {
    DrawRectangle(boxX, boxY, boxW, boxH, LIGHTGRAY);
    DrawRectangleLines(boxX, boxY, boxW, boxH, BLACK);

    if(remaining > 0.0f) {
        int secondsLeft = (int)(remaining + 1);
        DrawText(TextFormat("Time: %d", secondsLeft), boxX + 15, boxY + 20, 20, BLACK);
    } else {
        DrawText("DONE", boxX + 35, boxY + 20, 25, BLUE);

        // check for mouse click inside box
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), boxRect)) {
            CloseWindow(); // Box disappears
        }
    }
   }

}