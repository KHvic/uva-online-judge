#include <bits/stdc++.h>
using namespace std;

char m;
int r,c;
string parse, res;
int idx = 0;

void toDecomposeMap(int rowStart, int rowEnd, int colStart, int colEnd){
    if(rowStart > rowEnd || colStart > colEnd) return;
    int totalSize = (rowEnd-rowStart+1)*(colEnd-colStart+1);
    int bitCount = 0;
    for(int i=rowStart;i<=rowEnd;i++)
        for(int j=colStart;j<=colEnd;j++)
            bitCount += (parse[i*c+j]-'0');
    if(bitCount == totalSize){
        res += '1';
    } else if(bitCount == 0){
        res += '0';
    } else {
        res += 'D';
        // top left
        toDecomposeMap(rowStart,(rowStart+rowEnd)/2,colStart,(colStart+colEnd)/2);
        // top right
        toDecomposeMap(rowStart,(rowStart+rowEnd)/2,(colStart+colEnd)/2+1,colEnd);
        // btm left
        toDecomposeMap((rowStart+rowEnd)/2+1,rowEnd,colStart,(colStart+colEnd)/2);
        // btm right
        toDecomposeMap((rowStart+rowEnd)/2+1,rowEnd,(colStart+colEnd)/2+1,colEnd);
    }
}

void toBitMap(int rowStart, int rowEnd, int colStart, int colEnd){
    if(rowStart > rowEnd || colStart > colEnd) return;
    char ch = parse[idx++];
    if(ch == 'D'){
        // top left
        toBitMap(rowStart,(rowStart+rowEnd)/2,colStart,(colStart+colEnd)/2);
        // top right
        toBitMap(rowStart,(rowStart+rowEnd)/2,(colStart+colEnd)/2+1,colEnd);
        // btm left
        toBitMap((rowStart+rowEnd)/2+1,rowEnd,colStart,(colStart+colEnd)/2);
        // btm right
        toBitMap((rowStart+rowEnd)/2+1,rowEnd,(colStart+colEnd)/2+1,colEnd);
    } else {
        for(int i=rowStart;i<=rowEnd;i++)
            for(int j=colStart;j<=colEnd;j++)
                res[i*c+j] = ch;
    }
}

int main() {
    while(cin>>m, m!='#'){
        cin >> r >> c;
        cin >> parse;
        while(m == 'B' && parse.size() != r*c){
            cin >> res;
            parse += res;
        }
        idx = 0;
        if(m == 'D'){
            res.resize(r*c);
            toBitMap(0,r-1,0,c-1);
        } else {
            res.clear();
            toDecomposeMap(0,r-1,0,c-1);
        }
        printf("%c%4d%4d",(m=='D'?'B':'D'),r,c);
        for(int i=0;i<res.size();i++){
            if(i%50 == 0) cout << endl;
            printf("%c",res[i]);
        }
        cout << endl;
    }
}
