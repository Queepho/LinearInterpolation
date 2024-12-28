#include <iostream>
#include <iomanip>
using namespace std;

double Y[3] = {0.5,0.5,0};

double Weyl_red[3] = {0.49933611,0.49933113,0.00122475};
double Weyl_blue[3] = {0.50067533,0.50067367,-0.00125412};

double Scale = 3.56;

int trigger = 2; //(2 for Surface; 3 for Bulk)

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

int main()
{
	double Left_point[3] = {0,0,0};
	double Right_point[3] = {0,0,0};

	Find_Point(Left_point,0);
	Find_Point(Right_point,1);

	cout<<"M ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Left_point[i] << " ";

	}
	cout<<"R ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_red[i] << " ";

	}
	cout<<"\n";


	cout<<"R ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_red[i] << " ";

	}
	cout<<"Y ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Y[i] << " ";

	}
	cout<<"\n";


	cout<<"Y ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Y[i] << " ";

	}
	cout<<"B ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_blue[i] << " ";

	}
	cout<<"\n";



	cout<<"B ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Weyl_blue[i] << " ";

	}
	cout<<"N ";
	for(int i=0;i<trigger;i++)
	{
		cout<< fixed << setprecision(8) << Right_point[i] << " ";
	}
	cout<<endl;

	if(trigger == 2)
	{
		double diff_x = abs(Scale * (Y[0] - Weyl_red[0]));
		double diff_y = abs(Scale * (Y[1] - Weyl_red[1]));
		double diff_z = abs(Scale * (Y[2] - Weyl_red[2]));

		cout<<"The diff_x "<<fixed<<setprecision(8)<<diff_x<<endl;
		cout<<"The diff_y "<<fixed<<setprecision(8)<<diff_y<<endl;
		cout<<"The diff_z "<<fixed<<setprecision(8)<<diff_z<<endl;

		cout<<"The Arc_set for x "<<fixed<<setprecision(8)<<2*diff_x<<endl;
		cout<<"The Arc_set for y "<<fixed<<setprecision(8)<<2*diff_y<<endl;
		cout<<"The Arc_set for z "<<fixed<<setprecision(8)<<2*diff_z<<endl;
	}

}