#include<bits/stdc++.h>
using namespace std;


void taski_totalcombination(vector<int>Die1, vector<int>Die2)
{
    
    int totalcombination=Die1.size()*Die2.size(); //(direct approach)
    
    // int totalcombination=0;
    
    // for(int i=0; i<Die1.size(); i++)
    // {
    //     for(int j=0; j<Die2.size(); j++)
    //     {
    //         totalcombination++;
    //     }
        
    // }
    
    cout<<"Total Combination :"<<" Size of Die1 X Size of Die2: "<<totalcombination<<endl;
    cout<<endl;
}



void taskii_combinationspossible(vector<int>Die1, vector<int>Die2)
{
    cout<<"All Possible Combinations:"<<endl;
    cout<<endl;
    
    for(int i=1; i<=Die1.size(); i++)
    {
        for(int j=1; j<=Die2.size(); j++)
        {
            cout<<'('<<i<<","<<j<<')'<<" ";
        }
        
        cout<<endl;
    }
    
    cout<<endl;
}

void taskiii_probability(vector<int>Die1, vector<int>Die2)
{
    
    cout<<"All Possible Sums:"<<endl;
    cout<<endl;
    
    map<int, float>combination;
    set<int>unique;
    map<int, vector<vector<int>>>values;
    
    for(int i=0; i<Die1.size(); i++)
    {
        for(int j=0; j<Die2.size(); j++)
        {
            vector<int>val;
            val.push_back(i+1);
            val.push_back(j+1);
            
            int sum=0;
            sum=Die1[i]+Die2[j];
            
            values[sum].push_back(val);
            
            if(!unique.count(sum))
            {
                cout<<sum<<" ";
            }
            unique.insert(sum);
            combination[sum]++;
        }
    }
    cout<<endl;
    cout<<endl;
    
    
    cout << "Combinations for Each Sum:" << endl;
    cout<<endl;
    
    for (auto x : values) 
    {
        cout << "Sum " << x.first << ": ";
        
        for (auto v : x.second) 
        {
            cout << "(" << v[0] << ", " << v[1] << ") ";
        }
        
        cout << endl;
    }
    cout<<endl;
    
    int totalcombination=Die1.size()*Die2.size();

    cout<<"Probability of All Possible Sums:"<<endl;
    cout<<endl;

    for(auto x: combination)
    {
        cout<<"probability(sum="<<x.first<<")="<<" ";
        cout<<x.second<<"(occurence)/"<<totalcombination<<"(totalcombination)="<<" ";
        float probability=x.second/totalcombination;
        cout<<probability;
        cout<<endl;
    }
    
}

int main()
{
    vector<int>Die1={1,2,3,4,5,6};
    vector<int>Die2={1,2,3,4,5,6};
    
    taski_totalcombination(Die1, Die2);
    taskii_combinationspossible(Die1, Die2);
    taskiii_probability(Die1, Die2);

    return 0;
}
