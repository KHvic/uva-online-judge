#include <bits/stdc++.h>

using namespace std;

vector<int> backtable;

// build reverse string backtable
void kmpPreprocess(const string& str){
    backtable.assign(str.length()+1,0);
    backtable[0] = -1; int i=0,j=-1;
    while(i<str.length()){
        while(j>=0 && str[str.length()-1-i] != str[str.length()-1-j])
            j = backtable[j];
        i++; j++;
        backtable[i] = j;
    }
}

int kmp(const string& str){
    int i=0, j=0;
    // pattern = reverse(str)
    // haystack = str
    while(i<str.length()){
        while(j>=0 && str[i] != str[str.length()-1-j])
            j = backtable[j];
        j++; i++;
    }
    // j is the longest suffix length that matches its reverse suffix
    return j;
}

int main()
{
    string in;
    while(getline(cin,in)){
        kmpPreprocess(in);
        int suffixLen = kmp(in);
        for(int i=in.length()-suffixLen-1; i>=0; i--){
            in += in[i];
        }
        cout << in << endl;
    }
}
