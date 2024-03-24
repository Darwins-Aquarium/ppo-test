//
// Created by niels on 22-3-24.
//

#ifndef PPO_H
#define PPO_H
#include "Game.h"
#include "torch/torch.h"
#include "Network.h"

struct BatchResult {
    std::vector<std::vector<int>> observations;
    std::vector<int> actions;
    std::vector<float> log_probs;
    std::vector<float> rewards;
    std::vector<float> reward_to_gos;
    std::vector<int> lengths;
};

struct PPOParams {
    int timesteps_per_batch=32;
    int timesteps_per_episode=1000;
};

class PPO {

private:
    torch::Tensor cov_mat;
    std::unique_ptr<Network> actor;
    std::unique_ptr<Network> critic;
    std::unique_ptr<torch::optim::Optimizer> actor_optimizer;
    std::unique_ptr<torch::optim::Optimizer> critic_optimizer;
    std::unique_ptr<Game> game;
    PPOParams params;


    BatchResult rollout();


public:
    void learn(int total_timesteps);
    PPO(PPOParams params);
};



#endif //PPO_H
