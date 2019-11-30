#include <bits/stdc++.h>

using namespace std;

// nim game summary: xor of all piles
// if xor is 0, first player can win, because it is a balanced game
// whenever it is balanced, the player can win
int main()
{
    int tc,n,m,r,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d %d %d",&m,&n,&r,&c);
        // nim game of four piles
        // left, right, top, btm of bad piece
        int numAbove = r;
        int numBelow = m-1-r;
        int numLeft = c;
        int numRight = n-1-c;
        int nimGame = numAbove ^ numBelow ^ numLeft ^ numRight;
        if(nimGame == 0) {
            printf("Hansel\n"); // hansel start first, so he can win if balanced
        } else {
            printf("Gretel\n");
        }
    }
}
