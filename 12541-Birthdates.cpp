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
    int n, day, month, year;
    string name;
    scanf("%d\n",&n);
    vector<pair<tuple<int,int,int>, string> > people;
    while(n--){
        cin >> name >> day >> month >> year;
        people.push_back({make_tuple(year,month,day), name});
    }
    sort(people.begin(),people.end());
    cout << people.back().second << endl;
    cout << people.front().second << endl;
}
