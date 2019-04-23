#include <iostream>
#include <sstream>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main()
{
    string in1,in2;
    unordered_map<string,string> trans;
    while(getline(cin,in1), !in1.empty()){
        istringstream iss(in1);
        iss >> in1 >> in2;
        trans[in2] = in1;
    }
    while(cin >> in1){
        if(trans.count(in1)) cout << trans[in1] << endl;
        else cout << "eh" << endl;
    }
}
