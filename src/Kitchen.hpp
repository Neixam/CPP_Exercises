#pragma once

#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <cstring>
#include <set>
#include <string>

class Kitchen
{
public:
    Kitchen() = default;
    const Unit& register_unit(Unit unit);
    const Ingredient& register_ingredient(Ingredient ingredient);
    const Unit* find_unit(const std::string& name) const;
    const Ingredient* find_ingredient(const std::string& name) const;
private:
    std::set<Unit> _units;
    std::set<Ingredient> _ingredients;
};
