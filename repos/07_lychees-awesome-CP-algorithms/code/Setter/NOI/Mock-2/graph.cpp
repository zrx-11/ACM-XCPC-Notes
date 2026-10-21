#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<map>
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
typedef unsigned long long ull;
const int maxn=800010;
const int mod=998244353;
int n,m;
int first[maxn],nxt[maxn],to[maxn],e;
void AddEdge(int u,int v) {
	to[e]=v;nxt[e]=first[u];first[u]=e++;
	to[e]=u;nxt[e]=first[v];first[v]=e++;
}
ull rnd() {
	ull res=rand()^(rand()<<16);
	res<<=32;
	res|=rand()^(rand()<<16);
	return res;
}
int vis[maxn],vis2[maxn],clo;
ull val[maxn],ev[maxn];
ll cnt,all,ans;
map<ull,int> M;
void dfs(int x,int la) {
	vis[x]=++clo;
	for(int i=first[x];~i;i=nxt[i]) if(i!=(la^1)) {
		if(!vis[to[i]]) dfs(to[i],i);
		else if(vis[to[i]]<vis[x]) {
			ev[i]=rnd();cnt++;all++;
			val[x]^=ev[i];
			val[to[i]]^=ev[i];
			M[ev[i]]++;
		}
	}
}
void dfs2(int x,int la) {
	vis2[x]=++clo;
	for(int i=first[x];~i;i=nxt[i]) if(i!=(la^1)&&!vis2[to[i]]) {
		dfs2(to[i],i),val[x]^=val[to[i]];
	}
	if(val[x]) {
		all++;
		(cnt+=2*M[val[x]]+1)%=mod;
		M[val[x]]++;
	}
}
int main() {
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	srand(52501);
	n=read(),m=read();
	memset(first,-1,sizeof(first));
	rep(i,1,m) AddEdge(read(),read());
	int tmp=m-n-2,res=1,res2=1;
	rep(i,1,n) if(!vis[i]) {
		dfs(i,-1),tmp++;
		dfs2(i,-1);
	}
	rep(i,1,tmp) res=(res+res)%mod;
	rep(i,1,tmp+1) res2=(res2+res2)%mod;
	all=(all*all-cnt)%mod;
	ans=(res2*cnt%mod+res*all%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
