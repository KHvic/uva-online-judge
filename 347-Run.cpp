#include <unordered_set>

using namespace std;
int res[10000000] = {};

bool isValid(int n){
    bool taken[10] = {};
    string str = to_string(n);
    int idx = 0;
    int size = str.length();
    unordered_set<int> reachedIdx;
    while(reachedIdx.size() != size){
        int moves = str[idx] - '0';
        idx = (idx+moves) % size;
        if(reachedIdx.count(idx) || taken[moves]) return false;
        reachedIdx.insert(idx);
        taken[moves] = true;
    }
    return idx == 0;
}

int main()
{
    int cases = 1;
    int n;
    for(int i=9999998;i>=0;i--) res[i] = isValid(i) ? i : res[i+1];
    while(scanf("%d",&n),n) printf("Case %d: %d\n",cases++,res[n]);
}
