#include <iostream>
using namespace std;
class GradeBook
{
public:
	int number;
	int weight;
	void dissplayMessage() const     //��������������Ϊ
	{
		cout <<"Welcom to the grade book!" << endl;
	}
	
};

int main()
{
	GradeBook myGradebook;
	myGradebook.dissplayMessage();
	GradeBook lisi;
	cout <<lisi.weight<<endl;
		 
}
