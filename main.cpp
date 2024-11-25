#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct problem
{
    string id;
    string speciality;
};
struct doctor
{
    string id;
    string speciality;
    bool available;
};

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;
    vector<problem> p;

    for (int i = 0; i < no_problems; i++)
    {
        problem n;
        inFile >> n.id;
        inFile >> n.speciality;
        p.push_back(n);
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
    for (auto& prob : p)
    {
        bool assigned = false;
        for (auto& doc : d)
        {
            if (doc.available && doc.speciality == prob.speciality)
            {
                cout << doc.id << " " << prob.id << '\n';
                doc.available = false;
                assigned = true;
                break;

            }
        }
    }
    return 0;
}