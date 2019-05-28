#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,len,n,v;
    cin >> t;
    while(t--){
        cin >> len >> n;
        int least = 0, most = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            int more = max(len-v,v);
            int less = min(len-v,v);
            least = max(less,least);
            most = max(more,most);
        }
        printf("%d %d\n",least,most);
    }
}
