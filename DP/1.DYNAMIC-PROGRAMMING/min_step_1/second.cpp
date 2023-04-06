// using dynamic programming and memoization

#include <iostream>
using namespace std;

#include <climits>
// using dynamic programming
int cnt1_dp(int n)
{
    // create a array of size n+1
    int *ans = new int[n + 1];
    ans[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int x = ans[i - 1];
        int y = INT_MAX;
        int z = INT_MAX;
        if (i % 2 == 0)
        {
            y = ans[i / 2];
        }
        if (i % 3 == 0)
        {
            z = ans[i/3];
        }

        ans[i] = min(x, min(y, z)) + 1;
    }

    return ans[n];
}

// using memeoization
int cnt1_mem_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }
    // check wether the ans exist or not
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int x = cnt1_mem_helper(n - 1, ans);
    int y = INT_MAX;
    int z = INT_MAX;
    if (n % 2 == 0)
    {
        y = cnt1_mem_helper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = cnt1_mem_helper(n / 3, ans);
    }

    int output = min(x, min(y, z)) + 1;
    ans[n] = output;
    return output;
}
// using memoization
int cnt1_mem(int n)
{

    // if(n<=1){ return 0;}
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    return cnt1_mem_helper(n, ans);
}
int main()
{
    int n;
    cin >> n;

    int ans = cnt1_mem(n);
    int ans1 = cnt1_dp(n);
    cout << ans << " " << ans1 << endl;
}