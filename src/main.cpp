#include "../include/union.h"
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
    std::vector<int> lis = config["create_life"].as<std::vector<int>>();
    std::vector<int> lis_d = config["deapth_life"].as<std::vector<int>>();

    Game game(size, n, lis, lis_d); //size, n
    if (init_random)
        game.init_random();
    States state(game);

    std::thread settings_window_thread(init_sett_thread, std::ref(state));
    game.run();

    
    settings_window_thread.join();

    return 0;
}