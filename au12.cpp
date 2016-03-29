#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
#define llt long long int
using namespace std;

void generate_primes(bool isPrime[], int len){
	isPrime[1]=false;
	isPrime[0]=false;
	for(int i=2;i<=sqrt(len);i++){
		if(isPrime[i]==true){
			for(int j=i*i;j<=len;j=j+i){
				isPrime[j]=false;
			}
		}
	}
}

llt find_greater_prime(llt num, vector<int> &primes){
	num++;
	bool ans_found;
	if(num < primes[primes.size()-1]){
		for(llt i=num;i<=INT_MAX;i++){
			ans_found = true;
			for(int j=0;j<=primes.size() && primes[j] <= sqrt(i);j++){
				if(i%primes[j] == 0){
					ans_found = false;
					break;
				}
			}
			if(ans_found == true){
				return i;
			}
		}
	}
	else{
		while(true){
			ans_found = true;
			for(llt i=2;i<= sqrt(num);i++){
				if(num % i == 0){
					ans_found = false;
					num++;
					break;
				}
			}
			if(ans_found == true)
				return num;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	bool isPrime[31624];
	fill_n(isPrime, 31624, true);
	vector <int> primes;
	generate_primes(isPrime, 31623);
	for(int i=0;i<=31623;i++){
		if(isPrime[i] == true)
			primes.push_back(i);
	}
	// for(int i=0;i<primes.size();i++){
	// 	cout<<primes[i]<<" ";
	// }
	// cout<<endl;
	int t;
	cin>>t;
	while(t--){
		llt n;
		cin>>n;
		cout<<find_greater_prime(n, primes)<<endl;
	}
}