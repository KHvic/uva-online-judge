#include <bits/stdc++.h>
using namespace std;

int main() {
    string in;
    while(getline(cin,in), in != "#"){
        // count schemes
        unordered_map<string,int> cntMap;
        vector<string> scheme;
        int res = 0;
        int best = INT_MAX;
        do{
            scheme.push_back(in);
            istringstream iss(in);
            while(getline(iss,in,',')) cntMap[in]++;
        }while(getline(cin,in), in[0] != 'e');

        for(int i=0;i<scheme.size();i++){
            istringstream iss(scheme[i]);
            int cost = 0;
            // add number of schemes differing from this allocation
            while(getline(iss,in,',')) cost += scheme.size() - cntMap[in];
            if(cost < best){
                res = i;
                best = cost;
            }
        }
        printf("%d\n",res+1);
    }
}
