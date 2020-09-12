#include "vector.hpp"

#include <vector>
#include <climits>

int GetMin(std::vector<int> v) {
    int min = INT_MAX;

    for (int i : v) {
        if (i < min)
            min = i;
    }

    return min;
}

int GetMax(std::vector<int> v) {
    int max = INT_MIN;

    for (int i : v) {
        if (i > max)
            max = i;
    }

    return max;
}

double GetAvg(std::vector<int> v) {
    int sum = 0, count = 0;

    for (int i : v) {
        sum += i;
        count += 1;
    }

    return (double) sum/count;
}
