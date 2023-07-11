// To-Do-List CLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "list.h"
int main()
{
    List list;
    string command, argument;
    int idx;
    while (true) {
        std::cout << "to-do list:\n";
        list.print();
        std::cin >> command;
        std::getline(std::cin, argument);
        //std::cin >> argument;
        if (command.compare("add") == 0) {
            list.add(argument);
        }
        else if (command.compare("del") == 0) {
            try {
                idx = std::stoi(argument);
                
                list.deleteItem(idx);
            }
            catch(int& e){
                cout << argument << " is not a valid index";
            }
            catch (std::invalid_argument& e) {
                cout << argument << " is not a valid index";
            }
            catch (std::out_of_range& e) {
                cout << argument << " is too high!";
            }
            
        }
        std::cout << "\n";
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
