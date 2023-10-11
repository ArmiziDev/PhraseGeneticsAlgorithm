//
// Created by Arman on 10/11/23.
//

#include "Population.h"

#include <algorithm>

Population::Population(const std::string& target, int populationSize, double mutationRate)
        : target(target), mutationRate(mutationRate) {
    for (int i = 0; i < populationSize; i++) {
        population.emplace_back(target.size());
    }
}

void Population::naturalSelection() {
    matingPool.clear();
    double maxFitness = 0;
    for (const auto& dna : population) {
        double fitness = dna.calcFitness(target);
        if (fitness > maxFitness) {
            maxFitness = fitness;
        }
    }

    for (const auto& dna : population) {
        int n = static_cast<int>(dna.calcFitness(target) / maxFitness * 100);
        for (int j = 0; j < n; j++) {
            matingPool.push_back(dna);
        }
    }
}

void Population::generate() {
    for (size_t i = 0; i < population.size(); i++) {
        int a = rand() % matingPool.size();
        int b = rand() % matingPool.size();
        DNA partnerA = matingPool[a];
        DNA partnerB = matingPool[b];
        DNA child = partnerA.crossover(partnerB);
        child.mutate(mutationRate);
        population[i] = child;
    }
}

std::string Population::getBest() const {
    return std::max_element(population.begin(), population.end(),
                            [&](const DNA& a, const DNA& b) {
                                return a.calcFitness(target) < b.calcFitness(target);
                            })->getGene();
}
