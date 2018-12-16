/* Add this to the task 1.1  */

/* Function first_integers - creates new list, inserts values from 1 to N with function insert,
   which is described above */

ll* first_integers(int N)
{
    ll* new_list = ll_new();
    int i;
    for (i = 1; i <= N; i++)
        ll_insert(new_list, i);
    return new_list;
}

// Example

int main(void)
{
    ll* b;
    b = first_integers(5);
    ll_print(b);
    
    return 0;
}
