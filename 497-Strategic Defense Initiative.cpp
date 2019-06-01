#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        vector<int> nums;
        vector<int> dp;
        vector<int> prev;
        int bestIdx = 0;
        int best = 0;
        while(getline(cin,in),in != ""){
            int cur = stoi(in);
            int parent = -1, longest = 0;
            for(int i=0;i<nums.size();i++){
                if(cur > nums[i] && dp[i]>longest){
                    parent = i;
                    longest = dp[i];
                }
            }
            if(++longest > best){
                bestIdx = nums.size();
                best = longest;
            }
            nums.push_back(cur);
            dp.push_back(longest);
            prev.push_back(parent);
        }
        stack<int> res;
        while(bestIdx!=-1){
            res.push(nums[bestIdx]);
            bestIdx = prev[bestIdx];
        }
        printf("Max hits: %d\n",best);
        while(!res.empty())
            printf("%d\n",res.top()), res.pop();
        if(t) printf("\n");
    }
}
