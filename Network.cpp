//
// Created by niels on 22-3-24.
//

#include "Network.h"

torch::Tensor Network::forward(const torch::Tensor& observation) {
    auto x = torch::relu(fc1->forward(observation));
    x = torch::dropout(x, 0.5, is_training());
    x = torch::log_softmax(fc2->forward(x), 1);
    return x;
}

Network::Network(int num_inputs, int num_outputs) {
    fc1 = register_module("fc1", torch::nn::Linear(num_inputs, 10));
    fc2 = register_module("fc2", torch::nn::Linear(10, num_outputs));
}
