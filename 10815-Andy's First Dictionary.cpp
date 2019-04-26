#include <bits/stdc++.h>
using namespace std;

int main() {
    string in;
    set<string> distinct;
    while(getline(cin,in)){
        in = regex_replace(in,regex("[^a-zA-Z]")," ");
        transform(in.begin(),in.end(),in.begin(),::tolower);
        istringstream iss(in);
        while(iss >> in) distinct.insert(in);
    }
    for(auto& s : distinct) cout << s << endl;
}
