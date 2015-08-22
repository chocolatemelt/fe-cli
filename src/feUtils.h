#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <random>
#include <time.h>

class feUtils {
  public:
    std::mt19937 rand;

    feUtils();
    
    feUtils(std::string s);

    int feRNG();
};

#endif
