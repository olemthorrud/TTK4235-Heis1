#include "doors.h"
#include <time.h>
#include "queue.h"


void Keep_doors_open_3_sek(int current_floor, int STOP){ 

    const int start_time = time(NULL);
     

    elevio_doorOpenLamp(1);

    while ((time(NULL) - start_time) < 3){
      if (!STOP){
        Set_buttons_pressed();
        order_light_handler(buttons_pressed); 
      }  
    }
    
    int obstr = elevio_obstruction();
    
    while(obstr){
      if (!STOP){
        Set_buttons_pressed();
        order_light_handler(buttons_pressed); 
        elevio_floorIndicator(current_floor);
        obstr = elevio_obstruction();
      }  
    }

    elevio_doorOpenLamp(0); 
} 