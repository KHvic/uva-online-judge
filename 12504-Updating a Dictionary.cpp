#include <bits/stdc++.h>
using namespace std;

void printVector(vector<string>& vec){
    for(auto& str : vec){
        cout << str << (&str != &vec.back() ? "," : "\n");
    }
}

int main() {
    int t;
    string old,next;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,old);
        getline(cin,next);
        vector<string> newKeys,removeKeys,changedKeys;
        unordered_map<string,string> dict;
        old = regex_replace(old,regex("[{},]")," ");
        next = regex_replace(next,regex("[{},]")," ");
        istringstream iss(old);
        while(iss >> old){
            int delimit = old.find(":");
            string key = old.substr(0,delimit);
            string val = old.substr(delimit+1);
            dict[key] = val;
        }
        iss.str(next);
        iss.clear();
        while(iss >> next){
            int delimit = next.find(":");
            string key = next.substr(0,delimit);
            string val = next.substr(delimit+1);
            if(dict.find(key) == dict.end()) newKeys.push_back(key);
            else if(dict[key] != val) changedKeys.push_back(key);
            dict.erase(key);
        }
        for(auto& p : dict) removeKeys.push_back(p.first);
        if(newKeys.empty() && removeKeys.empty() && changedKeys.empty())
            cout << "No changes" << endl;
        else {
            sort(newKeys.begin(),newKeys.end());
            sort(removeKeys.begin(),removeKeys.end());
            sort(changedKeys.begin(),changedKeys.end());
            if(!newKeys.empty()){
                cout<<"+";
                printVector(newKeys);
            }
            if(!removeKeys.empty()){
                cout<<"-";
                printVector(removeKeys);
            }
            if(!changedKeys.empty()){
                cout<<"*";
                printVector(changedKeys);
            }
        }
        cout << endl;
    }
}
