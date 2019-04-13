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
    int a,b;
    int v,s,d;
    while(scanf("%d %d",&a,&b),a){
        vector<vector<int> > pilot(b,vector<int>());
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cin >> v;
                pilot[j].push_back(v-1);
            }
        }
        cin >> s;
        while(s--){
            int highest = 0;
            vector<int> winner;
            int k;
            cin >> k;
            int score[k] = {};
            for(int i=0;i<k;i++){
                cin >> d;
                score[i] = d;
            }
            for(auto& p : pilot){
                int sum = 0;
                for(auto& v : p){
                    sum += (v<k ? score[v] : 0);
                }
                if(sum>highest){
                    winner.clear();
                    winner.push_back(&p-&pilot[0]+1);
                    highest = sum;
                }
                else if(sum == highest){
                    winner.push_back(&p-&pilot[0]+1);
                }
            }
            sort(winner.begin(),winner.end());
            for(auto& v : winner){
                cout << v << (&v == &winner.back() ? "\n" : " ");
            }
        }
    }
}
