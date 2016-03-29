#include <iostream>
#include <math.h>
#define len 32000
using namespace std;
void generate_primes(bool isPrime[], int limit){
	isPrime[1]=false;
	isPrime[0]=false;
	for(int i=3;i<=sqrt(limit);i=i+2){
		if(isPrime[i]==true){
			for(int j=i*i;j<=limit;j=j+i){
				isPrime[j]=false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int a,b,n;
	bool isPrime[len+1];
	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;
	for (int i=3;i<=len;i=i+2){
		isPrime[i] = true;
	}
	for (int i=4;i<=len;i=i+2){
		isPrime[i] = false;
	}
	int ans, final_ans;
	final_ans = 0;
	generate_primes(isPrime, len);
	cin>>a>>b>>n;
	int counter, temp;
	for(int i=a;i<=b;i++){
		ans = 1;
		if(i==1){
			if(n==1){
				final_ans++;
			}
			continue;
		}
		temp = i;
		for(int j=2;j<=len;j++){
			counter = 0;
			if (isPrime[j]==true && temp%j==0){
				while(temp!=1 && temp%j==0){
					temp = temp/j;
					counter++; 
				}
				if(temp == 1){
					ans = ans*(counter+1);
					break;
				}
				else{
					ans = ans*(counter+1);
				}
			}
		}
		if(ans == n){
			final_ans++;
		}
	}
	cout<<final_ans<<endl;
	return 0;
}