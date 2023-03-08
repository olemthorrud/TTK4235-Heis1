#include "run.h"
#include "standby.h"
#include "initialize.h"
#include "elevio.h"
#include "queue.h"

void run() {

    CURRENT_FLOOR = initialize();
    int TAKES_ORDERS = 1;

    while(1){

        //check_stop();               //Vi må til en hver tid sjekke stop, cleare queue
        Stanby();
        while(order_exist() && !STOP){         //check_orders sjekker om det er ordre og om man skal ta imot ordre
            Set_buttons_pressed();
            Move();                   //beveg deg til en-ordre (beregn hvor neste ordre skal, og om man kan stoppe på veien)
            //openDoors();            //man skal alltid åpne døren når man er ferdig med en ordre
        }
    }
}




