#include <bits/stdc++.h>
using namespace std;

int tc,d,ok;
string in;
vector<int> factorial;
vector<int> digits;
vector<int> cnt_digit;
int memo[1<<10][10001];

int solve(int bitmask, int mod){
    if(bitmask == ok) return mod==0;
    if(memo[bitmask][mod] != -1) return memo[bitmask][mod];

    int res = 0;
    for(int i=0;i<digits.size();i++)
        if((bitmask &(1<<i))==0)
            res += solve(bitmask | (1<<i), (mod*10+digits[i])%d);
    return memo[bitmask][mod] = res;
}

int main() {
    factorial.push_back(1);
    while(factorial.size()!=10)
        factorial.push_back(factorial.size()*factorial.back());

    scanf("%d",&tc);
    while(tc--){
        cnt_digit.assign(10,0);
        digits.clear();
        memset(memo, -1, sizeof memo);
        cin >> in;
        scanf("%d",&d);
        for(char c : in) {
            int v = c-'0';
            digits.push_back(v);
            cnt_digit[v]++;
        }
        ok = (1<<digits.size())-1;
        int total_cnt = solve(0,0);
        for(int i=0;i<10;i++) total_cnt /= factorial[cnt_digit[i]];
        printf("%d\n",total_cnt);
    }
}
