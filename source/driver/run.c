#include "run.h"
#include "initialize.h"
#include "elevio.h"
#include "queue.h"
#include "lights.h"

void run() {

    int current_floor = initialize();
    int target_floor;



while(1) {
    
    MoveState state = IDLE;

    while(order_exist()){

        Set_buttons_pressed();
        order_light_handler(buttons_pressed); 
        current_floor = elevio_floorSensor();
        target_floor = calculate_nxt_floor(current_floor, state);
        state = calculate_state(current_floor, target_floor);
        
        do {
            Set_buttons_pressed();
            order_light_handler(buttons_pressed); 
            current_floor = elevio_floorSensor();
            target_floor = calculate_nxt_floor(current_floor, state);
            move_elevator(state);
        } while(current_floor != target_floor);
        
        clear_btn(current_floor);
        //skru av bestillingslys - den er ekspedert
        //stopp motor
        //open doors
    }

}

}




