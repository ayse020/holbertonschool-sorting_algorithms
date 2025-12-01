#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    /* Check for invalid input */
    if (array == NULL || size < 2)
        return;

    /* Outer loop - passes through the array */
    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        
        /* Inner loop - compares adjacent elements */
        for (j = 0; j < size - i - 1; j++)
        {
            /* If current element is greater than next, swap them */
            if (array[j] > array[j + 1])
            {
                /* Swap elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                
                /* Set swapped flag to true */
                swapped = 1;
                
                /* Print array after swap (as required) */
                print_array(array, size);
            }
        }
        
        /* If no swaps occurred, array is already sorted */
        if (swapped == 0)
            break;
    }
}
