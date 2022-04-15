#include<iostream>
#include<string>
#include<map>
using namespace std;

int parent[50001];
map<string, int> persons;
map<int, string> numberToPerson;

int get_parent(int i)
{
    if(i == parent[i])
        return i;

    parent[i] = get_parent(parent[i]);
    return parent[i];
}

void Union(int i,int j)
{
    int i_par = get_parent(i);
    int j_par = get_parent(j);

    if(i_par!=j_par)
    {
        parent[j_par] = i_par;
    }
}


int main()
{

    char flag;
    string par;
    string child;
    int idx=1;
    while(true)
    {
        cin >> flag;

        if(flag == '$')
            break;

        if(flag == '#')
        {
            cin >> par;
            
            if(persons.find(par) == persons.end())
            {
                persons[par] = idx;
                numberToPerson[idx] = par;
                parent[idx] = idx;
                idx++;
            }
        }else if(flag == '+')
        {
            cin >> child;
            if(persons.find(child) == persons.end())
            {
                persons[child] = idx;
                numberToPerson[idx] = child;
                parent[idx] = idx;
                idx++;
            }

            Union(persons[par],persons[child]);

        }else if(flag == '?')
        {
            cin >> child;
            int par = get_parent(persons[child]);
            printf("%s %s\n",child.c_str(),numberToPerson[par].c_str());
        }
    }


    return 0;
}