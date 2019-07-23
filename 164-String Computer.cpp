#import <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    while(cin >> a,a!="#"){
        cin >> b;
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1));
        for(int i=0;i<=b.length();i++) dp[0][i] = i;
        for(int i=0;i<a.length();i++){
            dp[i+1][0] = i+1;
            for(int j=0;j<b.length();j++){
                if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j];
                else dp[i+1][j+1] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
            }
        }
        stack<tuple<char,int,int>> ops;
        int i=a.length(), j=b.length();
        while(i!=0 || j!=0){
            if(i!=0 && dp[i-1][j]+1 == dp[i][j]) {
                ops.push(make_tuple('D',i,j));
                i--;
            } else if(j!=0 && dp[i][j-1]+1 == dp[i][j]){
                ops.push(make_tuple('I',i,j));
                j--;
            } else if(a[i-1] == b[j-1]) {
                i--; j--;
            } else {
                ops.push(make_tuple('C',i,j));
                i--; j--;
            }
        }
        string commands = "";
        int offset = 0;
        while(!ops.empty()){
            char c;
            tie(c,i,j) = ops.top(); ops.pop();
            commands += c;
            if(c=='I') offset++;
            int pos = i+offset;
            if(c=='C'){
                commands += b[j-1];
            } else if(c=='I'){
                commands += b[j-1];
            } else if(c=='D'){
                commands += a[i-1];
                offset--;
            }
            if(pos<10) commands += '0';
            commands += to_string(pos);
        }
        commands += 'E';
        cout << commands << endl;
    }
}
