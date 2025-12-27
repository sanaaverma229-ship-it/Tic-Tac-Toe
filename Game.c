#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};
char winner = ' ';
int turn_count = 0;

void display_board();
int check_win();
void mark_place(char mark);

void display_board()
{
    printf("\nTic-Tac-Toe\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  (1 | 2 | 3)\n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  (4 | 5 | 6)\n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  (7 | 8 | 9)\n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
    printf("-----------------\n");
}

int check_win()
{
    char m;
    
    for (int i = 0; i < 3; i++)
    {
        m = board[i][0];
        if (m != ' ' && board[i][1] == m && board[i][2] == m)
        {
            winner = m;
            return 1;
        }
        
        m = board[0][i];
        if (m != ' ' && board[1][i] == m && board[2][i] == m)
        {
            winner = m;
            return 1;
        }
    }
    
    m = board[0][0];
    if (m != ' ' && board[1][1] == m && board[2][2] == m)
    {
        winner = m;
        return 1;
    }
    
    m = board[0][2];
    if (m != ' ' && board[1][1] == m && board[2][0] == m)
    {
        winner = m;
        return 1;
    }
    
    return 0;
}

void mark_place(char mark)
{
    int pos = -1;
    int row, col;
    
    char *player_name = (mark == 'X') ? "Cross (X)" : "Circle (O)";
    
    while (1)
    {
        printf("%s Turn. Enter position (1-9): ", player_name);
        
        if (scanf("%d", &pos) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        while (getchar() != '\n');
        
        if (pos < 1 || pos > 9)
        {
            printf("Invalid position. Please enter a number from 1 to 9.\n");
            continue;
        }
        
        row = (pos - 1) / 3;
        col = (pos - 1) % 3;
        
        if (board[row][col] != ' ')
        {
            printf("Position %d is already occupied by '%c'. Choose a different spot.\n", pos, board[row][col]);
        }
        else
        {
            board[row][col] = mark;
            turn_count++;
            break;
        }
    }
}

int main()
{
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Cross (X) goes first, followed by Circle (O).\n");
    printf("Enter a number (1-9) to choose your position.\n");

    while (winner == ' ' && turn_count < 9)
    {
        display_board();
        mark_place('X');
        if (check_win()) break;
        
        if (turn_count < 9)
        {
            display_board();
            mark_place('O');
            if (check_win()) break;
        }
    }
    
    display_board();
    
    if (winner != ' ')
    {
        printf("Winner is: %c\n", winner);
    }
    else
    {
        printf("Game is a Draw!\n");
    }
    
    return 0;
}