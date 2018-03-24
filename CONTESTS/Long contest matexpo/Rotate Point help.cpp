#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);

			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			assert(cnt>0);
			if(is_neg){
				x= -x;
			}
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}


long long mod=1000000007;
struct mat{
	long long a[3][3];
	mat(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a[i][j] = 0;
			}
		}
	}
};

mat mul(mat a,mat b){
	mat ret;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				ret.a[i][j]  += a.a[i][k] * b.a[k][j];
			}
			ret.a[i][j] %= mod;
		}
	}
	return ret;
}


int n;
int q;
int x[200200];
int y[200200];
int a[200200];

mat getMat(int ind){
	int S,C;
	if(a[ind] == 0){
		S=0;
		C=1;
	} else if(a[ind] == 90){
		S=1;
		C=0;
	}  else if(a[ind] == 180){
		S=0;
		C=-1;
	} else {
		S=-1;
		C=0;
	}
	mat ret;
	ret.a[0][0]= C;ret.a[0][1]= S;ret.a[0][2]= 0;
	ret.a[1][0]= -S;ret.a[1][1]= C;ret.a[1][2]= 0;
	ret.a[2][0]= (y[ind] * S - x[ind] * C + x[ind])% mod;ret.a[2][1]= (y[ind] - x[ind] * S -y[ind] * C)%mod;ret.a[2][2]= 1;
	return ret;
}


mat sgt[800800];

void build(int nd,int l,int r){
	if(l==r){
		sgt[nd] = getMat(l);
		return;
	}
	int mid=(r+l)/2;
	build(2*nd,l,mid);
	build(2*nd+1,mid+1,r);
	sgt[nd]=mul(sgt[2*nd],sgt[2*nd+1]);
}

void update(int nd,int l,int r,int ind){
	if(l==r){
		sgt[nd] = getMat(l);
		return;
	}
	int mid=(r+l)/2;
	if(ind<=mid)
		update(2*nd,l,mid,ind);
	else
		update(2*nd+1,mid+1,r,ind);
	sgt[nd]=mul(sgt[2*nd],sgt[2*nd+1]);
}

mat query(int nd,int l,int r,int s,int e){
	if(s<=l && r<=e){
		return sgt[nd];
	}
	int mid=(r+l)/2;
	mat ret;
	bool f=false;
	if(s<=mid){
		f=true;
		ret= query(2*nd,l,mid,s,e);
	}
	if(mid+1<=e){
		if(f){
			ret= mul(ret,query(2*nd+1,mid+1,r,s,e));
		} else {
			ret= query(2*nd+1,mid+1,r,s,e);
		}
	}
	return ret;
}

void print(long long a[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%lld ",a[i][j]);
        puts("");
    }
    puts("");
}

int main(){
	n=readIntLn(1,100000);
	for(int i=1;i<=n;i++){
		x[i]=readIntSp(0,1000000000);
		y[i]=readIntSp(0,1000000000);
		a[i]=readIntLn(0,360-1);
		assert(a[i] % 90 ==0);
	}
	build(1,1,n);

	print(sgt[4].a);
	print(sgt[5].a);
	print(sgt[2].a);

	q=readIntLn(1,200000);
	while(q--){
		int ty;
		ty=readIntSp(1,2);
		if(ty==1){
			int x,y,l,r;
			x=readIntSp(0,1000000000);
			y=readIntSp(0,1000000000);
			l=readIntSp(1,n);
			r=readIntLn(l,n);
			mat g=query(1,1,n,l,r);
			printf("%lld %lld\n",(((x * g.a[0][0] + y * g.a[1][0] + g.a[2][0])% mod) + mod) % mod,((( x * g.a[0][1] + y * g.a[1][1] + g.a[2][1])% mod ) + mod ) % mod);
		} else {
			int u,xx,yy,aa;
			u=readIntSp(1,n);
			xx=readIntSp(0,1000000000);
			yy=readIntSp(0,1000000000);
			aa=readIntLn(0,360-1);
			assert(aa % 90 ==0);
			x[u]=xx;
			y[u]=yy;
			a[u]=aa;
			update(1,1,n,u);
		}
	}
	assert(getchar()==-1);
}
