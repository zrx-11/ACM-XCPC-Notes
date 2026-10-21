#include<cstdio>
#include<cctype>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ren for(int i=first[x];i;i=nxt[i])
using namespace std;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=160010;
const int maxnode=20000010;
int n,L,m,A[maxn],ans[maxn];
int first[maxn<<2],nxt[maxnode],num[maxnode],ql[maxnode],qr[maxnode],ToT;
void AddQuery(int pos,int l,int r,int id) {
    num[++ToT]=id;ql[ToT]=l;qr[ToT]=r;nxt[ToT]=first[pos];first[pos]=ToT;
}
int f[maxn],g[maxn],S[maxn];
void solve(int x,int l,int r) {
    if(r-l+1<L) return;
    int mid=l+r>>1,lc=x<<1,rc=lc|1;
    ren {
        if(qr[i]<=mid) AddQuery(lc,ql[i],qr[i],num[i]);
        else if(ql[i]>mid) AddQuery(rc,ql[i],qr[i],num[i]);
        else if(ql[i]!=l||qr[i]!=r) AddQuery(lc,ql[i],mid,num[i]),AddQuery(rc,mid+1,qr[i],num[i]);
    }
    rep(p,max(l,mid-L+1),mid) {
        f[p-1]=g[p]=0;
        rep(i,p,r) {
            if(i-p+1<L) f[i]=0;
            else f[i]=max(f[i-1],f[i-L]+(S[i]-S[i-L]));
        }
        dwn(i,p-1,l) {
            if(p-i<L) g[i]=0;
            else g[i]=max(g[i+1],g[i+L]+(S[L+i-1]-S[i-1]));
        }
        ren if(qr[i]>=p&&ql[i]<=p) ans[num[i]]=max(ans[num[i]],f[qr[i]]+(ql[i]<p?g[ql[i]]:0));
    }
    if(l<r) solve(lc,l,mid),solve(rc,mid+1,r);
}
int main() {
    n=read();L=read();
    rep(i,1,n) S[i]=S[i-1]+(A[i]=read());
    m=read();
    rep(i,1,m) {
        int l=read(),r=read();
        if(l<=r) AddQuery(1,l,r,i);
    }
    solve(1,1,n);
    rep(i,1,m) printf("%d\n",ans[i]);
    return 0;
}
