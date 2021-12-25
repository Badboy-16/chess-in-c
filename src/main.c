#include <stdio.h>
#include <stdbool.h>

#define WHITE 1
#define BLACK 0
#define FILES 8
#define RANKS 8
#define PIECES 32
#define PIECESPERSIDE PIECES/2
#define SQUARES FILES*RANKS

void makepieces();
void emptyboard();
void genboard();
void printboard();

const char piecelist[PIECES] = "RNBQKBNRPPPPPPPPpppppppprnbqkbnr";

struct piece {
    char type;
    int side;
    int file;
    int rank;
    bool board;
};

struct piece pieces[PIECES];

char board[RANKS][FILES];

int main()
{

}

void makepieces()
{
    for (int i = 0; i < PIECES; i++) {
        int fileindex = i % FILES;
        pieces[i].type = piecelist[i];
        pieces[i].file = fileindex;
        pieces[i].board = true;
        if (i < PIECESPERSIDE) {
            pieces[i].side = WHITE;
            pieces[i].rank = i / RANKS;
        } else {
            pieces[i].side = BLACK;
            pieces[i].rank = (i + SQUARES - PIECES) / RANKS;
        }
    }
}

void emptyboard()
{
    for (int r = 0; r < RANKS; r++) {
        for (int f = 0; f < FILES; f++) {
            board[r][f] = '.';
        }
    }
}

void genboard()
{
    struct piece *piecesptr = pieces;
    for (int i = 0; i < PIECES; i++) {
        int piecefile = piecesptr->file;
        int piecerank = piecesptr->rank;
        char piecetype = piecesptr->type;
        board[piecerank][piecefile] = piecetype;
        piecesptr++;
    }
}

void printboard()
{
    for (int r = RANKS - 1; r >= 0; r--) {
        for (int f = 0; f < FILES; f++) {
            printf("%c", board[r][f]);
            printf("%s", "   ");
        }
        printf("%s", "\n\n");
    }
}
