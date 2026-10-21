#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
using namespace std;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
int k,bit[20];
ll f[20][1050][20][2];
//f[len][S][sumv][<?=]
ll solve(ll n) {
	memset(f,0,sizeof(f));
	int len=0;
	while(n) bit[++len]=n%10,n/=10;
	reverse(bit+1,bit+len+1);
	f[0][1][0][0]=1;
	rep(i,1,len) rep(S,1,1023) rep(v,0,k) rep(c,0,1) {
		ll ans=f[i-1][S][v][c];if(!ans) continue;
		rep(y,0,9) if(y<=bit[i]||c) {
			int S2=S|(1<<y),k2=v+1;
			rep(j,y+1,9) if(S>>j&1) S2^=(1<<j);
			if(S>>y&1) k2--;
			f[i][S2][k2][c|(y<bit[i])]+=ans;
		}
	}
	ll ans=0;
	rep(S,1,1023) ans+=f[len][S][k][1];
	return ans;
}
int main() {
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	ll l,r;scanf("%lld%lld",&l,&r);k=read();
	if(k>19) puts("0");
	else printf("%lld\n",solve(r+1)-solve(l));
	return 0;
}

