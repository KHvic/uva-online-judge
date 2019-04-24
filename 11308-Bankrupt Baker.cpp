#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,v;
    int m,n,b;
    string title,recipe;
    string word;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,title);
        unordered_map<string,int> ingredients;
        set<pair<int,string>> recipes;
        cin >> m >> n >> b;
        while(m--){
            cin >> word >> v;
            ingredients[word] = v;
        }
        while(n--) {
            cin.ignore();
            int total = 0;
            getline(cin,recipe);
            cin >> m;
            while(m--){
                cin >> word >> v;
                total += ingredients[word]*v;
            }
            recipes.insert({total,recipe});
        }
        bool tooExpensive = true;
        transform(title.begin(),title.end(),title.begin(),::toupper);
        cout << title << endl;
        for(auto& p : recipes){
            if(p.first <= b) {
                cout << p.second << endl;
                tooExpensive = false;
            }
        }
        cin.ignore();
        if(tooExpensive) cout << "Too expensive!" << endl;
        cout << endl;
    }
}
