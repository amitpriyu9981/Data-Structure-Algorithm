#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
using namespace std; 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
// typedef long long ll; 
#define infinity 899999999999999999 
// #define MOD_DEFINE const int MOD = 1e9 + 7; 
// #define endl '\n' 
// #define sz(v) ((int)(v).size()) 
// #define all(v) (v).begin(), (v).end() 
// #define space " " 
// #define int long long 
// #define vi vector<int> 
// #define pii pair<int, int> 
// #define pb(n) push_back(n) 
// #define ff first 
#define ss second 
#define mii map<int, int> 
#define umii unordered_map<int, int> 
#define w(t)  \ 
    int t;    \ 
    cin >> t; \
    while (t--) 
#define FIO                           \ 
    ios_base::sync_with_stdio(false); \ 
    cin.tie(NULL); 
#define cout std::cout 
#define cin std::cin 
#define l(var, initial, final) for (int var = initial; var < final; var++) 
#define pqb priority_queue<int> 
#define pqs priority_queue<int, vi, greater<int>> 
 
int32_t main() 
{ 
    FIO 
    w(t) 
    { 
        int n; 
        cin >> n; 
        vector<vector<int>> v(n, vector<int>(n - 1)); 
        vector<map<int, int>> m(n - 1); 
        l(i, 0, n) 
        { 
            l(j, 0, n - 1) 
            { 
                cin >> v[i][j]; 
                m[j][v[i][j]]++; 
            } 
        } 
        vi ans(n); 
        int maxi = 0; 
        int num = 0; 
        int mini = infinity; 
        int num2 = 0; 
        for (auto &j : m[0]) 
        { 
            if (j.second > maxi) 
            { 
                maxi = j.second; 
                num = j.first; 
            } 
            if (j.second < mini) 
            { 
                mini = j.second; 
                num2 = j.first; 
            } 
        } 
        ans[0] = num; 
        l(i, 1, n - 1) 
        { 
            ans[i] = num2; 
            for (auto &j : m[i]) 
            { 
                if (j.first != num2) 
                { 
                    num2 = j.first; 
                    break; 
                } 
            } 
        } 
 
        ans[n - 1] = num2; 
        for (auto &i : ans) 
        { 
            cout << i << " "; 
        } 
        cout << endl; 
    } 
 
    return 0; 
}