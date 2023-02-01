#pragma once
#include <iostream>
using namespace std;

class Plush {
public:
    Plush() = default;
    Plush(int cost) : _cost(cost)
    {}

    int get_cost() const {
        return _cost;
    }

    void set_cost(const int cost) {
        _cost = cost;
    }

    bool operator==(const Plush& oth) {
        return this == &oth;
    }
private:
    int _cost = 10;
};

ostream& operator<<(ostream& os, const Plush& other) {
    return os << "Plush costs " << other.get_cost();
}
