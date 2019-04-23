#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int t;
    string in;
    scanf("%d\n\n",&t);
    while(t--){
        int total = 0;
        map<string,int> cntMap;
        while(getline(cin,in), !in.empty()){
            total++;
            cntMap[in]++;
        }
        for(auto& p : cntMap)
            cout << p.first << " " << setprecision(4) << fixed << p.second*100.0/total << endl;
        if(t) cout << endl;
    }
}
