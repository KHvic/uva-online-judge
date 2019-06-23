#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string in,a,b;
    cin >> t;
    cin.ignore();
    while(t--){
        unordered_set<string> dict;
        while(getline(cin,in),in!="*"){
            dict.insert(in);
            cout << in ;
        }
        while(getline(cin,in),!in.empty()){
            istringstream iss(in);
            iss >> a >> b;
            int steps = 0;
            queue<string> bfs;
            bfs.push(a);
            bool found = false;
            while(!bfs.empty() && !found){
                int len = bfs.size();
                for(int k=0;k<len;k++){
                    string cur = bfs.front(); bfs.pop();
                    if(cur == b){
                        found = true;
                        break;
                    }
                    for(int i=0;i<cur.length();i++){
                        string next = cur;
                        for(char c='a';c<='z';c++){
                            next[i] = c;
                            if(c != cur[i] && dict.count(next))
                                bfs.push(next);
                        }
                    }
                }
                if(!found) steps++;
            }
            cout << a << " " << b << " " << steps << endl;
        }
        if(t) cout << endl;
    }
}
