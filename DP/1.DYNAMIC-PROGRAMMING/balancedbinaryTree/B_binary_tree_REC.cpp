#include<bits/stdc++.h>
// #include<climits>
using namespace std;



int Balancedbinary(int h){
    // Base case
    if(h<=1){ return 1; }
    int mod=(int)pow(10,9)+7;
    int x=Balancedbinary(h-1);
    int y=Balancedbinary(h-2);
    int t1=(int)(((long)(x)*x)%mod);
    int t2=((2*(long)(x)*y)%mod);
    long long ans=(t1+t2)%mod;
    return ans;

}

// int main(){

//     int h; cin>>h;
//     long ans=Balancedbinary(h);
//     cout<<ans<<endl;
// }



#include <iostream>
using namespace std;

int balanced_BT_DP(int n){
    int *ans=new int[n+1];
    int mod=1e9+7;
    ans[0]=1;
    ans[1]=1;
    for(int i=2; i<=n; i++){
        int x=ans[i-1]%mod;
        int y=ans[i-2]%mod;
        int t1=(int)(((long)(x)*x)%mod);
        int t2=(int)((2*(long)(x)*y)%mod);
        ans[i]=(t1+t2)%mod;
    }
    return ans[n];
}


long long int balancedBTsHelper(int *ans, int n)
{
    if (n <= 1)
    {
        return 1;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    long long int x = balancedBTsHelper(ans, n - 1);
    long long int y = balancedBTsHelper(ans, n - 2);
    long long int mod = 1e9 + 7;
    long long int temp1 = (x * x) % mod;
    long long int temp2 = (2 * x * y) % mod;
    ans[n] = (temp1 + temp2) % mod;
    return ans[n];
}

long long int balancedBTs(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return balancedBTsHelper(ans, n);
}

int main()
{
    int n;
    cin >> n;
    cout << balanced_BT_DP(n);
}