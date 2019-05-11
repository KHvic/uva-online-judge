#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> s2vec = {0},r2vec = {0},s3vec = {0},r3vec = {0},s4vec = {0},r4vec = {0};
    for(int i=1;i<=100;i++){
        // add i*i one sized cube
        // in a 3by3 square, there exist (i-1)^2 2sized square & (i-2)^2 3sized cube
        long long s2 = s2vec.back() + i*i;
        long long s3 = s3vec.back() + i*i*i;
        long long s4 = s4vec.back() + (i*i*i*i);
        // total cube/square in kth dimension is pow of arithmetic series
        // 1*(1+2+3) + 2*(1+2+3) + 3*(1+2+3)
        long long r2 = pow((i*(i+1))/2,2) - s2;
        long long r3 = pow((i*(i+1))/2,3) - s3;
        long long r4 = pow((i*(i+1))/2,4) - s4;
        s2vec.push_back(s2); s3vec.push_back(s3); s4vec.push_back(s4);
        r2vec.push_back(r2); r3vec.push_back(r3); r4vec.push_back(r4);
    }

    int n;
    while(cin >> n){
        printf("%lld %lld %lld %lld %lld %lld\n",s2vec[n],r2vec[n],s3vec[n],r3vec[n],s4vec[n],r4vec[n]);
    }
}
