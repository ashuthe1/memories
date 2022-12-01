#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define rapid ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ld long double
#define tc ll test; cin>>test; while(test--)
using namespace std;

ll dp(ll i,ll j,ll n,ll m,vector<vector<ll>> v,vector<vector<ll>> vis){
	if(vis[i][j]==1) return 0;
	vis[i][j] = 1;
	
	if(i==n-1 && j==n-1){
		return v[i][j];
	}

	ll right =0,down =0;

	if(vis[(i+1)%n][j%n]==0){
		right = v[i][j] + dp(i+1,j,n,n,v,vis);
	}
	if(vis[(i)%n][(j+1)%n]==0){
		down = v[i][j] + dp(i,j+1,n,n,v,vis);
	}

	return max(right,down);

	
}

void solve(){	
	
	ll n;
	cin>>n;

	vector<vector<ll>> v(n,vector<ll> (n,0));
	vector<vector<ll>> vis(n,vector<ll> (n,0));

	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			cin>>v[i][j];
		}
	}
	// vector<vector<int>> dpp(n,vector<int> (m,-1));

	cout<<dp(0,0,n,n,v,vis)<<endl;


	
}


int main() {
	// your code goes here

    ll test;
	cin>>test;
    
	for(ll i =0;i<test;i++){
		solve();
	}
    
    	    
	return 0;
}