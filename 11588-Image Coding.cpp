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

int main() {
    int t, v;
    int r, c, m, n;
    int k = 1;
    string in;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d %d %d %d\n",&r,&c,&m,&n);
        int best = 0;
        vector<int> cnt(26,0);
        for(int i=0;i<r;i++){
            getline(cin,in);
            for(char c : in){
                cnt[c-'A']++;
                best = max(best,cnt[c-'A']);
            }
        }
        int imptCnt = 0;
        for(int i : cnt)
            if(i == best) imptCnt += best;
        printf("Case %d: %d\n", k++, imptCnt*m+(r*c-imptCnt)*n);
    }
}
