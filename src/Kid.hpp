#pragma once
#include <string>
#include <iostream>
using namespace std;

class Kid {
public:
    Kid(const string& name, const int money) : _name(name), _money(money)
    {}

    string get_name() const {
        return _name;
    }

    int get_money() const {
        return _money;
    }
private:
    string _name;
    int _money = 0;
};

ostream& operator<<(ostream& os, const Kid& other) {
    return os << other.get_name() << " has " << other.get_money() << " euros.";
}