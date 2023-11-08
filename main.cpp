#include <iostream>
#include <string>

class AbstractEmployee {
    virtual void EmployeePromotion() = 0;
};

class Employee : AbstractEmployee {
private:
    std::string Name;
    std::string Company;
    int Age{};
public:
    void setName(std::string name) {
        Name = name;
    }

    std::string getName() {
        return Name;
    }

    void setCompany(std::string company) {
        Company = company;
    }

    std::string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18)
            Age = age;
    }

    int getAge() {
        return Age;
    }

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

    void EmployeePromotion() {
        if (Age > 30)
            std::cout << Name << "  got promoted for age" << '\n';
        else
            std::cout << Name << "  sorry for age" << '\n';
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
    em2.setCompany("BMW");
    em2.setAge(12);
    std::cout << "Change: \n" << "company - " << em2.getCompany() << '\n' << "age - " << em2.getAge() << '\n';
    em2.IntroduceYourself();
    std::cout << "Promotion: \n";
    em1.EmployeePromotion();
    em2.EmployeePromotion();
    return 0;
}