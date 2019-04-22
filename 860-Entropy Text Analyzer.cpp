#include <bits/stdc++.h>
using namespace std;

void countSent(unordered_map<string,int>& cntMap, string& in, int& totalWord){
    in = regex_replace(in, regex("[\\s()\",.:;!?]"), " ");
    transform(in.begin(),in.end(),in.begin(),::tolower);
    istringstream iss(in);
    string word;
    while(iss >> word) {
        cntMap[word]++;
        totalWord++;
    }
}

int main() {
    string in;
    while(getline(cin,in), in != "****END_OF_INPUT****"){
        unordered_map<string,int> cntMap;
        int totalWord = 0;
        countSent(cntMap, in, totalWord);
        while(getline(cin,in),in != "****END_OF_TEXT****"){
            countSent(cntMap, in, totalWord);
        }
        // compute
        double eT = 0;
        double eRel = 0;
        if(totalWord){
            for(auto& p : cntMap){
                eT += p.second*(log10(totalWord) - log10(p.second));
            }
            eT /= totalWord;
            eRel = eT*100.0/log10(totalWord);
        }
        printf("%d %.1f %.0f\n",totalWord, eT, eRel);
    }
}
