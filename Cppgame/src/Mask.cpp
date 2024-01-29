#include "Mask.h"


#include <algorithm>
#include <array>


#include "SDL2/SDL.h"


MASK::MASK() {}


std::array<int, 2> MASK::get_size() const
{
    return { width, height };
}


int MASK::get_at(int x, int y) const
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        return data[y * width + x];
    }
    else
    {
        return 0;
    }
}


bool MASK::overlaps(const MASK& other_mask, int xoffset, int yoffset)
{
    int xmin = std::max(0, -xoffset);
    int xmax = std::min(width, other_mask.get_size()[0] - xoffset);
    int ymin = std::max(0, -yoffset);
    int ymax = std::min(height, other_mask.get_size()[1] - yoffset);

    for (int y = ymin; y < ymax; y++)
    {
        for (int x = xmin; x < xmax; x++)
        {
            if (get_at(x, y) && other_mask.get_at(x + xoffset, y + yoffset))
            {
                return true;
            }
        }
    }

    return false;
}


MASK::~MASK()
{
    delete[] data;
}
