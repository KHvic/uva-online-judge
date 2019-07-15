
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    getline(cin,in);
    string res = "";
    while(getline(cin,in), in != "___________"){
        in.erase(remove(in.begin(),in.end(),'|'),in.end());
        in.erase(remove(in.begin(),in.end(),'.'),in.end());
        int ascii = 0;
        for(int i=0;i<in.length();i++)
            if(in[i] == 'o')
                ascii |= (1<<(7-i));
        res += (char)(ascii);
    }
    cout << res;
}
