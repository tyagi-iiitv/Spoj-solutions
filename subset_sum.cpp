#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int test;
	cin>>test;
	while(test--){
		int len; 
		cin>>len;
		int value[len];
		int sum = 0;
		for(int i=0;i<len;i++){
			cin>>value[i];
			sum += value[i];
		}
		static bool result[100][100000];
		for(int i=0;i<len;i++){
			for(int j=0;j<=sum;j++){
				if(i==0){
					if(j==value[0])
						result[i][j] = true;
					else
						result[i][j] = false;
				}
				else{
					if(j<value[i])
						result[i][j] = result[i-1][j];
					else if(j==value[i] || result[i-1][j] == true || result[i-1][j-value[i]] == true)
						result[i][j] = true;
					else{
						result[i][j] = false;
					}
				}
			}
		}
		long long int ans = 0;
		for(int i=0;i<=sum;i++){
			if(result[len-1][i] == true)
				ans += i;
		}
		cout<<ans<<endl;
	}
	return 0;
}