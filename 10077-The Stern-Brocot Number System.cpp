#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    pair<int,int> left,right,mid;
    while(scanf("%d %d",&a,&b),!(a==1 && b==1)){
        string res = "";
        left = {0,1}, right = {1,0}, mid = {1,1};
        while(mid.first != a || mid.second != b){
            // avoid floating point calc
            int v1 = a*mid.second, v2 = b*mid.first;
            if(v1<v2){ // go left
                right = mid;
                mid = {left.first+mid.first, left.second+mid.second};
                res += 'L';
            } else { // go right
                left = mid;
                mid = {mid.first+right.first, mid.second+right.second};
                res += 'R';
            }
        }
        cout << res << endl;
    }
}
