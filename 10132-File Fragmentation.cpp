#include <bits/stdc++.h>
using namespace std;

// count & take highest occurence between all pair that have the correct size
int main() {
    int t;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        vector<string> parts;
        int minSize = INT_MAX, maxSize = INT_MIN;
        while(getline(cin,in), !in.empty()){
            minSize = min((int)in.length(),minSize);
            maxSize = max((int)in.length(),maxSize);
            parts.push_back(in);
        }
        unordered_map<string,int> cntMap;
        string best = "";
        for(int i=0;i<parts.size();i++)
            for(int j=i+1;j<parts.size();j++)
        if(parts[i].size() + parts[j].size() == (minSize+maxSize)){
            string combine1 = parts[i]+parts[j], combine2 = parts[j]+parts[i];
            if(++cntMap[combine1] > cntMap[best]) best = combine1;
            if(++cntMap[combine2] > cntMap[best]) best = combine2;
        }
        cout << best << endl;
        if(t) cout << endl;

    }
}
