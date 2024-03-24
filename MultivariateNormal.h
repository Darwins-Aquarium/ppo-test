//
// Created by niels on 24-3-24.
//

#ifndef MULTIVARIATENORMAL_H
#define MULTIVARIATENORMAL_H
#include "torch/torch.h"



class MultivariateNormal {
private:
    torch::Tensor mean;
    torch::Tensor cov_mat;
public:
    MultivariateNormal(const torch::Tensor& mean, const torch::Tensor& cov_mat);
    torch::Tensor sample();

};



#endif //MULTIVARIATENORMAL_H
