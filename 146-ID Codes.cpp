#include <iostream>
#include <fstream>
#include <sstream>
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

int main(){
    string in;
    while(cin >> in, in != "#"){
        cout << (next_permutation(in.begin(),in.end()) ? in : "No Successor" )<< endl;
    }
}
