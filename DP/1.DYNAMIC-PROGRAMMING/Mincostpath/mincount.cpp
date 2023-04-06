#include<iostream>
#include<climits>
#include<cmath>



/*
int f(int *a,int *b,int n,int m){
    sort(a,a+n);
    sort(b,b+m);
    int i=0; int j=0;
    int count=0;
    while(i<n and j<m){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else {
            count++;
            i++;
            j++;
        }
    }
    return count;

}

*/



using namespace std;
// using memeoization
int getmincount1_helper(int *ans,int n){
    if(n<=1){ return n; }
    
}
int getmincount1(int n){
    int *ans=new int[n+1];
    for(int i=0; i<=n; i++){
        ans[i]=-1;
    }
    return getmincount1_helper(ans,n);
}

// getmincount function using recursion   #APPROACH-1
int getmincount(int  n){
    // using recursion
    if(n<=1){ return n; }
    int i=1;
    int j=INT_MAX;
    while(i*i<=n){
       j=min(j,getmincount(n-pow(i,2)));
       i++;
    }
    // add 1 and return the ans;
    return j+1;
}

int main(){

    int n; cin>>n;
    cout<<getmincount(n)<<endl;
}