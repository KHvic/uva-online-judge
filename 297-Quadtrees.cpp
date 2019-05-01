#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isFull;
    Node* c1,*c2,*c3,*c4;
    Node(){
        c1 = c2 = c3 = c4 = NULL;
        isFull = true;
    }
    Node(Node* a,Node* b,Node* c,Node* d){
        c1=a,c2=b,c3=c,c4=d;
        isFull = false;
    }
};

Node* build(string& str, int& idx){
    if(str[idx] == 'f') return new Node();
    if(str[idx] == 'e') return NULL;
    Node* a = build(str,++idx);
    Node* b = build(str,++idx);
    Node* c = build(str,++idx);
    Node* d = build(str,++idx);
    return new Node(a,b,c,d);
}

int combine(Node* a,Node* b,int curSize){
    if((a&&a->isFull) || (b&&b->isFull))
        return curSize;
    if(a&&b){
        return combine(a->c1,b->c1,curSize/4) + combine(a->c2,b->c2,curSize/4) +
        combine(a->c3,b->c3,curSize/4) + combine(a->c4,b->c4,curSize/4);
    } else if(a || b){
        if(b) a=b;
        return combine(a->c1,NULL,curSize/4) + combine(a->c2,NULL,curSize/4) +
        combine(a->c3,NULL,curSize/4) + combine(a->c4,NULL,curSize/4);
    }
    return 0;
}

int main() {
    int t;
    string a,b;
    scanf("%d",&t);
    while(t--){
        cin >> a >> b;
        int i=0;
        Node* node_a = build(a,i);
        i=0;
        Node* node_b = build(b,i);
        cout << "There are " << combine(node_a,node_b,1024) << " black pixels." << endl;
    }
}
