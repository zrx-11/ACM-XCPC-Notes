#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=160010;
int n,m,S[maxn],A[maxn],f[maxn],g[maxn];
ll sum[maxn];
int main() {
	freopen("exhibition.in","r",stdin);
	freopen("exhibition.out","w",stdout);
	n=read();m=read();
	rep(i,1,m*2) A[read()]++;
	rep(i,1,n) S[i]=S[i-1]+A[i],sum[i]=sum[i-1]+(ll)A[i]*i;
	int p=0,ssum=0,cur=0;
	rep(i,1,n) {
		ssum+=A[i];
		while(cur<(ssum+1)/2) cur+=A[++p];
		f[i]=p;
	}
	p=n+1;ssum=cur=0;
	dwn(i,n,1) {
		ssum+=A[i];
		while(cur<(ssum+1)/2) cur+=A[--p];
		g[i]=p;
	}
	ll ans=1ll<<60;
	rep(mid,0,n) { 
		ll res=0;
		if(S[mid]) {
			res+=(ll)S[f[mid]]*f[mid]-sum[f[mid]];
			res+=(sum[mid]-sum[f[mid]])-(ll)f[mid]*(S[mid]-S[f[mid]]);
		}
		if(S[mid]!=S[n]) {
			res+=(ll)(S[g[mid+1]]-S[mid])*g[mid+1]-(sum[g[mid+1]]-sum[mid]);
			res+=(sum[n]-sum[g[mid+1]])-(ll)(S[n]-S[g[mid+1]])*g[mid+1];
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
