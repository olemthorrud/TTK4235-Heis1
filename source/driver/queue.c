#include "queue.h"


int order_exist() {
    for(int i = 0; i<N_FLOORS; i++){
        for(int y = 0; y<N_BUTTONS; y++)
        if (elevio_callButton(i, y)) {
            return 1;
        }
    }
    return 0;
}


void Set_buttons_pressed() {
    for(int i = 0; i<N_FLOORS; i++){
        for(int y = 0; y<N_BUTTONS; y++)
        if (elevio_callButton(i, y)) {
            buttons_pressed[i][y] = 1;
        }
    }
}



int calculate_nxt_floor(int current_floor, MotorDirection motor_dir) {

    int next_floor = current_floor;

    switch (motor_dir)
    {

    //skal vi ned(-1); iterer ovenifra og ned, sjekk index 1, 2 i matrise 
    case DIRN_DOWN:
    for(int i = current_floor; i >= 0; i--) {
        if(buttons_pressed[i][BUTTON_HALL_DOWN] || buttons_pressed[i][BUTTON_CAB]){
            next_floor = i;
            buttons_pressed[i][BUTTON_HALL_DOWN] = 0;
            buttons_pressed[i][BUTTON_CAB] = 0;
            return next_floor;

        }
    }
    

    //skal vi opp(1); iterer nedenifra og opp, sjekk index 0, 2 i matrise
    case DIRN_UP:
    for(int i = current_floor; i <= N_FLOORS; i++){
        if(buttons_pressed[i][BUTTON_HALL_UP] || buttons_pressed[i][BUTTON_CAB]){
            next_floor = i;
            buttons_pressed[i][BUTTON_HALL_UP] = 0;
            buttons_pressed[i][BUTTON_CAB] = 0;
            return next_floor;
        }
    }


    //iterer gjennom alle etasjer
    case DIRN_STOP:
    for (int i = 0; i < N_FLOORS; i++) {
        for (int y = 0; i < N_BUTTONS; y++)
            {
            if(buttons_pressed[i][y]){
                next_floor = i;
                buttons_pressed[i][BUTTON_CAB] = 0;
                buttons_pressed[i][BUTTON_HALL_DOWN] = 0;
                buttons_pressed[i][BUTTON_HALL_UP] = 0;

                return next_floor;
            }
        }        
    }

    default:

    return next_floor;
}
}



