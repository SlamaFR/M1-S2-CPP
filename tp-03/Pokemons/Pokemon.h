#pragma once

#include <string>
#include <utility>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
private:
    const std::string _name;
    Trainer*          _trainer = nullptr;

public:
    explicit Pokemon(std::string name)
        : _name(std::move(name))
    {}

    const std::string& name() const { return _name; }

    const Trainer* trainer() const { return _trainer; }

    void trainer(Trainer* trainer) { _trainer = trainer; }
};
