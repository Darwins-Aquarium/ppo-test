//
// Created by niels on 22-3-24.
//

#ifndef NETWORK_H
#define NETWORK_H
#include <torch/torch.h>


class Network : torch::nn::Module {
private:
    torch::nn::Linear fc1;
    torch::nn::Linear fc2;

public:
    Network() {
        fc1 = register_module("fc1", torch::nn::Linear(2, 10));
        fc2 = register_module("fc2", torch::nn::Linear(10, 4));
    }

    torch::Tensor forward(const torch::Tensor& observation) {
        auto x = torch::relu(fc1->forward(observation));
        x = torch::dropout(x, 0.5, is_training());
        x = torch::log_softmax(fc2->forward(x), 1);
        return x;
    }
};


#endif //NETWORK_H
