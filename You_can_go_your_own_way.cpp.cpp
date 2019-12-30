#include <iostream>
#include <cstring>
using namespace std;

main()
{
    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        for(int j=0; j<((2*n)-2); j++)
        {
            if(s[j] == 'E') s[j]='S';
            else s[j]= 'E';
        }

        cout<<"Case #"<<i+1<<": "<<s<<endl;
    }
}
