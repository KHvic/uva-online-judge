#include <bits/stdc++.h>
using namespace std;

bool isValid(long long n){
    bool taken[10] = {false};
    while(n){
        int cur = n%10;
        if(taken[cur]) return false;
        taken[cur] = true;
        n /= 10;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    long long n;
    while(t--){
        cin >> n;
        for(long long i=1;i*n<=9876543210;i++){
            long long j = i*n;
            if(isValid(j) && isValid(i))
                printf("%lld / %lld = %lld\n",j,i,n);
        }
        if(t)cout << endl;
    }
}
