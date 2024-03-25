#include <iostream>

#include "MultivariateNormal.h"
#include "Network.h"

int main() {
    torch::Tensor mu = torch::tensor({{1.0, 2.0}});
    torch::Tensor cov = torch::tensor({{2.0, 1.0}, {1.0, 2.0}});

    std::cout << MultivariateNormal(mu, cov, 2).sample() << std::endl;

    return 0;
}
