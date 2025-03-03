#include "../include/game.h"
#include <yaml-cpp/yaml.h>

int time_sleep = 60;
ColorType color_cell;
int amount = 0;

void init_sett_thread(States& state){
    state.run();
}

int main() {
    YAML::Node config = YAML::LoadFile("../config.yaml");
    int size = config["size"].as<int>();
    int n = config["n"].as<int>();
    std::string clr = config["color"].as<std::string>();
    color_cell = to_cColr(clr);
    bool init_random = config["init_random"].as<bool>();

    Game game(size, n); //size, n
    if (init_random)
        game.init_random();
    States state(game);

    std::thread settings_window_thread(init_sett_thread, std::ref(state));
    game.run();

    
    settings_window_thread.join();

    return 0;
}