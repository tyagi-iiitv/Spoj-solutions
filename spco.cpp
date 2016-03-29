#include <iostream>
#define llt unsigned long long int
using namespace std;

void fill_ncr(llt ncr[][65]){
	for(int i=0;i<65;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i){
				ncr[i][j] = 1;
				continue;
			}
			ncr[i][j] = ncr[i-1][j-1]+ncr[i-1][j];
		}
	}
}

void fill_n_bits_prime(llt n_bits_prime[], llt ncr[][65], int primes[]){
	n_bits_prime[0]=n_bits_prime[1] = 0;
	n_bits_prime[2]=1;
	for(int bits=3;bits<65;bits++){
		llt result = 0;
		for(int j=0;primes[j]<=bits && j< 18;j++){
			result += ncr[bits-1][primes[j]-1];
		}
		n_bits_prime[bits] = result;
	}
}

int total_bits(llt num){
	int ans = 0;
	while(num){
		ans++;
		num >>=1;
	}
	return ans;
}

bool is_prime(llt num, int primes[]){
	int set_bits = 0;
	while(num){
		if(num&1)
			set_bits++;
		num >>= 1;
	}
	bool jump = false;
	for(int i=0;i<=18;i++){
		if(primes[i] == set_bits)
			jump = true;
	}
	return jump;
}

llt primes_less_than(llt num, llt ncr[][65], int num_bits, int primes[]){
	llt ans = 0;
	int bits = 1;
	llt temp = num;
	int ones_count = 0;
	while(temp){
		if(temp & 1)
			ones_count++;
		temp >>= 1;
	}
	temp = num;
	while(bits < num_bits){
		if(temp & 1){
			// if(num == 7){
			// 	cout<<ones_count<<" "<<bits<<" "<<temp<<" "<<primes[0]<<endl;
			// }
			ones_count--;
			for(int i=0;primes[i] <= num_bits && i<18;i++){
				int n = bits-1;
				int r = primes[i] - ones_count;
				if(n>=r && r>=0 && n>=0){
					ans += ncr[n][r];
					// cout<<"ncr["<<n<<"]["<<r<<"] ";
				}
				if(r > n)
					break;
				
			}
		}
		bits++;
		temp >>= 1;
	}
	// cout<<endl;
	ans += (is_prime(num, primes)?1:0);
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	int primes[18] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61	};
	llt ncr[65][65];
	fill_ncr(ncr);
	llt n_bits_prime[65];
	fill_n_bits_prime(n_bits_prime, ncr, primes);
	// for(llt i=1;i<=100;i++){
	// 	cout<<primes_less_than(i,ncr,total_bits(i),primes)<<endl;
	// }
	int t;
	cin>>t;
	while(t--){
		llt a,b;
		cin>>a>>b;
		int bits_a = total_bits(a);
		int bits_b = total_bits(b);
		llt ans = 0;
		if(bits_a == bits_b){
			llt ans_a = primes_less_than(a, ncr, bits_a, primes); //calculates the primes less than this number having the same number of bits
			llt ans_b = primes_less_than(b, ncr, bits_b, primes);
			ans = ans_b - ans_a + (is_prime(a, primes)?1:0); 
		}
		else{
			for(int i=bits_a+1;i<bits_b;i++)
				ans += n_bits_prime[i];
			llt ans_a = primes_less_than(a, ncr, bits_a, primes); //calculates the primes less than this number having the same number of bits
			llt ans_b = primes_less_than(b, ncr, bits_b, primes);
			// cout<<ans_a<<endl;
			// cout<<ans_b<<endl;
			ans += ans_b + (n_bits_prime[bits_a] - ans_a + is_prime(a, primes)?1:0);
		}
		cout<<ans<<endl;
	}
	return 0;
}