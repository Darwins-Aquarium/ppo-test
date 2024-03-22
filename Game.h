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
    static constexpr int move_down = 0;
    static constexpr int move_up = 1;
    static constexpr int move_left = 2;
    static constexpr int move_right = 3;

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
