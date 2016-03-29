#include <iostream>
#include <stack> 
#include <algorithm>
using namespace std;

struct str{
	int i;
	int j;
	int tree_no;
	bool next_dir; //left = false and right = true	
};

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	char input[202][202];
	int visited[202][202];	
	while(t--){
		int r,c;
		cin>>r>>c;
		for(int i=0;i<r+2;i++){
			input[i][0] = '#';
			input[i][c+1] = '#';
		}
		for(int i=0;i<c+2;i++){
			input[0][i] = '#';
			input[r+1][i] = '#';
		}
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>input[i][j];
				visited[i][j] = 0;
			}
		}
		struct str cur_pos;
		cur_pos.i = 1;
		cur_pos.j = 1;
		int ans = 0;
		cur_pos.next_dir = true;
		stack<struct str> s;
		visited[1][1] = (input[1][1] == 'T'?1:0);
		cur_pos.tree_no = visited[1][1];
		s.push(cur_pos);
		while(!s.empty()){
			cur_pos = s.top();
			s.pop();
			if(visited[cur_pos.i][cur_pos.j] > cur_pos.tree_no)
				continue;
			visited[cur_pos.i][cur_pos.j] = cur_pos.tree_no;
			ans = max(ans, cur_pos.tree_no);
			struct str temp;
			if(cur_pos.next_dir){
				if(input[cur_pos.i+1][cur_pos.j] == 'T'){
					temp.i = cur_pos.i+1;
					temp.j = cur_pos.j;
					temp.next_dir = false;
					temp.tree_no = cur_pos.tree_no + 1;
					s.push(temp);
				}
				else if(input[cur_pos.i+1][cur_pos.j] == '0'){
					temp.i = cur_pos.i+1;
					temp.j = cur_pos.j;
					temp.next_dir = false;
					temp.tree_no = cur_pos.tree_no;
					s.push(temp);
				}
				if(input[cur_pos.i][cur_pos.j+1] == 'T'){
					temp.i = cur_pos.i;
					temp.j = cur_pos.j + 1;
					temp.next_dir = true;
					temp.tree_no = cur_pos.tree_no + 1;
					s.push(temp);
				}
				else if(input[cur_pos.i][cur_pos.j+1] == '0'){
					temp.i = cur_pos.i;
					temp.j = cur_pos.j + 1;
					temp.next_dir = true;
					temp.tree_no = cur_pos.tree_no;
					s.push(temp);
				}
			}
			if(!cur_pos.next_dir){
				if(input[cur_pos.i+1][cur_pos.j] == 'T'){
					temp.i = cur_pos.i+1;
					temp.j = cur_pos.j;
					temp.next_dir = true;
					temp.tree_no = cur_pos.tree_no + 1;
					s.push(temp);
				}
				else if(input[cur_pos.i+1][cur_pos.j] == '0'){
					temp.i = cur_pos.i+1;
					temp.j = cur_pos.j;
					temp.next_dir = true;
					temp.tree_no = cur_pos.tree_no;
					s.push(temp);
				}
				if(input[cur_pos.i][cur_pos.j-1] == 'T'){
					temp.i = cur_pos.i;
					temp.j = cur_pos.j - 1;
					temp.next_dir = false;
					temp.tree_no = cur_pos.tree_no + 1;
					s.push(temp);
				}
				else if(input[cur_pos.i][cur_pos.j-1] == '0'){
					temp.i = cur_pos.i;
					temp.j = cur_pos.j - 1;
					temp.next_dir = false;
					temp.tree_no = cur_pos.tree_no;
					s.push(temp);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}