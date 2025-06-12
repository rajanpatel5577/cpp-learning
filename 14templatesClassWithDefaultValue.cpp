#include<iostream>
#include <string>

namespace srsran {

template <typename T = int, typename U = std::string>
class my_class
{
public:
  my_class(T t, U u) : t_(t), u_(u) {}

  void display() const
  {
    std::cout << "T: " << t_ << ", U: " << u_ << std::endl;
  }

private:
  T t_;
  U u_;
};

} // namespace srsran

int main()
{
  using namespace srsran;

  my_class<> obj1(42, "Hello");
  obj1.display();

  my_class<double, std::string> obj2(3.14, "World");
  obj2.display();

  return 0;
}