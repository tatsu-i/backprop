#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "connectionist.h"


void Init(){
	int i,j,k;
	for (j = 0; j < MID; j++) {
		for (i = 0; i <= IN; i++) {
			nt.Wji[j][i]=(double)rand()/(double)RAND_MAX-0.5;
		}
	}
	for (k = 0; k < OUT; k++) {
		for (j = 0; j <= MID; j++) {
			nt.Wkj[k][j]=(double)rand()/(double)RAND_MAX-0.5;

		}
	}
	nt.X[IN] = 1.0; nt.H[MID] = 1.0;
}

void Input(){
	int i, k;

	for (i = 0; i < IN; i++) {
		nt.X[i] = rand()%2;
	}
	nt.X[0] = 0, nt.X[1] = 0;//static
	printf("nt.X[0]=%lf,nt.X[1]=%lf\n", nt.X[0],nt.X[1]);
	//入力が決まったので教師を作る
	//nt.XOR
	if (nt.X[0]==nt.X[1]) {
		nt.T[0] = 0.0;
	}else{
		nt.T[0] = 1.0;
	}
}

double sigmoid(double x){
	return (1.0/(1.0+exp(-1.0*x)));
}

void Forward(){
	int i, j, k;
	double Tj[MID], Uk[OUT];
	for (j = 0; j < MID ; j++) {
		for (Tj[j] = 0, i = 0; i < IN+1; i++) {
			Tj[j] += nt.X[i]*nt.Wji[j][i];
		}
		nt.H[j] = sigmoid(Tj[j]);
	}
	for (k = 0; k < OUT; k++) {
		for (Uk[k] = 0, j = 0; j < MID+1; j++) {
			Uk[k] += nt.H[j]*nt.Wkj[k][j];
		}
		nt.O[k] = sigmoid(Uk[k]);
	}
}
void BackProp(){
	int i, j, k;
	double dWji[MID][IN+1],dWkj[OUT][MID+1];
	double sum = 0;

	for (k = 0; k < OUT; k++) {
		for (j = 0; j < MID+1; j++) {
			dWkj[k][j] = -1.0*MYU*(-1.0*(nt.T[k]-nt.O[k])*nt.O[k]*(1.0-nt.O[k])*nt.H[j]);
		}
	}
	for (j = 0; j < MID ; j++) {
		for (i = 0; i < IN+1; i++) {
			for (sum = 0,k = 0; k < OUT; k++) {
				sum += nt.Wkj[k][j]*(nt.T[k]-nt.O[k])*nt.O[k]*(1.0-nt.O[k]);
			}
			dWji[j][i] = MYU*nt.H[j]*(1.0-nt.H[j])*nt.X[i]*sum;
		}
	}
	//update
	for (k = 0; k < OUT; k++) {
		for (j = 0; j < MID+1; j++) {
			nt.Wkj[k][j] += dWkj[k][j];
		}
	}
	for (j = 0; j < MID; j++) {
		for (i = 0; i < IN+1; i++) {
			nt.Wji[j][i] += dWji[j][i];
		}
	}
}
double CheckError(){
	double err = 0;
	
	nt.X[0]=0.0, nt.X[1]=0.0, Forward();
	err += fabs(nt.O[0]-0.0);
	nt.X[0]=0.0, nt.X[1]=1.0, Forward();
	err += fabs(nt.O[0]-0.0);
	nt.X[0]=1.0, nt.X[1]=0.0, Forward();
	err += fabs(nt.O[0]-0.0);
	nt.X[0]=1.0, nt.X[1]=1.0, Forward();
	err += fabs(nt.O[0]-0.0);
	return 0.0;
}
