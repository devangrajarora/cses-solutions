#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i <= b ; i++)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define w(x) ll x; cin>>x; while(x--)

int dr4[] = {0,1,0,-1}, dc4[] = {1,0,-1,0};
int dr8[] = {0,1,1,1,0,-1,-1,-1}, dc8[] = {1,1,0,-1,-1,-1,0,1};

/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

	int n; cin >> n;
	vi a(n);
	rep(i,n) cin >> a[i];
	unordered_map<int,int> m;

	/* 
		testcases of this question are set such that unordered_map with default configuration gives TLE due to large number of collisions
		std::map can be used and that will give AC, but a faster solution would be to modify the unordered_map to avoid collisions

	*/

	m.reserve(1<<10); // initail size 

	/*
		Sets the number of buckets in the container to the most appropriate to contain at least n elements.
		If n is greater than the current bucket_count multiplied by the max_load_factor, the container's bucket_count is increased and a rehash is forced.
		n shows minimmum bucket_count of unordered_map without crossing load_factor
	*/

	m.max_load_factor(0.25); // trading off space for time

	/*
		The load factor is the ratio between the number of elements in the container (its size) and the 
		number of buckets. The load factor influences the probability of collision in the hash table.
		The container uses the value of max_load_factor as the threshold that forces an increase in the number of buckets 
		(and thus causing a rehash).
		Default load_factor is 1.0. Smaller max_load_factor is suitable to avoid collisions as, increase in collisons would mean increase in load_factor, and
		as load_factor crosses max_load_factor, rehash is called.
	*/

	int i = 0, j = 0, ans = 1;

	while(j < n) {

		while(m[a[j]]) {
			m[a[i]]--;
			i++;
		}

		m[a[j]]++;		
		ans = max(ans, j-i+1);
		j++;
	} 

	p1(ans);
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