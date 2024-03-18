//
// Created by niels on 18-3-24.
//

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <random>


class Game {
private:
    const int game_size = 8;
    const int player_token = 1;
    const int target_token = 2;
    const int empty = 0;
    const int move_down = 0;
    const int move_up = 0;
    const int move_left = 0;
    const int move_right = 0;

    std::pair<int,int> player_pos; // (y, x)
    std::pair<int,int> target_pos; // (y, x)
    std::mt19937 rng;
public:
    void new_game();
    [[nodiscard]] std::vector<int> get_actions() const;
    int perform_action(int action);
    [[nodiscard]] std::vector<int> get_observations() const;
};



#endif //GAME_H
