#include <stdio.h>
#include <stdlib.h>
#include "connectionist.h"

int
main(int argc, char* argv[]) {
	srand(1);
	Init();//重みを+-0.5の乱数で初期化
	
	while (1) {
		Input();
		Forward();
		BackProp();

		if (CheckError() < EPS) {
			break;
		}
	}
	//結果を表示
	nt.X[0]=0.0;nt.X[1]=0.0;Forward();
	printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
	nt.X[0]=0.0;nt.X[1]=1.0;Forward();
	printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
	nt.X[0]=1.0;nt.X[1]=0.0;Forward();
	printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
	nt.X[0]=1.0;nt.X[1]=1.0;Forward();
	printf("X[0]=%lf,X[1]=%lf,O[0]=%.4lf\n", nt.X[0],nt.X[1],nt.O[0]);
	return 0;
}


