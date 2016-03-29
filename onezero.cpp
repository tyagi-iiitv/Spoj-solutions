#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		int cur_num = 1;
		int parent[num], value[num];
		fill_n(parent, num, -1);
		parent[1] = 0;
		value[1] = 1;
		queue<int> q;
		while(cur_num % num != 0){
			int cur_num_0 = (cur_num*10) % num;
			if(parent[cur_num_0] == -1){
				parent[cur_num_0] = cur_num;
				value[cur_num_0] = 0;
				q.push(cur_num_0);
				// cout<<"parent of "<<cur_num_0<<" is :"<<cur_num<<endl;
			}
			int cur_num_1 = (cur_num_0+1) % num;
			if(parent[cur_num_1] == -1){
				parent[cur_num_1] = cur_num;
				value[cur_num_1] = 1;
				q.push(cur_num_1);
				// cout<<"parent of "<<cur_num_1<<" is :"<<cur_num<<endl;
			}
			cur_num = q.front();
			// cout<<"popping: "<<cur_num<<endl;
			q.pop();
		}
		stack<int> s;
		while(parent[cur_num] != 0){
			s.push(value[cur_num]);
			cur_num = parent[cur_num];
		}
		cout<<"1";
		while(!s.empty()){
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
	}
	return 0;
}