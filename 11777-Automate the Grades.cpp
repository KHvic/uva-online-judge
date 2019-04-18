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

int main() {
    int t;
    int cases = 1;
    cin >> t;
    int t1,t2,f,a,c1,c2,c3;
    while(t--){
        cin >> t1 >> t2 >> f >> a >> c1 >> c2 >> c3;
        vector<int> classScore = {c1,c2,c3};
        sort(classScore.begin(),classScore.end());
        int total = t1+t2+f+a+(classScore[1] + classScore[2])/2;
        char grade;
        if(total>=90) grade = 'A';
        else if(total>=80) grade = 'B';
        else if(total>=70) grade = 'C';
        else if(total>=60) grade = 'D';
        else grade = 'F';
        printf("Case %d: %c\n",cases++,grade);
    }
}
