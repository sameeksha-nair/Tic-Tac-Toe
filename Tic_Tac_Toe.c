#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void InitializeBoard(int m, int n , char board[][n])
{
    int c =1;
    for(int i =0; i<m; i++)
    {
       for(int j=0; j< n; j++)
       {
          board[i][j] = c+'0';
          c++;
       }
    }
}
void PrintBoard(int m, int n, char board[][n])
{
    printf("\n");
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<3;j++)
         {   
            
            if(j<2)
            {
                printf("  %c  |",board[i][j]);
            }
            else
            {
                 printf("  %c   ",board[i][j]);
            }

         }
         printf("\n"); if(i<2)printf("_____|_____|_____\n");
     } printf("\n");

}
void CreateBoard(int m, int n, char board[][n])
{
    int num; char c;
    char let[2];
    printf("\nEnter the number of the cell where you want to insert 'X' or 'O': ");
    scanf("%d", &num);
    while(num<1 || num>9)
    {
         PrintBoard(3,3,board);
         printf("\nEnter the number of the cell where you want to insert 'X' or 'O': ");
         scanf("%d", &num);

    }
    printf("\nType 'X' or 'O': ");
    scanf("%s", let); c= let[0]; c=toupper(c);
    while(c!='X'&& c!='O')
    {
      printf("\nType 'X' or 'O': ");
      scanf("%s", let); c= let[0]; c=toupper(c);   
    }
    printf("\n");
    switch(num)
    {
        case 1: board[0][0]=c; break;
        case 2: board[0][1]=c; break;
        case 3: board[0][2]=c; break;
        case 4: board[1][0]=c; break;
        case 5: board[1][1]=c; break;
        case 6: board[1][2]=c; break;
        case 7: board[2][0]=c; break;
        case 8: board[2][1]=c; break;
        case 9: board[2][2]=c; break;
        default: printf("\nEnter valid number");
    }
}
int IsValidBoard(int m, int n, char board[][n])
{
    int x=0,o=0;
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(board[i][j]=='X')x++;
                 else if(board[i][j]=='O')o++;
             }
         }
    if(x-o==1||x-o==0||x-o==-1)
    {
        printf("\nBoard is valid\n");
        return 1;
    }
    else
     {
         printf("\nBoard is invalid\nTry Again\n");
         exit(0);
         
     }
}
void ListWinningCells(int m, int n, char board[][n])
{
    int k=0;
     for (int i=0; i<m; i++) 
    { 
        if(board[i][0]==board[i][1] && board[i][2]>46 && board[i][2]<58)
        {
              printf("\nCell %c Player %c wins", board[i][2],board[i][0]); k++;
        }
        if(board[i][0]==board[i][2] && board[i][1]>48 && board[i][1]<58)
        {
              printf("\nCell %c Player %c wins", board[i][1],board[i][2]); k++;
        } 
        if(board[i][2]==board[i][1] && board[i][0]>48 && board[i][0]<58)
        {
              printf("\nCell %c Player %c wins", board[i][0],board[i][2]); k++;
        } 
    }
    for(int j=0; j<m;j++)
    {
        if(board[0][j]==board[1][j] && board[2][j]>48 && board[2][j]<58)
        {
              printf("\nCell %c Player %c wins", board[2][j],board[0][j]); k++;
        } 
        if(board[0][j]==board[2][j] && board[1][j]>48 && board[1][j]<58)
        {
              printf("\nCell %c Player %c wins", board[1][j],board[2][j]); k++;
        }
        if(board[1][j]==board[2][j] && board[0][j]>48 && board[0][j]<58)
        {
              printf("\nCell %c Player %c wins", board[0][j],board[2][j]); k++;
        }
    }
         if(board[0][0]==board[1][1] && board[2][2]>48 && board[2][2]<58)
        {
              printf("\nCell %c Player %c wins", board[2][2],board[0][0]); k++;
        } 
        if(board[0][0]==board[2][2] && board[1][1]>48 && board[1][1]<58)
        {
              printf("\nCell %c Player %c wins", board[1][1],board[0][0]); k++;
        }
        if(board[1][1]==board[2][2] && board[0][0]>48 && board[0][0]<58)
        {
              printf("\nCell %c Player %c wins", board[0][0],board[1][1]); k++;
        }
        if(board[0][2]==board[1][1] && board[2][0]>48 && board[2][0]<58)
        {
            printf("\nCell %c Player %c wins", board[2][0],board[1][1]); k++; 
        } 
        if(board[1][1]==board[2][0] && board[0][2]>48 && board[0][2]<58)
        {
            printf("\nCell %c Player %c wins", board[0][2],board[1][1]); k++; 
        }
        if(board[2][0]==board[0][2] && board[1][1]>48 && board[1][1]<58)
        {
            printf("\nCell %c Player %c wins", board[1][1],board[0][2]); k++; 
        }
        
if(k==0) printf("\nNo winning cells");
printf("\n");
}
char WhoIsTheWinner(int m, int n, char board[][n])
{
    int k=0,i=0,j=0;
    if ((board[0][0] == board[0][1]) && board[0][0] == board[0][2])
    {
        printf("\nPlayer %c is the winner", board[0][0]); 
        exit(0);
    }
    else if ((board[2][0] == board[2][1]) && board[2][0] == board[2][2])
    {
        printf("\nPlayer %c is the winner", board[2][0]); 
        exit(0);
    }
    else if ((board[0][0] == board[1][0]) && board[0][0] == board[2][0])
    {
        printf("\nPlayer %c is the winner", board[0][0]); 
        exit(0);
    }
    else if ((board[0][2] == board[1][2]) && board[0][2] == board[2][2])
    {
        printf("\nPlayer %c is the winner", board[0][2]); 
        exit(0);
    }
    else if ((board[0][0] == board[1][1]) && board[0][0] == board[2][2])
    {
        printf("\nPlayer %c is the winner", board[0][0]); 
        exit(0);
    }
    else if ((board[0][2] == board[1][1]) && board[0][2] == board[2][0])
    {
        printf("\nPlayer %c is the winner", board[0][2]); ;
        exit(0);
    }
    else if ((board[1][0] == board[1][1]) && board[1][0] == board[1][2])
    {
        printf("\nPlayer %c is the winner", board[1][0]); 
        exit(0);
    }
    else if ((board[0][1] == board[1][1]) && board[0][1] == board[2][1])
    {
        printf("\nPlayer %c is the winner", board[0][1]); 
        exit(0);
    }
        for(i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if(board[i][j]=='X' || board[i][j]=='O')k++;
            }
        }
        if(k==9)printf("\nDraw\n");
    
    printf("\n\n\n"); return 0;
}
void Start(int m, int n, char board[][n])
{
    InitializeBoard(3,3,board);
    for(int i=0;i<9;i++)
    {
       PrintBoard(3,3,board);
       CreateBoard(3,3,board);
       IsValidBoard(3,3,board);
       ListWinningCells(3,3,board);
       WhoIsTheWinner(3,3,board);
    }
}

int main()
{
   char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
   char temp;
   
   printf("Welcome to TIC-TAC-TOE!\n");
   printf("Press s to start :)\n-->");
   scanf("%c", &temp);
   temp= tolower(temp);
   while(temp!='s'){
       printf("Please type s");
   }
   Start(3,3,board);
   while( getchar() != '\n' );
   main();
}   

