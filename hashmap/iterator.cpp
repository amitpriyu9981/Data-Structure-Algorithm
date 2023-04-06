#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){

    // concept of iterator
    unordered_map<string,int> ourmap;
    ourmap["abc"]=1;
    ourmap["abc1"]=2;
    ourmap["abc2"]=3;
    ourmap["abc3"]=4;
    ourmap["abc4"]=5;
    
    cout<<"In case of the unordere map"<<endl;

    unordered_map<string,int>:: iterator it=ourmap.begin();
    while(it != ourmap.end()){
        cout<<"Key "<<it->first<<" "<<"value "<<it->second<<endl;
        it++;
    }
    
    // find 
    unordered_map<string,int> ::iterator it2=ourmap.find("abc");
    // erase 
    ourmap.erase(it2); // we can even pass the iterator to the erease function
    // ourmap.erase(it2,it2+4);



    // in case of the vector how iterator is working
    vector<int> v;
    v.push_back(10);
    v.push_back(100);
    v.push_back(1000);
    v.push_back(1230);
    
    cout<<"Iterator in case of the vector ,"<<endl;
    vector<int>::iterator it1=v.begin();
    while(it1 != v.end()){
        cout<<*it1<<endl;
        it1++;
    }
    return 0;

}