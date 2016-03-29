#include <iostream>
#include <algorithm>
#include <stdio.h>
#define llt long long int
#define ld long double
using namespace std;

ld pi = 3.14159265358979323846264338327950;
ld binary_search(ld areas[], int n, int f){
	ld start = 0;
	ld end = areas[n-1];
	while(end - start >= 10e-5){
		int temp = 0;
		ld mid = (end+start)/2;
		for(int i=0;i<n;i++){
			temp += (int) (areas[i]/mid);	
		}
		if(temp >= f)
			start = mid;
		else
			end = mid;
	}
	return start;
}

int main(){
	ios::sync_with_stdio(false);
	llt t;
	cin>>t;
	while(t--){
		int n,f;
		cin>>n>>f;
		f++;
		ld areas[n];
		for(int i=0;i<n;i++){
			cin>>areas[i];
			areas[i] *= (areas[i]*pi);
		}
		sort(areas, areas+n);
		printf("%.4Lf\n",binary_search(areas, n, f));
	}
	return 0;
}