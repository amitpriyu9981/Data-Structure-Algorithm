#include<iostream>
using namespace std;

#include<queue>

int main(){
    
    // for min priority queue use greater<int> as a comparitor
    priority_queue<int,vector<int>,greater<int> > p;
    p.push(10);
    p.push(78);
    p.push(4);
    p.push(2);
    p.push(100);
    p.push(56);
    cout<<"Size : "<<p.size()<<endl;
    cout<<"Top : "<<p.top()<<endl;
    while(!p.empty()){
        cout<<p.top()<< " ";
        p.pop();
    }
    cout<<endl;
    return 0;
}