#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,v;
    while(cin >> n, n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        while(n--){
            cin >> v;
            pq.push(v);
        }
        int res = 0;
        while(pq.size() > 1) {
            int sum = pq.top(); pq.pop();
            sum += pq.top(); pq.pop();
            res += sum;
            pq.push(sum);
        }
        cout << res << endl;
    }
}
