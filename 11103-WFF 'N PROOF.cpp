#include <bits/stdc++.h>
using namespace std;

int main() {
    string in;
    while(getline(cin,in),in!= "0"){
        string lower = "";
        string upper = "";
        int n = 0;
        for(auto& c : in){
            if(c == 'N') n++;
            else if(isupper(c)) upper += c;
            else lower += c;
        }
        if(lower.empty()) printf("no WFF possible\n");
        else {
            while(n--) printf("N");
            for(int i=1,j=0;i<lower.length() && j<upper.length(); i++,j++)
                printf("%c%c",lower[i],upper[j]);
            printf("%c\n",lower[0]);
        }
    }
}
