#include "../../include/union.h"

Field::Field(int size, int n, sf::RenderWindow& window, std::vector<int>& lis, std::vector<int>& lis_d) : size(size), n(n), 
            window(window), lis(lis), lis_d(lis_d) {
    field.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i].push_back({new Cell(size, i, j, window), 0});
        }
    }
}

Field::~Field() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete field[i][j].first;
        }
    }
}

void Field::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j].first->print();
        }
    }
}

void Field::in_rm_neighbors(int i, int j, int mode=0) {
    int r_x = (i + 1) % n, l_x = (i - 1 + n) % n;
    int u_y = (j + 1) % n, d_y = (j - 1 + n) % n;
    field[l_x][j].second += mode;
    field[r_x][j].second += mode;
    field[i][u_y].second += mode;
    field[i][d_y].second += mode;

    field[l_x][u_y].second += mode;
    field[l_x][d_y].second += mode;
    field[r_x][u_y].second += mode;
    field[r_x][d_y].second += mode;
}


void Field::recolor(int x, int y) {
    int i = x / size;
    int j = y / size;

    field[i][j].first->recolor();
    if (field[i][j].first->alife == 1) amount++;
    else amount--;
    in_rm_neighbors(i, j, field[i][j].first->alife);
}


void Field::next_move() {
    auto start_time=std::chrono::steady_clock::now(); 

    std::vector<std::pair<int, int>> to_flip;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j].first->alife == -1 && in(field[i][j].second, lis)) {
                to_flip.push_back({i, j});
            } 
            else if (field[i][j].first->alife == 1 && in(field[i][j].second, lis_d)) {
                to_flip.push_back({i, j});
            }
        }
    }

    for (auto [i, j] : to_flip) {
        recolor(i * size, j * size);
    }

    auto end_time=std::chrono::steady_clock::now();
    auto res=std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
    std::cout << res.count() << std::endl;

}

void Field::init_random(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int r_ch = rand() % 3;
            if (r_ch == 0){
                recolor(i * size, j * size);
            }
        }
    }
}


bool Field::in(int x, std::vector<int>& lis){
    return find(lis.begin(), lis.end(), x) != lis.end();
}

void Field::clear(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            field[i][j].first->alife = -1;
            field[i][j].first->color = ColorType::WHITE;
            field[i][j].second = 0;
            field[i][j].first->chacge();
        }
    }
    amount=0;
}