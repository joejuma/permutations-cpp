#pragma once
/*
    # Permutations Library (C++)
    Version 1.0
    By Joseph Juma

    ## About
    Provides a simple set of permutation functions, for generating permutations
    from a set of possible values.

    ## License
    Please see the LICENSE.md file for more information.

    ## Copyright
    Copyright Joseph Juma, 2024. All rights reserved.
*/
#ifndef PERMUTATION__H
#define PERMUTATION__H
/* Deps */
#include <vector>

/* Namespace */
namespace Permutation
{
    template <typename T>
    uint64_t calculateNumberOfPermutations(const std::vector<std::vector<T>>& values)
    {
        uint64_t i = 1;
        for (uint64_t i = 0; i < values.size(); i++)
        {
            i *= values[i].size();
        };

        return i;
    };

    template <typename T>
    void permutations(
        const std::vector<std::vector<T>>& values,
        std::vector<std::vector<T>>& results,
        std::vector<T>& permutation,
        const uint64_t& depth
    )
    {
        /*
            Generates every permutation from the given matrix of possible
            values.
        */

        // Allocate some useful variables,
        uint64_t length = values.size() - 1; // Used in comparing an index,

        // For each possible value at this depth,
        for (uint64_t i = 0; i < values[depth].size(); i++)
        {
            // Create a copy of the current permutation,
            std::vector<T> current(permutation);

            // Append the current value,
            current.push_back(values[depth][i]);

            // If we aren't at the maximum depth,
            if (depth < length)
            {
                permutations(values, results, current, (depth + 1));
            }
            // Else, if the depth has reached the length,
            else if (depth == length)
            {
                // Add generated permutation to the list of permutations,
                results.push_back(current);
            };
        };

        // All done, the results vector should be passed up the chain.
    };

    template <typename T>
    void permutations(
        const std::vector<std::vector<T>>& values,
        std::vector<std::vector<T>>& results
    )
    {
        /*
            Generates every permutation from the given matrix of possible
            values.
        */

        std::vector<T> initial;
        permutations<T>(values, results, initial, 0);
    };
};
#endif