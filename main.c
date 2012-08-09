#include "text.h"
#include "char_list.h"

int main()
{
    text *txt = text_new();
    get_text(txt);
    //print(txt);
    char_list *list = char_list_new();
    get_char_list(list, txt);
    print_char_list(list);
    free_text(txt);
    return 0;
}


