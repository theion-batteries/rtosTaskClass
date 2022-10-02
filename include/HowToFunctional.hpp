#include <functional>
#include <memory>
#include <iostream>
#include <thread>

class Wrapper {
   public:
      void member1() {
          std::cout << "i am member1" << std::endl;
      }
      void member2(const char *arg1, unsigned arg2) {
          std::cout << "i am member2 and my first arg is (" << arg1 << ") and second arg is (" << arg2 << ")" << std::endl;
      }
      std::thread member1Thread() {
          return std::thread(&Wrapper::member1, std::ref(*this)); // std::thread (std::ref(obj));

      }
      std::thread member2Thread(const char *arg1, unsigned arg2) {
          return std::thread([=] { member2(arg1, arg2); }); // or [this] = [=]
      }
};








void repeat_n(unsigned int n, std::function<void ()> const &f)
{
  for (unsigned int i = 0; i < n; ++i) {
    f();
  }
}

void f_ptr()
{
  std::cout << "Legacy-Funktion\n";
}

struct FObj
{
  void operator()()
  {
    std::cout  << "Funktionsobjekt\n";
  }
};