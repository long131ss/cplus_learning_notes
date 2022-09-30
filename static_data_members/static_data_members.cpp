#include <iostream>
using namespace std;
//reference to https://www.geeksforgeeks.org/static-data-members-c/?ref=gcse
class A {
  int x;

 public:
  A() { cout << "A's constructor called " << endl; }
};

class B {
  static A a;//这个地方是静态成员变量的声明

 public:
  B() { cout << "B's constructor called " << endl; }
  //static A getA() { return a; }
};
//不管是上面的class A 还是class B,类里面的都是对类的声明declration

 
//A B::a;//个人理解,这个地方是定义,也就是初始化
int main() {
  B b;
  //A a = b.getA();
  return 0;
}
