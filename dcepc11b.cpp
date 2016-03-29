#include <iostream>
#define llt long long int
using namespace std;

llt mode_calculator(llt a, llt b, llt m){
	llt x=1, y=a;
	while(b>0){
		if(b&1){
			x = (x*y)%m;		
		}
		y = (y*y)%m;
		b>>=1;
	}
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		llt n,p;
		cin>>n>>p;
		if(n>=p)
			cout<<"0"<<endl;
		else{
			llt result = -1;
			for(int i=n+1;i<p;i++){
				llt output = mode_calculator(i,p-2,p);
				result = (result*output)%p;
			}
			cout<<result+p<<endl;
		}
	}
	return 0;
}