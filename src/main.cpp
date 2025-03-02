#include "../include/game.h"

#include <yaml-cpp/yaml.h>

int time_sleep = 60;
std::mutex eventMutex;
ColorType color_cell;

void tmp(States& state){
    state.run();
}

int main() {
    YAML::Node config = YAML::LoadFile("../config.yaml");
    int size = config["size"].as<int>();
    int n = config["n"].as<int>();
    std::string clr = config["color"].as<std::string>();
    color_cell = to_cColr(clr);

    Game new_game(size, n); //size, n
    States state(new_game);

    std::thread sec_w(tmp, std::ref(state));
    std::thread proc(processing_events, std::ref(state), std::ref(new_game));
    new_game.run();

    sec_w.join();
    proc.join();

    return 0;
}