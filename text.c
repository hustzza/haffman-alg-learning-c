#include "text.h"
#include <stdio.h>
#include <stdlib.h>

struct _queue {
    char c;
    struct _queue *next;
    struct _queue *prev;
};

struct _text {
    struct _queue *head;
    struct _queue *last;
};

void get_text(text *txt)
{

    txt->head = queue_new();
    txt->last = queue_new();
    txt->head->prev = NULL;
    txt->head->c = '\0';
    txt->last->prev = txt->head;
    txt->last->next = NULL;
    txt->last->c = '\0';
    txt->head->next = txt->last;

    char c;
    while ((c=getchar()) != EOF)
        add(c, txt);
}

void add(char c, text *txt)
{
    queue *element = queue_new();
    element->c = c;
    element->next = txt->last;
    element->prev = txt->last->prev;
    txt->last->prev->next = element;
    txt->last->prev = element;
}

void print(text *txt)
{
    queue *elem = txt->head->next;
    printf("\n");

    while (elem->next != NULL)
    {
        printf("%c", elem->c);
        elem = elem->next;
    }
    printf("%c\n", elem->c);
}


void free_text(text *txt)
{
    queue *element = txt->last->prev;

    while(element->prev != txt->head)
    {
        free(txt->last);
        txt->last = element;
        element = txt->last->prev;
    }
    free(element);
    free(txt->last);
    free(txt->head);
    free(txt);


}

text* text_new(void)
{
    return malloc(sizeof(text));
}

queue* queue_new(void)
{
    return malloc(sizeof(queue));
}

queue* text_head(text *txt)
{
    return txt->head;
}

queue* text_last(text *txt)
{
    return txt->last;
}

queue* text_element_next(queue *element)
{
    return element->next;
}

queue* text_element_prev(queue *element)
{
    return element->prev;
}

char text_element_getchar(queue *element)
{
    return element->c;
}
