#include <bits/stdc++.h>
using namespace std;

// Function to return an
// array
int* fun()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *ptr = arr;
    cout << "ptr ptr address:" << ptr << endl;
	return ptr;
}
// Driver Code
int main()
{

	int* arr = fun();
    cout << "arr ptr address:" << arr << endl;
	cout << arr[2];

	return 0;
}
