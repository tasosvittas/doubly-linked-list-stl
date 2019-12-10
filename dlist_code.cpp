#include <iostream>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

struct students
{
    string id;
    string name;
    int year;
    string direction;
    double grade;

    bool operator==(const students &other) const
    {
        return id == other.id;
    }
};

int main()
{
    list<students> alist;

    string line;
    fstream fin;
    fin.open("students.txt", ios::in);
    while (getline(fin, line))
    {
        stringstream ss(line);
        students stud;
        ss >> stud.id;
        ss >> stud.name;
        ss >> stud.year;
        ss >> stud.direction;
        ss >> stud.grade;
        alist.push_back(stud);
        cout << stud.id << " " << stud.name << " " << stud.year << " " << stud.direction << " " << stud.grade << " " << endl;
    }
    
    cout << " " << endl;
    cout << "The new list is(stl):" << endl;
    struct students s2 = {"011", "iasonas", 3, "CS", 7};
    alist.push_front(s2);
    struct students s3 = {"012", "electra", 5, "CE", 6.0};
    alist.push_back(s3);
    for (students stud : alist)
        cout << stud.id << " " << stud.name << " " << stud.year << " " << stud.direction << " " << stud.grade << " " << endl;

    cout << " " << endl;
    cout << "List after removing the student with id 005(stl):" << endl;
    struct students s4 = {"005"};
    alist.remove(s4);
    for (students stud : alist)
        cout << stud.id << " " << stud.name << " " << stud.year << " " << stud.direction << " " << stud.grade << " " << endl;
    
    cout << " " << endl;
    cout<< "Only Students with CS direction and grade >=5 "<< endl;
    list<students>::iterator it;
    for (it = alist.begin(); it != alist.end(); ++it)
    {
        if (it->direction == "CS" && it->grade >= 5)
            cout << it->id << " " << it->name << " " << it->year << " " << it->direction << " " << it->grade << " " << endl;
    }
    
    cout << " " << endl;
    cout<<"Reverse List"<<endl;
    list<students>::reverse_iterator iter;
    for (iter = alist.rbegin(); iter != alist.rend(); ++iter)
    {
        if (iter->direction == "CS" && iter->grade >= 5)
            cout << iter->id << " " << iter->name << "  " << iter->direction << "  " << iter->grade << endl;
    }
    fin.close();
}
