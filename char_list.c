#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "char_list.h"


struct _element_of_char_list {
    char c;
    int count;
    double freq;
    element_of_char_list *next;
    element_of_char_list *prev;
};

struct _char_list {
    int length;
    element_of_char_list *head;
    element_of_char_list *last;
};


element_of_char_list *element_of_char_list_new()
{
    return malloc(sizeof(element_of_char_list));
}

char_list *char_list_new()
{
    return malloc(sizeof(char_list));
}

void get_char_list(char_list *list, text *txt)
{
    list->length = 0;
    list->head = element_of_char_list_new();
    list->last = element_of_char_list_new();
    list->head->next = list->last;
    list->last->prev = list->head;
    list->head->prev = list->last->next = NULL;

    queue *element = text_head(txt);
    while((element = text_element_next(element)) != text_last(txt))
        add_to_list(list, text_element_getchar(element));
}


void add_to_list(char_list *list, char c)
{
    element_of_char_list *element = list->head;
    while((element != NULL) && (element->c != c))
        element = element->next;

    if (element != NULL)
    {
        list->length += 1;
        element->count += 1;
    } else {
        list->length += 1;
        element = element_of_char_list_new();
        element->count = 1;
        element->c = c;
        element->next = list->last;
        element->prev = list->last->prev;
        element->next->prev = element;
        element->prev->next = element;
    }

    element_of_char_list *temp_elem = list->head;
    while((temp_elem = temp_elem->next) != list->last)
        temp_elem->freq = (1.0 / list->length) * temp_elem->count;
}

void print_char_list(char_list *list)
{
    printf("\nChar\tCount\tFrequence\n");
    element_of_char_list *element = list->head;
    while((element = element->next) != list->last)
        if(element->c == '\n')
            printf("%s\t%d\t%1.7f\n", "\\n", element->count, element->freq);
        else if (element->c == ' ')
            printf("%s\t%d\t%1.7f\n", "' '", element->count, element->freq);
        else
            printf("%c\t%d\t%1.7f\n", element->c, element->count, element->freq);
}

/* void char_list_sort(char_list *list)
{
    *element = list->head;
    while((element = list->head->next) != list->last)
    {
        temp_elem = element;
    }
}


void replace_elements(element_of_char_list *a, element_of_char_list *b)
{
    element_of_char_list *temp = a;
    a->next->prev = b;
    a->prev->next = b;
    b->next->prev = a;
    b->prev->next = a;

}
*/
