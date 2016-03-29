#include <iostream>
#include <queue>
using namespace std;

struct str{
	int i;
	int j;
	int k;
	int dist;
};

int found_blue(int k){
	return k | 1 ;
}
int found_yellow(int k){
	return k | 2;
}
int found_red(int k){
	return k | 4;
}
int found_green(int k){
	return k | 8;
}

bool contains_blue(int k){
	if((k & 1) == 1)
		return true;
	else
		false;
}
bool contains_yellow(int k){
	if((k & 2) == 2)
		return true;
	else
		false;
}
bool contains_red(int k){
	if((k & 4) == 4)
		return true;
	else
		false;
}

bool contains_green(int k){
	if((k & 8) == 8)
		return true;
	else
		false;
}

bool check(struct str cur_state, char next_state){
	if(next_state == '#')
		return false;
	else if(next_state == 'B')
		return contains_blue(cur_state.k);
	else if(next_state == 'Y')
		return contains_yellow(cur_state.k);
	else if(next_state == 'R')
		return contains_red(cur_state.k);
	else if(next_state == 'G')
		return contains_green(cur_state.k);
	else
		return true;
}

int update(struct str cur_state, char next_state){
	if(cur_state.k == 15)
		return cur_state.k;
	else if(next_state == 'b')
		return found_blue(cur_state.k);
	else if(next_state == 'y')
		return found_yellow(cur_state.k);
	else if(next_state == 'r')
		return found_red(cur_state.k);
	else if(next_state == 'g')
		return found_green(cur_state.k);
	else
		return cur_state.k;
}

int main(){
	ios::sync_with_stdio(false);
	int r,c;
	cin>>r>>c;
	while(r!=0){
		char mat[102][102];
		for(int i=0;i<=c+1;i++){
			mat[0][i] = '#';
			mat[r+1][i] = '#';
		}
		for(int i=0;i<=r+1;i++){
			mat[i][0] = '#';
			mat[i][c+1] = '#';
		}
		int cur_i, cur_j;
		int cur_k = 0;
		int cur_dist = 0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>mat[i][j];
				if(mat[i][j] == '*'){
					cur_i = i;
					cur_j = j;
					mat[i][j] = '.';
				}
			}
		}
		struct str cur_state;
		cur_state.i = cur_i;
		cur_state.j = cur_j;
		cur_state.k = cur_k;
		cur_state.dist = cur_dist;
		bool visited[102][102][16];
		for(int i=0;i<=r+1;i++){
			for(int j=0;j<=c+1;j++){
				for(int k=0;k<16;k++){
					visited[i][j][k] = false;
				}
			}
		}
		queue<struct str>q;
		q.push(cur_state);
		while(!q.empty() && mat[cur_state.i][cur_state.j] != 'X'){
			cur_state = q.front();
			// cout<<"popping: "<<mat[cur_state.i][cur_state.j]<<" with keys: "<<cur_state.k<<endl;
			q.pop();
			if(!visited[cur_state.i][cur_state.j][cur_state.k]){
				// cout<<"Entering not visisted"<<endl;
				visited[cur_state.i][cur_state.j][cur_state.k] = true;
				// cout<<"checking with :"<<mat[cur_state.i-1][cur_state.j]<<endl;
				if(check(cur_state, mat[cur_state.i - 1][cur_state.j])){ //checks for # and keys door combination
					// cout<<"Got true"<<endl;
					struct str next_state;
					next_state.k = update(cur_state, mat[cur_state.i - 1][cur_state.j]); // updates the distance and other values
					next_state.i = cur_state.i - 1;
					next_state.j = cur_state.j;
					next_state.dist = cur_state.dist + 1;
					q.push(next_state);
				}
				// cout<<"checking with :"<<mat[cur_state.i+1][cur_state.j]<<endl;
				if(check(cur_state, mat[cur_state.i + 1][cur_state.j])){ //checks for # and keys door combination
					// cout<<"Got true"<<endl;
					struct str next_state;
					next_state.k = update(cur_state, mat[cur_state.i + 1][cur_state.j]); // updates the distance and other values
					next_state.i = cur_state.i + 1;
					next_state.j = cur_state.j;
					next_state.dist = cur_state.dist + 1;
					q.push(next_state);
				}
				// cout<<"checking with :"<<mat[cur_state.i][cur_state.j-1]<<endl;
				if(check(cur_state, mat[cur_state.i][cur_state.j - 1])){ //checks for # and keys door combination
					// cout<<"Got true"<<endl;
					struct str next_state;
					next_state.k = update(cur_state, mat[cur_state.i][cur_state.j - 1]); // updates the distance and other values
					next_state.i = cur_state.i;
					next_state.j = cur_state.j-1;
					next_state.dist = cur_state.dist + 1;
					q.push(next_state);
				}
				// cout<<"checking with :"<<mat[cur_state.i][cur_state.j+1]<<endl;
				if(check(cur_state, mat[cur_state.i][cur_state.j + 1])){ //checks for # and keys door combination
					// cout<<"Got true"<<endl;
					struct str next_state;
					next_state.k = update(cur_state, mat[cur_state.i][cur_state.j + 1]); // updates the distance and other values
					next_state.i = cur_state.i;
					next_state.j = cur_state.j + 1;
					next_state.dist = cur_state.dist + 1;
					q.push(next_state);
				}
				//check in all the four directions and push the appropriate next state with increased distance
			}
		}
		if(q.empty())
			cout<<"The poor student is trapped!"<<endl;
		else
			cout<<"Escape possible in "<<cur_state.dist<<" steps."<<endl;
		//--------- Code above this line --------//
		cin>>r>>c;
	}
	return 0;
}