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

void swapRow(vector<vector<int> >& m,int i,int j){
    swap(m[i],m[j]);
}

void swapCol(vector<vector<int> >& m,int i,int j){
    for(int k=0;k<m.size();k++){
        swap(m[k][i],m[k][j]);
    }
}

void transpose(vector<vector<int> >& m){
    for(int i=0;i<m.size();i++)
        for(int j=i;j<m.size();j++)
            swap(m[i][j],m[j][i]);
}

int main(){
    int t;
    scanf("%d",&t);
    int k = 1;
    while(t--){
        int s,v;
        int a,b;
        int inc = 0;
        string command;
        scanf("%d",&s);
        vector<vector<int> > m(s,vector<int>());
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                scanf("%1d",&v);
                m[i].push_back(v);
            }
        }
        scanf("%d\n", &s);
        while(s--){
            cin >> command;
            if(command == "dec") inc--;
            else if(command == "inc") inc++;
            else if(command == "row"){
                cin >> a >> b;
                swapRow(m,a-1,b-1);
            }
            else if(command == "col"){
                cin >> a >> b;
                swapCol(m,a-1,b-1);
            }
            else {
                transpose(m);
            }
        }
        cout << "Case #" << k++ << endl;
        for(auto vec : m){
            for(auto& v : vec){
                v = (v+inc+10)%10;
                cout << v;
            }
            cout << endl;
        }
        cout << endl;
    }
}
