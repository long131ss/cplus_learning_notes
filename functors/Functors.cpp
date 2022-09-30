// C++ program to demonstrate working of
// functors.
#include <bits/stdc++.h>
using namespace std;

// A Functor
class increment
{
private:
	int num;
public:
	increment(int n) : num(n) { cout << "increment constructor" << std::endl; }

	// This operator overloading enables calling
	// operator function () on objects of increment
	int operator () (int arr_num) const {
        cout << "increment operator called:" << arr_num << endl;
		return num + arr_num;
	}
};

// Driver code
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int to_add = 5;
    increment obj(to_add);//创建increament 对象,此时调用的是构造函数, 为什么不是调用那个()方法呢,
    //个人理解，这个时候,对象都还有创建
    obj(2);//等价于obj.operator()(2);
	//transform(arr, arr+n, arr, obj);

	for (int i=0; i<n; i++)
		cout << arr[i] << " " << endl;
}
