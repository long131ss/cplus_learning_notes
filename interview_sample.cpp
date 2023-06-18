// templates samples in C++
#include <iostream>
#include <thread>
// template functions
template <typename T>
T myMax(T x, T y) {
  return (x > y) ? x : y;
}

//define a function
void myCallableFunction (int a){
    std::cout << "myCallableFunction thread_id-->" << std::this_thread::get_id()<< std::endl;
    std::cout << "myCallableFunction parameter:" << a << std::endl;
}

// template class
template <typename T, typename U>
class A {
  T x;
  U y;

 public:
  A(T x,U y) { std::cout << "A Constructor" << std::endl; }
};

// program entry point
int main(int argc, char** arg) {
  char* filename = new char[2];
  // 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
  // std::cout << "args: " << arg[0] << " " << arg[1] << " argc11111" <<
  // std::endl;
  std::cout << myMax<int>(1, 2) << std::endl;
  std::cout << myMax<double>(1.1, 2.2) << std::endl;
  std::cout << myMax<char>('c', 'a') << std::endl;
  // initial A class here
  // A<int, double> a(1,2.2);
  A<int, double> a{1, 2.2};
  //   A<int, double> a = A<int, double>(1, 2.2);

  //create thread
  std::cout << "main thread id: " << std::this_thread::get_id()<<std::endl;
  //std::thread t(myCallableFunction,1);
  std::thread t([](void){
    std::cout << "thread callable lamda expression-->"<< std::this_thread::get_id()<< std::endl;
  });
  //t.detach();
  t.join();
  return 0;
}