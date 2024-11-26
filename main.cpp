#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct problem
{
    bool operator <(const problem& p1)const 
    {
        return p1.prioritate < prioritate;
    }
    string id;
    string speciality;
    int durata;
    int prioritate;
};
struct doctor
{
    int timp = 8;
    string id;
    string speciality;
    bool available = true;
};

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;
    priority_queue<problem> pq;
    for (int i = 0; i < no_problems; i++)
    {
        problem n;
        inFile >> n.id;
        inFile >> n.speciality;
        inFile >> n.durata;
        inFile >> n.prioritate;
        pq.push(n);
    }

    inFile >> no_doctors;
    vector<doctor> d;
   
    for (int i = 0; i < no_doctors; i++)
    {
        doctor x;
        inFile >> x.id;
        inFile >> x.speciality;
        x.available = true;
        d.push_back(x);
    }
    /*for (auto& prob : p)
    {
        auto it = find_if(d.begin(), d.end(), [&prob](const doctor& doc)
            {
                if (doc.speciality == prob.speciality and doc.available == true)
                    return true;
                else return false;
            });
            if (it != d.end())
            {
                (*it).available = false;
                cout << (*it).id << ' ' << prob.id << '\n';

            }
    }*/
    while (pq.size() != 0)
    {
        pq.top();
        pq.pop();
    }
    return 0;
}