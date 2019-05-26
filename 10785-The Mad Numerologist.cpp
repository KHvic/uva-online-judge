#include <bits/stdc++.h>
using namespace std;

const string vowels = "AUEOI";
const string consonants = "JSBKTCLDMVNWFXGPYHQZR";

int main() {
    int t,n,tc=1;
    cin >> t;
    while(t--){
        cin >> n;
        string selectedVowels = "";
        string selectedConsonants = "";
        for(int i=0;i<n;i++){
            if(i%2)
                selectedConsonants += consonants[selectedConsonants.size()/5];
            else
                selectedVowels += vowels[selectedVowels.size()/21];
        }
        sort(selectedConsonants.begin(),selectedConsonants.end());
        sort(selectedVowels.begin(),selectedVowels.end());
        printf("Case %d: ",tc++);
        for(int i=0,j=0;i+j<n;){
            if((i+j)%2) printf("%c",selectedConsonants[j++]);
            else printf("%c",selectedVowels[i++]);
        }
        printf("\n");
    }
}
