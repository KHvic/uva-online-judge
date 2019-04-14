#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

int main(){
    unordered_set<string> ban;
    string in;
    vector<pair<string, string> > items;
    while(cin >> in, in != "::"){
        ban.insert(in);
    }
    cin.ignore();
    while(getline(cin,in)){
        transform(in.begin(), in.end(), in.begin(), ::tolower);
        istringstream iss(in);
        string word;
        string cur = "";
        while(iss >> word){
            if(!cur.empty()) cur += " ";
            if(!ban.count(word)){
                string upper = word;
                transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
                string newTitle = iss.str();
                newTitle.replace(cur.size(),upper.length(),upper);
                items.push_back({word,newTitle});
            }
            cur += word;
        }
    }
    stable_sort(items.begin(),items.end(),[](pair<string,string> a , pair<string,string> b){
                return a.first < b.first;
                });
    for(auto it=items.begin();it!=items.end();it++)
        cout<<it->second<<endl;
}
