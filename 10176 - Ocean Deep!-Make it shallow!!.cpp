#include <bits/stdc++.h>

using namespace std;

// modulo works for binary conversion if we only need partial result
int main()
{
    char c;
    long long res = 0;
    while(scanf("%c",&c) != EOF) {
        if(c == '1' || c == '0') {
            res <<= 1;
            if(c == '1') res += 1;
            res %= 131071;
        } else if (c == '#') {
            cout << (res == 0 ? "YES" : "NO") << endl;
            res = 0;
        }
    }
}
