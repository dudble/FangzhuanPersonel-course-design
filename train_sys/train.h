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

void insertion(message arr[],int len)
{
    for(int i=1;i<len;i++){
        int key = arr[i].money;
        int j = i-1;
        while(j>=0 && arr[j].money>arr[j+1].money)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1].money = key;
    }
}