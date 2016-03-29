#include <iostream>
#include <queue>
using namespace std;

struct str{
	int i;
	int j;
};

int main(){
	ios::sync_with_stdio(false);
	int t;
	int cost[8][8];
	cin>>t;
	int temp = t;
	while(t--){
		// cout<<"..."<<endl;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cost[i][j] = -1;
			}
		}
		int start_i, start_j, end_i, end_j;
		char a[2], b[2];
		cin>>a>>b;
		t = --temp;
		start_i = (int)(a[1]-'1');
		start_j = (int)(a[0]-'a');
		end_i = (int)(b[1]-'1');
		end_j = (int)(b[0]-'a');
		struct str cur_pos;
		cur_pos.i = start_i;
		cur_pos.j = start_j;
		cost[start_i][start_j] = 0;
		bool ans = false;
		int final_cost = 0;
		queue<struct str>q;
		q.push(cur_pos);
		while(true){
			cur_pos = q.front();
			if(cur_pos.i == end_i && cur_pos.j == end_j){
				final_cost = cost[cur_pos.i][cur_pos.j];
				break;
			}
			q.pop();
			struct str temp;
			if(cur_pos.i-1 >=0 && cur_pos.j-2 >=0){
				if(cost[cur_pos.i-1][cur_pos.j-2] == -1 || cost[cur_pos.i-1][cur_pos.j-2] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i-1;
					temp.j = cur_pos.j-2;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}

			}
			if(cur_pos.i+1 < 8 && cur_pos.j-2 >=0){
				if(cost[cur_pos.i+1][cur_pos.j-2] == -1 || cost[cur_pos.i+1][cur_pos.j-2] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i+1;
					temp.j = cur_pos.j-2;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}				
			}
			if(cur_pos.i-2 >=0 && cur_pos.j-1 >=0){
				if(cost[cur_pos.i-2][cur_pos.j-1] == -1 || cost[cur_pos.i-2][cur_pos.j-1] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i-2;
					temp.j = cur_pos.j-1;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}
			}
			if(cur_pos.i+2 < 8 && cur_pos.j-1 >=0){
				if(cost[cur_pos.i+2][cur_pos.j-1] == -1 || cost[cur_pos.i+2][cur_pos.j-1] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i+2;
					temp.j = cur_pos.j-1;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}
			}
			if(cur_pos.i-2 >=0 && cur_pos.j+1 < 8){
				if(cost[cur_pos.i-2][cur_pos.j+1] == -1 || cost[cur_pos.i-2][cur_pos.j+1] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i-2;
					temp.j = cur_pos.j+1;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}
			}
			if(cur_pos.i+2 < 8 && cur_pos.j+1 < 8){
				if(cost[cur_pos.i+2][cur_pos.j+1] == -1 || cost[cur_pos.i+2][cur_pos.j+1] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i+2;
					temp.j = cur_pos.j+1;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}
			}
			if(cur_pos.i-1 >=0 && cur_pos.j+2 < 8){
				if(cost[cur_pos.i-1][cur_pos.j+2] == -1 || cost[cur_pos.i-1][cur_pos.j+2] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i-1;
					temp.j = cur_pos.j+2;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}
			}
			if(cur_pos.i+1 < 8 && cur_pos.j+2 < 8){
				if(cost[cur_pos.i+1][cur_pos.j+2] == -1 || cost[cur_pos.i+1][cur_pos.j+2] > cost[cur_pos.i][cur_pos.j]){
					temp.i = cur_pos.i+1;
					temp.j = cur_pos.j+2;
					cost[temp.i][temp.j] = cost[cur_pos.i][cur_pos.j]+1;
					q.push(temp);
				}
			}
		}
		cout<<final_cost<<endl;
	}
	return 0;
}