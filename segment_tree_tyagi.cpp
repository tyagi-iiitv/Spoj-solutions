#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


template <class T>
class SegmentTree{
	
public:
	int len, size;
	T *seg_tree;
	T *arr;
	SegmentTree(int len, T arr[]){
		this->len = len;
		this->arr = arr; 
		int x = (int) (ceil(log2(len)));
		size = 2*(int) pow(2,x);
		seg_tree = new T[size+1];
	}
	
	void generate_seg_tree(int pos, int start, int end){
		if(start > end)
			return;
		if(start == end){
			// cout<<"initialising seg_tree["<<pos<<"] with "<<arr[start]<<endl;
			seg_tree[pos] = arr[start];
			return;
		}
		generate_seg_tree(pos*2, start, (start+end)/2);
		generate_seg_tree(pos*2+1, (start+end)/2 + 1, end);
		// cout<<"initialising seg_tree["<<pos<<"] with "<<"seg_tree["<<pos*2<<"] + seg_tree["<<pos*2+1<<"]"<<endl;
		seg_tree[pos] = seg_tree[pos*2] + seg_tree[pos*2+1];
	}

		

};

int main(){
	int arr[6] = {1, 3, 5, 7, 9, 11};
	SegmentTree<int> obj(6, arr);
	obj.generate_seg_tree(1,0,5);	
	int *seg_tree = obj.seg_tree;
	
}
