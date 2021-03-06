#include "include/raylib.h"
#include <string.h>
#include <iostream>

int main() {
  constexpr int screenHeight{450};
  constexpr int screenWidth{800};

  InitWindow(screenWidth, screenHeight, "First Window");

  SetTargetFPS(60);

// initialise vars

   
  Vector2 ballPos{(float)screenWidth * 0.5, (float)screenHeight * 0.5};
  Vector2 touchPosition{0,0};
   
  int BALL_SPEED{5};
  int lastGesture{GESTURE_NONE}; // keeping track of our last Gesture 
  int currentGesture{GESTURE_NONE}; // for Gesture controll 
  int gestureCount{0};

  constexpr float touchBorderWR{screenWidth - 230.0f};
  constexpr float touchBorderHR{screenHeight - 20.0f};  
  constexpr int touchBorderWL{220};
  constexpr int touchBorderHL{10};
  Rectangle touchArea = { touchBorderWL, touchBorderHL, touchBorderWR, touchBorderHR }; 

  char gestureString[20][32]{}; // max amount we store
// for movement rectangle 
 

 
 while (!WindowShouldClose()) {
//  Gestures

  lastGesture = currentGesture;
  currentGesture = GetGestureDetected(); 
  touchPosition = GetTouchPosition(0); 


  if(CheckCollisionPointRec(touchPosition, touchArea) && (currentGesture != GESTURE_NONE)){
    if(currentGesture != GESTURE_NONE)
    {
       if(currentGesture != lastGesture)
      {
        switch(currentGesture)
        {
          case GESTURE_TAP:         strcpy(gestureString[gestureCount], "GESTURE TAP");         break;
          case GESTURE_DOUBLETAP:   strcpy(gestureString[gestureCount],  "GESTURE DOUBLE TAP");  break;
          case GESTURE_HOLD:        strcpy(gestureString[gestureCount],  "GESTURE HOLD");        break;
          case GESTURE_DRAG:        strcpy(gestureString[gestureCount],  "GESTURE DRAG");        break;
          case GESTURE_SWIPE_RIGHT: strcpy(gestureString[gestureCount],  "GESTURE SWIPE RIGHT"); break;
          case GESTURE_SWIPE_LEFT:  strcpy(gestureString[gestureCount],  "GESTURE SWIPE LEFT");  break;
          case GESTURE_SWIPE_UP:    strcpy(gestureString[gestureCount],  "GESTURE SWIPE UP");    break;
          case GESTURE_SWIPE_DOWN:  strcpy(gestureString[gestureCount],  "GESTURE SWIPE DOWN");  break;
          case GESTURE_PINCH_IN:    strcpy(gestureString[gestureCount],  "GESTURE PINCH IN");    break;
          case GESTURE_PINCH_OUT:   strcpy(gestureString[gestureCount],  "GESTURE PINCH OUT");   break;
          default: break;
        }    
        gestureCount++; 
        // resetting the array
        if(gestureCount >= 20){
          for(int i{0}; i < 20; i++){
             strcpy(gestureString[i], "\0");
             gestureCount = 0;
            }
          }
        }
      } 
    }
   // move ball on key down 
    if(IsKeyDown(KEY_A)) ballPos.x -= BALL_SPEED; // which is 5
    if(IsKeyDown(KEY_D)) ballPos.x += BALL_SPEED;
    if(IsKeyDown(KEY_W)) ballPos.y -= BALL_SPEED;
    if(IsKeyDown(KEY_S)) ballPos.y += BALL_SPEED;
 

    int tpX = touchPosition.x;
    int tpY = touchPosition.y;
    BeginDrawing();
    ClearBackground(DARKGRAY);

    DrawRectangleRec(touchArea, GRAY);
    DrawRectangle(225, 15, screenWidth - 240, screenHeight - 30, DARKGRAY); // border
    
   //  DrawCircleV(touchPosition, RadiusCircle, GOLD); // drawing the circle (with radius 5.5)
    DrawText(TextFormat("The Y position of the ball is: %03d", tpY), 225,20,20,RED); 
    DrawText(TextFormat("The X position of the ball is: %03d", tpX),  225,40,20,RED);

    for (int i{0}; i < gestureCount; i++)
      {
          if (i%2 == 0) DrawRectangle(10, 30 + 20*i, 200, 20, Fade(LIGHTGRAY, 0.5f));
          else DrawRectangle(10, 30 + 20*i, 200, 20, Fade(LIGHTGRAY, 0.3f));

          if (i < gestureCount - 1) {
            DrawText(gestureString[i], 35, 36 + 20*i, 10, DARKGRAY);
            
          }
          else DrawText(gestureString[i], 35, 36 + 20*i, 10, MAROON);
      }
    
    DrawRectangleLines(10, 29, 200, screenHeight - 50, RAYWHITE);
    if (currentGesture != GESTURE_NONE) DrawCircleV(touchPosition, 30, MAROON);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
