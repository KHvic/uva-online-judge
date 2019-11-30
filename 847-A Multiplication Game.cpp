#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        bool p1Turn = true;
        for(int cur=1; cur<n; p1Turn=!p1Turn){
            if(p1Turn) cur*=9; // optimal for stan is to choose 9
            else cur*=2; // optimal for ollie is to choose 2
        }
        if(p1Turn) printf("Ollie wins.\n");
        else printf("Stan wins.\n"); // last player is stan
    }
}
