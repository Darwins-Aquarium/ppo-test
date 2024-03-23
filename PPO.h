//
// Created by niels on 22-3-24.
//

#ifndef PPO_H
#define PPO_H
#include "torch/torch.h"
#include "Game.h"
#include "Network.h"


class PPO {

private:
    torch::Tensor cov_mat;
    std::unique_ptr<Network> actor;
    std::unique_ptr<Network> critic;
    std::unique_ptr<torch::optim::Optimizer> actor_optimizer;
    std::unique_ptr<torch::optim::Optimizer> critic_optimizer;


public:
    void learn(int total_timesteps);
    PPO();
};



#endif //PPO_H
