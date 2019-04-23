#include <iostream>
#include <sstream>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main()
{
    int a,b;
    string in;
    int v;
    scanf("%d %d",&a,&b);
    unordered_map<string,int> cost;
    while(a--){
        cin >> in >> v;
        cost[in] = v;
    }
    while(b--){
        int total = 0;
        while(cin >> in , in != "."){
            total += cost[in];
        }
        cout << total << endl;
    }
}
