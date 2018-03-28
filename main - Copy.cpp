#include <iostream>
#include <numeric>
#include <istream>
#include <string>
using namespace std;
int main()
{
    int x;
    string y;
    cout<<"1- Cipher a message "<<endl;
    cout<<"2- Decipher a message "<<endl;
    cout<<"3- Stop "<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"select what you want [1,2,3] : ";
    cin>>x;
    if(x==1)
    {
        cout<<"write the message you want to cipher :";
        cin.ignore();
        getline(cin,y);
        for(int i=0 ; i<y.length() ;++i)
        {
            if(y[i]>= 'a' && y[i] <='z'){

                cout<<(char)((3 * (y[i]-'a')+6)%26+'a');
            }
            else if (y[i] >= 'A' && y[i] <='Z'){
                cout<<((char)((3 *(y[i]-'A')+ 6) % 26 +'A'));
            }

        }
    }



    return 0;
}
