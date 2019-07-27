#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    while(getline(cin,in),in!="*"){
        vector<vector<int>> dp(in.length(),vector<int>(in.length(),1e6));
        for(int i=0;i<in.length();i++)
            for(int j=i;j<in.length();j++)
                dp[i][j] = j-i+1;

        for(int len=1;len<in.size();len++){
            for(int start=0;start+len<in.size();start++){
                int high=start+len;
                int full_len = high-start+1;
                for(int mid=start;mid<high;mid++)
                    dp[start][high] = min(dp[start][high],dp[start][mid]+dp[mid+1][high]);

                for(int sub_len=1;sub_len<=full_len/2;sub_len++){
                    if(full_len%sub_len == 0){
                        // check if start to high have a cycle repetition of sub_len
                        // that is (sub_str)^k
                        string pattern = in.substr(start,sub_len);
                        bool match = true;
                        for(int j=start+sub_len;j<=high && match;j+=sub_len){
                            string haystack = in.substr(j,sub_len);
                            if(pattern != haystack) match = false;
                        }
                        if(match){
                            dp[start][high] = min(dp[start][high],dp[start][start+sub_len-1]); // count only first cycle
                        }
                    }
                }
            }
        }
        cout << dp[0][in.length()-1] << endl;
    }
}
