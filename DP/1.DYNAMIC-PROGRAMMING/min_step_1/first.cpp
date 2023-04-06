#include<iostream>
using namespace std;

#include<climits>


// brutforce approach
int getminsteptoreach1(int n){
    if(n<=1){ return 0; }

    int x=getminsteptoreach1(n-1);
    int y=INT_MAX; int z=INT_MAX;
    if(n%2==0){ y=getminsteptoreach1(n/2); }
    if(n%3==0){ z=getminsteptoreach1(n/3); }

    int ans=min(x,min(y,z));
    return ans+1;
}


int main(){
    int n; cin>>n;

    int finalans=getminsteptoreach1(n);
    cout<<finalans<<endl;

}