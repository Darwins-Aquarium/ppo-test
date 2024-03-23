#include <iostream>

#include "Network.h"

int main() {
    auto net = std::make_unique<Network>(Network(2, 4));
    auto observation = torch::ones({1, 2});
    auto res = net->forward(observation);
    for(int i=0; i<4; i++) {
        std::cout << res[0][i] << std::endl;
    }

    return 0;
}
