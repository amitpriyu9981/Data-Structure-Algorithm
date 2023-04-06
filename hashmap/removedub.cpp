#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> removedub(vector<int> a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i <size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]]=true;
        output.push_back(a[i]);

    }
    return output;
}
int main(){
    // int a[]={2,3,5,4,6,2,4,3,7,8,5,4,6,4,3};
    int n; cin>>n; vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> output=removedub(a,n);
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}