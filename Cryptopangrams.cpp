#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

main()
{
    int t;
    cin>>t;

    for(int T=0; T<t; T++){

        long long int N, L;
        cin>>N>>L;
        vector<long long int> v;

        for(long long int i=0; i<L; i++){

            long long int x;
            cin>>x;
            v.push_back(x);
        }

        vector<long long int> primes;

        for(long long int i=2; i<=N; i++){

            int flag=1;

            for(long long int j=2; j<=i/2; ++j){
                if(i%j == 0 && i!=2)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
                primes.push_back(i);

        }

        vector <long long int> result;
        vector <long long int> temp;

        for(long long int i=0; i<primes.size(); i++){

            if((v[0] % primes[i]) == 0)
            {
                long long z = primes[i];
                result.push_back(z);
                z = (v[0] / primes[i]);
                result.push_back(z);
                break;
            }
        }

        for(long long int i=1; i<v.size(); i++)
        {
            long long int z;
            z = v[i] / result[i];
            result.push_back(z);
        }
        temp = result; //copying vector value
        sort(result.begin(), result.end());

        set <long long int> final_result;

        for(long long int i=0; i<result.size(); i++){
            long long int z = result[i];
            final_result.insert(z);
        }


        map <char,long long int> m;
        map<char,long long int>::iterator itr_map;
        auto itr = final_result.begin();

        for(long long int i=0; i<26; i++,++itr){
            m.insert(pair<char,long long int>('A'+i, *itr));
        }

        cout<<"Case #"<<T+1<<": ";

        for(long long int i=0; i<temp.size(); i++)
        {
            for(auto ittr = m.begin(); ittr!=m.end(); ++ittr){
                if((ittr->second) == temp[i])
                    cout<< ittr->first;
            }

        }
        cout<<endl;


    }
}
