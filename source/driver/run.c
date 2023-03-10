#include "run.h"
#include "initialize.h"
#include "elevio.h"
#include "queue.h"

void run()
{

    int current_floor = initialize();
    int target_floor;

    while (1)
    {

        MoveState state = IDLE;
        int temp;

        while (order_exist())
        {
            target_floor = calculate_nxt_floor(state);
            state = calculate_state(current_floor, target_floor); // kan bare være opp eller ned

            do
            {
                Set_buttons_pressed();
                current_floor = elevio_floorSensor();
                temp = target_floor;
                target_floor = check_for_stops(current_floor, temp, state);
                move_elevator(state);
            } while (current_floor != target_floor);

            elevio_motorDirection(DIRN_STOP);
            clear_btn(current_floor);

            // stopp motor
            // open doors
        }
    }
}
