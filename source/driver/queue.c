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


// int calculate_nxt_floor(){
//     for(int i = 0; i<N_FLOORS; i++){
//         for(int y = 0; y<N_BUTTONS; y++)
//         if (elevio_callButton(i, y)) {
//             buttons_pressed[i][y] = 1;
//         }
//     }
// }

/* int calculate_nxt_floor(){
    if(elevio_floorSensor()) {

    }

    else if();
} */