#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in1,in2;
    int tc=1;
    while(getline(cin,in1)){
        getline(cin,in2);

        cout << setw(2) << fixed << tc++ << ". ";
        if(in1.empty() || in2.empty()){
            cout << "Blank!" << endl;
            continue;
        }
        in1 = regex_replace(in1,regex("[^a-zA-Z0-9]")," ");
        in2 = regex_replace(in2,regex("[^a-zA-Z0-9]")," ");

        vector<string> seqA, seqB;
        istringstream iss(in1);
        while(iss >> in1) seqA.push_back(in1);
        iss.clear(); iss.str(in2);
        while(iss >> in2) seqB.push_back(in2);

        vector<int> dp(seqB.size()+1);
        for(int i=0;i<seqA.size();i++){
            vector<int> dpNext(seqB.size()+1);
            for(int j=0;j<seqB.size();j++){
                if(seqA[i] == seqB[j])
                    dpNext[j+1] = dp[j]+1;
                else
                    dpNext[j+1] = max(dp[j+1],dpNext[j]);
            }
            dp = dpNext;
        }
        cout << "Length of longest match: " << dp.back() << endl;
    }
}
