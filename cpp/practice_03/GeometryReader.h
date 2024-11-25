#pragma once

#include "GeometryData.h"
#include <array>
#include <string>
#include <vector>


class GeometryReader
{
public:

    GeometryReader() = default;

    GeometryData read(std::string coordinatefile);

private:
};
