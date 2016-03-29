#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct pos{
	int i;
	int j;
};

typedef struct pos Pos;

map<char, struct pos> my_map;
int main(){
	ios::sync_with_stdio(false);
	my_map['S'].i = 1;
	my_map['S'].j = 0;
	my_map['E'].i = 0;
	my_map['E'].j = 1;
	my_map['N'].i = -1;
	my_map['N'].j = 0;
	my_map['W'].i = 0;
	my_map['W'].j = -1;
	int n,m;
	cin>>n>>m;
	int num[n][m];
	bool counted[n][m];
	char dirs[n][m];
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		for(int j=0;j<m;j++){
			dirs[i][j] = temp[j];
			num[i][j] = 0;
			counted[i][j] = false;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(num[i][j] == 0){
				stack<Pos> s;
				Pos cur_pos;
				cur_pos.i = i;
				cur_pos.j = j;
				while(!counted[cur_pos.i][cur_pos.j] && num[cur_pos.i][cur_pos.j] == 0){
					s.push(cur_pos);
					counted[cur_pos.i][cur_pos.j] = true;
					// cout<<"counting: "<<cur_pos.i<<" "<<cur_pos.j<<endl;
					Pos temp;
					temp.i = cur_pos.i + my_map[dirs[cur_pos.i][cur_pos.j]].i;
					temp.j = cur_pos.j + my_map[dirs[cur_pos.i][cur_pos.j]].j;
					cur_pos = temp;
				}
				if(num[cur_pos.i][cur_pos.j] != 0){
					while(!s.empty()){
						Pos temp = s.top();
						s.pop();
						num[temp.i][temp.j] = num[cur_pos.i][cur_pos.j];
					}
				}
				else{
					ans++;
					while(!s.empty()){
						Pos temp = s.top();
						s.pop();
						num[temp.i][temp.j] = ans;
					}
				}	
			}

		}
	}
	cout<<ans<<endl;
	return 0;
}