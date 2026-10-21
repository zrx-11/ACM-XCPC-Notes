#include<cstdio>
#include<cctype>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ren for(int i=first[x];i;i=next[i])
using namespace std;
const int BufferSize=1<<16;
char buffer[BufferSize],*head,*tail;
inline char Getchar() {
	if(head==tail) {
		int l=fread(buffer,1,BufferSize,stdin);
		tail=(head=buffer)+l;
	}
	return *head++;
}
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=55;
const double eps=1e-12;
typedef double Matrix[maxn][maxn];
const int maxm=550;
int n,m,s,x[9],e[maxn][maxn];
void gauss(Matrix& A) {
	rep(i,0,n-1) {
		int r=i;
		rep(j,i+1,n-1) if(fabs(A[j][i])>fabs(A[r][i])) r=j;
		if(fabs(A[r][i])<eps) continue;
		if(r!=i) rep(j,0,n) swap(A[i][j],A[r][j]);
		rep(k,0,n-1) if(k!=i)
			dwn(j,n,i) A[k][j]-=A[k][i]/A[i][i]*A[i][j];
	}
}
double f[maxn][maxm];
int check(int S) {
	int c1=0,c2=0,c3=0,c=0;
	if(S&1) c1++;if(S&2) c1++;if(S&4) c1++;
	if(S&8) c2++;if(S&16) c2++;if(S&32) c2++;
	if(S&64) c3++;if(S&128) c3++;if(S&256) c3++;
	if(c1>=2) c++;if(c2>=2) c++;if(c3>=2) c++;
	return c>=2;
}
Matrix A;
int main() {
	n=read();m=read();
	rep(i,1,m) {
		int u=read(),v=read();
		e[u][v]=e[v][u]=1;
	}
	rep(i,0,8) x[i]=read();s=read();
	dwn(S,511,0) {
		if(!check(S)) {
			rep(i,0,n) rep(j,0,n) A[i][j]=0;
			rep(i,0,n-1) {
				int j=0;
				rep(k,0,8) if(x[k]==i) j|=(1<<k);
				if(j&&(!(S&j))) {A[i][i]=1;A[i][n]=f[i][S|j];continue;}
				A[i][i]=1;A[i][n]=1;int cnt=0;
				rep(v,0,n-1) if(e[i][v]) cnt++;
				rep(v,0,n-1) if(e[i][v]) A[i][v]=-1.0/cnt;
			}
			gauss(A);
			rep(i,0,n-1) if(fabs(A[i][i])>eps) f[i][S]=A[i][n]/A[i][i];
		}
	}
	printf("%.3lf\n",f[s][0]);
	return 0;
}
