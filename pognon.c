#include "pognon.h"

double POGNON(int tour) {
    double a = 1000;

    for (int i = 1; i < tour; i++) {
        a = a * 2.16;
    }

    return a;
}
