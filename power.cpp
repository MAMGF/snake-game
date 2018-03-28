#include <iostream>
using namespace std;
int main()
{
   /* int x,y,r;
    r=0;
    cout<<"Enter the first number :";
    cin>>x;
    cout<<"Enter the second number :";
    cin>>y;
    while(x>=y)
        {
            x=x-y;
            r++;
        }
        cout<<x<<r;*/

	int num, pow, sum = 0, addNum = 0;

	cout << "Please enter a number: ";
	cin >> num;
	cin.ignore();

	cout << "Please enter the power of the previous number: ";
	cin >> pow;
	cin.ignore();

	int count = 1;

	for(int i = 0; i < pow; i++)
	{

		while(count > 0)
		{
			addNum = addNum + num;
			count--;
		}

		count = addNum;
		sum = addNum;
		addNum = 0;
	}

	if(pow == 0)
		sum = 1;

	cout << num << " to the power of " << pow << " is " << sum << endl;

	cin.ignore();


    return 0;
}
