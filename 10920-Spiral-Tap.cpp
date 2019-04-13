#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b), a){
        // compute size of square
        int root = sqrt(b);
        if(root % 2 == 0) root--;// round down even size
        // compute starting position of 1,9,25...
        // get middle square position and move top right
        int row = (a/2+1) + root/2;
        int col = row;
        int remain = b - pow(root,2);
        if(remain != 0) {
            // compute direction coordinate is in
            // north left south right
            int direction = (remain-1)/(root+1);
            remain = (remain-1) % (root+1);
            if(direction == 0){
                // north
                row += 1;
                col -= remain;
            } else if(direction == 1){
                // west
                col -= root;
                row -= remain;
            } else if(direction == 2){
                // south
                row -= root;
                col -= (root-1);
                col += remain;
            } else {
                // east
                col += 1;
                row -= (root-1);
                row += remain;
            }
        }
        printf("Line = %d, column = %d.\n",row,col);
    }
}
