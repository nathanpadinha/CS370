#include <raylib.h>
#include "cook.h"
#include <ctime>
#include <cstdlib>

int main() {
    InitWindow(800, 800, "Pocalypse Pizzeria");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCookingStation();

        EndDrawing();

    }

    CloseWindow();
    return 0;
    
}