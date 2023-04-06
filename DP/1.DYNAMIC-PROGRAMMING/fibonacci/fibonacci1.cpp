#include <iostream>
using namespace std;

int fibo(int n)
{
    // base case
    if (n <= 1)
    {
        return n;
    }
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
} 

int fib_2_helper(int n, int *ans)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fib_2_helper(n - 1, ans);
    int b = fib_2_helper(n - 2, ans);
    ans[n] = a + b;
    return ans[n];
}

int fib_2(int n)
{
    // creating an array to stroe the previouus small output and save them a
    int *ans = new int[n + 1];
    // initilise all with the -1
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fib_2_helper(n, ans);
}

int main()
{
    int n;
    cin >> n;

    int ans = fib_2(n);
    cout << ans << endl;
}