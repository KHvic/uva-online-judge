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
#include <deque>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    while(cin >> n, n){
        list<int> deck;
        for(int i=n;i>0;i--) deck.push_back(i);
        cout << "Discarded cards:";
        while(deck.size() > 1){
            cout << " " << deck.back();
            deck.pop_back();
            if(deck.size() > 1) cout << ",";
            deck.push_front(deck.back()); deck.pop_back();
        }
        cout << endl << "Remaining card: " << deck.front() << endl;
    }
}
