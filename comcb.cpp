#include <iostream>
#include <stack>
using namespace std;

int sum,r,c;
bool visited[26][26];
stack<int> seq_i;
stack<int> seq_j;

bool solve(int i, int j, int index){
	if(i < 0 || i>=r || j<0 || j >= c || visited[i][j])
		return false;
	if(index == sum){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	visited[i][j] = true;
	if(solve(i-1, j-2, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i+1, j-2, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i-2, j-1, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i+2, j-1, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i-2, j+1, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i+2, j+1, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i-1, j+2, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	else if(solve(i+1, j+2, index+1)){
		seq_i.push(i);
		seq_j.push(j);
		return true;
	}
	visited[i][j] = false;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				visited[i][j] = false;
			}
		}
		cin>>r>>c;
		sum = r*c;
		bool ans = false;
		for(int i=0;i<c && !ans;i++){
			for(int j=0;j<r && !ans;j++){
				if(solve(j,i,1)){
					ans = true;
				}
			}
		}
		if(ans){
			while(!seq_i.empty()){
				cout<<(char)(seq_j.top()+'A')<<seq_i.top()+1;
				seq_i.pop();
				seq_j.pop();
			}
			cout<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
	return 0;
}