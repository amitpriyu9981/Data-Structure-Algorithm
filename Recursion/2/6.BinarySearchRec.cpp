#include<iostream>
#include<vector>
using namespace std;
int binarysearchhelper(int *arr,int start,int end,int element){
    if(start > end) return -1;
    int mid=start+(end-start)/2;
    if(arr[mid]==element) return mid;
    if(arr[mid]<element) return binarysearchhelper(arr,mid+1,end,element);
    else return binarysearchhelper(arr,start,mid-1,element);
    
}
int binarysearch(int *arr,int n,int element){
    int start=0;
    int end=n-1;
    return binarysearchhelper(arr,start,end,element);
}

int main(){
    int n; cin>>n;
    // vector<int> arr(n);
    int *arr=new int[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int element; cin>>element;

    int ans=binarysearch(arr,n,element);
    cout<<ans<<endl;
    return 0;
    

}