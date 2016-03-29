// C++ program to find maximum rectangular area in linear time
#include <iostream>
#include <stack>
#define llt long long int
using namespace std;

// The main function to find the maximum rectangular area under given
// histogram with n bars
llt getMaxArea(int hist[], int n)
{
	// Create an empty stack. The stack holds indexes of hist[] array
	// The bars stored in stack are always in increasing order of their
	// heights.
	stack<int> s;

	llt max_area = 0; // Initalize max area
	int tp;
	llt area_with_top; // To store area with top bar as the smallest bar

	// Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i]){
			s.push(i++);
			// cout<<"pushing "<<s.top()<<endl;
		}

		// If this bar is lower than top of stack, then calculate area of rectangle 
		// with stack top as the smallest (or minimum height) bar. 'i' is 
		// 'right index' for the top and element before top in stack is 'left index'
		else
		{
			tp = s.top(); // store the top index
			s.pop(); // pop the top

			// Calculate the area with hist[tp] stack as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			// cout<<"area for "<<tp<<" is "<<area_with_top<<endl;

		// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate area with every
	// popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
		// cout<<"area for popped hist "<<tp<<" is "<<area_with_top<<" with i : "<<i<<endl;		
		if (max_area < area_with_top)
		max_area = area_with_top;
	}

	return max_area;
}

// Driver program to test above function
int main()
{
	int n = 1;
	while(n){
		cin>>n;
		if(n!=0){
			int hist[n];
			for(int i=0;i<n;i++){
				cin>>hist[i];
			}
			cout << getMaxArea(hist, n)<<endl;
		}
	}
	return 0;
}
