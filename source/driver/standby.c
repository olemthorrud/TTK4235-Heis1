#include "standby.h"
#include "elevio.h"

void Standby() {
    elevio_motorDirection(DIRN_STOP);
}