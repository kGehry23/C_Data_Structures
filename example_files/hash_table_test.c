#include <stdio.h>
#include <strings.h>
#include "../data_structures/hash_table/hash_table.h"

int main(void)
{

    hash_table table;
    initialize_hash_table(&table, 5, 0.5, 0);
    put(&table, 756473, "Test");

    printf("\n%s", (*(table.table_ptr))[3].value);

    return 0;
}
