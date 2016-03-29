#include <iostream>
#include <stack>
#define llt unsigned long long int
using namespace std;

llt find_max_area(llt heights[], int len){
	// for(int i=0;i<len;i++){
	// 	cout<<heights[i]<<" ";
	// }
	// cout<<endl;
	stack<int> s;
	int i=0;
	llt max_area = 0;
	while(i<len){
		if(s.empty() || heights[i] >= heights[s.top()]){
			s.push(i);
			// cout<<"pushing "<<s.top()<<endl;
			i++;
		}
		else{
			int cur_pos = s.top();
			s.pop();
			// cout<<"popping out :"<<cur_pos<<endl;
			llt cur_area = heights[cur_pos] * (s.empty() ? i : i - s.top() - 1);
			// cout<<"area for popped hist "<<cur_pos<<" is "<<cur_area<<" with i : "<<i<<endl;
			if(cur_area > max_area)
				max_area = cur_area;  
		}
	}
	while(!s.empty()){
		int cur_pos = s.top();
		// cout<<"popping out :"<<cur_pos<<endl;
		s.pop();
		llt cur_area = heights[cur_pos] * (s.empty() ? i : i - s.top() - 1);
		// cout<<"area for popped hist "<<cur_pos<<" is "<<cur_area<<" with i : "<<i<<endl;
		if(cur_area > max_area)
			max_area = cur_area;	
	}
	return max_area;
}

int main(){
	ios::sync_with_stdio(false);
	int n = 1;
	while(n){
		cin>>n;
		if(n!=0){
			llt heights[n];
			for(int i=0;i<n;i++){
				cin>>heights[i];
			}
			cout<<find_max_area(heights, n)<<endl;
		}
	}
	return 0;
}













































































