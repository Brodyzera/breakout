#include <SDL2/SDL.h>
#include "Engine.h"

int main(int argc, char* argv[]) {
    int width {800};
    int height {600};
    bool is_running {false};

    Engine engine{};

    // Initialize SDL2
    engine.Initialize(width, height);

    // Main loop
    while (engine.get_is_running()) {
        engine.ProcessInput();
        // Game Update
        // Render
    }

    // Shutdown SDL components / systems
    engine.Shutdown();

    return 0;
}