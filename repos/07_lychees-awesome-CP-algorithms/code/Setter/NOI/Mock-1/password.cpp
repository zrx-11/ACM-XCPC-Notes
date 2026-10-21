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
const int maxn=55;
const int mod=998244353;
int N;
struct Matrix {
	int A[maxn][maxn];
	Matrix operator * (const Matrix& b) const {
		Matrix c;
		rep(i,1,N) rep(j,1,N) {
			int ans=0;
			rep(k,1,N) (ans+=(ll)A[i][k]*b.A[k][j]%mod)%=mod;
			c.A[i][j]=ans;
		}
		return c;
	}
	void init() {memset(A,0,sizeof(A));}
	void print() {
		rep(i,1,N) rep(j,1,N) printf("%d%c",A[i][j],j==N?'\n':' ');
	}
};
Matrix tmp;
void qpow(Matrix& ans,int n) {
	tmp=ans;n--;
	for(;n;n>>=1,tmp=tmp*tmp) if(n&1) ans=ans*tmp;
}
int n,m,ch[maxn][10],cnt,pos[10];
void insert(char* s,int x) {
	int j=0;
	for(int i=0;s[i];i++) {
		int c=s[i]-'0';
		if(!ch[j][c]) ch[j][c]=++cnt;
		j=ch[j][c];
	}
	pos[x]=j;
}
int q[maxn],f[maxn];
vector<int> G[maxn];
void build() {
	int l=1,r=0;
	rep(c,0,9) if(ch[0][c]) q[++r]=ch[0][c];
	while(l<=r) {
		int u=q[l++];
		rep(c,0,9) {
			if(!ch[u][c]) {ch[u][c]=ch[f[u]][c];continue;}
			int v=ch[u][c];q[++r]=v;
			int j=f[u];
			while(j&&!ch[j][c]) j=f[j];
			f[v]=ch[j][c];
		}
	}
	rep(i,1,cnt) G[f[i]].pb(i);
}
Matrix T;
void mark(int x) {
	rep(j,1,N) T.A[x+1][j]=0;
	rep(i,0,G[x].size()-1) mark(G[x][i]);
}
char s[maxn];
int main() {
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);
	n=read();m=read();
	rep(i,1,n) scanf("%s",s),insert(s,i);
	build();
	int ans=0;N=cnt+1;
	rep(S,0,(1<<n)-1) {
		int c=0;T.init();
		rep(i,0,cnt) rep(j,0,9) T.A[ch[i][j]+1][i+1]++;
		rep(i,0,n-1) if(S>>i&1) mark(pos[i+1]),c++;
		qpow(T,m);
		rep(i,1,N) {
			if(c&1) (ans+=mod-T.A[i][1])%=mod;
			else (ans+=T.A[i][1])%=mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
