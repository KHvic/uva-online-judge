#include <bits/stdc++.h>
using namespace std;

// anything less than 32 => use bit manipulation for fast check on all fields

int main()
{
    string in;
    vector<pair<int,int>> people;
    while(getline(cin,in)){
        if(in == "."){
            bool valid = false;
            for(int i=0;i<(1<<16)&&!valid;i++){
                valid = true;
                for(auto& p : people){
                    int notWithin = i ^ 0xffff;
                    if(p.first & i) continue;
                    if(p.second & notWithin) continue;
                    valid = false; break;
                }
                if(valid){
                    printf("Toppings: ");
                    for(int j=0;j<16;j++)
                        if(i&(1<<j)) printf("%c",(char)(j+'A'));
                    printf("\n");
                }
            }
            if(!valid) 
                printf("No pizza can satisfy these requests.\n");
            people.clear();
        } else {
            int likes = 0, dislike = 0;
            for(int i=0;i<in.length()-1;i+=2){
                if(in[i] == '+')
                    likes |= (1<<(in[i+1]-'A'));
                else
                    dislike |= (1<<(in[i+1]-'A'));
            }
            people.push_back({likes,dislike});
        }
    }
}
