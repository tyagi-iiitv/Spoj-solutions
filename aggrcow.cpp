#include <iostream>
#include <algorithm>
#include <climits>
#define llt long long int
using namespace std;

bool possible(int stalls[], int value, int len, int cows){
	cows--;
	int i = 1;
	// if(value == 7){
	// 	for(int k=0;k<len;k++){
	// 		cout<<stalls[k]<<endl;
	// 	}
	// }
	while(i<len && cows > 0){
		if(stalls[i]-stalls[i-1] >= value){
			// cout<<stalls[i-1]<<" and "<<stalls[i]<<" have two cows"<<endl;
			cows--;
			i++;
		}
		else{
			int j=i+1;
			while(j<len && stalls[j] - stalls[i-1] < value){
				j++;
			}
				// cout<<stalls[i-1]<<" and "<<stalls[j]<<" have two cows"<<endl;
			if(j<len)
				cows--;
			i = j+1;
		}
	}
	if(cows == 0)
		return true;
	else
		return false;
}

int binary_search(int stalls[], int n, int cows){  //we stop when we find cost_mid is less than cost_next and cost_prev
	int min = 0;
	int max = INT_MAX;
	while(min<max){
		int mid = (max+min)/2;
		bool possible_mid = possible(stalls, mid, n, cows);
		bool possible_next = possible(stalls, mid+1, n, cows);
		if(possible_mid && !possible_next){
			// cout<<min<<" "<<mid<<" "<<max<<" "<<possible_mid<<" "<<possible_next<<endl;
			return mid;
		}
		else if(possible_mid && possible_next){
			// cout<<min<<" "<<mid<<" "<<max<<" "<<possible_mid<<" "<<possible_next<<endl;
			min = mid;
		}
		else{
			// cout<<min<<" "<<mid<<" "<<max<<" "<<possible_mid<<" "<<possible_next<<endl;
			max = mid;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	llt t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		int stalls[n];
		for(int i=0;i<n;i++){
			cin>>stalls[i];
		}
		sort(stalls, stalls+n);
		cout<<binary_search(stalls, n, c)<<endl;
	}
	return 0;
}