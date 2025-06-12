#include <memory>
#include <iostream>
#include <string>
using namespace std;
namespace srsran
{

    class base_entity
    {
    public:
        base_entity() : value(0) {}
        explicit base_entity(int v) : value(v) {}
        virtual ~base_entity() = default;

        virtual void print_info()
        //  void print_info()
        {
            cout << "print function from base_entity class" << endl;
            cout << "Base value: " << value << endl;
        }

    protected:
        int value;
    };

    class derived_entity : public base_entity
    {
    public:
        explicit derived_entity(int v) : base_entity(v), derived_value(v) {}

        void print_info() override
        // void print_info() 
        {
            cout << "print function from derived_entity class" << endl;
            cout << "Derived value: " << derived_value << endl;
        }

    private:
        int derived_value;
    };

} // namespace srsran

int main()
{

    using namespace srsran;

    std::unique_ptr<base_entity> base_ptr = std::make_unique<base_entity>(4);
    std::unique_ptr<derived_entity> derived_ptr = std::make_unique<derived_entity>(5);

    base_ptr->print_info();    // Calls base_entity::print_info
    derived_ptr->print_info(); // Calls derived_entity::print_info

    std::unique_ptr<base_entity> poly_ptr = std::make_unique<derived_entity>(6);
    poly_ptr->print_info(); // Calls derived_entity::print_info due to virtual

    return 0;
}