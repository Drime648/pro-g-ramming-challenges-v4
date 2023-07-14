#include <iostream>
#include "MarkovModel.h"
int main() {
    string s = "gagggagaggcgagaaa";
    MarkovModel m = MarkovModel(s, 2);
    string startingState = "ga";
    m.gen(startingState, 10);
    return 0;
}
