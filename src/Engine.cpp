#include "Engine.h"
#include <iostream>

Engine::Engine() {
    window_ = nullptr;
    renderer_ = nullptr;
    is_running_ = false;
    player_state_ = IN_PLACE;
}

Engine::~Engine() {
    Shutdown();
}

void Engine::Initialize(int width, int height) {
    // Initialize SDL and sub-systems
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Initializing SDL...");
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error Initializing SDL.");
        is_running_ = false;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Creating window object...");
    window_ = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN);

    if (!window_)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error creating SDL window.");
        is_running_ = false;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Creating renderer object...");
    renderer_ = SDL_CreateRenderer(window_, -1, 0);

    if (!renderer_)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error creating SDL renderer.");
        is_running_ = false;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Initialization complete! Engine is now running...");
    is_running_ = true;
}

void Engine::ProcessInput() {
    while (SDL_PollEvent(&event_) != 0) {
        switch (event_.type) {
            case SDL_QUIT: {
                is_running_ = false;
                break;
            }

            case (SDL_KEYDOWN): {
                if (event_.key.keysym.sym == SDLK_LEFT) {
                    player_state_ = MOVE_LEFT;
                } else if (event_.key.keysym.sym == SDLK_RIGHT) {
                    player_state_ = MOVE_RIGHT;
                }
                break;
            }

            case (SDL_KEYUP): {
                player_state_ = IN_PLACE;
                break;
            }

            default: {
                break;
            }
        }
    }
    std::cout << player_state_ << std::endl;
}

void Engine::Update() {

}

void Engine::Shutdown() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
}

bool Engine::get_is_running() {
    return is_running_;
}

void Engine::SetPlayerVelocity(Player_State player_state) {

}