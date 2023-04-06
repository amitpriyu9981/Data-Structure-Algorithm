#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// partition function
int getpartition(int arr[],int s,int e){
    // take first element as a pivot 
    // count the  no of element less than the pivot
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    
    // pivot index is s+cnt
    int pivot_index=s+cnt;
    // swap 
    swap(&arr[s],&arr[pivot_index]);
    
    // make sure that all the element in left should be smaller and right side is greater
    int i=s;
    int j=e;
    while(i<pivot_index &&  j>pivot_index){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        // else we have to swap
        if(i<pivot_index && j>pivot_index){
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    return pivot_index;
}

void getquicksort(int arr[],int s,int e){
    
    if(s>=e){
        return;
    }
    
    int p=getpartition(arr,s,e);
    // left
    getquicksort(arr,s,p-1);
    getquicksort(arr,p+1,e);                                                // right part
}
    

void quickSort(int input[], int size) {

    if(size==0 or size==1) return;
    
    getquicksort(input,0,size-1);
    
}
int main(){
    int n; cin>>n;
    int *input=new int[n];
    for(int i=0; i<n; i++) cin>>input[i];
    quickSort(input,n);
    for(int i=0; i<n; i++) cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}
