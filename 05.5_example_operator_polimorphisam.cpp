
#include <iostream>
#include <string>


namespace srsran {

// Template vector class similar to std::vector, with dot product
template <typename T>
class simple_vector
{
public:
  explicit simple_vector(std::size_t n) : size_(n), arr_(new T(size_)) {}
  ~simple_vector() = default;

  std::size_t size() const { return size_; }

   T& operator[](std::size_t idx) const { return arr_[idx]; }

  T dot_product(const simple_vector& other) const
  {
    if (size_ != other.size_) {
     std::cout<<"Vector sizes do not match for dot product."<<std::endl;
      return 0;
    }
    T result = 0;;
    for (std::size_t i = 0; i < size_; ++i) {
      result += arr_[i] * other.arr_[i];
    }
    return result;
  }

private:
  std::size_t size_;
  T *arr_;
};

} // namespace srsran

int main()
{


  using namespace srsran;

  simple_vector<int> v1(3), v2(3);
  v1[0] = 1; v1[1] = 2; v1[2] = 3;
  v2[0] = 2; v2[1] = 3; v2[2] = 4;
  std::cout<< "Dot product result (int): " << v1.dot_product(v2) <<std::endl;

  simple_vector<float> v3(3), v4(3);
  v3[0] = 1.1f; v3[1] = 2.2f; v3[2] = 3.3f;
  v4[0] = 2.2f; v4[1] = 3.3f; v4[2] = 4.4f;
  std::cout << "Dot product result (float): " << v3.dot_product(v4) << std::endl;


  return 0;
}