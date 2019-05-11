#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int i=6;i<=200;i++){
        int aCube = i*i*i;
        for(int j=2;j<i;j++){
            int bCube = j*j*j;
            for(int k=j+1;k<i;k++){
                int cCube = k*k*k;
                int remain = aCube - bCube - cCube;
                if(remain <=0) break;
                // check if remaining is a cube number
                double cubeRoot = cbrt(remain);
                if(cubeRoot <= k) break;
                if(cubeRoot - floor(cubeRoot) == 0)
                    cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << cubeRoot << ")" << endl;
            }
        }
    }
}
