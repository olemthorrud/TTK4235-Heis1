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
    //elevio_floorIndicator(current_floor);
    int target_floor;
    int temp;
    int remember_floor; 
    int remember_state; 
    int has_stopped = 0; 
while(1) { 
    
    MoveState state = IDLE;

    
    int STOP = elevio_stopButton();

    if (STOP){
        clear_orders();
        elevio_stopLamp(1); 
        order_light_handler(buttons_pressed); 
        int a = elevio_floorSensor(); 

        if (a != -1){
            elevio_doorOpenLamp(1);
        }
        

        while (STOP)
        {
            STOP = elevio_stopButton();
            
        } 

        has_stopped = 1; 

        elevio_stopLamp(0);

        if (a != -1){
            Keep_doors_open_3_sek(a, STOP);
        }
         
    }

       
    Set_buttons_pressed();
          
        //print_buttons(); 
    
   

    
    while(order_exist()){ 
        Set_buttons_pressed();
        order_light_handler(buttons_pressed);
        target_floor = calculate_nxt_floor(state, remember_floor, remember_state, has_stopped);
        printf("target floor %d \n", target_floor);
        state = calculate_state(current_floor, target_floor, remember_floor); // kan bare være opp eller ned
        STOP = elevio_stopButton(); 
         

        do { 
            current_floor = elevio_floorSensor();
            if (current_floor != -1){
                remember_floor = current_floor; 
                elevio_floorIndicator(current_floor);

            }
            Set_buttons_pressed();
            order_light_handler(buttons_pressed); 
            temp = target_floor;
            target_floor = check_for_stops(current_floor, temp, state);
            move_elevator(state);
     
            STOP = elevio_stopButton(); 
            
        
        } while((current_floor != target_floor) && !STOP);


        elevio_motorDirection(DIRN_STOP);
        remember_state = state; 
        if (STOP){       
        clear_orders();  
        break; 
        }
        Set_buttons_pressed();
        clear_btn(current_floor);
        order_light_handler(buttons_pressed); 
        Keep_doors_open_3_sek(current_floor, STOP);
        //digg

    }
}
}
