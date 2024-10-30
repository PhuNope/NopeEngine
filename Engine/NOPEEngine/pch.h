#pragma once

// Standal library
#include <memory>
#include <stdint.h>
#include <set>
#include <random>
#include <limits>
#include <vector>
#include <string>
#include <bitset>
#include <cassert>
#include <assert.h>
#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>


template<typename T> using Shared = std::shared_ptr<T>;
template<typename T> using Unique = std::unique_ptr<T>;

#if ON_NOPE_ENGINE

#if DYNAMIC_BUILD

#ifdef _MSC_VER
#define NOPE_API __declspec(dllexport)
#else
#define NOPE_API __attribute__((visibility("default")))
#endif // _MSC_VER

#else

#define NOPE_API

#endif // DYNAMIC_BUILD

#else

#if DYNAMIC_IMPORT

#ifdef _MSC_VER
#define NOPE_API __declspec(dllimport)
#else
#define NOPE_API
#endif // _MSC_VER

#else

#define NOPE_API

#endif // DYNAMIC_IMPORT

#endif // ON_NOPE_ENGINE

// Runtime assert
#define NOPE_ASSERT assert

// Static assert
#if defined(__clang__) || defined(__gcc__)
#define NOPE_STATIC_ASSERT _Static_assert
#else
#define NOPE_STATIC_ASSERT static_assert
#endif // defined(__clang__) || defined(__gcc__)

#if defined(__clang__) || defined(__gcc__)
#define NOPE_FORCE_INLINE __attribute__((always_inline)) inline
#define NOPE_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
#define NOPE_FORCE_INLINE __forceinline
#define NOPE_NOINLINE __declspec(noinline)
#else
#define NOPE_FORCE_INLINE inline
#define NOPE_NOINLINE
#endif // defined(__clang__) || defined(__gcc__)

#define NOPE_FREE_MEMORY(memory) if(memory != nullptr){ delete memory; memory = nullptr; }

#define BIND_EVENT_FUNCTION(function)[this](auto&... args) -> decltype(auto)\
	{ return this->function(std::forward<decltype(args)>(args)...);}