#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,v;
    while(cin >> n, n){
        bool notEmpty = false;
        for(int i=0;i<n;i++){
            cin >> v;
            if(v){
                if(notEmpty) printf(" ");
                notEmpty = true;
                printf("%d",v);
            }
        }
        if(!notEmpty) printf("0");
        printf("\n");
    }
}
