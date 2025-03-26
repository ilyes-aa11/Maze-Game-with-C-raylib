#include "Macros.h"
#include "Player.h"
#include <string>


int main() {
    InitWindow(SCREENWIDTH , SCREENHEIGHT , "MAZE");
    SetTargetFPS(60);
    
    restartgame__label:
    Maze game(ROWS , COLS);
    game.InitMaze();
    Player p1(game.GetStartX() + 0.5 ,game.GetStartY() + 0.5 ,3.0,std::min(CELLHEIGHT,CELLWIDTH)/4.0);
    
    float timer = 0.0;
    int seconds = 0 , minutes = 0;
    Camera2D cam;
    Vector2 textPos , worldPos;
    std::string s_timer;
    cam.zoom = 3.8;
    cam.rotation = 0.0;
    cam.offset = {SCREENWIDTH/2.0 , SCREENHEIGHT/2.0};
    
    while(!WindowShouldClose()) {
        
        if(p1.EndCheck(game.GetEnd())) {
            goto restartgame__label;
        }
        
        float deltatime = GetFrameTime();
        timer += deltatime;
        seconds += (int) timer;
        minutes += seconds / 60;
        timer = (timer >= 1) ? timer-1:timer;
        seconds = seconds % 60;
        s_timer = ( (minutes < 10) ? "0"+std::to_string(minutes):std::to_string(minutes) ) + ":" + ( (seconds < 10) ? "0"+std::to_string(seconds):std::to_string(seconds) );

        if(IsKeyDown(KEY_W)) p1.MoveUp(game , deltatime);
        if(IsKeyDown(KEY_S)) p1.MoveDown(game , deltatime);
        if(IsKeyDown(KEY_A)) p1.MoveLeft(game , deltatime);
        if(IsKeyDown(KEY_D)) p1.MoveRight(game , deltatime);
        if(IsKeyPressed(KEY_R)) cam.zoom += 0.2;
        if(IsKeyPressed(KEY_E)) cam.zoom -= 0.2;

        cam.target = {p1.GetX() * CELLWIDTH , p1.GetY() * CELLHEIGHT}; // updating the camera position
        textPos = { 10, 10 };  // 10 pixels from the top-left corner of the screen
        worldPos = GetScreenToWorld2D(textPos, cam);
        
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(cam);
                DrawMaze(game);
                DrawStart(game);
                DrawEnd(game);
                DrawPlayer(p1);
                DrawText(s_timer.c_str() , worldPos.x , worldPos.y , 10 , GRAY);
            EndMode2D();
        EndDrawing();
    }

    
    CloseWindow();
    return 0;
}