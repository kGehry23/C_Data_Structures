#include <stdio.h>
#include "../data_structures/hash_table/hash_table.h"

int main(void)
{

    hash_table table;
    initialize_hash_table(&table, 5, 0.5, 0);

    printf("%ld", (*(table.table_ptr))[0].value);

    // put(&table, 756473);

    return 0;
}
