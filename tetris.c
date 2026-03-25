#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 10
#define HEIGHT 20

int board[HEIGHT][WIDTH];

int pieceX = WIDTH / 2;
int pieceY = 0;

int piece[4][4] = {
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0}
};

void draw()
{
    system("clear");

    for(int y=0;y<HEIGHT;y++)
    {
        for(int x=0;x<WIDTH;x++)
        {
            int filled = board[y][x];

            for(int py=0;py<4;py++)
            for(int px=0;px<4;px++)
            {
                if(piece[py][px] &&
                   y == pieceY+py &&
                   x == pieceX+px)
                   filled = 1;
            }

            printf(filled ? "[]" : " .");
        }
        printf("\n");
    }
}

int collision(int nx,int ny)
{
    for(int py=0;py<4;py++)
    for(int px=0;px<4;px++)
    {
        if(piece[py][px])
        {
            int x = nx + px;
            int y = ny + py;

            if(x < 0 || x >= WIDTH || y >= HEIGHT)
                return 1;

            if(y >= 0 && board[y][x])
                return 1;
        }
    }
    return 0;
}

void mergePiece()
{
    for(int py=0;py<4;py++)
    for(int px=0;px<4;px++)
    {
        if(piece[py][px])
            board[pieceY+py][pieceX+px] = 1;
    }

    pieceX = WIDTH/2;
    pieceY = 0;
}

void clearLines()
{
    for(int y=HEIGHT-1;y>=0;y--)
    {
        int full = 1;

        for(int x=0;x<WIDTH;x++)
            if(!board[y][x])
                full = 0;

        if(full)
        {
            for(int yy=y;yy>0;yy--)
                for(int x=0;x<WIDTH;x++)
                    board[yy][x] = board[yy-1][x];

            y++;
        }
    }
}

void enableRaw()
{
    struct termios t;
    tcgetattr(0,&t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0,TCSANOW,&t);
}

int kbhit()
{
    struct termios oldt,newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO,&oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newt);

    oldf = fcntl(STDIN_FILENO,F_GETFL,0);
    fcntl(STDIN_FILENO,F_SETFL,oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    fcntl(STDIN_FILENO,F_SETFL,oldf);

    if(ch != EOF)
    {
        ungetc(ch,stdin);
        return 1;
    }

    return 0;
}

int main()
{
    enableRaw();

    while(1)
    {
        draw();

        if(kbhit())
        {
            char c = getchar();

            if(c=='a' && !collision(pieceX-1,pieceY))
                pieceX--;

            if(c=='d' && !collision(pieceX+1,pieceY))
                pieceX++;

            if(c=='s' && !collision(pieceX,pieceY+1))
                pieceY++;
        }

        if(!collision(pieceX,pieceY+1))
            pieceY++;
        else
        {
            mergePiece();
            clearLines();
        }

        usleep(200000);
    }

    return 0;
}
