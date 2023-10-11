//
// Created by Arman on 10/11/23.
//

#ifndef WORDGENETICS_DNA_H
#define WORDGENETICS_DNA_H

#pragma once
#include <string>

class DNA {
public:
    DNA(int length);
    void generateRandom();
    std::string getGene() const;
    double calcFitness(const std::string& target) const;
    DNA crossover(const DNA& partner) const;
    void mutate(double mutationRate);

private:
    std::string gene;
};



#endif //WORDGENETICS_DNA_H
