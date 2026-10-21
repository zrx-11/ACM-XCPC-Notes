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
const int maxn=35;
const int mod=998244353;
int qpow(int n,int m) {
	int ans=1;
	for(;m;m>>=1,n=(ll)n*n%mod) if(m&1) ans=(ll)ans*n%mod;
	return ans;
}
typedef int Matrix[maxn][maxn];
int gauss(int n,Matrix A) {
	int ans=1;
	rep(i,1,n) {
		int r=i;
		rep(j,i+1,n) if(A[j][i]) r=j;
		if(r!=i) swap(A[i],A[r]),ans*=-1;
		int inv=qpow(A[i][i],mod-2);
		rep(k,i+1,n) {
			int tmp=(ll)A[k][i]*inv%mod;
			rep(j,i,n) (A[k][j]+=mod-(ll)tmp*A[i][j]%mod)%=mod;
		}
	}
	rep(i,1,n) ans=(ll)ans*A[i][i]%mod;
	return (ans+mod)%mod;
}
int n,k,T[maxn*maxn],y[maxn*maxn];
int fac[maxn*maxn],ifac[maxn*maxn],Inv[maxn*maxn];
Matrix w,A; 
struct Poly {
	int n,A[maxn*maxn];
	Poly() {n=1;memset(A,0,sizeof(A));}
	Poly operator + (const Poly& b) const {
		Poly c;c.n=max(n,b.n);
		rep(i,0,c.n-1) c.A[i]=(A[i]+b.A[i])%mod;
		return c;
	}
	Poly operator * (const Poly& b) const {
		Poly c;c.n=n+b.n-1;
		rep(i,0,n-1) rep(j,0,b.n-1) (c.A[i+j]+=(ll)A[i]*b.A[j]%mod)%=mod;
		return c;
	}
	Poly operator / (const Poly& b) const {
		Poly c;c=*this;c.n=n-b.n+1;
		dwn(i,n-1,0) if(c.A[i+1]) {
			T[i]=c.A[i+1];
			rep(j,0,b.n-1) (c.A[i+j]+=mod-(ll)c.A[i+1]*b.A[j]%mod)%=mod;
		}
		else T[i]=0;
		rep(i,0,n-1) c.A[i]=T[i];
		return c;
	}
	void print() {
		dwn(i,n-1,0) printf("+ %d x^%d",A[i],i);puts("");
	}
};
int main() {
	n=read();k=read();
	rep(i,1,n) rep(j,1,n) w[i][j]=read();
	Inv[0]=Inv[1]=fac[0]=ifac[0]=1;
	rep(i,2,n*k) Inv[i]=(ll)(mod-mod/i)*Inv[mod%i]%mod;
	rep(i,1,n*k) fac[i]=(ll)fac[i-1]*i%mod;
	rep(i,1,n*k) ifac[i]=(ll)ifac[i-1]*Inv[i]%mod;
	rep(x,0,n*k) {
		memset(A,0,sizeof(A));
		rep(i,1,n) rep(j,1,n) if(i!=j) {
			int pw=1,base=(ll)w[i][j]*x%mod;
			rep(t,0,k) {
				(A[i][j]+=(ll)pw*ifac[t]%mod)%=mod;
				pw=(ll)pw*base%mod;
			}
		}
		rep(i,1,n) rep(j,1,n) if(i!=j) (A[i][i]+=A[i][j])%=mod,A[i][j]=mod-A[i][j];
		y[x]=gauss(n-1,A);
	}
	Poly ans,tq;
	Poly eq,tmp;
	eq.A[0]=1;          
	tmp.n=2;tmp.A[1]=1;  
	rep(i,0,n*k) {
		tmp.A[0]=mod-i;
		eq=eq*tmp;
	}
	rep(x,0,n*k) {
		tmp.A[0]=mod-x;
		tq=eq/tmp;
		int v=1;
		rep(i,0,n*k) if(i!=x) v=(ll)v*(mod+x-i)%mod;
		v=(ll)qpow(v,mod-2)*y[x]%mod;
		rep(i,0,eq.n-1) tq.A[i]=(ll)tq.A[i]*v%mod;
		ans=ans+tq;
	}
	printf("%d\n",(ll)ans.A[k]*fac[k]%mod);
	return 0;
}
