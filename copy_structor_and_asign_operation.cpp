#include <iostream>

// define a class with a copy constructor and a copy assignment operator
class A {
 public:
  A(int i) : i(i) {}
  A(const A &a) : i(a.i) { std::cout << "copy constructor" << std::endl; }
  A &operator=(const A &a) {
    std::cout << "copy assignment operator" << std::endl;
    i = a.i;
    return *this;  // 返回值跟返回引用的区别，是会多一次拷贝
  }

 private:
  int i;
};

int main() {
  A a(1);
  A b(2);
  b = a;  // copy assignment operator
  return 0;
}

//https://stackoverflow.com/questions/64635936/copy-assignment-operator-is-not-called
/**
 * #include<iostream>
using namespace std;

class mc{
    public:
        mc()=default;
        mc(mc& that){cout<<1;} //simplified copy constructor
        mc& operator=(mc& that){cout<<2; return that;} // simplified copy assignment operator
        mc operator=(mc that){cout<<2; return that;}   // another simplified copy assignment operator
};

int main(){
    mc i;       //call default constructor
    mc j = i;   //Why this line calls j's copy constructor? 
                //It used "=" symbol, how come copy assignment operator (operator=) is not called? 
}
 * 
*/
