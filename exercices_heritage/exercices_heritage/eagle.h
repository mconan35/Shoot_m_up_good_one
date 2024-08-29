#pragma once
#include "bird.h"

class Eagle : public Bird {
public:
    bool IsCarnivore() override;
};
