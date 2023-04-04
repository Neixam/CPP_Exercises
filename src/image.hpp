#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>

template <typename P, size_t W, size_t H>
class Image
{
public:
    Image<P, W, H>() = default;
    ~Image() = default;
    Image<P, W, H>(const P& pi)
    {
        for (auto& line : _img)
            line.fill(pi);
    }
    P& operator()(const size_t i, const size_t j)
    {
        return _img[j][i];
    }
    const P& operator()(const size_t i, const size_t j) const
    {
        return _img[j][i];
    }
    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
    {
        for (size_t j = 0; j < H; j++)
            for (size_t i = 0; i < W; i++)
                _img[j][i] = functor(i, j);
    }
private:
    std::array<std::array<P, W>, H> _img;
};

template <typename P, size_t W, size_t H>
Image<P, W, H> operator+(const Image<P, W, H>& i1, const Image<P, W, H>& i2)
{
    return Image<P, W, H>([i1, i2](size_t i, size_t j) { return i1(i, j) + i2(i, j); });
}