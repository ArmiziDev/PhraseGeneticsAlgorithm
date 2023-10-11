#include "Population.h"
#include <iostream>

int main() {
    std::string target = "Hello World!";
    int populationSize = 1000;
    double mutationRate = 0.01;

    Population pop(target, populationSize, mutationRate);

    int generation = 0;
    while (pop.getBest() != target) {
        generation++;
        pop.naturalSelection();
        pop.generate();
        std::cout << "Generation: " << generation << " | " << pop.getBest() << std::endl;
    }

    std::cout << "Target achieved in " << generation << " generations." << std::endl;

    return 0;
}
