#include <algorithm>

#include "asteroid.h"
#include "countHits.h"

using std::max;

int countHits(const std::vector<Asteroid> &a) {
    int leftward_mass = 0;  // No asteroids encountered
    int total_hits = 0;     // No hits to start

    for (auto it = a.crbegin(); it != a.crend(); ++it) {
        switch (it->d) {
            case left:
                leftward_mass = max(leftward_mass, it->m);
                break;
            case right:
                if (it->m == leftward_mass) {
                    leftward_mass = 0;
                } else if (it->m > leftward_mass) {
                    ++total_hits;
                    leftward_mass = 0;
                }
                break;
        }
    }

    return total_hits;
}
