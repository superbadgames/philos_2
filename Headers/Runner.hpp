#pragma once
#include <Tower/framework.h>
#include "Simulator/SimulatorMap.hpp"

#ifdef PHILOS_EXPORTS
#define PHILOS_API __declspec(dllexport)
#else
#define PHILOS_API __declspec(dllimport)
#endif



Simulator::p_SimulatorMap simulatorMap;

extern "C" PHILOS_API void LoadProject(F32 width, F32 height);

extern "C" PHILOS_API void Update(F32 delta);

extern "C" PHILOS_API void Render();

