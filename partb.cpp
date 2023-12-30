#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> frequency;
vector<int>DieA;
vector<int>DieB;


void undoom_dice(vector<int> &Die3, vector<int> &Die4)
{
    unordered_map<int, int> frequency2;
    bool flag = true;

    for (int i = 0; i < Die3.size(); i++)
    {
        for (int j = 0; j < Die4.size(); j++)
        {
            frequency2[Die3[i] + Die4[j]]++;

            if (frequency2[Die3[i] + Die4[j]] > frequency[(Die3[i] + Die4[j])])
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            break;
        }
    }

    if (flag)
    {
        DieA=Die3;
        DieB=Die4;

    }
}

void possibledie4(vector<int> &Die3, vector<int> &Die4, int n)
{
    if (n == 5)
    {
        undoom_dice(Die3, Die4);
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        Die4[n] = i + 1;
        possibledie4(Die3, Die4, n + 1);
    }
}

void possibledie3(vector<int> &Die3, int n)
{
    if (n == 5)
    {
        vector<int> Die4 = {1, 0, 0, 0, 0, 8};
        possibledie4(Die3, Die4, 1);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        Die3[n] = i + 1;
        possibledie3(Die3, n + 1);
    }
}

void probabilitycheck(vector<int>Die1, vector<int>Die2)
{
    map<int, float>combination;
    
    for(int i=0; i<Die1.size(); i++)
    {
        for(int j=0; j<Die2.size(); j++)
        {
            int sum=0;
            sum=Die1[i]+Die2[j];
            combination[sum]++;
        }
    }
    
    int totalcombination=Die1.size()*Die2.size();

    cout<<"Probability Check of New Dice:"<<endl;
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

void print(vector<int>DieA, vector<int>DieB)
{
    cout<<"Loki's Doomed Dice with No Change in Probability";
    cout<<endl<<endl;
    
    sort(DieA.begin(), DieA.end());
    sort(DieB.begin(), DieB.end());
    
    cout << "New Die1: ";
        
        for (int i = 0; i < DieA.size(); i++)
        {
            cout << DieA[i]<<" ";
            
        }
        cout << endl;
        
        cout << "New Die2: ";
        
        for (int i = 0; i < DieB.size(); i++)
        {
            cout << DieB[i]<<" ";
        }
        
        cout << endl<< endl;
        
}

int main()
{
    vector<int> Die1 = {1, 2, 3, 4, 5, 6};
    vector<int> Die2 = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < Die1.size(); i++)
    {
        for (int j = 0; j < Die2.size(); j++)
        {
            int sum = Die1[i] + Die2[j];
            frequency[sum]++;
        }
    }

    vector<int> Die3 = {1, 0, 0, 0, 0, 4};

    possibledie3(Die3, 1);
    
    print(DieA, DieB);
    
    probabilitycheck(DieA, DieB);
    

    return 0;
}
