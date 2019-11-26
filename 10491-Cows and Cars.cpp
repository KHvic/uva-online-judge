#include <bits/stdc++.h>
using namespace std;


// probability of cars:
// choose car then car = (cars-1)/(total-show-1)
// choose cow then car = car/(total-show-1)
int main() {
    int cows,cars,show;
    while(scanf("%d %d %d",&cows,&cars,&show) != EOF) {
        int total = cars+cows;
        double carFirst = (double)(cars)/total*(double)(cars-1)/(total-show-1);
        double cowFirst = (double)(cows)/total*(double)(cars)/(total-show-1);
        printf("%.5f\n",carFirst+cowFirst);
    }
}
