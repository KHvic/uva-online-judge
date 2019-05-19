#include <bits/stdc++.h>
using namespace std;

void dfs(int idx,vector<string>& cur,vector<string>& papers, int s){
    if(cur.size() == s){
        for(auto& str : cur){
            cout << str;
            if(&str == &cur.back()) cout << endl;
            else cout << ", ";
        }
        return;
    }
    for(int i=idx;i<papers.size();i++){
        cur.push_back(papers[i]);
        dfs(i+1,cur,papers,s);
        cur.pop_back();
    }
}

int main()
{
    int t;
    int l,r;
    string in,paper;
    scanf("%d\n",&t);
    while(t--){
        vector<string> papers;
        getline(cin,in);
        while(getline(cin,paper),!paper.empty()){
            papers.push_back(paper);
        }
        if(in == "*"){
            l=1;
            r=papers.size();
        } else {
            int space = in.find(" ");
            if(space == in.npos){
                l = r = stoi(in);
            } else {
                l = stoi(in.substr(0,space));
                r = stoi(in.substr(space+1));
            }
        }
        vector<string> cur;
        for(;l<=r;l++){
            printf("Size %d\n",l);
            dfs(0,cur,papers,l);
            printf("\n");
        }
        if(t) printf("\n");
    }
}
