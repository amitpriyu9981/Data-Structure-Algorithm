
#include<iostream>
#include<string>
using namespace std;

int lcs_DP(string s, string t){
    int m=s.size();
    int n=t.size();
    int **output=new int*[m+1];
    for(int i=0; i<=m; i++) output[i]=new int[n+1];
    
    // fill first row with the 0
    for(int i=0; i<=n; i++) output[0][i]=0;
    // fill the first column with the 0
    for(int i=1; i<=m; i++) output[i][0]=0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            //if first character is matched
            if(s[m-i]==t[n-j]){
                output[i][j]=1+output[i-1][j-1];
            }
            else{
                int a=output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                output[i][j]=max(a,max(b,c));
            }
        }
    }
    return output[m][n];
}
// APPROCAH -2 USING MEMEOIZATION TOP DOWN APPROACH
int lcs_mem(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();
	
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return 0;
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	// Recursive calls
	if(s[0] == t[0]) {
		ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
	}
	else {
		int a = lcs_mem(s.substr(1), t, output);
		int b = lcs_mem(s, t.substr(1), output);
		int c = lcs_mem(s.substr(1), t.substr(1), output);
		ans = max(a, max(b, c));
	}

	// Save your calculation
	output[m][n] = ans;

	// Return ans
	return ans;
}

int lcs_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}
    return  lcs_mem(s,t,output);
}

int lcs(string s,string t){
    if(s.size()==0 or t.size()==0){ 
        return 0;
    }
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else{
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        int c=lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }

}

int main(){
    string s; string t; cin>>s; cin>>t;
    cout<< lcs_DP(s,t)<<endl;
    cout<<lcs(s,t)<<endl;
    cout<<lcs_mem(s,t)<<endl;
}