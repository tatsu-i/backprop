#include <stdio.h>
#include <stdlib.h>
#include "connectionist.h"

int
main(int argc, char* argv[]) {
	srand(1);
	Init();//重みを+-0.5の乱数で初期化
	unsigned int i = 0;

	printf("\x1b[35mXORの学習\n\x1b[36m");
	printf("======== start ========\n\x1b[32m");
	while(1){
		Input();
		Forward();
		BackProp();

		//結果を表示
		printf("学習回数: \x1b[31m%d\x1b[32m回目\n", ++i);
		nt.X[0]=0.0;nt.X[1]=0.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=\x1b[31m%.4lf\x1b[32m\n", nt.X[0],nt.X[1],nt.O[0]);
		nt.X[0]=0.0;nt.X[1]=1.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=\x1b[31m%.4lf\x1b[32m\n", nt.X[0],nt.X[1],nt.O[0]);
		nt.X[0]=1.0;nt.X[1]=0.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=\x1b[31m%.4lf\x1b[32m\n", nt.X[0],nt.X[1],nt.O[0]);
		nt.X[0]=1.0;nt.X[1]=1.0;Forward();
		printf("X[0]=%lf,X[1]=%lf,O[0]=\x1b[31m%.4lf\x1b[32m\n", nt.X[0],nt.X[1],nt.O[0]);
		if (CheckError() < EPS)
			break;
		else
			printf("\x1b[5A");
	}
	printf("\x1b[36m======== stop ========\n");
	return 0;
}


