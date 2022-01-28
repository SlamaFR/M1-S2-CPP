#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

#include <array>
#include <memory>
#include <string>
#include <utility>

// A person that capture Pokemons and make them fight.
class Trainer
{
private:
    const std::string       _name;
    std::array<Pokeball, 6> _pokeballs;
    PC&                     _pc;

public:
    Trainer(std::string name, PC& pc)
        : _name(std::move(name))
        , _pc(pc)
    {}

    const std::string& name() const { return _name; }

    const std::array<Pokeball, 6>& pokeballs() const { return _pokeballs; }

    void capture(std::unique_ptr<Pokemon> pokemon)
    {
        for (auto& pokeball : _pokeballs) {
            if (pokeball.empty()) {
                pokemon->trainer(this);
                pokeball.store(std::move(pokemon));
                return;
            }
        }
        pokemon->trainer(this);
        _pc.receive(std::move(pokemon));
    }
    void store_in_pc(int index)
    {
        if (index < 0 || index > 5) {
            return;
        }
        Pokeball& pokeball = _pokeballs[index];
        if (!pokeball.empty()) {
            _pc.receive(std::make_unique<Pokemon>(pokeball.pokemon()));
            pokeball.store(nullptr);
        }
    }
};
