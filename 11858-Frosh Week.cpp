#include <bits/stdc++.h>
using namespace std;
#define ll long long

int v,n;
vector<int> vec;

ll merge_sort(int low, int high) {
    if(low >= high) return 0;
    int mid = (low+high)/2;
    ll cnt = 0;
    cnt += merge_sort(low,mid);
    cnt += merge_sort(mid+1,high);

    vector<int> tmp;
    int l=low,r=mid+1;
    while(l <= mid || r <= high) {
        // right ended or left smaller
        if(r > high || (l <= mid && vec[l] < vec[r])) {
            tmp.push_back(vec[l]);
            cnt += r-(mid+1); // this many right problem item has been smaller than vec[l]
            l++;
        } else {
            tmp.push_back(vec[r]);
            r++;
        }
    }
    // copy back
    for(int i=0;i<tmp.size();i++) {
        vec[i+low] = tmp[i];
    }
    return cnt;
}

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        vec.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&v);
            vec.push_back(v);
        }
        printf("%lld\n", merge_sort(0, n-1));
    }
}
