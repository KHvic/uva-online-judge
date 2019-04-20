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
    int t, a, k;
    scanf("%d",&t);
    while(t--){
        cin >> a >> k;
        // conversion from binary to gray code is simply k^(k>>1)
        cout << (k^(k>>1)) << endl;
    }
}
// additional
// convert gray code back to binary position
//    num = num ^ (num >> 16);
//    num = num ^ (num >> 8);
//    num = num ^ (num >> 4);
//    num = num ^ (num >> 2);
//    num = num ^ (num >> 1);
