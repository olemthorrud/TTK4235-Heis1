#include "run.h"

void run() {
    //define all buttons
    int buttons_pressed[N_FLOORS][N_BUTTONS] = {
        {0, 0, 0},                      //1. floor {BTN_UP, BTN_DWN, BTN_CAB}
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int CURRENT_FLOOR = initialize();
    int TAKES_ORDERS = 1;


    while(1){

        //check_stop();               //Vi må til en hver tid sjekke stop, cleare queue
        Stanby();
        while(order_exist()){         //check_orders sjekker om det er ordre og om man skal ta imot ordre, OG SKRUR PÅ LYS
            Move();                   //beveg deg til en-ordre (beregn hvor neste ordre skal, og om man kan stoppe på veien)
            //openDoors();            //man skal alltid åpne døren når man er ferdig med en ordre
        }
    }
}




