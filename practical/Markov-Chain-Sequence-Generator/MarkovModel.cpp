//
// Created by Dhruv Kandula on 7/14/23.
//

#include "MarkovModel.h"

MarkovModel::MarkovModel(string& text, int k) {
    this->k = k;
    int j{0};
    string kgram;
    char nextChar;
    for (int i = 0; i < k; ++i) {
        fullText.append(text);
    }

    while (j < fullText.size()) {
        kgram = fullText.substr(j, k);
        if (j + k >= fullText.size()) {
            //it is last substring
            nextChar = fullText.at(0);
        } else {
            nextChar = fullText.at(j + k);
        }
        //update frequency table
        ++frequencyTable[kgram];
        //now update the nextCharTable
        ++nextCharTable[kgram][nextChar];

        j += k;
    }
    //calculate all values for nextCharProbTable
    auto it = frequencyTable.begin();
    float denominator = 1;
    float numerator;
    while (it != frequencyTable.end())
    {
        kgram = it->first;
        denominator = it->second;
        auto it2 = nextCharTable[kgram].begin();
        while(it2 != nextCharTable[kgram].end()){
            nextChar = it2->first;
            numerator = it2->second;
            nextCharProbTable[kgram][nextChar] = numerator / denominator;


            it2++;
        }

//        cout << '\n';
        ++it;
    }
}


//
void MarkovModel::printTable() {
    auto it = frequencyTable.begin();
    while (it != frequencyTable.end())
    {
        std::cout << "Kgram: " << it->first << ", freq: " << it->second;
        cout << '\t';
        auto it2 = nextCharTable[it->first].begin();
        auto it3 = nextCharProbTable[it->first].begin();
        while(it2 != nextCharTable[it->first].end()){
            std::cout << "char: " << it2->first << ", freq: " << it2->second  << ", prob: " << it3->second << '\t';

            it3++;
            it2++;
        }

        cout << '\n';
        ++it;
    }
}
//
int MarkovModel::order() {
    return this->k;
}
//
int MarkovModel::freq(string&kgram) {
    if(kgram.size() != k){
        throw(std::invalid_argument("Invalid kgram"));
    }
    return frequencyTable[kgram];
}
//
int MarkovModel::freq(string& kgram, char c) {
    if(kgram.size() != k){
        throw(std::invalid_argument("Invalid kgram"));
    }

    return nextCharTable[kgram][c];
}
//
char MarkovModel::randChar(string& kgram) {
    if(kgram.size() != k){
        throw(std::invalid_argument("Invalid kgram"));
    }
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    float r  = dis(gen);
    map<char, float> table = nextCharProbTable[kgram];
    auto iter = table.begin();
    while(iter != table.end()){
        if(r <= iter -> second){
            return iter -> first;
        }
        r -= iter -> second;


        iter++;
    }
    return nextCharProbTable[kgram].begin() -> first;
}

string MarkovModel::gen(string& kgram, int T) {
    string generated;
    string state = kgram;
    char c;
    for(int i {0}; i < T; ++i){
        cout << state << ", " << generated << '\n';

        c = randChar(state);
        generated += c;
        state += c;
        state = state.substr(1, k);
    }



    return generated;
}
