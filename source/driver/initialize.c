#include "initialize.h"
#include "elevio.h"


int initialize(){
    int floor = elevio_floorSensor();
    while (floor != 0)
    {
        elevio_motorDirection(DIRN_DOWN);
        floor = elevio_floorSensor();
    }
    elevio_motorDirection(DIRN_STOP);
    return floor;
}