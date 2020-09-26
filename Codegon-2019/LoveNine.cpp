#include<bits/stdc++.h>
using namespace std;

int LoveNineUtil(int n,int x, vector<vector<int>> &dp,vector<int> &v){
	if(x == 0){
		return 0;
	}
	if(n == 0){
		return 100000;
	}
	
	if(dp[n][x] != -1){
		return dp[n][x];
	}	
	else{
		
		if(v[n-1] <= x){
			return dp[n][x] = min(1+LoveNineUtil(n,x-v[n-1],dp,v),LoveNineUtil(n-1,x,dp,v));
		}
		else{
			return dp[n][x] = LoveNineUtil(n-1,x,dp,v);
		}
	}
	
	
}

int LoveNine(int x){
	
	if(x<9){
		return -1;
	}
	int n = x/10;
	
	if(x%10==9){
		n++;
		
	}
	
	vector<int> v;
	int t = 9;
	for(int i=0;i<n;i++){
		v.push_back(t);
		t+=10;
	}
	
	// for(int i=0;i<n;i++){
	// 	cout<<v[i]<<" ";
	// }
	
	// cout<<n<<" "<<x<<endl;

	vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
	
	return LoveNineUtil(n,x,dp,v);
	
	
	

	
}

int main(){

	int x;
	cin>>x;
	
	
	int ans = LoveNine(x);
	// cout<<endl<<endl<<endl;
	cout<<ans;
	
	
	
}
