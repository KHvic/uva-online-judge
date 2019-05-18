#include <bits/stdc++.h>
using namespace std;
int res;
int least;

void dfs(int cnt,vector<int>& vec){
    bool sorted = true;
    for(int i=1;i<vec.size();i++){
        if(vec[i] < vec[i-1]){
            sorted = false;
            swap(vec[i],vec[i-1]);
            dfs(cnt+1,vec);
            swap(vec[i],vec[i-1]);
        }
    }
    if(sorted){
        if(cnt && cnt == least) res++;
        else if(cnt < least){
            res = cnt > 0;
            least = cnt;
        }
    }
}

int main()
{
    int n,v;
    int tc=1;
    while(cin >> n,n){
        vector<int> vec;
        for(int i=0;i<n;i++){
            cin >> v;
            vec.push_back(v);
        }
        res = 0, least = INT_MAX;
        dfs(0,vec);
        printf("There are %d swap maps for input data set %d.\n",res,tc++);
    }
}
