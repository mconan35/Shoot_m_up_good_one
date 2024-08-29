#pragma once
#include "bird.h"

class Swan : public Bird {
public:
    bool IsCarnivore() override;
};