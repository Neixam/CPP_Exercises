#pragma once
#include <string>
#include <optional>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class PlushStore {
public:
    PlushStore(const string& name) : _name(name)
    {}

    string get_name() const {
        return _name;
    }

    int get_wealth_amount() const {
        return _wealth_amount;
    }

    int get_stock_size() const {
        return _stock.size();
    }

    int get_debt_amount() const {
        return _debt_amount;
    }

    int make_plush(const int plush) {
        if (_wealth_amount == 0) {
            return 0;
        }
        _stock.emplace_back(_wealth_amount >= plush ? plush + _xp : _wealth_amount + _xp);
        if (_wealth_amount >= plush) {
            _wealth_amount -= plush;
            return plush + _xp++;
        }
        const auto ret = _wealth_amount;
        _wealth_amount = 0;
        return ret + _xp++;
    }

    void loan(const int wee) {
        _wealth_amount += wee;
        _debt_amount += (wee + (wee / 10));
    }

    int get_experience() const {
        return _xp;
    }

    optional<Plush> buy(int money) {
        const auto comp = [](const Plush& a, const Plush& b)
                { return a.get_cost() < b.get_cost(); };
        const auto min = min_element(_stock.begin(), _stock.end(), comp);
        const auto plush_min = *min;
        if (min->get_cost() > money) {
            return nullopt;
        }
        _wealth_amount += plush_min.get_cost();
        _stock.erase(remove(_stock.begin(), _stock.end(), plush_min), _stock.end());
        for (const auto& p : _stock) {
            cout << p << endl;
        }
        return make_optional(plush_min);
    }
private:
    string _name;
    vector<Plush> _stock;
    int _wealth_amount = 0;
    int _debt_amount = 0;
    int _xp = 0;
};