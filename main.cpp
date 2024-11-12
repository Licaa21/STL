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
};
int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    
    inFile >> no_problems;
    string name, speciality;
    std::vector<problem> problems;
    for (int i = 0; i < no_problems; i++)
    {
        problem n;
        inFile >> n.id;
        inFile >> n.speciality;
        problems.push_back(n);
      
    }

    inFile >> no_doctors;

    std::vector<doctor> doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        doctor doc;

        inFile >> doc.id;
        inFile >> doc.speciality;
        
        doctors.push_back(doc);
    }
    for (auto problem: problems)
    {
        bool found = 0;
        for (auto doctor: doctors)
        {
            if (problem.speciality == doctor.speciality)
            {
                found = 1;
                break;
            }
            
        }
        if (found == 0)
            cout << problem.id << " " << "Repsins" << endl;
        else
            cout << problem.id << " " << "Acceptat"<< endl;

    }
    
    return 0;
}
