#pragma once

#include <SDL2/SDL.h>

class Engine {
public:
    Engine();
    ~Engine();
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Shutdown();
    bool get_is_running();
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Event event_;
    bool is_running_;

    enum Player_State {
        MOVE_RIGHT,
        MOVE_LEFT,
        IN_PLACE
    };

    Player_State player_state_;

    void SetPlayerVelocity(Player_State player_state);
};