#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sequence = ""; // store single sequence
    int totalLength=0; // length from 1 to n
    vector<long long> lens(1,0); // cumulative length of concat seq
    for(int i=1;i<35000;i++){
        int length = (int)log10(i)+1;
        totalLength += length;
        sequence += to_string(i);
        lens.push_back(totalLength+lens.back());
    }

    int t,v;
    cin >> t;
    while(t--){
        cin >> v;
        int low = 0, high = 34999;
        // bisect right to find next smaller sequence
        while(low<high){
            int mid = (low+high)/2+1;
            if(lens[mid] >= v) high = mid-1;
            else low = mid;
        }
        // n-th digit in sequence
        printf("%c\n", sequence[v-lens[high]-1]);
    }
}
