#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define MAXN 100010
ll tree[MAXN], ans[MAXN], n;
pair<ll, ll> arr[MAXN];
ll sum(int x) {
    ll ret = 0;
    for (int i = x; i > 0; i -= (i&-i)) ret += tree[i];
    return ret;
}
void update(int x,ll val) {
    for (int i = x; i <= n; i += (i&-i)) tree[i] += val;
}
int main() {
    scanf(" %lld", &n);
    for (int i = 1; i <= n; i++) {
        ll x; scanf(" %lld", &x);
        update(i,(ll)1);
        arr[i] = { x,(ll)i };
    }
    sort(arr + 1, arr + n + 1);
    ll tsum = 0, prev = 0, pos = 0;
    for (int i = 1; i <= n; i++) {
        pos = arr[i].first;
        if(prev != pos)     tsum += sum(n)*(pos - prev);
        ans[arr[i].second] = tsum - (sum(n) - sum(arr[i].second));
        update(arr[i].second,-1);
        prev = pos;
    }
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
}