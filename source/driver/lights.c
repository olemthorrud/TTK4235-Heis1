#include "doors.h"
#include <time.h>
#include "lights.h"

#include <stdio.h>
#include <stdlib.h>

void order_light_handler(int bestillingsmatrise[N_FLOORS][N_BUTTONS]){
    
    for (int f = 0; f < N_FLOORS; f++){
        for (int b = 0; b < N_BUTTONS; b++){
            int floor = f; 
            int button = b;
            if (bestillingsmatrise[f][b] == 1){
                elevio_buttonLamp(f, b, 1); 
            }else{
                elevio_buttonLamp(f, b, 0);
            }
            }
        }
    }
    