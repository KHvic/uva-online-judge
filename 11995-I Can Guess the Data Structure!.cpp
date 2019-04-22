#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n, a, b;
    while(scanf("%d",&n) != EOF){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isS = true, isQ = true, isPQ = true;
        while(n--){
            cin >> a >> b;
            if(a == 1){
                s.push(b);
                q.push(b);
                pq.push(b);
            } else {
                if(s.empty()) {
                    isS = isQ = isPQ = false;
                    continue;
                }
                if(isS) {
                    isS = s.top() == b;
                    s.pop();
                }
                if(isQ) {
                    isQ = q.front() == b;
                    q.pop();
                }
                if(isPQ) {
                    isPQ = pq.top() == b;
                    pq.pop();
                }
            }
        }
        if(!isS && !isQ && !isPQ) cout << "impossible";
        else if(isS && !isQ && !isPQ) cout << "stack";
        else if(!isS && isQ && !isPQ) cout << "queue";
        else if(!isS && !isQ && isPQ) cout << "priority queue";
        else cout << "not sure";
        cout << endl;
    }
}
