#define IN 2
#define MID 3
#define OUT 1
#define EPS 0.5
#define MYU 0.8

void Init();
void Input();
void Forward();
void BackProp();
double CheckError();
double sigmoid(double);

struct neuron_t{
	double X[IN+1];
	double H[MID+1];
	double O[OUT];
	double T[OUT];
	double Wji[MID][IN+1];
	double Wkj[OUT][MID+1];
}nt;
