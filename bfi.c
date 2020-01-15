#include <stdio.h>

char tape[30000] = {0};
char code[30000];

int main(int argc, char *argv[]) {
    int ip, j = 0, k = 0;
    int ret_addr[3000];
    char *ptr = tape;
    FILE *fp;
    fp = fopen(argv[1], "r");
    while((code[k++] = fgetc(fp)) != EOF);
    for(ip = 0; code[ip]; ip++) {
        switch(code[ip]) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++*ptr;
                break;
            case '-':
                --*ptr;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                 ret_addr[j++] = ip;
                 break;
            case ']':
                if(*ptr)
                    ip = ret_addr[j - 1];
                else
                    j--;
                break;
        }
    }
    fclose(fp);
    return 0;
}
