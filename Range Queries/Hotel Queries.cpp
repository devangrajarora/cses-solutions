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

	vector<ll> seg, maxPos;
	ll size;
	ll n;

	void init(int n) {
		this -> n = n;
		size = 4*n;
		seg.assign(size,0ll);
		maxPos.assign(size,0ll);
	}

	void build(vi &a, int pos, int l, int r) {
		if(l == r) {
			seg[pos] = a[l];
			maxPos[pos] = l;
			return;
		}

		int mid = (l + r) / 2;
		build(a,2*pos+1,l,mid);
		build(a,2*pos+2,mid+1,r);
		maxPos[pos] = (seg[2*pos+1] > seg[2*pos+2]) ? maxPos[2*pos+1] : maxPos[2*pos+2];
		seg[pos] = max(seg[2*pos+1],seg[2*pos+2]);
	}

	void build(vi &a) {
		build(a,0,0,n-1);
	}

	void update(vi &a, ll num, int idx, int pos, int l, int r) {
		if(l == r) {
			// p2(num,idx);
			seg[pos] = num;
			maxPos[pos] = l;
			a[idx] = num;
			return;
		}

		int mid = (l + r) / 2;
		if(idx <= mid) update(a,num,idx,2*pos+1,l,mid);
		else update(a,num,idx,2*pos+2,mid+1,r);
		
		maxPos[pos] = (seg[2*pos+1] > seg[2*pos+2]) ? maxPos[2*pos+1] : maxPos[2*pos+2];
		seg[pos] = max(seg[2*pos+1],seg[2*pos+2]);		
	}

	void update(vi &a, ll num, int idx) {
		update(a,num,idx,0,0,n-1);
	}

	
	pii query(ll req, int pos, int l, int r) {

		if(l == r) return {seg[pos], maxPos[pos]};
		int mid = (l + r) / 2;

		return (seg[2*pos+1] >= req) ?  query(req,2*pos+1,l,mid) : query(req,2*pos+2,mid+1,r);
	}

	pii query(ll req) {
		return query(req,0,0,n-1);
	}
};

void solve() {

	ll n, m; cin >> n >> m;
	vi rooms(n), ans(m);
	ll req;

	rep(i,n) cin >> rooms[i];

    SegmentTree seg;

    seg.init(n);
    seg.build(rooms);

	rep(i,m) {
		cin >> req;
		pii res = seg.query(req);
		if(res.fi >= req) {
			ans[i] = res.se+1;
			seg.update(rooms,res.fi-req,res.se);
		} else {
			ans[i] = 0;
		}
	}

	p1(ans);
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