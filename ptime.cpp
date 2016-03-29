#include <iostream>
#include <algorithm>
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

int main(){
	ios::sync_with_stdio(false);
	bool isPrime[10001];
	int counter[10001];
	fill_n(counter, 10001, 0);
	fill_n(isPrime, 10001, true);
	generate_primes(isPrime, 10000);
	int num;
	cin>>num;
	for(int i=num;i>=2;i--){
		int temp = i;
		for(int j=2;j<=10000;j++){
			if(isPrime[j] == true){
				while(temp%j == 0){
					counter[j]++;
					temp = temp/j;
				}
			}
			if(temp == 1)
				break;
		}
	}
	bool first = true; 
	for(int i=0;i<=10000;i++){
		if(isPrime[i] == true && counter[i] != 0){
			if (first){
				cout<<i<<"^"<<counter[i]<<" ";
				first = false;
			}
			else{
				cout<<"* "<<i<<"^"<<counter[i]<<" ";
			}
		}
	}
	cout<<endl;
	return 0;
}