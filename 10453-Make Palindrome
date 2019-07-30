#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    while(getline(cin,in)){
        vector<vector<int>> dp(in.length(),vector<int>(in.length(),1e6));
        vector<vector<int>> decision(in.length(),vector<int>(in.length()));
        for(int len=0;len<in.length();len++){
            for(int left=0;left+len<in.length();left++){
                int right = left+len;
                if(in[left] == in[right]){
                    dp[left][right] = left+1>=right-1 ? 0 : dp[left+1][right-1];
                } else {
                    int leftCost = dp[left][right-1]; // insert on left
                    int rightCost = dp[left+1][right]; // insert on right
                    if(leftCost > rightCost) {
                        dp[left][right] = rightCost+1;
                        decision[left][right] = 1;
                    } else {
                        dp[left][right] = leftCost+1;
                        decision[left][right] = 2;
                    }
                }
            }
        }
        int left=0,right=in.length()-1;
        string leftStr="",rightStr="";
        while(left<=right){
            if(in[left] == in[right]){
                if(left==right) leftStr += in[left];
                else {
                    leftStr += in[left];
                    rightStr += in[left];
                }
                left++; right--;
            } else if(decision[left][right] == 1){
                // insert left character on right
                rightStr += in[left];
                leftStr += in[left];
                left++;
            } else if(decision[left][right] == 2){
                // insert right character on left
                leftStr += in[right];
                rightStr += in[right];
                right--;
            }
        }
        reverse(rightStr.begin(),rightStr.end());
        cout << dp[0][in.length()-1] << " " << leftStr << rightStr << endl;
    }
}
