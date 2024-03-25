//
// Created by niels on 24-3-24.
//

#include "MultivariateNormal.h"

#include <utility>

MultivariateNormal::MultivariateNormal(torch::Tensor  mean, torch::Tensor  cov_mat, const int dim) : mean(std::move(mean)), cov_mat(std::move(cov_mat)), dim(dim){
}

torch::Tensor MultivariateNormal::sample() {
    auto eps = torch::ones({1,1})*0.0001;
    auto K = this->cov_mat + eps*torch::eye(this->dim);
    auto L = torch::linalg_cholesky(K);
    auto rv = torch::randn({1, this->dim});
    auto result =  this->mean +torch::mm(rv, L);
    return result;

}
