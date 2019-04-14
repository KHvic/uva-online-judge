#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

struct person {
    string title, firstname, lastname, address, department;
    string homephone, workphone, campusbox;
    person(string t, string f, string l, string a, string d,string h,string w,string c) {
        this->title = t;
        this->firstname = f;
        this->lastname = l;
        this->address = a;
        this->department = d;
        this->homephone = h;
        this->workphone = w;
        this->campusbox = c;
    }
};

int main(){
    int t;
    string in;
    string dept, title, fname, lname, address, hphone, wphone, cbox;
    scanf("%d\n",&t);
    vector<person*> plist;
    while(t--){
        getline(cin,dept);
        while(getline(cin,in), !in.empty()){
            istringstream iss(in);
            getline(iss, title, ',');
            getline(iss, fname, ',');
            getline(iss, lname, ',');
            getline(iss, address, ',');
            getline(iss, hphone, ',');
            getline(iss, wphone, ',');
            getline(iss, cbox, ',');
            person* p = new person(title,fname,lname,address,dept,hphone,wphone,cbox);
            plist.push_back(p);
        }
    }
    sort(plist.begin(),plist.end(),[](person* a, person* b){
            return a->lastname < b->lastname;
    });

    for(auto& p : plist){
        cout << "----------------------------------------" << endl;
        cout << p->title << " " << p->firstname << " " << p->lastname << endl;
        cout << p->address << endl;
        cout << "Department: " << p->department << endl;
        cout<< "Home Phone: " << p->homephone << endl;
        cout<< "Work Phone: " << p->workphone << endl;
        cout<< "Campus Box: " << p->campusbox << endl;
    }
}
