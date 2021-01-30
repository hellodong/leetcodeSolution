

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int calcMatrixSize(int stringlen, int numRows)
{
    int blta, remain, lines, reline;

    blta = stringlen / (numRows * 2 - 2);
    remain = stringlen % (numRows * 2 - 2);
    reline = (remain <=numRows)?(remain + numRows - 1) / numRows:1+remain - numRows;

    lines = blta * (numRows - 1) + reline;
    return lines;
}

void posChar(int stridx, int rows, int *row, int *line)
{
    int blta, remain, reline;

    blta = stridx / (rows * 2 - 2);
    remain = stridx % (rows * 2 - 2);
    if (remain < rows){
        *row = remain;
        reline = 0;
    }else{
        *row = 2 * rows - remain - 2;
        reline = remain - rows + 1;
    }
    *line = (rows - 1) * blta + reline;
}

char *convert(char *s, int numRows)
{
    if (NULL == s || numRows <2){
        return s;
    }

    int lines, lens;
    lens = strlen(s);
    lines = calcMatrixSize(lens, numRows);    
    char (*matrix)[lines] = (char (*)[lines])malloc(lines * numRows);
    if (NULL == matrix){
        return NULL;
    }

    int idx, row, line;
    for(row = 0;row < numRows;row++){
        memset(matrix[row], 0x00, lines);
    }
    for (idx = 0; idx < lens;idx++) {
        posChar(idx, numRows, &row, &line);
        matrix[row][line] = s[idx];
    }

    idx = 0;
    for(row = 0;row < numRows;row++){
        for(line = 0;line < lines;line++){
            if(matrix[row][line] != 0){
                s[idx++] = matrix[row][line];
                //printf("%c ", matrix[row][line]);
            }else{
                //printf("  ");
            }
        }
        //printf("\n");
    }

    free(matrix);
    //puts(s);
    return s;
}

int main(void)
{
    char str[] = "hellowordabc";
    convert(str, 5);
    return 0;
}
