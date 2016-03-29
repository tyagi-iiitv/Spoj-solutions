#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void generate_non_squares(bool isNonSquare[], int len){
	isNonSquare[0]=false;
	for(int i=2;i<=sqrt(len);i++){
		if(isNonSquare[i]==true){
			int temp = i*i;
			if(isNonSquare[temp] == true){
				// int factor = 1;
				for(int j=temp;j<=len;j=j+temp){
					isNonSquare[j] = false;
				}
				// while(temp*factor<=len){
				// 	// cout<<"..."<<temp*factor<<endl;
				// 	isNonSquare[temp*factor] = false;
				// 	factor++;
				// }
			}
		}
		// else{
		// 	for(int j=i*2;j<=len;j=j+i)
		// 		isNonSquare[j] = false;
		// }
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	bool isNonSquare[100001];
	fill_n(isNonSquare, 100001, true);
	generate_non_squares(isNonSquare, 100000);
	int contains[100001][10] = {0};
	for(int i=1;i<=100000;i++){
		if(isNonSquare[i] == true){
			int temp = i;
			while(temp != 0){
				contains[i][temp%10] = contains[i-1][temp%10] + 1 ;
				temp /= 10;
			}
			for(int j=0;j<10;j++){
				if(contains[i][j]==0){
					contains[i][j] = contains[i-1][j];
				}
			}
		}
		else{
			for(int j=0;j<10;j++)
				contains[i][j] = contains[i-1][j];
		}
	}
	// for(int i=0;i<=40;i++){
	// 	cout<<i<<": ";
	// 	for(int j=0;j<10;j++){
	// 		cout<<contains[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	while(t--){
		int a,b, digit;
		cin>>a>>b>>digit;
		cout<<contains[b][digit]-contains[a-1][digit]<<endl;
	}
	return 0;
}