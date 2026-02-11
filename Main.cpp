#include "constents.hpp"
#include "PizzaCut.hpp"







    



int main(void){ InitWindow(screenWidth, screenHeight, "Pizza Cut"); SetTargetFPS(60); //Set on same line as main method to clear up room & because its constent

    while (!WindowShouldClose()){
        // Update variables   
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mousePosition1 = GetMousePosition();
        }if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                mousePosition2 = GetMousePosition();
                midpointOfLine = calculateMidpoint(mousePosition1, mousePosition2);
                points = calculatePoints(midpointOfLine);
            }
       




        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText(text.c_str(), 400, 100, 20, GRAY);
            DrawText(to_string(points).c_str(), 50, 100, 20, GRAY);
            DrawCircleV(PizzaCenter, PizzaRadius, DARKBLUE);
            DrawLineEx(PizzaLineHZStart, PizzaLineHZEnd, 3.0 , RED);
            DrawLineEx(PizzaLineVTStart, PizzaLineVTEnd, 3.0 , RED);

            DrawLineEx(mousePosition1, mousePosition2, 3.0, BLACK);
            
            


        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    
    CloseWindow();
    

    return 0;
}