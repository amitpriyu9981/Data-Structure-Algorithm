#include <iostream>
using namespace std;

#include <queue>

int main()
{

    priority_queue<int> p;

    // for insert use push
    p.push(10);
    p.push(100);
    p.push(30);
    p.push(78);
    p.push(52);
    p.push(86);
    p.push(45);
    p.push(36);
    
    // size
    cout<<"size : "<<p.size()<<endl;
    cout<<((p.empty())?"True":"False");
    // top element
    cout<<"Top element is "<<p.top()<<endl;
    while(!p.empty()){
        cout<<p.top()<<" "; // here we get element in decreasing order, because inbuilt priority queue is a max heap
        p.pop();
    }
    return 0;
}