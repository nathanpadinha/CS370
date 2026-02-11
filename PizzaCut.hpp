#include "constents.hpp"

float PizzaRadius = 250.0;

//Drawing Pizza ***TEMP UNTIL ASSETS***
Vector2 PizzaCenter = { 400.0f, 400.0f };
Vector2 PizzaLineHZStart = { PizzaCenter.x - PizzaRadius, PizzaCenter.y  };
Vector2 PizzaLineHZEnd = { PizzaCenter.x + PizzaRadius, PizzaCenter.y  };
Vector2 PizzaLineVTStart = { PizzaCenter.x, PizzaCenter.y - PizzaRadius };
Vector2 PizzaLineVTEnd = { PizzaCenter.x, PizzaCenter.y + PizzaRadius };

Vector2 mousePosition1;
Vector2 mousePosition2;
Vector2 midpointOfLine;
    
float distanceFromCenter;

string text;

double points = 0.00;

const int screenWidth = 800, screenHeight = 800;

/*Calculates the midpoint of a between 2 vectors
Pre:
    2 fully populated Vector2
Post:
    Returns Vector2
Author: Nathan Padinha
*/
Vector2 calculateMidpoint(Vector2 vector1,  Vector2 vector2){
    midpointOfLine.x = ( vector1.x + vector2.x ) / 2;
    midpointOfLine.x = ( vector1.x + vector2.x ) / 2;
    midpointOfLine.y = ( vector1.y + vector2.y ) / 2;
    midpointOfLine.y = ( vector1.y + vector2.y ) / 2;
    
    return midpointOfLine;
}


/*Calculates Points based on distance between midpoint of player line and pizza center
and the furthest possible distance normalized to 100
Pre:
     1 fully populated Vector2
Post:
    Returns int
Author: Nathan Padinha */
int calculatePoints(Vector2 vector){
    double distance = Vector2Distance(vector, PizzaCenter); //Get distance between midpoint and center 
    double points = 100 - ( (distance / screenWidth) * 100);//
    
    points = ceil(points);
    int newPoints = points;
    
    return newPoints;
    
}
    