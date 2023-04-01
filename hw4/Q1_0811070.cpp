#include <iostream>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

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
    int direction_cnt = 0;
    int now_col_dir = 0;
    int now_row_dir = 0;
    int now_row = 0;
    int now_col = 0;

    int **terr = new int*[rows];
    for(int i = 0; i < rows; i++){
        terr[i] = new int [cols];
    }

    // initialize the 2d array [ok]
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            terr[i][j] = -1;
            //cout << terr[i][j] << " ";
        }
        //cout << endl;
    }

    while(1){
        // determine the boundary
        if(rows == 1){
            /*only one rows*/
            direction_cnt = 0;

        }else{
            if(now_row == rows - 1 && now_col == 0){
                /* touch boundary 1*/
                direction_cnt ++;
            }else if(now_row == rows - 1 && now_col == cols - 1){
                /* touch boundary 2*/
                direction_cnt ++;
            }else if(now_row == 0 && now_col == cols - 1){
                /* touch boundary 3*/
                direction_cnt ++;
            }else if(terr[now_row + now_row_dir][now_col + now_col_dir] != -1){
                /* touch snack*/
                direction_cnt ++;
            }else{}
        }

        // assign values to the matrix
        terr[now_row][now_col] = head -> ratWeight;

        //cout << now_row << " " << now_col << " " << head -> ratWeight << endl;
        head = head -> nextRat;

        if(head == nullptr){
            break;
        }

        // determine the direction
        if(direction_cnt % 4 == RIGHT){
            now_col_dir = 1;
            now_row_dir = 0;
        }else if (direction_cnt % 4 == DOWN){
            now_col_dir = 0;
            now_row_dir = 1;
        }else if(direction_cnt % 4 == LEFT){
            now_col_dir = -1;
            now_row_dir = 0;
        }else{
            now_col_dir = 0;
            now_row_dir = -1;
        }

        now_col += now_col_dir;
        now_row += now_row_dir;
    }

    return terr;
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