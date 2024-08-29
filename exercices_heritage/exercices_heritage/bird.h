#pragma once
#include "animal.h"

class Bird : public Animal {
public:
    bool IsFish() override;
    bool IsBird() override;
};
