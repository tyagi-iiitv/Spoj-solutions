#include <iostream>
#include <string>
#include <map>
#include <math.h>
#define llt long long
using namespace std;
map<char, int> dict; 

int main(){
	ios::sync_with_stdio(false);
	int total, cur_value, len;
	llt ans;
	cin>>total;
	string input;
	for(int t=1;t<=total;t++){
		ans = 0;
		cin>>input;
		len = input.length();
		cur_value = 0;
		dict.clear();
		dict[input[0]] = 1;
		for (int i=1;i<len;i++){
			if(dict.count(input[i]) == 0){
				dict[input[i]] = cur_value;
				cur_value = (cur_value == 0?2:cur_value+1);
			}
		}
		if(cur_value == 0){
			cur_value = 2;
		}
		for (int i = 0; i < input.length(); i++) {
        	ans = ans * cur_value + dict[input[i]];
     	}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;	
}