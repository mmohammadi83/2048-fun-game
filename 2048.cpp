#include <iostream>
#include <ctime>
#include <conio.h>

#define size 4

using namespace std;

void start_game();
void init(int [][size]);
void gennum(int [][size]);
void print_board(int [][size]);
int maximum(int [][size]);
bool is_continue(int [][size]);
void move(int [][size] , char );
int howmuch_digit(int );
void down(int [][size]);
void up(int [][size]);
void right(int [][size]);
void left(int [][size]);

int main() {
    system("cls");
    cout << "\t\t\t\tWelcome to 2048 game" << endl << endl;
    cout << "\t\t\t\t1. Start new game" << endl;
    cout << "\t\t\t\t2. Exit" << endl;
    cout << "\t\t\t\tenter your choose by number: ";
    short choose;
    choose = int(getch())-48;

    switch(choose){
        case 1: 
            system("cls");
            start_game();
            break;
        case 2:
            return 0;
        default:
            cout << "\n\n\t\t\t\tnot avable! try again." ;
            getch();
            main();        
    }
    
    return 0;
}

void start_game(){
    int board[size][size];

    init(board);
    gennum(board);
    gennum(board);
    print_board(board);

    char keymove;
    while (true) {
        keymove = getch();

        move(board , keymove);
        
        int max = maximum(board);
        if(max == 2048){
            cout << endl << "\t\t****************** congratulation! you are win *******************" << endl;
            break;
        }
        else if (!is_continue(board)) 
            gennum(board);
        else{
            cout << endl << "\t\txxxxxxxxxxxxx   oops! Game Over. you are loser. hahahahahaha  xxxxxxxxxxxxx" << endl;
            break;
        }
        system("cls");
        print_board(board);
    }
    getch();
    exit(0);
}

int howmuch_digit(int num){

    int digit = 0;
    while(num > 0){
        num = num / 10;
        digit++;
    }
    return digit;
}

void move(int board[][size] , char key){
    // move left
    if(key == 'a' || key == 'A'){
        left(board);
    }
    // move right
    else if(key == 'd' || key == 'D'){
        right(board);
    }
    // move up
    else if(key == 'w' || key == 'W'){
        up(board);
    }
    // move down
    else if(key == 's' || key == 'S'){
        down(board);
    }
    else if(key == 'e' || key == 'E'){
        exit(0);
    }
    else{
        char keymove;
        keymove = getch();
        move(board , keymove);
    }
}

void left(int board[][size]){
    for (int i = 0; i < size; i++) {
            int pre = 0;
            int current = 0;
            int merge = 0;

            for (int j = 0; j < size; j++) {
                if (board[i][j] != 0) {
                    if (current == 0) {
                        current = board[i][j];
                    } 
                    else {
                        pre = current;
                        current = board[i][j];

                        if (pre == current) {
                            board[i][merge] = pre + current;
                            merge++;
                            current = 0;
                        } 
                        else {
                            board[i][merge] = pre;
                            merge++;
                            pre = current;
                            current = board[i][j];
                        } // 2 4 8
                    }
                }
        }

        if (current != 0) 
            board[i][merge] = current;
        

        for (int j = merge + 1; j < size; j++) 
            board[i][j] = 0;
        
    }
}

void right(int board[][size]){
    for (int i = 0; i < size; i++) {
        int pre = 0;
        int current = 0;
        int merge = size - 1;

        for (int j = size - 1; j >= 0; j--) {
            if (board[i][j] != 0) {
                if (current == 0) {
                    current = board[i][j];
                } 
                else {
                    pre = current;
                    current = board[i][j];

                    if (pre == current) {
                        board[i][merge] = pre + current;
                        merge--;
                        current = 0;
                    } 
                    else {
                        board[i][merge] = pre;
                        merge--;
                        pre = current;
                        current = board[i][j];
                    }
                }
            }
        }

        if (current != 0) 
            board[i][merge] = current;
        

        for (int j = merge - 1; j >= 0; j--) 
            board[i][j] = 0;
        
    }
}

void up(int board[][size]){
    for (int j = 0; j < size; j++) {
        int pre = 0;
        int current = 0;
        int merge = 0;

        for (int i = 0; i < size; i++) {
            if (board[i][j] != 0) {
                if (current == 0) {
                    current = board[i][j];
                } 
                else {
                    pre = current;
                    current = board[i][j];

                    if (pre == current) {
                        board[merge][j] = pre + current;
                        merge++;
                        current = 0;
                    } 
                    else {
                        board[merge][j] = pre;
                        merge++;
                        pre = current;
                        current = board[i][j];
                    }
                }
            }
        }

        if (current != 0) 
            board[merge][j] = current;
        

        for (int i = merge + 1; i < size; i++) 
            board[i][j] = 0;
        
    }
}

void down(int board[][size]){
    for (int j = 0; j < size; j++) {
        int pre = 0;
        int current = 0;
        int merge = size - 1;

        for (int i = size - 1; i >= 0; i--) {
            if (board[i][j] != 0) {
                if (current == 0) {
                    current = board[i][j];
                } 
                else {
                    pre = current;
                    current = board[i][j];

                    if (pre == current) {
                        board[merge][j] = pre + current;
                        merge--;
                        current = 0;
                    } 
                    else {
                        board[merge][j] = pre;
                        merge--;
                        pre = current;
                        current = board[i][j];
                    }
                }
            }
        }

        if (current != 0) 
            board[merge][j] = current;
        

        for (int i = merge - 1; i >= 0; i--) 
            board[i][j] = 0;
        
    }
}

void init(int board [][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

void gennum(int board [][size]) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                counter++;
            }
        }
    }

    if (counter == 0) {
        return;
    }

    srand(time(NULL));
    int rnumber = rand() % counter + 1;

    counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                counter++;
                if (counter == rnumber) {
                    board[i][j] = (rand() % 2 + 1) * 2;
                    return;
                }
            }
        }
    }
}

void print_board(int board [][size]) {
    cout<<"enter 'E' or 'e' for exit game\n";
    cout << "'w'up 's'down 'd'right 'a'left \n\n";
    cout << "\t\t\t\t-------------------------" << endl;
    for (int i = 0; i < size*2 ; i++) {
        if(i % 2 == 0){
            int r = i/2;
            cout << "\t\t\t\t";
            for (int j = 0; j < size; j++) {
                if (board[r][j] == 0) 
                    cout << "|     ";
                else{
                    int digit = howmuch_digit(board[r][j]);
                    if(digit == 1) cout << "|  " << board[r][j] << "  ";
                    else if(digit == 2) cout << "| " << board[r][j] << "  ";
                    else if(digit == 3) cout << "| " << board[r][j] << " ";
                    else cout << "|" << board[r][j] <<" ";

                }
            }
            cout << "|" <<endl;
        }
        else
            cout << "\t\t\t\t-------------------------" << endl;
    }
}

int maximum(int board [][size]){
    int max = 0;
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(max < board[i][j])
                max = board[i][j];
        }
    }

    return max;
}

bool is_continue(int board [][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) 
                return false;
            
            if ((i < size - 1 && board[i][j] == board[i + 1][j]) || (j < size - 1 && board[i][j] == board[i][j + 1]))
                return false;
            
        }
    }
    return true;
}