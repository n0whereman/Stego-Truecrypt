#ifndef PERMUTATIONFACTORY_H
#define PERMUTATIONFACTORY_H

#ifndef __SHARED_PTR_PERMUTATION__
#define __SHARED_PTR_PERMUTATION__
#include <memory>
class Permutation;
typedef std::shared_ptr<Permutation> PermutationPtr;
#endif // __SHARED_PTR_PERMUTATION__

#include <vector>
//#include "Permutation.h"
using namespace std;

class PermutationFactory final
{
private:
    PermutationFactory();
public:
    // get vector of all permutations (each permutation once)
    static vector<PermutationPtr> getPermutations();
    // get instance of permutation based on the code name
    static PermutationPtr getPermutationByName(const string &name);
    // get instance of the default permutation
    static PermutationPtr getDefaultPermutation();
};

#endif // PERMUTATIONFACTORY_H
