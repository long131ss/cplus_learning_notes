// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return
// a pointer
int* fun()
{
	int x = 20;
	int* ptr = &x;
    cout << "fun ptr address:" << ptr  << endl;
	return ptr;
}
// Driver Code
int main()
{
	int* arr = fun();
    cout << "arr ptr address:" << arr << endl;
	cout << *arr << endl;
	return 0;
}
