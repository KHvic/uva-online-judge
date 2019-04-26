#include <bits/stdc++.h>
using namespace std;

int main() {
    string in="",in2;
    set<string> distinct;
    bool concat = false;
    while(getline(cin,in2)){
        in += in2;
        if(in.back() == '-') {
            concat = true;
            in.pop_back();
        } else in += " ";
    }
    in = regex_replace(in,regex("[^a-zA-Z\-]")," ");
    transform(in.begin(),in.end(),in.begin(),::tolower);
    istringstream iss(in);
    while(iss >> in) distinct.insert(in);
    for(auto& s : distinct) cout << s << endl;
}
