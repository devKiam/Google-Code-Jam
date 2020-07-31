#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin>>t;
    for(int T=1; T<=t; T++)
    {
        int n; cin>>n;
        vector< vector<int> > v;

        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<n; j++)
            {
                int x; cin>>x;
                row.push_back(x);
            }
            v.push_back(row);
        }

        int sum = 0;
        int r = 0;
        int c = 0;

        for(int i=0; i<n; i++)
        {
            map<int,int> mR;
            map<int,int> mC;
            bool flagR = false;
            bool flagC = false;

            for(int j=0; j<n; j++)
            {
                if(i==j) sum+=+v[i][j];

                mR[v[i][j]]++;
                mC[v[j][i]]++;

                if(mR[v[i][j]] > 1)
                {
                    flagR = true;
                }
                if(mC[v[j][i]] > 1)
                {
                    flagC = true;
                }
            }

            if(flagR==true) r++;
            if(flagC==true) c++;
        }

        cout<<"Case #"<<T<<": "<<sum<<" "<<r<<" "<<c<<"\n";

    }

}
