#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> dp;
    int res=0;
    string in;
    while (cin >> in)
    {
        int len=1;
        for(int i=0;i<=in.size();i++){
            // delete
            string edit(in);
            edit.erase(i, 1);
            if(dp.count(edit)) len=max(len, dp[edit]+1);
            for(char c ='a';c<='z';c++)
            {
                // insert
                edit = in;
                edit.insert(i,1,c);

                if(edit<in && dp.count(edit)) len=max(len, dp[edit]+1);

                // edit
                if(i<in.size()){
                    edit = in;
                    edit[i] = c;
                    if(edit<in && dp.count(edit)) len=max(len, dp[edit]+1);
                }
            }
        }

        dp[in]=len;
        res=max(res,len);
    }
    printf("%d\n",res);
}
