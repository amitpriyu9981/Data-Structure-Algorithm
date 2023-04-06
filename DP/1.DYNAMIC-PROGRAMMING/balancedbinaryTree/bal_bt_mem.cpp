#include<bits/stdc++.h>

// #include<climits>

// #include<cmaths>
using namespace std;

int get_no_of_balanced_BT_DP(int h){
    int *ans=new int[h+1];
}


int get_no_of_balanced_BT_Rec_helper(int *ans,int h){
    // Base case
    if(h<=1) { return  1; }    // here we are assuming that h>=0
    int mod=(int)(pow(10,8)+7);

    if(ans[h]!=-1){ return ans[h]; }
    int x=get_no_of_balanced_BT_Rec_helper(ans,h-1);
    int y=get_no_of_balanced_BT_Rec_helper(ans,h-2);
    
    int t1=(int)(((long)(x)*x)%mod);
    int t2=(int)((2*(long)(x)*y)%mod);
    ans[h]=(t1+t2)%mod;
    return ans[h];
}

int get_no_of_balanced_BT_Rec(int h){
    // declaring an arry dynamic of size h+1;
    int *ans=new int[h+1];
    for(int i=0; i<h; i++){ ans[i]=-1;}

    return  get_no_of_balanced_BT_Rec_helper(ans,h);
}


int main(){
    int h; cin>>h;
    int ans=get_no_of_balanced_BT_Rec(h);
    cout<<ans<<endl;
}