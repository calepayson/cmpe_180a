#include <math.h>

#include "distance.h"
#include "sqr.h"

float distance(XYPoint xy) { return sqrtf(sqr(xy.x) + sqr(xy.y)); }
