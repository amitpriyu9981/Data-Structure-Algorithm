#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int input[], int n, int k) {
	// first push k element in the max priority queue
	priority_queue<int> pq;
	for(int i = 0; i < k; i++) {
		pq.push(input[i]);
	}

	int j = 0; // for maintaining the index to which store the maximum value
	for(int i = k; i < n; i++) {
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}
     
    // for the last k element 
	while(!pq.empty()) {
		input[j] = pq.top();
		pq.pop();
        j++;
	}

}
	
int main() {
    int n; cin>>n; int arr[n];
    for(int i=0; i<n; i++){cin>>arr[i];}
    int k; cin>>k;
    kSortedArray(arr,n,k);
    for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
	// int input[] = {10, 12, 6, 7, 9};
	// int k = 3;
	// kSortedArray(input, 5, k);
	// for(int i = 0; i < 5; i++) {
	// 	cout << input[i] << " ";
	// }
}
