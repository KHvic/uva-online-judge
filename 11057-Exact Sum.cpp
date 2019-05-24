#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,v,t;
    while(cin >> n){
        vector<int> books;
        for(int i=0;i<n;i++){
            cin >> v;
            books.push_back(v);
        }
        cin >> t;
        
        sort(books.begin(),books.end());
        pair<int,int> res;
        auto lo=books.begin(), hi=prev(books.end());
        while(lo<hi){
            int sum = *lo+*hi;
            if(sum == t){
                res = {*lo,*hi};
                lo++; hi--;
            } else if(sum > t){
                hi--;
            } else {
                lo++;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",res.first,res.second);
    }
}
