#include "../include/game.h"

int time_sleep = 60;
std::mutex eventMutex;

void tmp(States& state){
    state.run();
}

int main() {
    Game new_game(40, 20); //size, n
    States state(new_game);

    std::thread sec_w(tmp, std::ref(state));
    std::thread proc(processing_events, std::ref(state), std::ref(new_game));
    new_game.run();

    sec_w.join();
    proc.join();

    return 0;
}