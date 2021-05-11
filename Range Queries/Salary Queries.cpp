#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
#define repeb(i,a,b) for(ll i = a ; i <= b ; i++)
#define rfor(i,n,a) for(ll i = n ; i >= a ; i--)
#define pb push_back
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair <ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define w(x) ll x; cin>>x; while(x--)

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << " ";
            os << v[i];
            first = false;
        }
        return os;
    }
    
/*-------------------------------------------------*/

// read once, read again, think, code

struct SegmentTree {
	
    vi mx,mn;
    ll sz, n;

    void init(ll n) {
        sz = 4*n;
        this -> n = n;
        mx.assign(sz,0ll);
        mn.assign(sz,0ll);
    }

    void build(vi &a, int pos, int l, int r) {
		if(l == r) {
			mx[pos] = a[l];
			mn[pos] = a[l];
			return;
		}

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		mx[pos] = max(mx[2*pos+1], mx[2*pos+2]);
		mn[pos] = min(mn[2*pos+1], mn[2*pos+2]);
	}

	void build(vi &a) {
		build(a,0,0,n-1);
	}

    void update(vi &a, ll idx, ll num, ll pos, ll l, ll r) {
        if(l == r) {
            mx[pos] = num;
            mn[pos] = num;
            a[l] = num;
            return;
        }

        ll mid = (l + r)/2;
        if(idx <= mid) update(a,idx,num,2*pos+1,l,mid);
        else update(a,idx,num,2*pos+2,mid+1,r);
		mx[pos] = max(mx[2*pos+1], mx[2*pos+2]);
		mn[pos] = min(mn[2*pos+1], mn[2*pos+2]);
    }

    void update(vi &a, ll idx, ll num) {
        update(a,idx,num,0,0,n-1);
    }

    ll query(vi &a, ll pos, ll l, ll r, ll ai, ll bi) {

    	if(ai <= mn[pos] and mx[pos] <= bi) {
    		return r-l+1;
    	}

        if(mn[pos] > bi or ai > mx[pos]) {
        	return 0;
        }

        ll mid = (l + r)/2;
        ll left = (mn[2*pos+1] > bi or ai > mx[2*pos+1]) ? 0 : query(a,2*pos+1,l,mid,ai,bi);
        ll right = (mn[2*pos+2] > bi or ai > mx[2*pos+2]) ? 0 : query(a,2*pos+2,mid+1,r,ai,bi);
        return left + right;

    }

    ll query(vi &a, ll ai, ll bi) {
        return query(a,0,0,n-1,ai,bi);
    }

};

/*
	seg.init(n);
	seg.build(a);
	seg.update(idx,num);
	seg.query(ql,qr);
*/

void solve() {

    ll n, q; cin >> n >> q;
    vi a(n);
    rep(i,n) cin >> a[i];

    SegmentTree seg;
    seg.init(n);
    seg.build(a);

    while(q--) {
    	char op; cin >> op;
    	if(op == '!') {
    		ll idx, num; cin >> idx >> num;
    		seg.update(a,idx-1,num);
    	} else {
    		ll ai, bi;
    		cin >> ai >> bi;
    		ll ans = seg.query(a,ai,bi);
    		p1(ans);
    	}
    }
}


int main()
{
	fastio;

    #ifndef ONLINE_JUDGE
    freopen("/home/devang/input.txt","r",stdin);
    freopen("/home/devang/output.txt","w",stdout);
    #endif

    //w(tc)
    	solve();
	
	return 0;
}