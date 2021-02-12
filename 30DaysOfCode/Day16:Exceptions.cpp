#include <string>
#include <iostream>

using namespace std;


int main(){
    string S;
    cin >> S;
     try
    {
        string::size_type no;
        no=stoi(S);
        cout<<no<<endl;
    }
    catch(exception a)
    {
        cout<<"Bad String";
    }

    return 0;
}