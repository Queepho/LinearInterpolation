#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Y[3] = {0.5,0.5,0};

double Weyl_red[3] = {0.49939352,0.49938880,0.00111321};
double Weyl_blue[3] = {0.50061770,0.50061585,-0.00114061};

//K1 K2 K3 are Reciprocal Vectors (Ang^-1) only active for One_WeylLine
double K1[3] = {1.418326,0.436757,-0.140816};
double K2[3] = {-1.418326,0.436757,-0.140816};
double K3[3] = {0.000000,0.000000,0.629151};

double Scale = 2;

int LineType = 1; //(1 for Two_WeylLine; 2 for One_WeylLine)
int KAlong = 3; //(1 for K1, 2 for K2, 3 for K3) only active for One_WeylLine
int WeylWhich = 1; //(1 for red, 2 for blue)


int trigger = 1; //(1 for Surface(100); 2 for Surface(001); 3 for Bulk)


double Left_point[3] = {0,0,0};
double Right_point[3] = {0,0,0};
//——————————————————————————————————————————————————————————————————————————————————————————

void Find_Point(double* Weyl ,int a)
{
	if(a == 0)
	{
		Weyl[0] = Y[0] - (Scale * (Y[0] - Weyl_red[0]));
		Weyl[1] = Y[1] - (Scale * (Y[1] - Weyl_red[1]));
		Weyl[2] = Y[2] - (Scale * (Y[2] - Weyl_red[2]));
	}else
	{
		Weyl[0] = Y[0] - (Scale * (Y[0] - Weyl_blue[0]));
		Weyl[1] = Y[1] - (Scale * (Y[1] - Weyl_blue[1]));
		Weyl[2] = Y[2] - (Scale * (Y[2] - Weyl_blue[2]));
	}

	
}

void Display_A(int StartI = 0, int EndI = 3)
{

	cout<<"M ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Left_point[i] << " ";

	}
	cout<<"R ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_red[i] << " ";

	}
	cout<<"\n";


	cout<<"R ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_red[i] << " ";

	}
	cout<<"Y ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Y[i] << " ";

	}
	cout<<"\n";


	cout<<"Y ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Y[i] << " ";

	}
	cout<<"B ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_blue[i] << " ";

	}
	cout<<"\n";



	cout<<"B ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_blue[i] << " ";

	}
	cout<<"N ";
	for(int i = StartI;i<EndI;i++)
	{
		cout<< fixed << setprecision(8) << Right_point[i] << " ";
	}
	cout<<endl;
}

void WeylLine()
{

	Find_Point(Left_point,0);
	Find_Point(Right_point,1);

	if((trigger == 2) && (trigger == 3))
	{
		Display_A(0,3);
	}else if(trigger == 1)
	{
		Display_A(1,3);
	}
	

	if(trigger != 3)
	{
		double diff_x = (Scale * (Y[0] - Weyl_red[0]));
		double diff_y = (Scale * (Y[1] - Weyl_red[1]));
		double diff_z = (Scale * (Y[2] - Weyl_red[2]));

		cout<<"The diff_x "<<fixed<<setprecision(8)<<diff_x<<endl;
		cout<<"The diff_y "<<fixed<<setprecision(8)<<diff_y<<endl;
		cout<<"The diff_z "<<fixed<<setprecision(8)<<diff_z<<endl;

		cout<<"The Arc_set for x "<<fixed<<setprecision(8)<<2*diff_x<<endl;
		cout<<"The Arc_set for y "<<fixed<<setprecision(8)<<2*diff_y<<endl;
		cout<<"The Arc_set for z "<<fixed<<setprecision(8)<<2*diff_z<<endl;
	}
}

void KLine()
{
	//To Normalization
	double Normal_F[3] = {0,0,0};
	if(KAlong == 1)
	{
		double Mount = (pow(K1[0],2) + pow(K1[1],2) + pow(K1[2],2)); 
		Normal_F[0] = K1[0] / sqrt(Mount);
		Normal_F[1] = K1[1] / sqrt(Mount);
		Normal_F[2] = K1[2] / sqrt(Mount);
	}else if(KAlong == 2)
	{
		double Mount = (pow(K2[0],2) + pow(K2[1],2) + pow(K2[2],2));
		Normal_F[0] = K2[0] / sqrt(Mount);
		Normal_F[1] = K2[1] / sqrt(Mount);
		Normal_F[2] = K2[2] / sqrt(Mount);
	}else if(KAlong == 3)
	{
		double Mount = (pow(K3[0],2) + pow(K3[1],2) + pow(K3[2],2));
		Normal_F[0] = K3[0] / sqrt(Mount);
		Normal_F[1] = K3[1] / sqrt(Mount);
		Normal_F[2] = K3[2] / sqrt(Mount);
	}else
	{
		cout<<"KAlong is wrong"<<endl;
	}
	double Left_point[3] = {0,0,0};
	double Right_point[3] = {0,0,0};
	char weylpoint = '0';

	double *WeylTar;

	if(WeylWhich == 1)
	{
		weylpoint = 'R';

		WeylTar = Weyl_red;
		Left_point[0] = Weyl_red[0] - (Scale * Normal_F[0]);
		Left_point[1] = Weyl_red[1] - (Scale * Normal_F[1]);
		Left_point[2] = Weyl_red[2] - (Scale * Normal_F[2]);

		Right_point[0] = Weyl_red[0] - (Scale * Normal_F[0]);
		Right_point[1] = Weyl_red[1] - (Scale * Normal_F[1]);
		Right_point[2] = Weyl_red[2] - (Scale * Normal_F[2]);
	}else if(WeylWhich == 2)
	{
		weylpoint = 'B';

		WeylTar = Weyl_blue;
		Left_point[0] = Weyl_blue[0] + (Scale * Normal_F[0]);
		Left_point[1] = Weyl_blue[1] + (Scale * Normal_F[1]);
		Left_point[2] = Weyl_blue[2] + (Scale * Normal_F[2]);

		Right_point[0] = Weyl_blue[0] + (Scale * Normal_F[0]);
		Right_point[1] = Weyl_blue[1] + (Scale * Normal_F[1]);
		Right_point[2] = Weyl_blue[2] + (Scale * Normal_F[2]);
	}else
	{
		cout<<"WeylWhich is wrong"<<endl;
	}


	cout<<"M ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Left_point[i] << " ";

	}
	cout<<weylpoint<<" ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << *(WeylTar + i) << " ";

	}
	cout<<"\n";

	cout<<weylpoint<<" ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << *(WeylTar + i) << " ";

	}
	cout<<"N ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Right_point[i] << " ";

	}
	cout<<"\n";

}

int main()
{

	if(LineType == 1)
	{
		WeylLine();
	}else if(LineType == 2)
	{
		KLine();
	}else
	{
		cout<<"None"<<endl;
	}

	return 0;
}