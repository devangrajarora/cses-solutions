#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

	ll n, d = 5, ans = 0;
	cin >> n;
	while(n/d) {
		ans += n/d;
		d *= 5; 
	}
	cout << (ans);   
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}