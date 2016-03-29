#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void generate_non_cubes(bool isNonCube[], int len){
	isNonCube[0]=false;
	for(int i=2;i<=100;i++){
		if(isNonCube[i]==true){
			int temp = i*i*i;
			if(isNonCube[temp] == true){
				// int factor = 1;
				for(int j=temp;j<=len;j=j+temp){
					isNonCube[j] = false;
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
	bool isNonCube[1000001];
	fill_n(isNonCube, 1000001, true);
	generate_non_cubes(isNonCube, 1000000);
	// for(int i=0;i<=40;i++)
	// 	cout<<isNonCube[i]<<endl;
	int pos[1000001] = {0};
	for(int i=1;i<=1000000;i++){
		if(isNonCube[i])
			pos[i] = pos[i-1]+1;
		else
			pos[i] = pos[i-1];
	}
	// for(int i=1;i<=100000;i++){
	// 	if(isNonSquare[i] == true){
	// 		int temp = i;
	// 		while(temp != 0){
	// 			contains[i][temp%10] = contains[i-1][temp%10] + 1 ;
	// 			temp /= 10;
	// 		}
	// 		for(int j=0;j<10;j++){
	// 			if(contains[i][j]==0){
	// 				contains[i][j] = contains[i-1][j];
	// 			}
	// 		}
	// 	}
	// 	else{
	// 		for(int j=0;j<10;j++)
	// 			contains[i][j] = contains[i-1][j];
	// 	}
	// }
	// for(int i=0;i<=40;i++){
	// 	cout<<i<<": ";
	// 	for(int j=0;j<10;j++){
	// 		cout<<contains[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int num = 0;
	for(int i=1;i<=t;i++){
		cin>>num;
		if(isNonCube[num])
			cout<<"Case "<<i<<": "<<pos[num]<<endl;
		else
			cout<<"Case "<<i<<": Not Cube Free"<<endl;
	}
	return 0;
}