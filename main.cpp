#include <iostream>
#include <string>

class Employee {
public:
    std::string Name;
    std::string Company;
    int Age{};

    void IntroduceYourself() const {
        std::cout << "Name - " << Name << '\n';
        std::cout << "Company - " << Company << '\n';
        std::cout << "Age - " << Age << '\n';
    }

    Employee(std::string name, std::string company, int age) {
        Name = name;
        Company = company;
        Age = age;

    }
};

int main() {
    Employee em1 = Employee("Mitra", "Yahoo", 36);
//    em1.Name = "Mitra";
//    em1.Company = "Yahoo";
//    em1.Age = 36;
    em1.IntroduceYourself();

    Employee em2 = Employee("Ali", "Apple", 28);
//    em2.Name = "Ali";
//    em2.Company = "Apple";
//    em2.Age = 28;
    em2.IntroduceYourself();

    return 0;
}