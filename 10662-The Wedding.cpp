#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,r,h;
    int p,a;
    while(scanf("%d %d %d",&t,&r,&h) != EOF){
        vector<unordered_set<int>> allowedR(t);
        vector<unordered_set<int>> allowedH(r);
        vector<unordered_set<int>> allowedT(h);
        vector<int> Tprice;
        vector<int> Rprice;
        vector<int> Hprice;

        for(int i=0;i<t;i++){
            cin >> p;
            Tprice.push_back(p);
            for(int j=0;j<r;j++){
                cin >> a;
                if(a==0) allowedR[i].insert(j);
            }
        }
        for(int i=0;i<r;i++){
            cin >> p;
            Rprice.push_back(p);
            for(int j=0;j<h;j++){
                cin >> a;
                if(a==0) allowedH[i].insert(j);
            }
        }
        for(int i=0;i<h;i++){
            cin >> p;
            Hprice.push_back(p);
            for(int j=0;j<t;j++){
                cin >> a;
                if(a==0) allowedT[i].insert(j);
            }
        }

        int res = 1e8;
        tuple<int,int,int> res2;
        for(int i=0;i<t;i++)
        for(int j=0;j<r;j++)
        for(int k=0;k<h;k++)
        if(allowedR[i].count(j) && allowedH[j].count(k) && allowedT[k].count(i)){
            int price = Tprice[i]+Rprice[j]+Hprice[k];
            if(price < res){
                res = price;
                res2 = make_tuple(i,j,k);
            }
        }
        if(res == 1e8) printf("Don't get married!\n");
        else printf("%d %d %d:%d\n",get<0>(res2),get<1>(res2),get<2>(res2),res);
    }
}
