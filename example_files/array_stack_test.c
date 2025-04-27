#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/stacks/array_stack.h"

int main()
{

    // int (*array)[5];

    // int test[5];

    // array = &test;

    // (&array)[0] = 1;

    // printf("%d", (&array)[0]);
    // printf("\n%d", test[0]);

    array_stack stack;

    initialize_array_stack(&stack, 5);
    // push(&stack, 4);
    // push(&stack, 5);
    // push(&stack, 6);
    // push(&stack, 7);

    // display_array_stack(&stack);

    return 0;
}
