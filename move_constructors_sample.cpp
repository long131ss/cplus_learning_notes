// C++ program without declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declaring the raw pointer as
	// the data member of the class
	int* data;

public:
	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
		*data = d;

		cout << "Constructor is called for "
			<< d << endl;
	};

	// Copy Constructor to delegated
	// Copy constructor
	Move(const Move& source)
		: Move{ *source.data }
	{

		// Copying constructor copying
		// the data by making deep copy
		cout << "Copy Constructor is called - "
			<< "Deep copy for "
			<< *source.data
			<< endl;
	}

	// Move Constructor
    Move(Move&& source)
        : data{ source.data }
    {
 
        cout << "Move Constructor for "
             << *source.data << endl;
        source.data = nullptr;
    }

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If the pointer is not
			// pointing to nullptr
			cout << "Destructor is called for "
				<< *data << endl;
		else

			// If the pointer is
			// pointing to nullptr
			cout << "Destructor is called"
				<< " for nullptr"
				<< endl;

		// Free the memory assigned to
		// data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Create vector of Move Class
	vector<Move> vec;
	vec.reserve(2);

	// Inserting object of Move class
	vec.emplace_back(Move{ 10 });
	vec.emplace_back(Move{ 20 });
	vec.emplace_back(20);
	return 0;

	//结论:从结果中可以看出，如果直接传对象给push_back和emplace_back，
	//无论是实名对象还是匿名对象，结果都是一样的，但是emplance_back不同的是你可以直接传构造对象的参数，
	//然后emplace_back函数里通过参数来直接构造对象，从而少了一次构造，效率更高。

	//通常使用push_back()向容器中加入一个右值元素（临时对象）的时候，
	//首先会调用构造函数构造这个临时对象,然后需要调用拷贝构造函数将这个临时对象放入容器中.原来的临时变量释放.这样造成的问题是临时变量申请的资源就浪费

	//emplace_back   在容器尾部添加一个元素,这个元素原地构造，不需要触发拷贝构造.而且调用形式更加简洁，直接根据参数初始化临时对象的成员
}

