#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int v,p,s,e;
    int tc=1;
    while(scanf("%d %d",&n,&m),n||m){
        vector<int> messageSize;
        vector<int> ordering;
        for(int i=0;i<n;i++){
            cin >> v;
            messageSize.push_back(v);
            ordering.push_back(i+1);
        }
        vector<tuple<int,int,int>> packets;
        for(int i=0;i<m;i++){
            cin >> p >> s >> e;
            packets.push_back(make_tuple(s,e,p));
        }
        int best = INT_MAX;
        do{
            vector<set<tuple<int,int,int>>> buffers(n);
            int maxBufferSize = 0;
            int curBufferSize = 0;
            int nextByteIdx = 1;
            int curMessageIdx = 0;
            for(int i=0;i<m;i++){
                curBufferSize += (get<1>(packets[i]) - get<0>(packets[i]) + 1);
                buffers[get<2>(packets[i])-1].insert(packets[i]);
                while(curMessageIdx < n &&
                      // has packet in buffer and that packet can pass
                      !buffers[ordering[curMessageIdx]-1].empty() && get<0>(*buffers[ordering[curMessageIdx]-1].begin()) == nextByteIdx){
                    auto it = buffers[ordering[curMessageIdx]-1].begin();
                    curBufferSize -= (get<1>(*it) - get<0>(*it) + 1);
                    nextByteIdx = get<1>(*it) + 1;
                    buffers[ordering[curMessageIdx]-1].erase(it);
                    // ready for next message
                    if(nextByteIdx >= messageSize[ordering[curMessageIdx]-1]){
                        curMessageIdx++;
                        nextByteIdx = 1;
                    }
                }
                maxBufferSize = max(maxBufferSize, curBufferSize);
            }
            best = min(best, maxBufferSize);
        } while(next_permutation(ordering.begin(),ordering.end()));
        printf("Case %d: %d\n\n",tc++,best);
    }
}
