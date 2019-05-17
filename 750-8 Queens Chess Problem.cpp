#include <bits/stdc++.h>

using namespace std;

int sol=0;
void backtrack(vector<int>& res,vector<bool>& rows,
    vector<bool>& diag1, vector<bool>& diag2,int c,int skip){
    if(c == 8) {
        sol++;
        if(sol < 10) printf(" %d     ",sol);
        else printf("%d     ",sol);
        for(auto& i : res) printf(" %d",i);
        cout << endl;
        return;
    }
    if(c == skip){
        backtrack(res,rows,diag1,diag2,c+1,skip);
        return;
    }
    for(int i=0;i<8;i++){
        if(rows[i] || diag1[i-c+7] || diag2[c+i]) continue;
        rows[i] = diag1[i-c+7] = diag2[c+i] = true;
        res[c] = i+1;
        backtrack(res,rows,diag1,diag2,c+1,skip);
        rows[i] = diag1[i-c+7] = diag2[c+i] = false;
    }
}

int main()
{
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        sol = 0;
        vector<int> res(8);
        vector<bool> rows(8);
        vector<bool> diag1(8);
        vector<bool> diag2(16);
        res[b-1] = a;
        rows[a-1] = diag1[a-b+7] = diag2[a+b-2] = true;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        backtrack(res,rows,diag1,diag2,0,b-1);
        if(t) cout << endl;
    }
}
