#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a,b,c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        bool solved = false;
        // 10000^(1/3) = 22
        for(int x = -22; x<= 22; x++) if(x*x <= c)
        for(int y = -100; y <= 100; y++)
        for(int z = - 100; z <= 100; z++){
            if(z == x || z == y || x == y) continue;
            if(x+y+z == a && x*y*z == b && x*x+y*y+z*z == c){
                solved = true;
                printf("%d %d %d\n",x,y,z);
                goto outer;
            }
        }
        outer:
            if(!solved) printf("No solution.\n");
    }
}
