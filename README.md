# Permutations Library (C++)
### By Joseph Juma

## About
Provides a simple set of permutation functions, for generating permutations from a set of possible values.

## Usage
1. Create a nested vector of values of the type of data you want. See the following code snippet for an example.
```
    std::vector<int> A = { 0, 1, 2 };
	std::vector<int> B = { 3, 4, 5, 6 };
	std::vector<int> C = { 7, 8 };
	std::vector<int> D = { 9 };

	std::vector<std::vector<int>> values = { A, B, C, D };
```
2. Create a results vector.
3. Pass these into the `Permutation.permutations()` function.
4. The results vector should now be full of vectors representing each possible permutation.

## License
Please see the LICENSE.md file for more information.

## Copyright
Copyright Joseph Juma, 2024. All rights reserved.
