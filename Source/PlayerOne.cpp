#include "pch.h"
#include "Players/PlayerOne.hpp"

using namespace Philos;

PlayerOne::PlayerOne(void) :
    _zipper(nullptr)
{
}

PlayerOne::~PlayerOne(void)
{
    _zipper.reset();
}

