#include <iostream>
#include <string>
#include <stdio.h>
#include <curl/curl.h>
using std::string;
using std::cin;
using std::cout;
int main() {
    cout << "this is a download manager\n" <<
    "please input a URL to download\n";

    string url;
    cin >> url;
    cout << "your url is: " << url;

    //step 1: make sure URL is valid
    //Make a simple HTTP GET request and make sure the response code is 200




    return 0;
}
