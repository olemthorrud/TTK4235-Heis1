#include "run.h"
#include "initialize.h"
#include "elevio.h"
#include "queue.h"
#include "lights.h"
#include "doors.h"
#include <stdlib.h>

void run()
{

    int current_floor = initialize();
    int target_floor;
    int temp;
while(1) {
    
    MoveState state = IDLE;
    Set_buttons_pressed();
    while(order_exist()){
        Set_buttons_pressed();
        order_light_handler(buttons_pressed);
        target_floor = calculate_nxt_floor(state);
        state = calculate_state(current_floor, target_floor); // kan bare være opp eller ned

        
        do {
            current_floor = elevio_floorSensor();
            Set_buttons_pressed();
            order_light_handler(buttons_pressed); 
            temp = target_floor;
            target_floor = check_for_stops(current_floor, temp, state);
            move_elevator(state);
        
        } while(current_floor != target_floor);
        
        elevio_motorDirection(DIRN_STOP);
        Set_buttons_pressed();
        clear_btn(current_floor);
        Keep_doors_open_3_sek();
        //digg

    }
}
}
