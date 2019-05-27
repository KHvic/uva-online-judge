#include <bits/stdc++.h>
using namespace std;

int main() {
    int b,s,v,tc=1;
    while(scanf("%d %d",&b,&s),b||s){
        int youngestBachelor = INT_MAX;
        for(int i=0;i<b;i++)
            cin >> v, youngestBachelor = min(youngestBachelor,v);
        for(int i=0;i<s;i++) cin >> v;
        printf("Case %d: ",tc++);
        if(b<=s) printf("0\n");
        else printf("%d %d\n",b-s,youngestBachelor);
    }
}
