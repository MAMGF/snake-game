               /**********************************************
               *                                             *
               *  FCI – Programming 1 – 2018 - Assignment 2  *
               *  Program Name:   Rail-fence cipher.cpp      *
               *  Last Modification Date:     xx/xx/xxxx     *
               *  Author1 and ID and Group:   xxxxx xxxxx    *
               *  Author2 and ID and Group:   xxxxx xxxxx    *
               *  Author3 and ID and Group:   xxxxx xxxxx    *
               *  Teaching Assistant:   xxxxx xxxxx          *
               *                                             *
               **********************************************/

#include <iostream>
#include <string>

using namespace std;

string msg, encrypted_msg;
int key;

//function to encrypt a message
string encryptrailfence(string msg, int key );

// This function receives cipher-text and key
// and returns the original text after decryption
string decryptRailFence(string , int );

 int main()
{

    bool f=true;
    while (f==true)
    {

       cout << "What do you like to do today" << endl;
       cout << "1-Cipher a message" << endl;
       cout << "2-Decipher a message" << endl;

       int option;
       cin >> option;

       if (option==1){
         cout << encryptrailfence(msg,key) << endl;
         f=false;}

       else if (option==2){
         cout << decryptRailFence(encrypted_msg,key) << endl;
         f=false;}

       else if (option>2 || option<1)
            cout << "Error!!" << endl<<"Retry again ";


    }

    return 0;

}

//function to encrypt a message
string encryptrailfence (string msg, int key)
{

    cout << endl << "Enter message: ";
    cin.ignore();
    getline(cin,msg);
    cout << "Enter key    : ";
    cin >>  key;

    //create a matrix
    //row=key, col=msg.length
    char rail[key][msg.length()];

    // filling the rail matrix to distinguish zig zag
    for (int i=0; i<key; i++)
    {
        for (int j=0; j<msg.length(); j++)
            rail [i][j]='.';
    }

    int row=0,col=0;
    bool dir_chg=true;

    for(int i=0; i<msg.length(); i++)
    {
       rail[row][col++]=msg[i];

       //change the direction when we have top or bottom
       if (row==0 || row==key-1)
        dir_chg=!dir_chg;

       dir_chg?row-- : row++;

    }

    //now we can construct the cipher using the rail matrix
    string result;
    for(int i=0; i<key ;i++)
    {
        for (int j=0; j<msg.length(); j++)
              if (rail[i][j]!='.'){
                 result.push_back(rail[i][j]);}

    }
    cout << endl << "plain message  : " << msg << endl;
    cout << "cipher message : " << result << "\n\n\n\n";
    //return result;


}


// This function receives cipher-text and key
// and returns the original text after decryption
string decryptRailFence(string encrypted_msg, int key)
{

    cout << endl << "Enter message: ";
    cin.ignore();
    getline(cin,encrypted_msg);
    cout << "Enter key    : ";
    cin >> key;

    //create a matrix
    char rail[key][(encrypted_msg.length())];

    // filling the rail matrix to distinguish zig zag
    for (int i=0; i<key; i++)
        for(int j=0; j<encrypted_msg.length(); j++)
            rail[i][j]='\n';


    int row=0,col=0;
    bool dir_chg=true;

    //draw zig zag
    for (int i=0; i<encrypted_msg.length(); i++)
    {
        //change direction
        if(row==0 )
            dir_chg=true ;
        if(row==key-1)
            dir_chg=false;

        rail[row][col++]='*';
        dir_chg?row++ : row--;

    }

    // filling the rail matrix to distinguish zig zag
    int index=0;
    for (int i=0; i<key; i++)
      for(int j=0; j<encrypted_msg.length(); j++)
            if(rail[i][j]=='*' && index<encrypted_msg.length())
                rail[i][j]=encrypted_msg[index++];

    // now read the matrix in zig-zag manner to construct
    // the resultant text
    row=0,col=0;
    string result;

      for(int j=0; j<encrypted_msg.length(); j++){
            if(rail[row][col]!='*' )
                result.push_back(rail[row][col++]);

             //change the direction when we have top or bottom
             if (row==0 || row==key-1)
                dir_chg=!dir_chg;

            dir_chg?row++ : row--;}


  cout << endl << "cipher message : " << encrypted_msg << endl ;
  cout << "plain message  : ";
  return result;

}
