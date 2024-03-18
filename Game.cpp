//
// Created by niels on 18-3-24.
//

#include "Game.h"

void Game::new_game() {
    std::uniform_int_distribution<int> uid(0,game_size*game_size-1);
    int temp_target_pos = uid(rng);
    int temp_player_pos;
    do {
        temp_player_pos = uid(rng);
    } while(temp_player_pos == temp_target_pos);
    player_pos = std::make_pair(temp_player_pos/8, temp_player_pos%8);
    target_pos = std::make_pair(temp_target_pos/8, temp_target_pos%8);
}

std::vector<int> Game::get_actions() const {
    /**
     * -> x
     * |
     * v - - - -
     * y -
     *   -
     *   -
     */
    std::vector<int> result;
    // up
    if(player_pos.first >0)
        result.push_back(move_up);

    // down
    if(player_pos.first<7)
        result.push_back(move_down);

    // left
    if(player_pos.second>0)
        result.push_back(move_left);

    // right
    if(player_pos.second<7)
        result.push_back(move_right);

    return result;
}

int Game::perform_action(const int action) {
    switch (action) {
        case move_up:
            player_pos.first--;
            break;
        case move_down:
            player_pos.first++;
            break;
        case move_left:
            player_pos.second--;
            break;
        case move_right:
            player_pos.second++;
            break;
    }
    if(player_pos.first == target_pos.first && player_pos.second == target_pos.second) {
        do {
            std::uniform_int_distribution uid(0,game_size*game_size-1);
            target_pos.first = uid(rng);
            target_pos.second = uid(rng);
        } while(player_pos.first == target_pos.first && player_pos.second == target_pos.second);
        return 1;
    }

    return 0;

}

std::vector<int> Game::get_observations() const {
    std::vector<int> result;
    result.push_back(target_pos.first - player_pos.first);
    result.push_back(target_pos.second - player_pos.second);
    return result;
}



