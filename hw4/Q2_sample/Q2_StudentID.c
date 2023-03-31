#include <stdio.h>
#include <stdlib.h>

// You MUST NOT modify this!
struct Snake {
    int ratWeight;
    struct Snake *nextRat;
};

struct Snake* digestMiddle(struct Snake* head) {
    // TODO
}

int** vomitAndCrawl(int rows, int cols, struct Snake* head, int digestInterval) {
    // TODO
}

// You MUST NOT modify this!
int main()
{
    int rows, cols, numOfRats, digestInterval;
    scanf("%d %d %d", &rows, &cols, &numOfRats);

    struct Snake* head = (struct Snake*)malloc(sizeof(struct Snake));
    struct Snake* current = head;

    for(int i=0; i<numOfRats ; i++)
    {
        scanf("%d", &current->ratWeight);
        if(i < numOfRats - 1)
        {
            struct Snake* nextRat = (struct Snake*)malloc(sizeof(struct Snake));
            current->nextRat = nextRat;
            current = current->nextRat;
        }
    }
    current->nextRat = NULL;

    scanf("%d", &digestInterval);

    int** terrarium = vomitAndCrawl(rows, cols, head, digestInterval);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d", terrarium[i][j]);
            if(j < cols-1)
                printf(" ");
        }
        if(i < rows-1)
            printf("\n");
    }

    for(int i=0; i<rows; i++)
    {
        free(terrarium[i]);
    }
    free(terrarium);

    return 0;
}

