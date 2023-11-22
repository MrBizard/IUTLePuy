#pragma once

template<unsigned int n>
constexpr unsigned long long fibonacci = fibonacci<n - 1> + fibonacci<n - 2>;

template<>
constexpr unsigned long long fibonacci<0> = 0;

template<>
constexpr unsigned long long fibonacci<1> = 1;

