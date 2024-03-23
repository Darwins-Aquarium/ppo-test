//
// Created by niels on 22-3-24.
//

#ifndef NETWORK_H
#define NETWORK_H
#include <torch/torch.h>


class Network final : public torch::nn::Module {
private:
    torch::nn::Linear fc1=nullptr;
    torch::nn::Linear fc2=nullptr;

public:
    explicit Network(int num_inputs, int num_outputs);
    torch::Tensor forward(const torch::Tensor& observation);
};


#endif //NETWORK_H
