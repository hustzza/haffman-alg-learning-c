typedef struct _queue queue;
typedef struct _text text;

void add(char, text *);
void get_text(text *);
void print(text *);
text *text_new(void);
queue *queue_new(void);
void free_text(text *);
queue* text_head(text *txt);
queue* text_last(text *txt);
queue* text_element_next(queue *element);
queue* text_element_prev(queue *element);
char text_element_getchar(queue *element);
