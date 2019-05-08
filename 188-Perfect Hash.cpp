#include <bits/stdc++.h>
using namespace std;

int indexStr(string& s){
    int v = 0;
    for(char c : s)
        v = (v<<5) + (c-'a'+1);
    return v;
}

int main() {
    string str,in;
    while(getline(cin,str)){
        vector<int> indexes;
        istringstream iss(str);
        while(iss >> in) indexes.push_back(indexStr(in));

        int C = 0, n = indexes.size();
        bool valid = false;
        while(!valid){
            valid = true;
            for(int i=0;i<n && valid;i++){
                for(int j=i+1;j<n && valid;j++){
                    int hashI = C/indexes[i], hashJ = C/indexes[j];
                    if(hashI%n == hashJ%n){
                        valid = false;
                        C = min((hashI+1)*indexes[i],(hashJ+1)*indexes[j]);
                    }
                }
            }
        }
        cout << str << endl;
        cout << C << endl << endl;
    }
}
