#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cout<<"Case #"<<tc<<": ";
        int depth = 0;
        string s; cin>>s;

        for(int i=0; i<s.size(); i++)
        {
            if( (s[i]-48) > depth )
            {

                for(int j=1; j <= (s[i]-48)-depth; j++)
                {
                    cout<<"(";
                }
                depth = s[i]-48;
            }
            else
            {
                for(int j=1; j <= depth-(s[i]-48); j++)
                {
                    cout<<")";
                }
                depth = s[i]-48;
            }
            cout<<s[i];
        }

        for(int i=0; i<depth; i++)
        {
            cout<<")";
        }
        cout<<"\n";
    }

}
