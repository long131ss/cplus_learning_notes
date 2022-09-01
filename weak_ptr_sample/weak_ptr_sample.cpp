#include <iostream>
#include <memory>
//refernce to https://blog.csdn.net/qq_38410730/article/details/105903979
class CB;
class CA {
  public:
    CA() {
      std::cout << "CA()" << std::endl;
    }
    ~CA() {
      std::cout << "~CA()" << std::endl;
    }
    void set_ptr(std::shared_ptr<CB>& ptr) {
      m_ptr_b = ptr;
    }
  private:
    std::shared_ptr<CB> m_ptr_b;
};

class CB {
  public:
    CB() {
      std::cout << "CB()" << std::endl;
    }
    ~CB() {
      std::cout << "~CB()" << std::endl;
    }
    void set_ptr(std::shared_ptr<CA>& ptr) {
      m_ptr_a = ptr;
    }
  private:
    //std::shared_ptr<CA> m_ptr_a;//ptr_a,和ptr_b指向的对象资源得不到释放,对象的析构函数没有调用
    std::weak_ptr<CA> m_ptr_a;//修改
};

int main()
{
  std::shared_ptr<CA> ptr_a(new CA());
  std::shared_ptr<CB> ptr_b(new CB());
  ptr_a->set_ptr(ptr_b);
  ptr_b->set_ptr(ptr_a);
  std::cout << ptr_a.use_count() << " " << ptr_b.use_count() << std::endl;

  return 0;
}
