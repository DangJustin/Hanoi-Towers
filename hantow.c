#include <stdio.h>
#include <unistd.h>
#include <string.h>

int peg1[9], peg2[9], peg3[9];


void display_pegs(){
int i,j;
printf("\n");
for (i=8;i>=0;i--){

    /* First Peg */
	for(j=0;j<10-peg1[i];j++)
		printf(" ");
	for(j=0;j<peg1[i];j++)
		printf("+");
	printf("|");
	for(j=0;j<peg1[i];j++)
		printf("+");
	for(j=0;j<10-peg1[i];j++)
		printf(" ");
	printf("    ");

	/* Second Peg */
	for(j=0;j<10-peg2[i];j++)
		printf(" ");
	for(j=0;j<peg2[i];j++)
		printf("+");
	printf("|");
	for(j=0;j<peg2[i];j++)
		printf("+");
	for(j=0;j<10-peg2[i];j++)
		printf(" ");
	printf("    ");

	/* Third Peg */
	for(j=0;j<10-peg3[i];j++)
		printf(" ");
	for(j=0;j<peg3[i];j++)
		printf("+");
	printf("|");
	for(j=0;j<peg3[i];j++)
		printf("+");
	for(j=0;j<10-peg3[i];j++)
		printf(" ");
	printf("\n");
}
printf("XXXXXXXXXXXXXXXXXXXXX    XXXXXXXXXXXXXXXXXXXXX    XXXXXXXXXXXXXXXXXXXXX\n");
printf("\n");
}

void movetest(int array1[], int array2[]){
    int temp,i,j;
    for (i=0;i< 9;i++){
        if (array1[i]==0){
            temp = array1[i-1];
            array1[i-1]=0;
            break;
        }
    }
    if (array1[8]!=0){
        temp = array1[8];
        array1[8] = 0;
    }

    for (j=0;j<9;j++){
        if (array2[j] == 0){
            array2[j] = temp;
            break;
        }
    }
}


void hanoi(int n, int array1[], int array2[], int array3[]){
    if (n>0){
     hanoi(n-1,array1,array3,array2);
    /* move stuff */
    movetest(array1,array2);
    sleep(1);
    display_pegs();
    hanoi(n-1,array3,array2,array1);
    }
}


int main(int argc, char *argv[])
{
    int i;
	int count;
	if (argc != 2){
		printf("Incorrect number of command line arguments, 1 needed (%d given)\n",argc-1);
		return 1;
	}
	if (strlen(argv[1])!=1){
		printf("%s is an improper argument (argument must be between 1 and 9)\n",argv[1]);
		return 1;
	}

	if (argv[1][0]<'1'||argv[1][0]>'9'){
		printf("%s is an improper argument (argument must be between 1 and 9)\n",argv[1]);
		return 1;
	}

	count = argv[1][0]-'0';

    for (i = 0; i < 9; i++) {
        if (count-i>0)
            peg1[i] = count-i;
        else
            peg1[i]=0;
    }
    for (i = 0; i < 9; i++) {
        peg2[i] = 0;
        peg3[i]= 0;
    }
	display_pegs();
	sleep(1);
	hanoi(count,peg1,peg2,peg3);
	printf("done\n");
    return 0;
}
