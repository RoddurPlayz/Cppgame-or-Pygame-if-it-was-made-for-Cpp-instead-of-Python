#pragma once


#include <algorithm>
#include <array>

#include "../SDL2-src/SDL.h"


class MASK
{
public:
    int width;

    int height;

    bool* data;

    MASK();

    std::array<int, 2> get_size() const;

    int get_at(int x, int y) const;

    bool overlaps(const MASK& other_mask, int xoffset, int yoffset);

    ~MASK();
};
