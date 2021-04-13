#include "stdio.h"
#include"iostream"
#include"math.h"
#include"ctime"
using namespace std;
//Поиск правой границы, зависищая от параметра а
float find_bor(float& a)
{
	float p;
	p = (acosf(1 - a / 2)) / a;
	return p;
}
//Генератор случайных чисел
double rand_search()
{
	return (((double)rand()) / RAND_MAX);

}
float get_continuous_value(double&F, float& a)
{
	float x ;

	if (F == 0)
	{
		x = float(-pow(2, 0.25));
		return x ;
	}
	if (F  == float(1.0))
	{

		return find_bor(a);
	}
	if (F < 0.5)
	{
		float x;
		x = float(- pow((2-4*F),0.25));
		return x;
	}
	if (F >= 0.5)
	{
		if (F == 0.5)
		{
			return 0;
		}
		x = acosf(1 -a*(F-0.5))/a;
		return x;
	}
		
}



int main()
{
	srand(time(NULL));
	float a;
	int  const  size = 100;
	float arr[size];
	double F;
	float temp ;
	int  i = 0;
	//cout << F << endl;
	cout << "Enter parametr a = ";
	cin >> a;
	cout << "Right border = " <<find_bor(a)<< endl;
	for (int i = 0; i < size; i++)
	{
		F = rand_search();
		arr[i] = get_continuous_value(F, a);

	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < size; i++)
	{
		cout << "The value of a random continuous quantity x" << i + 1 << "\t";

		cout << arr[i] << endl;
	}
	
	return 0;
}