// Kmap_Solver For (2,3,4) Variables
// Priority Order Is : Double Octate -> Octate -> Quad -> Double Pair -> Single Pair
#include <stdio.h>
#include <stdlib.h>
int main() {
	int choice;
	printf("Enter The No Of Variables In Kmap : (2 (OR) 3 (OR) 4): "); scanf("%d",&choice);
	if(choice==4){
    int kmap[16],i,cnt = 0, x = 0, coverage[16] = {0};
    printf("Enter The minterms value 0 or 1:\n");
    printf(" 0 Minterm 0000 (A'B'C'D'): ");   scanf("%d", &kmap[0]);
    printf(" 1 Minterm 0001 (A'B'C'D ): ");   scanf("%d", &kmap[1]);
    printf(" 2 Minterm 0010 (A'B'C D'): ");   scanf("%d", &kmap[2]);
    printf(" 3 Minterm 0011 (A'B'C D ): ");   scanf("%d", &kmap[3]);
    printf(" 4 Minterm 0100 (A'B C'D'): ");   scanf("%d", &kmap[4]);
    printf(" 5 Minterm 0101 (A'B C'D ): ");   scanf("%d", &kmap[5]);
    printf(" 6 Minterm 0110 (A'B C D'): ");   scanf("%d", &kmap[6]);
    printf(" 7 Minterm 0111 (A'B C D ): ");   scanf("%d", &kmap[7]);
    printf(" 8 Minterm 1000 (A B'C'D'): ");   scanf("%d", &kmap[8]);
    printf(" 9 Minterm 1001 (A B'C'D ): ");   scanf("%d", &kmap[9]);
    printf(" 10 Minterm 1010 (A B'C D'): ");  scanf("%d", &kmap[10]);
    printf(" 11 Minterm 1011 (A B'C D ): ");   scanf("%d", &kmap[11]);
    printf(" 12 Minterm 1100 (A B C'D'): ");   scanf("%d", &kmap[12]);
    printf(" 13 Minterm 1101 (A B C'D ): ");   scanf("%d", &kmap[13]);
    printf(" 14 Minterm 1110 (A B C D'): ");   scanf("%d", &kmap[14]);
    printf(" 15 Minterm 1111 (A B C D ): ");   scanf("%d", &kmap[15]);
    printf("Final Expression is :\n");
    printf("F(A,B,C,D) = ");
    for (i = 0; i < 16; i++) {if (kmap[i] == 1) cnt++;}
    if (cnt == 16) {printf("1\n"); return 0;} // Checking If Any Double Octate Is Formed
    if(cnt==0) {printf("0\n"); return 0;} // Checking If There Are No Min Terms
    // Checking If Any Octates Are Formed
    if(kmap[0] && kmap[1] && kmap[2] && kmap[3] && kmap[4] && kmap[5] && kmap[6] && kmap[7]){
    	if(x) printf(" + ");
    	printf("A'"); x = coverage[0] = coverage[1] = coverage[2] = coverage[3] = coverage[4] = coverage[5] = coverage[6] = coverage[7] = 1;
	}
	if(kmap[4] && kmap[5] && kmap[6] && kmap[7] && kmap[8] && kmap[9] && kmap[10] && kmap[11]){
		if(x) printf(" + ");
		printf("B"); x = coverage[4] = coverage[5] = coverage[6] = coverage[7] = coverage[8] = coverage[9] = coverage[10] = coverage[11] = 1;
	}
	if(kmap[12] && kmap[13] && kmap[14] && kmap[15] && kmap[8] && kmap[9] && kmap[10] && kmap[11]){
		if(x) printf(" + ");
		printf("A"); x = coverage[12] = coverage[13] = coverage[14] = coverage[15] = coverage[8] = coverage[9] = coverage[10] = coverage[11] = 1;
	}
	if(kmap[0] && kmap[1] && kmap[2] && kmap[3] && kmap[12] && kmap[13] && kmap[14] && kmap[15]){
		if(x) printf(" + ");
	    printf("B'"); x = coverage[0] = coverage[1] = coverage[2] = coverage[3] = coverage[12] = coverage[13] = coverage[14] = coverage[15] = 1;
	}
	if(kmap[0] && kmap[4] && kmap[8] && kmap[12] && kmap[1] && kmap[5] && kmap[9] && kmap[13]){
		if(x) printf(" + ");
		printf("C'"); x = coverage[0] = coverage[4] = coverage[8] = coverage[12] = coverage[1] = coverage[5] = coverage[9] = coverage[13] = 1;
	}
	if(kmap[1] && kmap[5] && kmap[9] && kmap[13] && kmap[2] && kmap[6] && kmap[10] && kmap[14]){
		if(x) printf(" + ");
		printf("D"); x = coverage[2] = coverage[6] = coverage[10] = coverage[14] = coverage[1] = coverage[5] = coverage[9] = coverage[13] = 1;
	}
	if(kmap[2] && kmap[6] && kmap[10] && kmap[14] && kmap[3] && kmap[7] && kmap[11] && kmap[15]){
		if(x) printf(" + ");
		printf("C"); x = coverage[2] = coverage[6] = coverage[10] = coverage[14] = coverage[3] = coverage[7] = coverage[11] = coverage[15] = 1;
	}
	if(kmap[0] && kmap[4] && kmap[8] && kmap[12] && kmap[3] && kmap[7] && kmap[11] && kmap[15]){
		if(x) printf(" + ");
		printf("D'"); x = coverage[0] = coverage[4] = coverage[8] = coverage[12] = coverage[3] = coverage[7] = coverage[11] = coverage[15] = 1;
	}
    // Checking if any Quads Are Formed
    if(kmap[0] && kmap[1] && kmap[4] && kmap[5] && (!coverage[0] || !coverage[1] || !coverage[4] || !coverage[5])){
    	if(x) printf(" + ");
    	printf("A'C'"); x = coverage[0] = coverage[1] = coverage[4] = coverage[5] = 1;
	}
	if(kmap[1] && kmap[2] && kmap[6] && kmap[5] && (!coverage[1] || !coverage[2] || !coverage[6] || !coverage[5])){
		if(x) printf(" + ");
		printf("A'D"); x = coverage[2] = coverage[1] = coverage[6] = coverage[5] = 1;
	}
	if(kmap[3] && kmap[2] && kmap[6] && kmap[7] && (!coverage[3] || !coverage[2] || !coverage[6] || !coverage[7])){
		if(x) printf(" + ");
		printf("A'C"); x = coverage[2] = coverage[3] = coverage[6] = coverage[7] = 1;
	}
	if(kmap[4] && kmap[5] && kmap[8] && kmap[9] && (!coverage[4] || !coverage[5] || !coverage[8] || !coverage[9])){
		if(x) printf(" + ");
		printf("BC'"); x = coverage[4] = coverage[5] = coverage[8] = coverage[9] = 1;
	}
	if(kmap[5] && kmap[6] && kmap[9] && kmap[10] && (!coverage[5] || !coverage[6] || !coverage[9] || !coverage[10])){
		if(x) printf(" + ");
		printf("BD"); x = coverage[5] = coverage[6] = coverage[9] = coverage[10] = 1;
	}
	if(kmap[6] && kmap[7] && kmap[10] && kmap[11] && (!coverage[6] || !coverage[7] || !coverage[10] || !coverage[11])){
		if(x) printf(" + ");
		printf("BC"); x = coverage[6] = coverage[7] = coverage[10] = coverage[11] = 1;
	}
	if(kmap[8] && kmap[9] && kmap[12] && kmap[13] && (!coverage[8] || !coverage[9] || !coverage[12] || !coverage[13])){
		if(x) printf(" + ");
		printf("AC'"); x = coverage[8] = coverage[9] = coverage[12] = coverage[13] = 1;
	}
	if(kmap[9] && kmap[10] && kmap[13] && kmap[14] && (!coverage[9] || !coverage[10] || !coverage[13] || !coverage[14])){
		if(x) printf(" + ");
		printf("AD"); x = coverage[9] = coverage[10] = coverage[13] = coverage[14] = 1;
	}
	if(kmap[10] && kmap[11] && kmap[14] && kmap[15] && (!coverage[10] || !coverage[11] || !coverage[14] || !coverage[15])){
		if(x) printf(" + ");
		printf("AC"); x = coverage[10] = coverage[11] = coverage[14] = coverage[15] = 1;
	}
	if(kmap[0] && kmap[1] && kmap[2] && kmap[3] && (!coverage[0] || !coverage[1] || !coverage[2] || !coverage[3])){
		if(x) printf(" + ");
		printf("A'B'"); x = coverage[0] = coverage[1] = coverage[2] = coverage[3] = 1;
	}
	if(kmap[4] && kmap[5] && kmap[6] && kmap[7] && (!coverage[4] || !coverage[5] || !coverage[6] || !coverage[7])){
		if(x) printf(" + ");
		printf("A'B"); x = coverage[4] = coverage[5] = coverage[6] = coverage[7] = 1;
	}
	if(kmap[8] && kmap[9] && kmap[10] && kmap[11] && (!coverage[8] || !coverage[9] || !coverage[10] || !coverage[11])){
		if(x) printf(" + ");
		printf("AB"); x = coverage[8] = coverage[9] = coverage[10] = coverage[11] = 1;
	}
	if(kmap[12] && kmap[13] && kmap[14] && kmap[15] && (!coverage[12] || !coverage[13] || !coverage[14] || !coverage[15])){
		if(x) printf(" + ");
		printf("AB'"); x = coverage[12] = coverage[13] = coverage[14] = coverage[15] = 1;
	}
	 if(kmap[0] && kmap[4] && kmap[12] && kmap[8] && (!coverage[0] || !coverage[4] || !coverage[12] || !coverage[8])) {
        if(x) printf(" + ");
        printf("C'D'"); x = coverage[0] = coverage[4] = coverage[12] = coverage[8] = 1;
    }

    if(kmap[1] && kmap[5] && kmap[13] && kmap[9] && (!coverage[1] || !coverage[5] || !coverage[13] || !coverage[9])) {
        if(x) printf(" + ");
        printf("C'D"); x = coverage[1] = coverage[5] = coverage[13] = coverage[9] = 1;
    }

    if(kmap[3] && kmap[7] && kmap[15] && kmap[11] && (!coverage[3] || !coverage[7] || !coverage[15] || !coverage[11])) {
        if(x) printf(" + ");
        printf("CD'"); x = coverage[3] = coverage[7] = coverage[15] = coverage[11] = 1;
    }

    if(kmap[2] && kmap[6] && kmap[14] && kmap[10] && (!coverage[2] || !coverage[6] || !coverage[14] || !coverage[10])) {
        if(x) printf(" + ");
        printf("CD"); x = coverage[2] = coverage[6] = coverage[14] = coverage[10] = 1;
    }
    if(kmap[0] && kmap[3] && kmap[12] && kmap[15] && (!coverage[0] || !coverage[12] || !coverage[15] || !coverage[3])){
    	if(x) printf(" + ");
    	printf("B'D'"); x = coverage[0] = coverage[3] = coverage[12] = coverage[15] = 1;
	}
	if(kmap[0] && kmap[1] && kmap[12] && kmap[13] && (!coverage[0] || !coverage[1] || !coverage[12] || !coverage[13])){
		if(x) printf(" + ");
		printf("B'C'"); x = coverage[0] = coverage[1] = coverage[12] = coverage[13] = 1;
	}
	if(kmap[1] && kmap[2] && kmap[13] && kmap[14] && (!coverage[1] || !coverage[2] || !coverage[13] || !coverage[14])){
		if(x) printf(" + ");
		printf("B'D"); x = coverage[1] = coverage[2] = coverage[13] = coverage[14] = 1;
	}
	if(kmap[2] && kmap[3] && kmap[14] && kmap[15] && (!coverage[2] || !coverage[3] || !coverage[14] || !coverage[15])){
		if(x) printf(" + ");
		printf("B'C"); x = coverage[2] = coverage[3] = coverage[14] = coverage[15] = 1;
	}
	if(kmap[0] && kmap[4] && kmap[3] && kmap[7] && (!coverage[0] || !coverage[4] || !coverage[3] || !coverage[7])){
		if(x) printf(" + ");
		printf("A'D'"); x = coverage[0] = coverage[4] = coverage[3] = coverage[7] = 1;
	}
	if(kmap[4] && kmap[8] && kmap[7] && kmap[11] && (!coverage[4] || !coverage[8] || !coverage[7] || !coverage[11])){
		if(x) printf(" + ");
		printf("BD'"); x = coverage[4] = coverage[8] = coverage[7] = coverage[11] = 1;
	}
	if(kmap[8] && kmap[12] && kmap[11] && kmap[15] && (!coverage[8] || !coverage[12] || !coverage[11] || !coverage[15])){
		if(x) printf(" + ");
		printf("AD'"); x = coverage[8] = coverage[12] = coverage[11] = coverage[15] = 1;
	}
	// Checking If Any Double Pairs Are Formed
	if(kmap[0] && kmap[1] && (!coverage[0] || !coverage[1])){
		if(x) printf(" + ");
		printf("A'B'C'"); x = coverage[0] = coverage[1] = 1;
	}
	if(kmap[1] && kmap[2] && (!coverage[1] || !coverage[2])){
		if(x) printf(" + ");
		printf("A'B'D"); x = coverage[1] = coverage[2] = 1;
	}
	if(kmap[3] && kmap[2] && (!coverage[3] || !coverage[2])){
		if(x) printf(" + ");
		printf("A'B'C"); x = coverage[3] = coverage[2] = 1;
	}
	if(kmap[3] && kmap[0] && (!coverage[3] || !coverage[0])){
		if(x) printf(" + ");
		printf("A'B'D'"); x = coverage[3] = coverage[0] = 1;
	}
	if(kmap[4] && kmap[5] && (!coverage[4] || !coverage[5])){
		if(x) printf(" + ");
		printf("A'BC'"); x = coverage[4] = coverage[5] = 1;
	}
	if(kmap[5] && kmap[6] && (!coverage[5] || !coverage[6])){
		if(x) printf(" + ");
		printf("A'BD"); x = coverage[5] = coverage[6] = 1;
	}
	if(kmap[7] && kmap[6] && (!coverage[7] || !coverage[6])){
		if(x) printf(" + ");
		printf("A'BC"); x = coverage[7] = coverage[6] = 1;
	}
	if(kmap[7] && kmap[4] && (!coverage[7] || !coverage[4])){
		if(x) printf(" + ");
		printf("A'BD'"); x = coverage[7] = coverage[4] = 1;
	}
	if(kmap[8] && kmap[9] && (!coverage[8] || !coverage[9])){
		if(x) printf(" + ");
		printf("ABC'"); x = coverage[8] = coverage[9] = 1;
	}
	if(kmap[9] && kmap[10] && (!coverage[9] || !coverage[10])){
		if(x) printf(" + ");
		printf("ABD"); x = coverage[9] = coverage[10] = 1;
	}
	if(kmap[10] && kmap[11] && (!coverage[10] || !coverage[11])){
		if(x) printf(" + ");
		printf("ABC"); x = coverage[10] = coverage[11] = 1;
	}
	if(kmap[8] && kmap[11] && (!coverage[8] || !coverage[11])){
		if(x) printf(" + ");
		printf("ABD'"); x = coverage[8] = coverage[11] = 1;
	}
	if(kmap[12] && kmap[13] && (!coverage[12] || !coverage[13])){
		if(x) printf(" + ");
		printf("AB'C'"); x = coverage[12] = coverage[13] = 1;
	}
	if(kmap[13] && kmap[14] && (!coverage[13] || !coverage[14])){
		if(x) printf(" + ");
		printf("AB'D");	x = coverage[13] = coverage[14] = 1;
	}
	if(kmap[14] && kmap[15] && (!coverage[14] || !coverage[15])){
		if(x) printf(" + ");
		printf("AB'C"); x = coverage[14] = coverage[15] = 1;
	}
	if(kmap[12] && kmap[15] && (!coverage[12] || !coverage[15])){
		if(x) printf(" + ");
		printf("AB'D'"); x = coverage[12] = coverage[15] = 1;
	}
	if(kmap[0] && kmap[4] && (!coverage[0] || !coverage[4])){
		if(x) printf(" + ");
		printf("A'C'D'"); x = coverage[0] = coverage[4] = 1;
	}
	if(kmap[4] && kmap[8] && (!coverage[4] || !coverage[8])){
		if(x) printf(" + ");
		printf("BC'D'"); x = coverage[4] = coverage[8] = 1;
	}
	if(kmap[12] && kmap[8] && (!coverage[12] || !coverage[8])){
		if(x) printf(" + ");
		printf("AC'D'"); x = coverage[12] = coverage[8] = 1;
	}
	if(kmap[12] && kmap[0] && (!coverage[12] || !coverage[12])){
		if(x) printf(" + ");
		printf("B'C'D'"); x = coverage[0] = coverage[12] = 1;
	}
	if(kmap[1] && kmap[5] && (!coverage[1] || !coverage[5])){
		if(x) printf(" + ");
		printf("A'C'D"); x = coverage[1] = coverage[5] = 1;
	}
	if(kmap[5] && kmap[9] && (!coverage[5] || !coverage[9])){
		if(x) printf(" + ");
		printf("BC'D"); x = coverage[5] = coverage[9] = 1;
	}
	if(kmap[13] && kmap[9] && (!coverage[13] || !coverage[9])){
		if(x) printf(" + ");
		printf("AC'D"); x = coverage[13] = coverage[9] = 1;
	}
	if(kmap[13] && kmap[1] && (!coverage[13] || !coverage[1])){
		if(x) printf(" + ");
		printf("B'C'D"); x = coverage[13] = coverage[1] = 1;
	}
	if(kmap[2] && kmap[6] && (!coverage[2] || !coverage[6])){
		if(x) printf(" + ");
		printf("A'CD"); x = coverage[2] = coverage[6] = 1;
	}
	if(kmap[6] && kmap[10] && (!coverage[6] || !coverage[10])){
		if(x) printf(" + ");
		printf("BCD"); x = coverage[6] = coverage[10] = 1;
	}
	if(kmap[10] && kmap[14] && (!coverage[10] || !coverage[14])){
		if(x) printf(" + ");
		printf("ACD"); x = coverage[10] = coverage[14] = 1;
	}
	if(kmap[14] && kmap[2] && (!coverage[14] || !coverage[2])){
		if(x) printf(" + ");
		printf("B'CD"); x = coverage[14] = coverage[2] = 1;
	}
	if(kmap[3] && kmap[7] && (!coverage[3] || !coverage[7])){
		if(x) printf(" + ");
		printf("A'CD'"); x = coverage[3] = coverage[7] = 1;
	}
	if(kmap[7] && kmap[11] && (!coverage[7] || !coverage[11])){
		if(x) printf(" + ");
		printf("BCD'"); x = coverage[7] = coverage[11] = 1;
	}
	if(kmap[11] && kmap[15] && (!coverage[11] || !coverage[15])){
		if(x) printf(" + ");
		printf("ACD'"); x = coverage[11] = coverage[15] = 1;
	}
	if(kmap[3] && kmap[15] && (!coverage[3] || !coverage[15])){
		if(x) printf(" + ");
		printf("B'CD'"); x = coverage[15] = coverage[3] = 1;
	}
	// Checking If Only single pairs Are Formed
    for (i = 0; i < 16; i++) {
    if (kmap[i] && !coverage[i]) { if (x) printf(" + ");
        switch (i) {
            case 0:  printf("A'B'C'D'"); break;
            case 1:  printf("A'B'C'D");  break;
            case 2:  printf("A'B'CD");  break;
            case 3:  printf("A'B'CD'");   break;
            case 4:  printf("A'BC'D'");  break;
            case 5:  printf("A'BC'D");   break;
            case 6:  printf("A'BCD");   break;
            case 7:  printf("A'BCD'");    break;
            case 8:  printf("ABC'D'");  break;
            case 9:  printf("ABC'D");   break;
            case 10: printf("ABCD");   break;
            case 11: printf("ABCD'");    break;
            case 12: printf("AB'C'D'");   break;
            case 13: printf("AB'C'D");    break;
            case 14: printf("AB'CD");    break;
            case 15: printf("AB'CD'");     break;
        }x = 1;
    }
    }   
    printf("\n");
}
   else if(choice == 3){
    int kmap[8],i,cnt = 0,coverage[8] = {0},x = 0;
	printf("Enter The Minterm Values (0 or 1):\n");
    printf("Minterm 000 (A'B'C'): "); scanf("%d", &kmap[0]);
    printf("Minterm 001 (A'B'C): "); scanf("%d",&kmap[1]);
    printf("Minterm 011 (A'BC): "); scanf("%d",&kmap[2]);
    printf("Minterm 010 (A'BC'): "); scanf("%d",&kmap[3]);
    printf("Minterm 100 (AB'C'): "); scanf("%d",&kmap[4]);
    printf("Minterm 101 (AB'C): "); scanf("%d",&kmap[5]);
    printf("Minterm 111 (ABC): "); scanf("%d",&kmap[6]);
    printf("Minterm 110 (ABC'): "); scanf("%d",&kmap[7]);
    printf("\nFinal Expression:\n");
    printf("F(A,B,C) = ");
    for(i=0;i<8;i++){if(kmap[i]) cnt++;}
	if(cnt==8){printf("1\n"); return 0;} // Checking If An Octate Is Formed
	if(cnt==0){printf("0\n"); return 0;} // Checking If There Are No Minterms
	// Checking If Any Quads Are Formed
	if(kmap[0] && kmap[1] && kmap[4] && kmap[5]){
	if(x) printf(" + ");
	printf("B'"); x = coverage[0] = coverage[1] = coverage[4] = coverage[5] = 1;
	}
	if(kmap[1] && kmap[2] && kmap[5] && kmap[6]){
	if(x) printf(" + ");
	printf("C"); x=coverage[1] = coverage[2] = coverage[5] = coverage[6] = 1;
	}
	if(kmap[2] && kmap[3] && kmap[6] && kmap[7]){
	if(x) printf(" + ");
	printf("B"); x = coverage[2] = coverage[3] = coverage[6] = coverage[7] = 1;
	}
	if(kmap[0] && kmap[1] && kmap[2] && kmap[3]){
		if(x) printf(" + ");
		printf("A'"); x = coverage[0] = coverage[1] = coverage[2] = coverage[3] = 1;
	}
	if(kmap[4] && kmap[5] && kmap[6] && kmap[7]){
		if(x) printf(" + ");
		printf("A"); x = coverage[4] = coverage[5] = coverage[6] = coverage[7] = 1;
	}
	if(kmap[0] && kmap[4] && kmap[3] && kmap[7]){
		if(x) printf(" + ");
		printf("C'"); x = coverage[0] = coverage[4] = coverage[3] = coverage[7] = 1;
	}
	// Checking If Any Double Pairs Are Formed
	if(kmap[0] && kmap[4] && (!coverage[0] || !coverage[4])){
		if(x) printf(" + ");
		printf("B'C'"); x = coverage[0] = coverage[4] = 1;
	}
	if(kmap[1] && kmap[5] && (!coverage[1] || !coverage[5])){
		if(x) printf(" + ");
		printf("B'C"); x = coverage[1] = coverage[5] = 1;
	}
	if(kmap[2] && kmap[6] && (!coverage[2] || !coverage[6])){
		if(x) printf(" + ");
		printf("BC"); x = coverage[2] = coverage[6] = 1;
	} 
	if(kmap[3] && kmap[7] && (!coverage[3] || !coverage[7])){
		if(x) printf(" + ");
		printf("BC'"); x  = coverage[3] = coverage[7] = 1;
	}
	if(kmap[0] && kmap[1] && (!coverage[0] || !coverage[1])){
		if(x) printf(" + ");
		printf("A'B'"); x = coverage[0] = coverage[1] = 1;
	}
	if(kmap[1] && kmap[2] && (!coverage[1] || !coverage[2])){
		if(x) printf(" + ");
		printf("A'C"); x = coverage[1] = coverage[2] = 1;
	}
	if(kmap[2] && kmap[3] && (!coverage[2] || !coverage[3])){
		if(x) printf(" + ");
		printf("A'B"); x = coverage[2] = coverage[3] = 1;
	}
	if(kmap[0] && kmap[3] && (!coverage[0] || !coverage[3])){
		if(x) printf(" + ");
		printf("A'C'"); x = coverage[0] = coverage[3] = 1;
	}
	if(kmap[4] && kmap[5] && (!coverage[4] || !coverage[5])){
		if(x) printf(" + ");
		printf("AB'"); x = coverage[4] = coverage[5] = 1;
	}
	if(kmap[5] && kmap[6] && (!coverage[5] || !coverage[6])){
		if(x) printf(" + ");
		printf("AC"); x = coverage[5] = coverage[6] =1;
	}
	if(kmap[6] && kmap[7] && (!coverage[6] || !coverage[7])){
		if(x) printf(" + ");
		printf("AB"); x = coverage[6] = coverage[7] = 1;
	}
	if(kmap[7] && kmap[4] && (!coverage[7] || !coverage[4])){
		if(x) printf(" + ");
		printf("AC'"); x = coverage[7] = coverage[4] = 1;
	}
	// Checking If Only Single Pairs Are Formed
		for(i=0;i<8;i++){
			if(kmap[i] && !coverage[i]){ if(x) printf(" + ");
				switch(i){
					case 0: printf("A'B'C'"); break;
					case 1: printf("A'B'C"); break;
					case 2: printf("A'BC"); break;
					case 3: printf("A'BC'"); break;
					case 4: printf("AB'C'"); break;
					case 5: printf("AB'C"); break;
					case 6: printf("ABC"); break;
					case 7: printf("ABC'"); break;
				}x=1;
			}
		}
	printf("\n");
}
	else if(choice == 2){
	int kmap[4],i,x = 0;
    printf("Enter The Minterm Values (0 or 1):\n");
    printf("Minterm 00 (A=0,B=0): "); scanf("%d", &kmap[0]);
    printf("Minterm 01 (A=0,B=1): "); scanf("%d", &kmap[1]);
    printf("Minterm 10 (A=1,B=0): ");  scanf("%d", &kmap[2]);
    printf("Minterm 11 (A=1,B=1): "); scanf("%d", &kmap[3]);
    printf("\nFinal expression:\n");
    printf("F(A,B) = ");
    if (kmap[0] && kmap[1] && kmap[2] && kmap[3]) {// Cheecking If Quad Is Formed
        printf("1\n");
        return 0;
    }
    // Checking If Any Double Pairs Are Formed
    if (kmap[0] && kmap[1]){
    if (x) printf(" + ");
    printf("A'"); x = 1;
    }
    if (kmap[2] && kmap[3]){
    if (x) printf(" + ");
    printf("A"); x = 1;
    }
    if (kmap[0] && kmap[2]){
    if (x) printf(" + ");
    printf("B'"); x = 1;
    }
    if (kmap[1] && kmap[3]){
    if (x) printf(" + ");
    printf("B"); x = 1;
    }
    // Checking If Only Single Pairs Are Formed
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
                }first = 0;
            }
        }
        if (first){printf("0");}
    }
    printf("\n");
	} 
	else{
		printf("\nPlease Enter A Valid Choice\n");
	}
}
