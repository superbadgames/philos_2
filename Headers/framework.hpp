#pragma once

#define WIN32_LEAN_AND_MEAN

// Windows Header Files
#include <windows.h>

// stl global includes
#include <cstdint>
#include <memory>
#include <string>

using std::shared_ptr;
using std::unique_ptr;
using std::string;


// Custom typedefs
typedef int8_t   S8;
typedef int16_t  S16;
typedef int32_t  S32;
typedef int64_t  S64;
typedef uint8_t  U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef float  F32;
typedef double F64;
// Seprate because sometimes we want to be able to change just what a real number is.
typedef float real;

#define REAL_MAX FLT_MAX
#define real_sqrt sqrtf
#define real_abs fabsf
#define real_sin sinf
#define real_cos cosf
#define real_tan tanf
#define real_atan atanf
#define real_atan2 atan2f
#define real_exp expf
#define real_pow powf
#define real_fmod fmod4
#define real_epsilon DBL_EPSILON
const real R_PI = static_cast<real>(3.14159265358979);

const float TO_RADIANS = 3.14159265f / 180.0f;
