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
    int dim;
public:
    MultivariateNormal(torch::Tensor  mean, torch::Tensor  cov_mat, int dim);
    torch::Tensor sample();

};



#endif //MULTIVARIATENORMAL_H
