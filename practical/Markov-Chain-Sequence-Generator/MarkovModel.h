//
// Created by Dhruv Kandula on 7/14/23.
//

#ifndef MARKOV_CHAIN_SEQUENCE_GENERATOR_MARKOVMODEL_H
#define MARKOV_CHAIN_SEQUENCE_GENERATOR_MARKOVMODEL_H

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "tuple"
#include "ctime"
#include "cstdlib"
#include "random"
using std::cout;
using std::map;
using std::string;
using std::vector;
using std::tuple;
using std::srand;
using std::rand;
using std::time;
class MarkovModel {
private:
    int k;
// map { kgram, array [freq, map(nextChar, freq), map(nextChar, probability) ] }
// map1 {kgram, freq}
// map2 {kgram, map<char, freq>}
// map3 {kgram, vector<map(char, probability)>}
    map <string, int> frequencyTable;
    map <string, map<char, int>> nextCharTable;
    map <string, map<char, float>> nextCharProbTable;

    string fullText;
public:
    MarkovModel(string& text, int k);
    int order();
    int freq(string& kgram);
    int freq(string& kgram, char c);
    char randChar(string& kgram);
    string gen(string& kgram, int T);
    void printTable();
};


#endif //MARKOV_CHAIN_SEQUENCE_GENERATOR_MARKOVMODEL_H
