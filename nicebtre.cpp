#include <iostream>
#include <algorithm>
using namespace std;

int i;

int solve(string tree){
    if(tree[i++] == 'l')
        return 1;
    else
        return max(solve(tree), solve(tree))+1;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string tree;
        cin>>tree;
        i=0;
        cout<<solve(tree)-1<<endl;
    }
    return 0;
}