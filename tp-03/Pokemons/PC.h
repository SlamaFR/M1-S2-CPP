#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>
#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
using Pokelist = std::vector<std::unique_ptr<Pokemon>>;

class PC
{
private:
    Pokelist _pokemons;

public:
    const Pokelist& pokemons() const;

    void receive(std::unique_ptr<Pokemon> pokemon);

    bool give_back(Trainer& trainer, const std::string& name);
};
