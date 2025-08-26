#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    int kmap[4];
    printf("Enter The Minterm Values (0 or 1):\n");
    printf("Minterm 00 (A=0,B=0): ");
    scanf("%d", &kmap[0]);
    printf("Minterm 01 (A=0,B=1): ");
    scanf("%d", &kmap[1]);
    printf("Minterm 10 (A=1,B=0): ");
    scanf("%d", &kmap[2]);
    printf("Minterm 11 (A=1,B=1): ");
    scanf("%d", &kmap[3]);
    printf("\nFinal expression:\n");
    printf("F(A,B) = ");
    if (kmap[0] && kmap[1] && kmap[2] && kmap[3]) {
        printf("1\n");
        return 0;
    }
    int x= 0;
    if (kmap[0] && kmap[1]){
    if (x) printf(" + ");
    printf("A'");
    x = 1;
}
    if (kmap[2] && kmap[3]){
    if (x) printf(" + ");
    printf("A");
    x = 1;
    }
    if (kmap[0] && kmap[2]){
    if (x) printf(" + ");
    printf("B'");
    x = 1;
    }
    if (kmap[1] && kmap[3]){
    if (x) printf(" + ");
    printf("B");
    x = 1;
    }
    if (!x) {
        int first = 1;
        for (i = 0; i < 4; i++) {
            if (kmap[i] == 1) {
                if (!first) printf(" + ");
                switch (i) {
                    case 0: printf("A'B'"); break;
                    case 1: printf("A'B");  break;
                    case 2: printf("AB'");   break;
                    case 3: printf("AB");  break;
                }
                first = 0;
            }
        }
        if (first){
            printf("0");
		}
    }
    printf("\n");
    return 0;
}

