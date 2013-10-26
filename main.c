#include <stdio.h>
#include <stdlib.h>
#include "connectionist.h"

int
main(int argc, char* argv[]) {
	srand(1);
	Init();//重みを+-0.5の乱数で初期化
	unsigned int i = 0;

	printf("XORの学習\n");
	printf("======== start ========\n");
	while(1){
		Input();
		Forward();
		BackProp();

		//結果を表示
		printf("%d回目\n", ++i);
		nt.X[0]=0.0;nt.X[1]=0.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
		nt.X[0]=0.0;nt.X[1]=1.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
		nt.X[0]=1.0;nt.X[1]=0.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
		nt.X[0]=1.0;nt.X[1]=1.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
		if (CheckError() < EPS)
			break;
		else
			printf("\x1b[5A");
	}
	printf("======== stop ========\n");
	return 0;
}


