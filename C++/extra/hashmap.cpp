#include <iostream>

using namespace std;

// Objective: Create a true O(1) hashmap
template <typename T1, typename T2, class Comp = greater<T1>>
class HashMap{
    T2* array;
};