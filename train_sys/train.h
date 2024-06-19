typedef struct
{
    char trip[7];
    char begin[50];
    char end[50];
    char begin_t[7],end_t[7];
    int total;
    int left;
    int money;
}message;

int cmp(const void *a,const void *b)
{
    return (*(message *)a).money > (*(message *)b).money ? 1:-1;
}
