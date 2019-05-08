#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n,v;
    
    while(scanf("%d:",&n), n){
        vector<int> prev;
        unordered_map<int,int> idxMap;
        for(int i=0;i<n;i++){
            cin >> v;
            prev.push_back(v);
            idxMap[v] = i;
        }
        bool hasProgression = false;
        for(int i=0;i<n && !hasProgression;i++)
        for(int j=i+1;j<n && !hasProgression;j++){
            int diff = prev[j] - prev[i];
            int nextInt = prev[j] + diff;
            if(nextInt > 9 || !idxMap.count(nextInt)) continue;
            if(idxMap[nextInt]>j) hasProgression = true;
        }
        cout << (hasProgression ? "no" : "yes") << endl;
    }
}
