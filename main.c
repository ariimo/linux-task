#include <stdio.h>
#include <string.h> 
#include "str.h"

int main (int argc, char *argv[])
{
    char str[MAX_STR_LEN+1], guess[MAX_STR_LEN+1];
    int k;
    FILE *fp1;

    if(argc != 3) { fprintf(stderr, "사용법: %s 파일 key\n", argv[0]);
        return 1;
    }
    fp1 = fopen(argv[1], "r");
    if(fp1 == NULL) { fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }
    k = strlen(argv[2]);
    if(k < 2) { fprintf(stderr, "키 %s는 두 자리 이상이어야 함.\n", argv[2]);
        return 3;
    }

    while (fgets(str, MAX_STR_LEN, fp1) != NULL ) {
        printf("%s", str);
        encrypt(str, guess, argv[2]);
        printf("-> %s", guess);
        printf("\n");
    }
    return 0;
}
