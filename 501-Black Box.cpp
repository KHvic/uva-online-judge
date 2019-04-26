#include <bits/stdc++.h>
using namespace std;
// Log(N) per operation using multiset
// alternative: use a maxHeap & minHeap
// maxHeap of size i, where top item is our result

int main() {
    int k,m,n,v;
    scanf("%d\n",&k);
    while(k--){
        cin >> m >> n;
        multiset<int> sorted;
        vector<int> items;
        while(m--){
            cin >> v;
            items.push_back(v);
        }
        auto it = items.begin();
        auto sortedIt = sorted.begin();
        while(n--){
            cin >> v;
            while(sorted.size()<v){
                sorted.insert(*it);
                // the inserted item is smaller, shift left
                // in c++ rb tree, larger/equal items are inserted to right
                if(sortedIt == sorted.end() || *sortedIt > *it) sortedIt--;
                it++;
            }
            cout << *sortedIt++ << endl;
        }
        if(k) cout<<endl;
    }
}
