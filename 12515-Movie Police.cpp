#include <bits/stdc++.h>

using namespace std;

int computeSimilarity(string& a, string& b){
    int best = 0;
    for(int i=0;i+b.size() <= a.size();i++){
        int match = 0;
        for(int j=0;j<b.size();j++){
            if(a[i+j] == b[j]) match++;
        }
        best = max(match,best);
    }
    return best;
}

int main()
{
    int m,q;
    string in;
    vector<string> movies;
    scanf("%d %d\n",&m,&q);
    while(m--){
        cin >> in;
        movies.push_back(in);
    }
    for(int i=0;i<q;i++){
        cin >> in;
        int best = 0;
        int idx = 1;
        for(int j=0;j<movies.size();j++){
            int sim = computeSimilarity(movies[j],in);
            if(sim > best){
                best = sim;
                idx = j+1;
            }
        }
        cout << idx << endl;
    }
}
