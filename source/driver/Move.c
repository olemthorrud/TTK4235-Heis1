#include "Move.h"
#include "queue.h"
#include "elevio.h"


void Move() {
    int next_floor;


    do
    { 

     Set_buttons_pressed();
        CURRENT_FLOOR = elevio_floorSensor();
        //next_floor = calculate_nxt_floor(CURRENT_FLOOR, );
        elevatorMove(CURRENT_FLOOR, next_floor);
        //check_stop();
        
        
    } while (CURRENT_FLOOR != next_floor || !STOP);
    
}


