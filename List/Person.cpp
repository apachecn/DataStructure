#include"Person.h"


ostream &operator<<(ostream &out, Person &person) {      // 实现输出运算符的重载
    out << person.name << "--------" << person.phone << endl;
    return out;
}

Person &Person::operator=(Person &person) {	 // 实现赋值运算符的重载
    this->name = person.name;
    this->phone = person.phone;
    return *this;
}


bool Person::operator==(Person &person) {		 // 实现比较运算符的重载
    if (this->name == person.name && this->phone == person.phone) {
        return true;
    }
    return false;
}
