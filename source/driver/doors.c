#include "doors.h"
#include <time.h>
#include "queue.h"


void Keep_doors_open_3_sek(){ 

    const int start_time = time(NULL);

    elevio_doorOpenLamp(1); 

    while ((time(NULL) - start_time) < 3){
      if (order_exist()){ //&& !STOP// ){
        Set_buttons_pressed();
      }  
    }

    elevio_doorOpenLamp(0); 
} 