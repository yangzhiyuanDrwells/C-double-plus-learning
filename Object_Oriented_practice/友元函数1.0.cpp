#include<iostream>

using namespace std;

class Distance{
	int meter;
	public:
		Distance(const Distance&)
		{
			cout<<"�������캯��������"<<endl; 
		 } 
		Distance():meter(0){

		}
		friend int addFive(Distance);
};
int addFive(Distance d){
	d.meter += 5;
	return d.meter;
}
int main()
{
	Distance D;
	cout<<"Disance: "<<addFive(D);
	return 0;
}

