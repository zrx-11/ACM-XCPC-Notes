#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int> pii;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=2610;
const int inf=1e9;
int n,A[maxn];
int f[2][maxn*2];// (0 -> 1) - (1 -> 0)
char p[maxn];
int main() {
	freopen("inverse.in","r",stdin);
	freopen("inverse.out","w",stdout);
	n=read();
	scanf("%s",p+1);
	rep(i,1,n) A[i]=read();
	rep(i,0,2*n) f[0][i]=-inf;
	f[0][n]=0;int cur=0,c1=0;
	rep(i,1,n) {
		cur^=1;
		rep(j,0,2*n) f[cur][j]=-inf;
		rep(j,0,2*n) {
			int& ans=f[cur^1][j];if(ans==-inf) continue;
			if(p[i]=='1') {
				f[cur][j]=max(f[cur][j],ans);
				f[cur][j-1]=max(f[cur][j-1],ans-A[i]+c1+j-n);
			}
			else {
				f[cur][j]=max(f[cur][j],ans+c1+j-n);
				f[cur][j+1]=max(f[cur][j+1],ans-A[i]);
			}
		}
		if(p[i]=='1') c1++;
	}
	int ans=-inf;
	rep(j,0,2*n) ans=max(ans,f[cur][j]);
	printf("%d\n",ans);
	return 0;
}
