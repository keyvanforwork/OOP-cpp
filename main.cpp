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

class Developer : public Employee {
private:
    std::string FavProgrammingLanguage;
    int Experience {};
public:
    void setFav(std::string favLang) {
        FavProgrammingLanguage = favLang;
    }

    std::string getFav() {
        return FavProgrammingLanguage;
    };

    void setExp(int experience) {
        Experience = experience;
    }

    int getExp() {
        return Experience;
    };

    Developer(std::string name, std::string company, int age, std::string favLang, int experience)
        : Employee(name, company, age)
    {
        FavProgrammingLanguage = favLang;
        Experience = experience;
    }
    void FixBug() {
        std::cout << getName() << " Fixing bugs with using " << FavProgrammingLanguage << " for " << Experience << " years \n";
    }
};

class Teacher : public Employee {
private:
    std::string Subject;
    int Experience {};
public:
    void setSub(std::string subject) {
        Subject = subject;
    }

    std::string getSub() {
        return Subject;
    };

    void setExp(int experience) {
        Experience = experience;
    }

    int getExp() {
        return Experience;
    };

    Teacher(std::string name, std::string company, int age, std::string subject, int experience)
            : Employee(name, company, age)
    {
        Subject = subject;
        Experience = experience;
    }
    void TeachLesson() {
        std::cout << getName() << " teaching the " << Subject << " for " << Experience << " years \n";
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

    Developer dev1 = Developer("Alex", "Google", 46, "C++", 17);
    dev1.IntroduceYourself();
    dev1.FixBug();

    Teacher tech1 = Teacher("Selena", "High school", 27, "Math", 2);
    tech1.IntroduceYourself();
    tech1.TeachLesson();

    std::cout << "Promotions: \n";
    em1.EmployeePromotion();
    em2.EmployeePromotion();
    dev1.EmployeePromotion();
    tech1.EmployeePromotion();

    return 0;
}