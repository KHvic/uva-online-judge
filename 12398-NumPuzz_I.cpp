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

void untap(vector<vector<int> >& m, int r, int c){
    m[r][c] = (m[r][c]+1)%10;
    if(r!=0) m[r-1][c] = (m[r-1][c]+1)%10;
    if(c!=0) m[r][c-1] = (m[r][c-1]+1)%10;
    if(r!=2) m[r+1][c] = (m[r+1][c]+1)%10;
    if(c!=2) m[r][c+1] = (m[r][c+1]+1)%10;
}

int main()
{
    string in;
    int i=1;
    while(getline(cin,in)){
        vector<vector<int> > m(3,vector<int>(3,0));
        for(auto it=in.rbegin(); it!=in.rend();it++){
            int v = *it-'a';
            int r = v/3;
            int c = v%3;
            untap(m,r,c);
        }
        cout << "Case #" << i++ << ":" << endl;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cout << m[i][j] << (j==2 ? "\n" : " ");
    }
}
