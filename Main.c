
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MATRIX_SIZE 4

int counter=0;

bool isWord(char s[]) {

return (!strcmp(s, "CAT") |
!strcmp(s, "CATS") |
!strcmp(s, "TRAM") |
!strcmp(s, "TRAMS") |
!strcmp(s, "TAME") | 
!strcmp(s, "CAR") |
!strcmp(s, "CARS") |
!strcmp(s, "RAT") | 
!strcmp(s, "RATS") |
!strcmp(s, "RAMP") |
!strcmp(s, "ART") |
!strcmp(s, "CART") |
!strcmp(s, "STAMP") | 
!strcmp(s, "TAKEN") |
!strcmp(s, "MEN") |
!strcmp(s, "MAKE") |
!strcmp(s, "TAKE") |
!strcmp(s, "ATE") |
!strcmp(s, "SELL") |
!strcmp(s, "STEEL") | 
!strcmp(s, "RAKE"));
}

void printWords(char matrixword[MATRIX_SIZE][MATRIX_SIZE],int i,int j,char str[],int check[MATRIX_SIZE][MATRIX_SIZE])
{
    char temp[16]={'\0'};
    strcpy(temp,str);
    int check1[4][4]={0};
    int up,down,left,right;
    memcpy(check1,check,4*4*sizeof(int));
    if(!check1[i][j]&&(i>-1&&j>-1&&i<MATRIX_SIZE&&j<MATRIX_SIZE)){
        char letter[2]={matrixword[i][j],'\0'};
        strcat(temp,letter);
        if(isWord(temp))
        {
            printf("%s\n",temp);
            counter++;
        }
        up=i-1;
        down=i+1;
        left=j-1;
        right=j+1;
        check1[i][j]=1;

        printWords(matrixword,up,j,temp,check1);
        printWords(matrixword,down,j,temp,check1);
        printWords(matrixword,i,left,temp,check1);
        printWords(matrixword,i,right,temp,check1);
    }
}

int main()
{
    char matrix[MATRIX_SIZE][MATRIX_SIZE]={{'C','A','R','T'},{'E','T','A','K'},{'E','S','M','E'},{'L','L','P','N'}};

     for(int i=0;i<MATRIX_SIZE;i++)
        {
            for(int j=0; j<MATRIX_SIZE; j++)
            {
                    char str[16]={'\0'};
                    int check[MATRIX_SIZE][MATRIX_SIZE]={0};
                    printWords(matrix,i,j,str,check);
            }
        }
        printf("\nWords found: %d",counter);
    	system("pause");

        return 0;
}


