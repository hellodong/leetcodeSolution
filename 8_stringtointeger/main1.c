#include <stdio.h>

int myatoi(char *str)
{
    int flag = 1;
    char *ptr = str;

    printf("%s\n", str);

    if (NULL == str){
        return 0;
    }
    
    for (;*ptr;ptr++) {
        if (*ptr == ' '){
            str++;
            continue;
        }else if (*ptr == '-'){
            flag = -1;
            str++;
        }else if (*ptr == '+'){
            flag = 1;
            str++;
        }else if (*ptr < '0' || *ptr > '9'){
            if (str == ptr){
                return 0;
            }
        }else{
            break;
        }
    }

    unsigned int bitval = 0, preval = 0;
    for (;*ptr;ptr++){
        if (*ptr <= '9' && *ptr >= '0'){
            bitval = bitval * 10 +(*ptr - '0');
        }else {
            break;
        }

        if (preval > bitval){
            if (flag == 1){
                return 0x80000000 - 1;
            }else{
                return 0x80000000;
            }
        }
        preval = bitval;
    }
    
    if (flag == 1){
        if (bitval > (0x80000000 - 1)){
            return 0x80000000 - 1;
        }
    }else {
        if (bitval > 0x80000000){
            return 0x80000000;
        }
    }
    return flag * bitval;
}

int main(int argc ,char *argv[])
{
    printf ("%d\n", myatoi(argv[1]));
    return 0;
}
    
