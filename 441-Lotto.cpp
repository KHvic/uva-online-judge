#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int n,v;
    bool first = true;
    while(cin >> n, n){
        vector<int> in;
        if(!first) cout << endl;
        first = false;
        while(n--) {
            cin >> v;
            in.push_back(v);
        }
        for(int i=0;i<in.size()-5;i++)
        for(int j=i+1;j<in.size()-4;j++)
        for(int k=j+1;k<in.size()-3;k++)
        for(int l=k+1;l<in.size()-2;l++)
        for(int m=l+1;m<in.size()-1;m++)
        for(int n=m+1;n<in.size();n++)
        printf("%d %d %d %d %d %d\n",in[i],in[j],in[k],in[l],in[m],in[n]);
    }

}
