#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;  


vector<int> getconnectedhelper(int **edges, int n, bool *visited, int sv,vector<int> &smalloutput) {
  visited[sv] = true;
  smalloutput.push_back(sv);
  for (int i = 0; i < n; i++) {
    if (edges[sv][i] == 1 and !visited[i]) {
      getconnectedhelper(edges, n, visited, i, smalloutput);
    }
  }
  return smalloutput;
}

vector<vector<int>> getconnected(int **edges, int n) {
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  vector<vector<int>> finalans;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      vector<int> smalloutput;
      smalloutput = getconnectedhelper(edges, n, visited, i, smalloutput);
      sort(smalloutput.begin(),smalloutput.end());
      finalans.push_back(smalloutput);
    }
  }
  return finalans;
}

int main() {
  int n, e;
  cin >> n >> e;
  int **edges = new int *[n];
  for (int i = 0; i < n; i++) {
    edges[i] = new int[n];
    for (int j = 0; j < n; j++) {
      edges[i][j] = 0;
    }
  }
  for (int i = 0; i < e; i++) {
    int f, s;
    cin >> f >> s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }
  vector<vector<int>> ans = getconnected(edges, n);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans.at(i).size(); j++) {
      cout << ans.at(i).at(j) << " ";
    }
    cout << endl;
  }
  return 0;
}