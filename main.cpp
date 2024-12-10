#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct problem
{
    
    string id;
    string speciality;
    int durata;
    int prioritate;
    bool operator <(const problem& p1)const 
    {
        return p1.prioritate > prioritate;
    }
};
struct doctor
{
    int timp;
    string id;
    string speciality;
    int probrez;
    vector<string> nrprob;
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
        doctor doc;
        inFile >> doc.id;
        inFile >> doc.speciality;
        doc.probrez = 0;
        doc.timp = 8;
        d.push_back(doc);

    }
    while (!pq.empty())
    {
        problem curent = pq.top();
        pq.pop();
        auto it = find_if(d.begin(), d.end(), [&curent](const doctor& doc) {
        return doc.speciality == curent.speciality;
        });
        if ((it != d.end()) && (it->timp >= curent.durata))
        {
            it->probrez++;
            it->timp -= curent.durata;
            it->nrprob.push_back(curent.id);
            
        }
    }
    for (const auto& doc : d)
    {
        if (!doc.nrprob.empty())
        {
            cout << doc.id << ' ' << doc.probrez;
            for (const auto& problem_id : doc.nrprob)
            {
                cout << ' ' << problem_id;
            }
            cout << '\n';
        }
    }
}