#include <bits/stdc++.h>

using namespace std;

string str;
int n; // the length of input string
vector<int> rankArr, tempRankArr; // rank array and temporary rank array (value determining the sorting order)
vector<int> suffixArr, tempSuffixArr; // suffix array and temporary suffix array (actual sorted order)
vector<int> cnt; // for counting sort
vector<int> LCP, PLCP; // longest common prefix

// counting sort on offset k, O(N)
void countingSort(int k) {
    int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n (max rank)
    cnt.assign(maxi,0); // frequency table assignment
    // step 1: counting
    for(i = 0; i < n; i++) // count the frequency of each rank
        cnt[i + k < n ? rankArr[i + k] : 0]++;
    // step 2: summing
    for (i = sum = 0; i < maxi; i++) {
        int tmp = cnt[i];
        cnt[i] = sum;
        sum += tmp;
    }
    // step 3: placement
    for (i = 0; i < n; i++)
        if(suffixArr[i]+k < n)// offset is within bound (not empty)
            tempSuffixArr[cnt[rankArr[suffixArr[i]+k]]++] = suffixArr[i];
        else // out of bound (empty character), have highest precedence lexicographically
            tempSuffixArr[cnt[0]++] = suffixArr[i];
    // update the suffix array
    for (i = 0; i < n; i++)
        suffixArr[i] = tempSuffixArr[i];
}
// O(NlogN)
void constructSA() {
    int i, k, r;
    rankArr.assign(n,0), tempRankArr.assign(n,0);
    suffixArr.assign(n,0), tempSuffixArr.assign(n,0);
    for (i = 0; i < n; i++) rankArr[i] = str[i]; // initial rankings (ASCII value)
    for (i = 0; i < n; i++) suffixArr[i] = i; // initial SA: {0, 1, 2, ..., n-1}

    for (k = 1; k < n; k <<= 1) { // repeat sorting process logN times by power of 2
        // sort based on pair(0,k) to get suffix array (sorted ordering)
        countingSort(k);
        countingSort(0);
        tempRankArr[suffixArr[0]] = r = 0; // re-ranking; start from rank r = 0, used for subsequent count sort
        for (i = 1; i < n; i++){ // compare adjacent suffixes
            // pair rank (value) are the same as previous
            if(rankArr[suffixArr[i]] == rankArr[suffixArr[i-1]] &&
               rankArr[suffixArr[i]+k] == rankArr[suffixArr[i-1]+k]
               )
                tempRankArr[suffixArr[i]] = r; // same rank
            else
                tempRankArr[suffixArr[i]] = ++r; // next rank
        }
        // update the rank array
        for (i = 0; i < n; i++)
            rankArr[i] = tempRankArr[i];
        if (rankArr[suffixArr[n-1]] == n-1) break; // nice optimization trick
    }
}

// based on Permuted Longest-Common-Prefix (PLCP) theorem
// O(N) as there are at most N increment&decrement
void computeLCP() {
    int i, L;
    LCP.assign(n,0); PLCP.assign(n,0);
    vector<int> prevSuffixIndex(n,-1);
    for(i=1;i<n;i++)
        prevSuffixIndex[suffixArr[i]] = suffixArr[i-1];
    // L is current character we are looking at
    for(i=L=0;i<n;i++) {
        if(prevSuffixIndex[i] == -1) { // special case
            PLCP[i] = 0;
            continue;
        }
        // compare with previous suffix in SA to check if prefix matches
        // can only increase N times at most, since string is n length
        while(i+L < n && prevSuffixIndex[i] + L < n &&
              str[i+L] == str[prevSuffixIndex[i] + L] &&
              str[i+L] != '$') // additional requirement for > 1 string
            L++;
        PLCP[i] = L;
        if(L) L--; // decrease 1 as we go to next suffix
    }
    // LCP is for suffix array ordering, PLCP is for original array ordering
    for(i =0;i<n;i++)
        LCP[i] = PLCP[suffixArr[i]];  // put the permuted LCP to the correct position
}


int main()
{
    int t; bool first = true;
    while(scanf("%d",&t),t!=0){
        if(!first) cout << endl;
        first = false;
        str = "";
        string in;
        vector<int> owner;
        for(int i=0;i<t;i++){
            cin >> in;
            str += in;
            str += "$";
            while(owner.size() < str.length())
                owner.push_back(i);
        }
        n = str.length();
        constructSA();
        computeLCP();

        // loop through suffix array
        // generalize LCS using sliding window
        // where a window contain t/2 different owner
        int maxLCP = 0;
        int uniqueOwner = 0;
        vector<int> LCSidx;
        vector<int> ownerCounter(t);
        int low=t,high=t; // the first t have $ prefix
        while(high<n){
            if(uniqueOwner <= t/2){ // slide high
                int ownerIdx = owner[suffixArr[high]];
                if(ownerCounter[ownerIdx]++ == 0)
                    uniqueOwner++;
                high++;
            } else { // fulfill criteria having > t/2 owner
                // the longest common prefix of this window is the minimum LCP[i] from low+1
                int minimum = INT_MAX; int pos = low+1;
                for(int i=low+1;i<high;i++){
                    if(LCP[i] < minimum){
                        minimum = LCP[i];
                        pos = i;
                    }
                }
                if(LCP[pos] > maxLCP){ // new longest
                    maxLCP = LCP[pos];
                    LCSidx.clear();
                }
                if(LCP[pos] == maxLCP) LCSidx.push_back(pos);
                
                // slide low
                int ownerIdx = owner[suffixArr[low]];
                if(--ownerCounter[ownerIdx] == 0)
                    uniqueOwner--;
                low++;
            }
        }
        if(maxLCP == 0) cout << "?" << endl;
        else {
            string prev = "";
            for(int idx : LCSidx){
                string next = str.substr(suffixArr[idx],maxLCP);
                if(next == prev) continue;
                prev = next;
                cout << next << endl;
            }
        }
    }
}
