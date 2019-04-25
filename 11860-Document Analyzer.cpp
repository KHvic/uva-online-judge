#include <bits/stdc++.h>
using namespace std;
// sliding window O(N)

int main() {
    int t;
    string in;
    int cases = 1;
    scanf("%d",&t);
    while(t--){
        vector<string> texts;
        unordered_map<string,int> countMap;
        while(getline(cin,in), in != "END"){
            in = regex_replace(in, regex("[^a-zA-Z]"), " ");
            istringstream iss(in);
            while(iss >> in) {
                texts.push_back(in);
                countMap[in] = 0;
            }
        }
        int numUnique = countMap.size();
        int ending = 0, start = 0;
        int shortest = INT_MAX;
        int p = 0, q = 0;
        int curUnique = 0;
        while(ending<texts.size()){
            if(++countMap[texts[ending++]] == 1) curUnique++;
            while(curUnique >= numUnique){
                if(--countMap[texts[start++]] == 0) curUnique--;
                if(ending-start < shortest){
                    shortest = ending-start;
                    q = ending; p = start;
                }
            }
        }
        cout << "Document " << cases++ << ": " << p << " " << q << endl;
    }
}
