#include <iostream>
#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

using namespace std;

// You MUST NOT modify this!
struct Snake {
    int ratWeight;
    Snake *nextRat;
    Snake() : ratWeight(0), nextRat(NULL) {}
    Snake(int x) : ratWeight(x), nextRat(NULL) {}
    Snake(int x, Snake *nextRat) : ratWeight(x), nextRat(nextRat) {}
};

int** vomitAndCrawl(int length, Snake* head) {
    int** terrarium = new int*[length];
    for(int i=0; i<length; i++)
    {
        terrarium[i] = new int[length];
        for(int j=0; j<length; j++)
        {
            terrarium[i][j] = -1;
        }
    }
    // TODO
    int now_dir = 0;
    int now_raw = 0;
    int now_col = 0;
    int raw_add = 0;
    int col_add = 0;
    
    while(1){
    	if(length == 1){
    		now_dir = 0;
		}else{
			if(now_col == 0 && now_raw == length - 1){
				now_dir++;
			}else if(now_col == length - 1 && now_raw == length - 1){
				now_dir ++;
			}else if(now_col == length - 1 && now_raw == 0){
				now_dir ++;
			}else if(terrarium[now_raw + raw_add][now_col + col_add] != -1){
				now_dir ++;
			}else{}
		}
		
		terrarium[now_raw][now_col] = head -> ratWeight;
		head = head -> nextRat;
		if(head == NULL){
			break;
		}
		
		if(now_dir %4 == DOWN){
			raw_add = 1;
			col_add = 0;
		}else if(now_dir %4 == RIGHT){
			raw_add = 0;
			col_add = 1;
		}else if(now_dir %4 == UP){
			raw_add = -1;
			col_add = 0;
		}else{
			raw_add = 0;
			col_add = -1;
		}
		
		now_raw += raw_add;
		now_col += col_add;
	}
    //
    return terrarium;
}

// You MUST NOT modify this!
int main()
{
    int length, numOfRats;
    cin >> length >> numOfRats;

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

    int** terrarium = vomitAndCrawl(length, head);

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            cout << terrarium[i][j];
            if(j < length-1)
                cout << " ";
        }
        if(i < length-1)
            cout << "\n";
    }

    return 0;
}

