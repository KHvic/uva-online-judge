#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;


int main() {
    string in;
    while(getline(cin,in), !in.empty()){
        list<string> listing;
        string cur = "";
        bool infront = false;
        for(char& c : in){
            if(c != '[' && c != ']') cur += c;
            if(c == '[' || c == ']' || &c == &in.back()){
                if(infront) listing.push_front(cur);
                else listing.push_back(cur);
                cur = "";
                infront = c == '[';
            }
        }
        for(string& str : listing) cout << str;
        cout << endl;
    }
}
