#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct birthday{
        int day;
        int month;
        int year;
        //struct list_head list;
    };

    //static LIST_HEAD(birthday_list);

    struct birthday *person;

    person = kmalloc(sizeof(*person), GFP_KERNEL);
    person->day=2;
    person->month=8;
    person->year=1995;
    INIT_LIST_HEAD(&person->list);

    list_add_tail(&person->list, &birthday_list);

    struct birthday *ptr;

    list_for_each_entry(ptr, &birthday_list, list) {
        /* on each iteration ptr points */
        /* to the next birthday struct */
    }

    list_del (struct list_head *element);

    struct birthday *ptr, *next;

    list_for_each_entry_safe(ptr,next,&birthday_list,list) {
        /* on each iteration ptr points */
        /* to the next birthday struct */
        list.del(&ptr->list);
        kfree(ptr);
    }
    return 0;
}
