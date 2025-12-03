#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        insert = current;
        current = current->next;
        
        while (insert->prev != NULL && insert->n < insert->prev->n)
        {
            /* Swap nodes */
            tmp = insert->prev;
            
            /* Update the next pointer of the node before tmp */
            if (tmp->prev != NULL)
                tmp->prev->next = insert;
            else
                *list = insert;
            
            /* Update the prev pointer of the node after insert */
            if (insert->next != NULL)
                insert->next->prev = tmp;
            
            /* Swap the nodes */
            tmp->next = insert->next;
            insert->prev = tmp->prev;
            insert->next = tmp;
            tmp->prev = insert;
            
            /* Print the list after swapping */
            print_list(*list);
        }
    }
}
