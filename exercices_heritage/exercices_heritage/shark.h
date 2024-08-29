#pragma once
#include "fish.h"

class Shark : public Fish {
public:
    bool IsCarnivore() override;
};
