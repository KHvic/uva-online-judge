#include <bits/stdc++.h>
using namespace std;

vector<string> nums = {
"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY",
"YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY"
};

bool solve(int idx,int remain,vector<string>& countdown,vector<bool>& damaged){
    if(remain == 0) return true;
    string& cur = countdown[countdown.size() - remain];
    string& ori = nums[idx];
    for(int i=0;i<7;i++){
        if(damaged[i] && cur[i] == 'Y') return false;
        else if(ori[i] == 'N' && cur[i] == 'Y') return false;
        else if(ori[i] == 'Y' && cur[i] == 'N') damaged[i] = true;
    }
    return solve(idx-1,remain-1,countdown,damaged);
}

int main()
{
    int t;
    string in;
    while(cin>>t,t){
        vector<string> countdown;
        for(int i=0;i<t;i++){
            cin>>in;
            countdown.push_back(in);
        }
        bool solved = false;
        for(int i=9;i-t+1>=0 && !solved;i--){
            vector<bool> damaged(7,false);
            solved = solve(i,t,countdown,damaged);
        }
        cout << (solved ? "MATCH" : "MISMATCH") << endl;
    }
}
