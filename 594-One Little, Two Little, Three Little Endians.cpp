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
    int v;
    while(scanf("%d",&v) == 1){
        int res = 0, init = v;
        for(int i=0;i<4;i++, v>>=8){
            res <<= 8;
            res |= (v) & 0xFF;
        }
        printf("%d converts to %d\n",init,res);
    }
}
