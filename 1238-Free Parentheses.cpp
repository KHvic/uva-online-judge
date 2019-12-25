#include <bits/stdc++.h>
using namespace std;

unordered_set<int> used;
vector<int> sig, num;
int N;
bool visited[31][31][6001];

// idea: treat number of open bracket with negative sign as negation -(...), as bracket doesn't matter for +(...)

// use dp to track whether if state is visited, avoid double processing
// dp state - visited[idx][open][val], position, number of remaining open bracket (also the number of negation), current evaluate value
void rec(int idx, int open, int val) {
    if (visited[idx][open][val+3000]) // the +3000 trick to convert negative indices to [200..6000]
        return;
    visited[idx][open][val+3000] = true;
    if (idx == N) // last number, current value is one of the possible
        {used.insert(val); return;}
    int nval = val;
    nval += num[idx] * sig[idx] * ((open % 2 == 0) ? 1 : -1); // negate if odd open brackets

    // option 1: put open bracket only if is negative sign (no different for positive sign, so not needed)
    if (sig[idx] == -1)
        rec(idx + 1, open + 1, nval);
    // option 2: put close bracket
    if (open > 0)
        rec(idx + 1, open - 1, nval);
    // option 3: normal, do nothing
    rec(idx + 1, open, nval);
}

int main() {
    string in, s;
    int v;
    while(getline(cin, in)) {
        used.clear();
        sig.clear(), num.clear();
        memset(visited, 0, sizeof visited);

        istringstream iss(in);
        iss >> v;
        sig.push_back(1);
        num.push_back(v);
        while(iss >> s) {
            if(s == "+") sig.push_back(1);
            else sig.push_back(-1);
            iss >> v, num.push_back(v);
        }
        N = num.size();
        rec(0, 0, 0);
        printf("%d\n", used.size());
    }
}
