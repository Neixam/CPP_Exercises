#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct Luma
{
    uint8_t gray;
};

template<typename A, typename B>
A from(const B & stuff);

template<>
RGBA from(const RGB& stuff)
{
    return {stuff.r, stuff.g, stuff.b, 255};
}

template<>
RGB from(const RGB& stuff)
{
    return stuff;
}

template<>
RGBA from(const RGBA& stuff)
{
    return stuff;
}

template<>
Luma from(const Luma& stuff)
{
    return stuff;
}

template<>
RGB from(const RGBA& stuff)
{
    return {stuff.r, stuff.g, stuff.b};
}

template<>
Luma from(const RGB& stuff)
{
    return {lib::rgb_to_grayscale(stuff.r, stuff.g, stuff.b)};
}

template<>
RGB from(const Luma& stuff)
{
    auto tmp = lib::grayscale_to_rgb(stuff.gray);
    return reinterpret_cast<RGB&>(tmp);
}

template<>
Luma from(const RGBA& stuff)
{
    return from<Luma, RGB>(from<RGB, RGBA>(stuff));
}

template<>
RGBA from(const Luma& stuff)
{
    return from<RGBA, RGB>(from<RGB, Luma>(stuff));
}

template<typename A, typename B, typename C>
A operator+(const B& stuff);

RGBA operator+(const RGBA& p1, const RGBA& p2)
{
    auto tmp = lib::mix_color(p1.r, p1.g, p1.b, p1.a, p2.r, p2.g, p2.b, p2.a);
    return {tmp[0], tmp[1], tmp[2], tmp[3]};
}