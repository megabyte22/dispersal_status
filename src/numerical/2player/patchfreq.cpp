#include <iostream>
#include "patchfreq.hpp"

PatchFreq::PatchFreq()
{
    for (int f_idx = 0; f_idx < fsize; ++f_idx)
    {
        f[f_idx] = 1.0 / fsize;

        std::cout << f[f_idx] << std::endl;
    }
} 

// data get/set function
double & PatchFreq::operator() (
        bool const envt_i
        ,int const state1
        ,int const state2)
{
    // use ordering, so if state2 is larger than state1
    // then switch order
    if (state2 > state1)
    {
        return(f[envt_i * 10 + state2 * 4 + state1]);
    }

    // state1 > state2
    return(f[envt_i * 10 + state1 * 4 + state2]);
} // end elem
