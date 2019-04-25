#include <bits/stdc++.h>
using namespace std;

int udfsFind(int* udfs, int n){
    return udfs[n] == n ? n : udfs[n] = udfsFind(udfs,udfs[n]);
}

void udfsJoin(int* udfs, int a, int b) {
    int par_a = udfsFind(udfs,a), par_b = udfsFind(udfs,b);
    udfs[par_a] = par_b;
}

int main() {
    int t,n,a,b;
    char c;
    string in;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d\n",&n);
        int success = 0, fail = 0;
        int udfs[n+1];
        for(int i=1;i<=n;i++) udfs[i]=i;
        while(getline(cin,in),!in.empty()){
            istringstream iss(in);
            iss >> c >> a >> b;
            if(c == 'c') udfsJoin(udfs,a,b);
            else if(udfsFind(udfs,a) == udfsFind(udfs,b))
                success++;
            else
                fail++;
        }
        printf("%d,%d\n",success,fail);
        if(t) cout << endl;
    }
}
