#include "defines.h"

void run_script_from_item(int taskID)
{
    script_env2_enable(taskID);
    script_run((void *)0x81E818F);
    task_delete(taskID);
}


void item_forme_change_handler()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item;
    run_after_graphics();
}

