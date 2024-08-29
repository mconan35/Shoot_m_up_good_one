#pragma once
#include "animal.h"

class Fish : public Animal {
public:
    bool IsFish() override;
    bool IsBird() override;
};
