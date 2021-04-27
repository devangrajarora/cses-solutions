#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define fi first
#define se second
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define repe(i,n) for(ll i = 0 ; i <= n ; i++)
#define repb(i,a,b) for(ll i = a ; i < b ; i++)
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

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

/*-------------------------------------------------*/

// read once, read again, think, code

void solve() {

    ll n, m;
    cin >> n >> m;

    vi nums(n), pos(n+1);

    // nums[i] -> number at index i
    // pos[i] -> position which number i is placed

    rep(i,n) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    int ans = 1;
    repb(i,1,n) {
        if(pos[i] > pos[i+1]) ans++;
    }

    rep(q,m) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int num1 = min(nums[u], nums[v]), num2 = max(nums[u], nums[v]);
        if(num1 > 1 and pos[num1] < pos[num1-1]) ans--;
        if(pos[num1] > pos[num1+1]) ans--;
        if(num2-num1 != 1 and pos[num2] < pos[num2-1]) ans--;
        if(num2 < n and pos[num2] > pos[num2+1]) ans--;

        swap(pos[nums[u]], pos[nums[v]]);
        swap(nums[u], nums[v]);

        if(num1 > 1 and pos[num1] < pos[num1-1]) ans++;
        if(pos[num1] > pos[num1+1]) ans++;
        if(num2-num1 != 1 and pos[num2] < pos[num2-1]) ans++;
        if(num2 < n and pos[num2] > pos[num2+1]) ans++;

        p1(ans);
    }
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