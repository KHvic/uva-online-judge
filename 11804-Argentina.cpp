#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,tc=1;
    string in;
    int a,d;
    cin >> t;
    while(t--){
        vector<tuple<string,int,int>> ppl;
        for(int i=0;i<10;i++){
            cin >> in >> a >> d;
            ppl.push_back(make_tuple(in,a,d));
        }
        sort(ppl.begin(),ppl.end(),[](tuple<string,int,int>& a,tuple<string,int,int>& b){
             // larger attack should go towards front
             if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
             // larger defense should go towards back
             else if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
             return get<0>(a) < get<0>(b);
             });
        sort(ppl.begin(),ppl.begin()+5);
        sort(ppl.begin()+5,ppl.end());
        printf("Case %d:\n",tc++);
        for(int i=0;i<5;i++){
            if(i==0) cout << "(";
            cout << get<0>(ppl[i]);
            if(i==4) cout << ")" << endl;
            else cout << ", ";
        }
        for(int i=0;i<5;i++){
            if(i==0) cout << "(";
            cout << get<0>(ppl[i+5]);
            if(i==4) cout << ")" << endl;
            else cout << ", ";
        }
    }
}
