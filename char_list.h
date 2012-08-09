#include "text.h"

typedef struct _element_of_char_list element_of_char_list;
typedef struct _char_list char_list;

element_of_char_list *element_of_char_list_new(void);
char_list *char_list_new(void);
void get_char_list(char_list *list, text *txt);
void add_to_list(char_list *, char);
void print_char_list(char_list *);
