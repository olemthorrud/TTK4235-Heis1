#include "Move.h"
#include "queue.h"
#include "elevio.h"


void Move() {
    int next_floor;


    do
    {

        CURRENT_FLOOR = elevio_floorSensor();
        next_floor = calculate_nxt_floor();
        elevatorMove(CURRENT_FLOOR, next_floor);
        //check_stop();
        
        
    } while (CURRENT_FLOOR != next_floor || !STOP);
    



}