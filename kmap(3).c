#include <stdio.h>
#include <stdlib.h>

int main() {
    int kmap[8];
    int x = 0, i;
    printf("Enter The Minterm Values (0 or 1):\n");
    printf("Minterm 000 (A'B'C'): "); scanf("%d", &kmap[0]);
    printf("Minterm 001 (A'B'C):  "); scanf("%d", &kmap[1]);
    printf("Minterm 011 (A'BC):   "); scanf("%d", &kmap[2]);
    printf("Minterm 010 (A'BC'):  "); scanf("%d", &kmap[3]);
    printf("Minterm 100 (AB'C'):  "); scanf("%d", &kmap[4]);
    printf("Minterm 101 (AB'C):   "); scanf("%d", &kmap[5]);
    printf("Minterm 111 (ABC):    "); scanf("%d", &kmap[6]);
    printf("Minterm 110 (ABC'):   "); scanf("%d", &kmap[7]);
    int cnt=0;
    // for octal
    for(i=0;i<8;i++){if(kmap[i]) cnt++;}
	if(cnt==8){printf("1\n"); return 0;} 
	if(cnt==0){printf("0\n"); return 0;}
	x= 0;

    int first = 1;

    // checks for quads
    if (kmap[0] && kmap[1] && kmap[2] && kmap[3]) { if (!first) printf(" + "); printf("A'"); first = 0; }
    if (kmap[4] && kmap[5] && kmap[6] && kmap[7]) { if (!first) printf(" + "); printf("A");  first = 0; }
    if (kmap[0] && kmap[1] && kmap[4] && kmap[5]) { if (!first) printf(" + "); printf("B'"); first = 0; }
    if (kmap[2] && kmap[3] && kmap[6] && kmap[7]) { if (!first) printf(" + "); printf("B");  first = 0; }
    if (kmap[0] && kmap[3] && kmap[4] && kmap[7]) { if (!first) printf(" + "); printf("C'"); first = 0; }
    if (kmap[1] && kmap[2] && kmap[5] && kmap[6]) { if (!first) printf(" + "); printf("C");  first = 0; }

    // checks for pairs
    if (kmap[0] && kmap[1]) { if (!first) printf(" + "); printf("A'B'"); first = 0; }
    if (kmap[2] && kmap[3]) { if (!first) printf(" + "); printf("A'B");  first = 0; }
    if (kmap[4] && kmap[5]) { if (!first) printf(" + "); printf("AB'");  first = 0; }
    if (kmap[6] && kmap[7]) { if (!first) printf(" + "); printf("AB");   first = 0; }

    if (kmap[0] && kmap[3]) { if (!first) printf(" + "); printf("A'C'"); first = 0; }
    if (kmap[1] && kmap[2]) { if (!first) printf(" + "); printf("A'C");  first = 0; }
    if (kmap[4] && kmap[7]) { if (!first) printf(" + "); printf("AC'");  first = 0; }
    if (kmap[5] && kmap[6]) { if (!first) printf(" + "); printf("AC");   first = 0; }

    if (kmap[0] && kmap[4]) { if (!first) printf(" + "); printf("B'C'"); first = 0; }
    if (kmap[1] && kmap[5]) { if (!first) printf(" + "); printf("B'C");  first = 0; }
    if (kmap[2] && kmap[6]) { if (!first) printf(" + "); printf("BC");   first = 0; }
    if (kmap[3] && kmap[7]) { if (!first) printf(" + "); printf("BC'");  first = 0; }

    // checks for single pairs
    for (i = 0; i < 8; i++) {
        if (kmap[i]) {
            switch (i) {
                case 0: if (!first) printf(" + "); printf("A'B'C'"); break;
                case 1: if (!first) printf(" + "); printf("A'B'C");  break;
                case 2: if (!first) printf(" + "); printf("A'BC");   break;
                case 3: if (!first) printf(" + "); printf("A'BC'");  break;
                case 4: if (!first) printf(" + "); printf("AB'C'");  break;
                case 5: if (!first) printf(" + "); printf("AB'C");   break;
                case 6: if (!first) printf(" + "); printf("ABC");    break;
                case 7: if (!first) printf(" + "); printf("ABC'");   break;
            }
            first = 0;
        }
    }

    printf("\n");
    return 0;
}

