//
// Created by Arman on 10/11/23.
//

#ifndef WORDGENETICS_POPULATION_H
#define WORDGENETICS_POPULATION_H

#pragma once
#include "DNA.h"
#include <vector>

class Population {
public:
    Population(const std::string& target, int populationSize, double mutationRate);
    void naturalSelection();
    void generate();
    std::string getBest() const;

private:
    std::vector<DNA> population;
    std::vector<DNA> matingPool;
    std::string target;
    double mutationRate;
};



#endif //WORDGENETICS_POPULATION_H
