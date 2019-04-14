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
    int n;
    while(cin >> n){
        string str[n];
        int maxLen = 0;
        for(int i=0;i<n;i++) {
            cin >> str[i];
            maxLen = max(maxLen, (int)str[i].length());
        }
        maxLen += 2;
        if(maxLen > 60) maxLen = 60;
        sort(str,str+n);
        int numItemPerRow = 62/maxLen;
        int numRows = (n-1)/numItemPerRow+1;
        cout << "------------------------------------------------------------" << endl;
        for(int i=0;i<numRows; i++){
            for(int j=i;j<n;j+= numRows){
                cout << str[j];
                // not last item in row
                if(j+numRows < n){
                    for(int k=str[j].length();k<maxLen;k++) cout << " ";
                }
            }
            cout << endl;
        }
    }
}
