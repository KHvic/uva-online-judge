#include <bits/stdc++.h>
using namespace std;
// property of KMP, N - prefixSuffixLen = minimum repeating cycle length

int kmpPreprocess(string& str){
    int i=0, j=-1;
    vector<int> backtable(str.length()+1);
    backtable[0] = -1;
    while(i<str.length()){
        // while not match, go back to previous prefix
        while(j >= 0 && str[i] != str[j]){
            j = backtable[j];
        }
        i++; j++;
        backtable[i] = j;
    }
    return j; // return prefix suffix length
}

int main()
{
    string in;
    while(getline(cin,in),in != "."){
        int prefixSuffixLen = kmpPreprocess(in);
        int minSeqSize = in.length() - prefixSuffixLen;
        if(in.length() % minSeqSize){
            printf("1\n");
        } else
            printf("%d\n",in.length()/minSeqSize);//num of repeatition
    }
}
