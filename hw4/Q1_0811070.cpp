#include <iostream>

using namespace std;

// You MUST NOT modify this!
struct Snake {
    int ratWeight;
    Snake *nextRat;
    Snake() : ratWeight(0), nextRat(nullptr) {}
    Snake(int x) : ratWeight(x), nextRat(nullptr) {}
    Snake(int x, Snake *nextRat) : ratWeight(x), nextRat(nextRat) {}
};

int** vomitAndCrawl(int rows, int cols, Snake* head) {
    // TODO
    int direction_cnt = 0; // 0 = go right
    int right = 0, down = 1, left = 2; up = 3;
    int now_col_dir = 0;
    int now_row_dir = 0;

    int **terr = new*[rows];
    for(int i = 0; i < rows; i++){
        terr[i] = new int [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            terr[i][j] = -1;
        }
    }

    while(1){
        int i = 0, j = 0;
        if(direction_cnt % 4 == right){
            now_col_dir = 0;
            now_row_dir = 1;
        }else if (direction_cnt % 4 == down){
            now_col_dir = 1;
            now_row_dir = 0;
        }else if(direction_cnt % 4 == left){
            now_col_dir = 0;
            now_row_dir = -1;
        }else{
            now_col_dir = -1;
            now_row_dir = 0;
        } 

        if(){
            
        }
        
        
    }







    return &terr;
}

// You MUST NOT modify this!
int main()
{
    int rows, cols, numOfRats;
    cin >> rows >> cols >> numOfRats;

    Snake* head = new Snake();
    Snake* current = head;

    for(int i=0; i<numOfRats ; i++)
    {
        cin >> current->ratWeight;
        if(i < numOfRats - 1)
        {
            Snake* nextRat = new Snake();
            current->nextRat = nextRat;
            current = current->nextRat;
        }
    }

    int** terrarium = vomitAndCrawl(rows, cols, head);

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << terrarium[i][j];
            if(j < cols-1)
                cout << " ";
        }
        if(i < rows-1)
            cout << "\n";
    }

    return 0;
}