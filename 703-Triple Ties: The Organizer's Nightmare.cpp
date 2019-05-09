#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,v;
   while(cin >> n){
       vector<vector<bool>> matrix(n,vector<bool>(n,false));
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++){
           cin >> v;
           matrix[i][j] = v;
       }
       vector<tuple<int,int,int>> res;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++){
                   if((!matrix[i][j] && !matrix[j][i] &&
                       !matrix[i][k] && !matrix[k][i] &&
                       !matrix[j][k] && !matrix[k][j]) ||
                       (matrix[i][j] && matrix[j][k] && matrix[k][i])
                    )
                    res.push_back(make_tuple(i+1,j+1,k+1));
                    if((matrix[k][j] && matrix[j][i] && matrix[i][k]))
                        res.push_back(make_tuple(k+1,j+1,i+1));
               }
           }
       }
       sort(res.begin(),res.end());
       cout << res.size() << endl;
       for(auto& t : res)
        printf("%d %d %d\n",get<0>(t),get<1>(t),get<2>(t));
   }
}
