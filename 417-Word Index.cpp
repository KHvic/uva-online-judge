#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    unordered_map<string,int> idxMap;
    int idx = 1;
    queue<string> patterns;
    for(char c='a';c<='z';c++) patterns.push(string{c});
    while(!patterns.empty()){
        string top = patterns.front(); patterns.pop();
        idxMap[top] = idx++;
        if(top.length() == 5) continue;
        for(char c=top.back()+1;c<='z';c++) patterns.push(top + c);
    }
    string in;
    while(cin >> in){
        cout << idxMap[in] << endl;
    }
}
