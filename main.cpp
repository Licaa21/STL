#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct problem
{

    string id;
    string speciality;
    int orasosire;
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
    set<problem> set;

    for (int i = 0; i < no_problems; i++)
    {
        problem n;
        inFile >> n.id;
        inFile >> n.speciality;
        inFile >> n.orasosire;
        inFile >> n.durata;
        inFile >> n.prioritate;
        set.insert(n);
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
}