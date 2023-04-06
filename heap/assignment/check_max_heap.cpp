// problem statement
// Given an array of integers, check whether it represents max-heap or not. 
//Return true if the given array represents max-heap, else return false
// 




#include<iostream>
using namespace std;
bool ismaxheap_helper(int *arr,int n,int index){
    int leftchildindex=2*index+1;
    int rightchildindex=2*index+2;
    
    // if index crosses half of the way then this is max heap for sure
    if(index>=n/2){
        return true;
    }
    while(leftchildindex<n || rightchildindex <n){
       if(arr[index]>arr[leftchildindex] and arr[index]>arr[rightchildindex] and 
        ismaxheap_helper(arr,n,leftchildindex) and ismaxheap_helper(arr,n,rightchildindex)){
            return true;
    }
    else{ return false;}
    }
    
}
bool ismaxheap(int *arr,int n){
    return ismaxheap_helper(arr,n,0);
}

int main(){
    int n; cin>>n; int *arr=new int[100000];
    for(int i=0; i<n; i++){ cin>>arr[i];}

    cout<<(ismaxheap(arr,n)?"True":"false")<<endl;
    delete []arr;
    return 0;
}