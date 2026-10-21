#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
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
const int maxn=530010;
const int maxnode=maxn*22;
const int BIT=21;
int ch[maxnode][2],sumv[maxnode],ToT;
int ans[maxn],root[maxn],result[maxn];
void insert(int r,int val) {
	int j=r;sumv[j]++;
	rep(i,0,BIT-1) {
		int c=val>>i&1;
		if(!ch[j][c]) ch[j][c]=++ToT;
		j=ch[j][c];
		sumv[j]++;
	}
	ans[r]^=val;
}
/* 
void print(int x,int cur,int res) {
	if(!x&&cur) return;
	if(cur==BIT) {
		rep(i,1,sumv[x]) printf("%d ",res);
		return;
	}
	print(ch[x][0],cur+1,res);
	print(ch[x][1],cur+1,res|(1<<cur));
}
*/
void add(int x) {
	swap(ch[x][0],ch[x][1]);
	if(ch[x][0]) add(ch[x][0]);
}
int res;
void query(int x,int cur) {
	if(ch[x][0]&&sumv[ch[x][0]]&1) res^=(1<<cur+1)-1;
	if(ch[x][1]) query(ch[x][1],cur+1);
}
void update(int r) {
	res=0;
	query(r,0);
	ans[r]^=res;
	add(r);
}
int merge(int x,int y) {
	if(!x) return y;
	if(!y) return x;
	sumv[x]+=sumv[y];
	ch[x][0]=merge(ch[x][0],ch[y][0]);
	ch[x][1]=merge(ch[x][1],ch[y][1]);
	return x;
}
int n,val[maxn],w[maxn];
int first[maxn],nxt[maxn],to[maxn],e;
void AddEdge(int u,int v) {
	to[++e]=v;nxt[e]=first[u];first[u]=e;
}
void dfs(int x) {
	insert(x,val[x]);
	for(int i=first[x];i;i=nxt[i]) {
		int v=to[i];
		dfs(v);
		update(v);
		ans[x]^=ans[v];
		x=merge(x,v);
	}
	result[x]=ans[x];
} 
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();ToT=n;
	rep(i,1,n) val[i]=read();
	rep(i,2,n) AddEdge(read(),i);
	dfs(1);
	ll sum=0;
	rep(i,1,n) sum+=result[i];
	printf("%lld\n",sum);
	return 0;
}

