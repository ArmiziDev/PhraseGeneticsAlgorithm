//
// Created by Arman on 10/11/23.
//

#include "DNA.h"
#include <cstdlib>
#include <cmath>

DNA::DNA(int length) : gene(length, ' ') {
    generateRandom();
}

void DNA::generateRandom() {
    for (char& c : gene) {
        c = ' ' + rand() % 95; // covers ASCII characters from space to '~'
    }
}

std::string DNA::getGene() const {
    return gene;
}

double DNA::calcFitness(const std::string& target) const {
    int score = 0;
    for (size_t i = 0; i < gene.size(); i++) {
        if (gene[i] == target[i]) {
            score++;
        }
    }
    return static_cast<double>(score) / target.size();
}

DNA DNA::crossover(const DNA& partner) const {
    DNA child(gene.size());
    int midpoint = rand() % gene.size();
    for (size_t i = 0; i < gene.size(); i++) {
        child.gene[i] = (i < midpoint) ? gene[i] : partner.gene[i];
    }
    return child;
}

void DNA::mutate(double mutationRate) {
    for (char& c : gene) {
        if ((rand() / static_cast<double>(RAND_MAX)) < mutationRate) {
            c = ' ' + rand() % 95;
        }
    }
}
