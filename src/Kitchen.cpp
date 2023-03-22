#include "Kitchen.hpp"
#include <utility>

const Unit& Kitchen::register_unit(Unit unit)
{
    auto [it, emplaced] = _units.emplace(std::move(unit));
    return *it;
}
const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto& p = _units.find(name, [](const auto& n, const auto& u) { return ;});
    if (p == _units.end())
        return nullptr;
    return &p->second;
}
const Ingredient& Kitchen::register_ingredient(Ingredient ingredient)
{
    _ingredients.try_emplace(ingredient);
    return ingredient;
}
const Ingredient* Kitchen::find_ingredient(const std::string& name) const
{
    const auto& p = _ingredients.find(name, [](const auto& i1, const auto& i2) {  });
    if (p == _ingredients.end())
        return nullptr;
    return &p->second;
}
