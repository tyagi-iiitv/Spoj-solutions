#include <iostream>
#include <math.h>
#include <climits>
#define llt long long int
using namespace std;
// #define llt long long int

llt find_cost(int bricks[], int cost[], int n, int value){
	llt ans = 0;
	for(int i=0;i<n;i++){
		llt temp = abs(bricks[i]-value);
		temp = temp*cost[i];
		// cout<<temp<<endl;
		ans += temp;
	}
	return ans;
}

llt binary_search(int bricks[], int cost[], int n){
	int min = 0;
	int max = INT_MAX;
	llt ans = 0;
	while(max > min){
		int mid = (min + max)/2;
		llt cost_mid = find_cost(bricks, cost, n, mid);
		llt cost_next = find_cost(bricks, cost, n, mid+1);
		llt cost_prev = find_cost(bricks, cost, n, mid-1);
		// cout<<min<<" "<<mid<<" "<<max<<" "<<cost_mid<<" "<<cost_next<<" "<<cost_prev<<" "<<endl;
		if(cost_next > cost_mid)
			max = mid;
		else
			min = mid;
		if(cost_next == ans)
			break;
		else
			ans = cost_next;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int bricks[n], cost[n];
		for(int i=0;i<n;i++){
			cin>>bricks[i];
		}
		for(int i=0;i<n;i++){
			cin>>cost[i];
		}
		cout<<binary_search(bricks, cost, n)<<endl;
	}
	return 0;
}