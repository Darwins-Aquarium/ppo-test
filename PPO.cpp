//
// Created by niels on 22-3-24.
//

#include "PPO.h"


PPO::PPO() {
    auto game = std::make_unique<Game>(Game());
    auto cov_mat = torch::full(game->num_actions, 0.5);
    this->cov_mat = torch::diag(cov_mat);
    this->actor = std::make_unique<Network>(Network(game->num_obs, game->num_actions));
    this->critic = std::make_unique<Network>(Network(game->num_obs, 1));
    this->actor_optimizer = std::make_unique<torch::optim::Adam>(torch::optim::Adam(actor->parameters()));
    this->critic_optimizer = std::make_unique<torch::optim::Adam>(torch::optim::Adam(critic->parameters()));
}

void PPO::learn(const int total_timesteps) {
    int num_timesteps = 0;
    int num_iterations = 0;
    while(num_timesteps < total_timesteps) {

    }

}
