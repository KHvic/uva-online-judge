#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string a,b;
    cin >> t;
    while(t--){
        bool valid = false;
        cin >> a >> b;
        // front shift y-axis
        for(int i=0;i<4 && !valid;i++){
            char tmp = a[0];
            a[0]=a[4];a[4]=a[1];a[1]=a[2];a[2]=tmp;
            // left shift x-axis
            for(int j=0;j<4 && !valid;j++){
                tmp=a[2];
                a[2]=a[5];a[5]=a[4];a[4]=a[3];a[3]=tmp;
                // z-axis shift left turn
                for(int k=0;k<4 && !valid;k++){
                    tmp=a[0];
                    a[0]=a[5];a[5]=a[1];a[1]=a[3];a[3]=tmp;
                    if(a==b) valid = true;
                }
            }
        }
        cout << (valid ? "Equal" : "Not Equal") << endl;
    }
}
