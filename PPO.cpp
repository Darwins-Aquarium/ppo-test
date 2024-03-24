//
// Created by niels on 22-3-24.
// based on: https://github.com/ericyangyu/PPO-for-Beginners/blob/master/ppo.py
//

#include "PPO.h"


PPO::PPO(PPOParams params) {
    this->game = std::make_unique<Game>(Game());
    auto cov_mat = torch::full(game->num_actions, 0.5);
    this->cov_mat = torch::diag(cov_mat);
    this->actor = std::make_unique<Network>(Network(game->num_obs, game->num_actions));
    this->critic = std::make_unique<Network>(Network(game->num_obs, 1));
    this->actor_optimizer = std::make_unique<torch::optim::Adam>(torch::optim::Adam(actor->parameters()));
    this->critic_optimizer = std::make_unique<torch::optim::Adam>(torch::optim::Adam(critic->parameters()));
    this->params = params;
}

BatchResult PPO::rollout() {
    std::vector<float> ep_rewards;
    BatchResult batch_result;
    int t = 0;
    while (t < this->params.timesteps_per_batch) {
        ep_rewards.clear();
        bool done = false;
        game->new_game();
        for (int ep_t = 0; ep_t < this->params.timesteps_per_episode; ep_t++) {
            t++;
            auto obs = game->get_observation();
            batch_result.observations.push_back(obs);
            // calculate action and log prob
            auto mean = this->actor->forward(
                torch::from_blob(obs.data(), {1, obs.size()}, torch::TensorOptions().dtype(torch::kInt32)));

        }
    }

    return batch_result;
}

void PPO::learn(const int total_timesteps) {
    int num_timesteps = 0;
    int num_iterations = 0;
    while (num_timesteps < total_timesteps) {
    }
}
