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
#include <bitset>
using namespace std;

int main() {
    int v;
    while(scanf("%d",&v),v){
        int cnt = 0;
        int a = 0, b = 0;
        for(int i=0;i<32;i++)
            if((v >> i) & 1){
                if(++cnt%2) a |= 1<<i;
                else b |= 1<<i;
            }
        cout << a << " " << b << endl;
    }
}
