#include <iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


class Date {
public: 
    int day;
    int month;
    int year;
    Date() {
        day = month = year = 0;
    }
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;

    }
};

class Department {
public:
    //vector<Staff> staff;
};

class Hospital {
public:
    string name = "Aban";
    string address = ".....";
    string phone = "021...";
    vector<Department*> dep;
};

class Person {
public:
    Hospital Ho;
    string title;
    string givenname;
    string middlename;
    string familyname;
    string name;
    Date birthDate;
    string gender;
    string homeaddress;
    string phone;
    void set_title(string str) { title = str; };
    void set_givenname(string str1) { givenname = str1; };
    void set_middlename(string str2) { middlename = str2; };
    void set_familyname(string str3) { familyname = str3; };
    void set_birthday(Date a) { birthDate = a; };
    void set_gender(string str4) { gender = str4; };
    void set_homeaddress(string str5) { homeaddress = str5; };
    void set_phone(string str6) { phone = str6; };
    void cinNAME() {
        name = givenname + " " + middlename + " " + familyname;
        size_t found = name.find_first_of(" ");
        while (found != string::npos) {
            name[found] = '%';
            found = name.find_first_of(" ", found + 1);
        }
    }
};

class Staff :public Person {
public:
    Date joined;
    string education;
    string certification;
    string languages;
};

class AdministrativeStaff :public Staff {

};

class TechnicalStaff :public Staff {

};

class FrontDeskStaff :public AdministrativeStaff {

};

class Technician :public TechnicalStaff {

};

class Technologist :public TechnicalStaff {

};

class Receptionist :public FrontDeskStaff {

};

class SurgicalTechnologist : public Technologist {

};

class Patient : public Person
{
public:
    string id;
    string gender;
    Date birthDate;
    int age;
    Date accepted;
    string sickness;
    string prescriptions;
    string allergies;
    string specialreqs;
};

class OperationsStaff : public Staff {
public:
};

class Nurse : public OperationsStaff {
};

class Doctor : public OperationsStaff {
public:
    string specialty;
    string locations;
};

class Surgeon : public Doctor {
};

static vector<Surgeon*> jarah;
static vector<Doctor*> doctor;
static vector<Nurse*> parastar;
static vector<Patient*> bimar;
static vector<TechnicalStaff*> TStaff;
static vector<Receptionist*> paziresh;

string cinS() {
    string n;
    cin >> ws;
    std::getline(cin, n);
    size_t found = n.find_first_of(" ");
    while (found != string::npos) {
        n[found] = '%';
        found = n.find_first_of(" ", found + 1);
    }
    return n;
}

string coutS(string n) {
    size_t found = n.find_first_of("%");
    while (found != string::npos) {
        n[found] = ' ';
        found = n.find_first_of("%", found + 1);
    }
    return n;
}

int difference(Date d1, Date d2) {
    int dif1 = (d1.year - d2.year) * 365;
    int dif2 = (d1.month - d2.month) * 30;
    int dif3 = (d1.day - d2.day);
    int dif = dif1 + dif2 + dif3;
    return dif;
}

int searchP(vector<Patient*> p, string n) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->name == n) {
            return i;
        }
    }
    return -1;
}

int searchD(vector<Doctor*> p, string n) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->name == n) {
            return i;
        }
    }
    return -1;
}

int searchN(vector<Nurse*> p, string n) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->name == n) {
            return i;
        }
    }
    return -1;
}

int searchS(vector<Surgeon*> p, string n) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->name == n) {
            return i;
        }
    }
    return -1;
}

int searchT(vector<TechnicalStaff*> p, string n) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->name == n) {
            return i;
        }
    }
    return -1;
}

int searchR(vector<Receptionist*> p, string n) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i]->name == n) {
            return i;
        }
    }
    return -1;
}

void LoadPatient() {
    ifstream PList("PATIENT.txt", ios::in);
    if (!PList) {
        cout << "cannot open the file";
    }
    else {
        int i = 0;
        string text;
        while (PList >> text) {
            int index = text.find("$");
            if (index > 0) {
                Patient* p = new Patient();
                p->name = text.substr(0, index).c_str();
                text = text.substr(index + 1);
                index = text.find("/");
                if (index > 0) {
                    p->birthDate.year = atoi(text.substr(0, index).c_str());
                    text = text.substr(index + 1);
                    index = text.find("/");
                    if (index > 0) {
                        p->birthDate.month = atoi(text.substr(0, index).c_str());
                        text = text.substr(index + 1);
                        index = text.find("$");
                        if (index > 0) {
                            p->birthDate.day = atoi(text.substr(0, index).c_str());
                            text = text.substr(index + 1);
                            index = text.find("$");
                            if (index > 0) {
                                p->age = atoi(text.substr(0, index).c_str());
                                text = text.substr(index + 1);
                                index = text.find("$");
                                if (index > 0) {
                                    p->gender = text.substr(0, index).c_str();
                                    text = text.substr(index + 1);
                                    index = text.find("$");
                                    if (index > 0) {
                                        p->homeaddress = text.substr(0, index).c_str();
                                        text = text.substr(index + 1);
                                        index = text.find("$");
                                        if (index > 0) {
                                            p->phone = text.substr(0, index).c_str();
                                            text = text.substr(index + 1);
                                            index = text.find("/");
                                            if (index > 0) {
                                                p->accepted.year = atoi(text.substr(0, index).c_str());
                                                text = text.substr(index + 1);
                                                index = text.find("/");
                                                if (index > 0) {
                                                    p->accepted.month = atoi(text.substr(0, index).c_str());
                                                    text = text.substr(index + 1);
                                                    index = text.find("$");
                                                    if (index > 0) {
                                                        p->accepted.day = atoi(text.substr(0, index).c_str());
                                                        text = text.substr(index + 1);
                                                        index = text.find("$");
                                                        if (index > 0) {
                                                            p->sickness = text.substr(0, index).c_str();
                                                            text = text.substr(index + 1);
                                                            index = text.find("$");
                                                            if (index > 0) {
                                                                p->allergies = text.substr(0, index).c_str();
                                                                text = text.substr(index + 1);
                                                                index = text.find("$");
                                                                if (index > 0) {
                                                                    p->specialreqs = text.substr(0, index).c_str();
                                                                    text = text.substr(index + 1);
                                                                    index = text.find("$");
                                                                    if (index > 0) {
                                                                        p->prescriptions = text.substr(0, index).c_str();
                                                                        text = text.substr(index + 1);
                                                                        index = text.find("$");
                                                                        if (index > 0) {
                                                                            p->id = text.substr(0, index).c_str();
                                                                            text = text.substr(index + 1);
                                                                            bimar.push_back(p);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void LoadDoctor() {
    ifstream DList("DOCTOR.txt", ios::in);
    if (!DList) {
        cout << "cannot open the file";
    }
    else {
        int i = 0;
        string text;
        while (DList >> text) {
            int index = text.find("$");
            if (index > 0) {
                Doctor* d = new Doctor();
                d->name = text.substr(0, index).c_str();
                text = text.substr(index + 1);
                index = text.find("/");
                if (index > 0) {
                    d->birthDate.year = atoi(text.substr(0, index).c_str());
                    text = text.substr(index + 1);
                    index = text.find("/");
                    if (index > 0) {
                        d->birthDate.month = atoi(text.substr(0, index).c_str());
                        text = text.substr(index + 1);
                        index = text.find("$");
                        if (index > 0) {
                            d->birthDate.day = atoi(text.substr(0, index).c_str());
                            text = text.substr(index + 1);
                            index = text.find("$");
                            if (index > 0) {
                                d->specialty = text.substr(0, index).c_str();
                                text = text.substr(index + 1);
                                index = text.find("$");
                                if (index > 0) {
                                    d->gender = text.substr(0, index).c_str();
                                    text = text.substr(index + 1);
                                    index = text.find("$");
                                    if (index > 0) {
                                        d->homeaddress = text.substr(0, index).c_str();
                                        text = text.substr(index + 1);
                                        index = text.find("$");
                                        if (index > 0) {
                                            d->phone = text.substr(0, index).c_str();
                                            text = text.substr(index + 1);
                                            index = text.find("/");
                                            if (index > 0) {
                                                d->joined.year = atoi(text.substr(0, index).c_str());
                                                text = text.substr(index + 1);
                                                index = text.find("/");
                                                if (index > 0) {
                                                    d->joined.month = atoi(text.substr(0, index).c_str());
                                                    text = text.substr(index + 1);
                                                    index = text.find("$");
                                                    if (index > 0) {
                                                        d->joined.day = atoi(text.substr(0, index).c_str());
                                                        text = text.substr(index + 1);
                                                        index = text.find("$");
                                                        if (index > 0) {
                                                            d->education = text.substr(0, index).c_str();
                                                            text = text.substr(index + 1);
                                                            index = text.find("$");
                                                            if (index > 0) {
                                                                d->certification = text.substr(0, index).c_str();
                                                                text = text.substr(index + 1);
                                                                index = text.find("$");
                                                                if (index > 0) {
                                                                    d->languages = text.substr(0, index).c_str();
                                                                    text = text.substr(index + 1);
                                                                    index = text.find("$");
                                                                    if (index > 0) {
                                                                        d->locations = text.substr(0, index).c_str();
                                                                        text = text.substr(index + 1);
                                                                        doctor.push_back(d);
                                                                    }    
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void LoadSurgon() {
    ifstream SList("SURGON.txt", ios::in);
    if (!SList) {
        cout << "cannot open the file";
    }
    else {
        int i = 0;
        string text;
        while (SList >> text) {
            int index = text.find("$");
            if (index > 0) {
                Surgeon* s = new Surgeon();
                s->name = text.substr(0, index).c_str();
                text = text.substr(index + 1);
                index = text.find("/");
                if (index > 0) {
                    s->birthDate.year = atoi(text.substr(0, index).c_str());
                    text = text.substr(index + 1);
                    index = text.find("/");
                    if (index > 0) {
                        s->birthDate.month = atoi(text.substr(0, index).c_str());
                        text = text.substr(index + 1);
                        index = text.find("$");
                        if (index > 0) {
                            s->birthDate.day = atoi(text.substr(0, index).c_str());
                            text = text.substr(index + 1);
                            index = text.find("$");
                            if (index > 0) {
                                s->specialty = text.substr(0, index).c_str();
                                text = text.substr(index + 1);
                                index = text.find("$");
                                if (index > 0) {
                                    s->gender = text.substr(0, index).c_str();
                                    text = text.substr(index + 1);
                                    index = text.find("$");
                                    if (index > 0) {
                                        s->homeaddress = text.substr(0, index).c_str();
                                        text = text.substr(index + 1);
                                        index = text.find("$");
                                        if (index > 0) {
                                            s->phone = text.substr(0, index).c_str();
                                            text = text.substr(index + 1);
                                            index = text.find("/");
                                            if (index > 0) {
                                                s->joined.year = atoi(text.substr(0, index).c_str());
                                                text = text.substr(index + 1);
                                                index = text.find("/");
                                                if (index > 0) {
                                                    s->joined.month = atoi(text.substr(0, index).c_str());
                                                    text = text.substr(index + 1);
                                                    index = text.find("$");
                                                    if (index > 0) {
                                                        s->joined.day = atoi(text.substr(0, index).c_str());
                                                        text = text.substr(index + 1);
                                                        index = text.find("$");
                                                        if (index > 0) {
                                                            s->education = atoi(text.substr(0, index).c_str());
                                                            text = text.substr(index + 1);
                                                            index = text.find("$");
                                                            if (index > 0) {
                                                                s->certification = atoi(text.substr(0, index).c_str());
                                                                text = text.substr(index + 1);
                                                                index = text.find("$");
                                                                if (index > 0) {
                                                                    s->languages = atoi(text.substr(0, index).c_str());
                                                                    text = text.substr(index + 1);
                                                                    index = text.find("$");
                                                                    if (index > 0) {
                                                                        s->locations = atoi(text.substr(0, index).c_str());
                                                                        text = text.substr(index + 1);
                                                                        jarah.push_back(s);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void LoadNurse() {
    ifstream NList("NURSE.txt", ios::in);
    if (!NList) {
        cout << "cannot open the file";
    }
    else {
        int i = 0;
        string text;
        while (NList >> text) {
            int index = text.find("$");
            if (index > 0) {
                Nurse* n = new Nurse();
                n->name = text.substr(0, index).c_str();
                text = text.substr(index + 1);
                index = text.find("/");
                if (index > 0) {
                    n->birthDate.year = atoi(text.substr(0, index).c_str());
                    text = text.substr(index + 1);
                    index = text.find("/");
                    if (index > 0) {
                        n->birthDate.month = atoi(text.substr(0, index).c_str());
                        text = text.substr(index + 1);
                        index = text.find("$");
                        if (index > 0) {
                            n->birthDate.day = atoi(text.substr(0, index).c_str());
                            text = text.substr(index + 1);
                            index = text.find("$");
                            if (index > 0) {
                                n->gender = text.substr(0, index).c_str();
                                text = text.substr(index + 1);
                                index = text.find("$");
                                if (index > 0) {
                                    n->homeaddress = text.substr(0, index).c_str();
                                    text = text.substr(index + 1);
                                    index = text.find("$");
                                    if (index > 0) {
                                        n->phone = text.substr(0, index).c_str();
                                        text = text.substr(index + 1);
                                        index = text.find("/");
                                        if (index > 0) {
                                            n->joined.year = atoi(text.substr(0, index).c_str());
                                            text = text.substr(index + 1);
                                            index = text.find("/");
                                            if (index > 0) {
                                                n->joined.month = atoi(text.substr(0, index).c_str());
                                                text = text.substr(index + 1);
                                                index = text.find("$");
                                                if (index > 0) {
                                                    n->joined.day = atoi(text.substr(0, index).c_str());
                                                    text = text.substr(index + 1);
                                                    index = text.find("$");
                                                    if (index > 0) {
                                                        n->education = atoi(text.substr(0, index).c_str());
                                                        text = text.substr(index + 1);
                                                        index = text.find("$");
                                                        if (index > 0) {
                                                            n->certification = atoi(text.substr(0, index).c_str());
                                                            text = text.substr(index + 1);
                                                            index = text.find("$");
                                                            if (index > 0) {
                                                                n->languages = atoi(text.substr(0, index).c_str());
                                                                text = text.substr(index + 1);
                                                                parastar.push_back(n);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void LoadReceptionist() {
    ifstream RList("RECEPTIONIST.txt", ios::in);
    if (!RList) {
        cout << "cannot open the file";
    }
    else {
        int i = 0;
        string text;
        while (RList >> text) {
            int index = text.find("$");
            if (index > 0) {
                Receptionist* r = new Receptionist();
                r->name = text.substr(0, index).c_str();
                text = text.substr(index + 1);
                index = text.find("/");
                if (index > 0) {
                    r->birthDate.year = atoi(text.substr(0, index).c_str());
                    text = text.substr(index + 1);
                    index = text.find("/");
                    if (index > 0) {
                        r->birthDate.month = atoi(text.substr(0, index).c_str());
                        text = text.substr(index + 1);
                        index = text.find("$");
                        if (index > 0) {
                            r->birthDate.day = atoi(text.substr(0, index).c_str());
                            text = text.substr(index + 1);
                            index = text.find("$");
                            if (index > 0) {
                                r->gender = text.substr(0, index).c_str();
                                text = text.substr(index + 1);
                                index = text.find("$");
                                if (index > 0) {
                                    r->homeaddress = text.substr(0, index).c_str();
                                    text = text.substr(index + 1);
                                    index = text.find("$");
                                    if (index > 0) {
                                        r->phone = text.substr(0, index).c_str();
                                        text = text.substr(index + 1);
                                        index = text.find("/");
                                        if (index > 0) {
                                            r->joined.year = atoi(text.substr(0, index).c_str());
                                            text = text.substr(index + 1);
                                            index = text.find("/");
                                            if (index > 0) {
                                                r->joined.month = atoi(text.substr(0, index).c_str());
                                                text = text.substr(index + 1);
                                                index = text.find("$");
                                                if (index > 0) {
                                                    r->joined.day = atoi(text.substr(0, index).c_str());
                                                    text = text.substr(index + 1);
                                                    index = text.find("$");
                                                    if (index > 0) {
                                                        r->education = atoi(text.substr(0, index).c_str());
                                                        text = text.substr(index + 1);
                                                        index = text.find("$");
                                                        if (index > 0) {
                                                            r->certification = atoi(text.substr(0, index).c_str());
                                                            text = text.substr(index + 1);
                                                            index = text.find("$");
                                                            if (index > 0) {
                                                                r->languages = atoi(text.substr(0, index).c_str());
                                                                text = text.substr(index + 1);
                                                                paziresh.push_back(r);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void LoadTechnicalStaff() {
    ifstream TList("TECHNICAL.txt", ios::in);
    if (!TList) {
        cout << "cannot open the file";
    }
    else {
        int i = 0;
        string text;
        while (TList >> text) {
            int index = text.find("$");
            if (index > 0) {
                TechnicalStaff* t = new TechnicalStaff();
                t->name = text.substr(0, index).c_str();
                text = text.substr(index + 1);
                index = text.find("/");
                if (index > 0) {
                    t->birthDate.year = atoi(text.substr(0, index).c_str());
                    text = text.substr(index + 1);
                    index = text.find("/");
                    if (index > 0) {
                        t->birthDate.month = atoi(text.substr(0, index).c_str());
                        text = text.substr(index + 1);
                        index = text.find("$");
                        if (index > 0) {
                            t->birthDate.day = atoi(text.substr(0, index).c_str());
                            text = text.substr(index + 1);
                            index = text.find("$");
                            if (index > 0) {
                                t->gender = text.substr(0, index).c_str();
                                text = text.substr(index + 1);
                                index = text.find("$");
                                if (index > 0) {
                                    t->homeaddress = text.substr(0, index).c_str();
                                    text = text.substr(index + 1);
                                    index = text.find("$");
                                    if (index > 0) {
                                        t->phone = text.substr(0, index).c_str();
                                        text = text.substr(index + 1);
                                        index = text.find("/");
                                        if (index > 0) {
                                            t->joined.year = atoi(text.substr(0, index).c_str());
                                            text = text.substr(index + 1);
                                            index = text.find("/");
                                            if (index > 0) {
                                                t->joined.month = atoi(text.substr(0, index).c_str());
                                                text = text.substr(index + 1);
                                                index = text.find("$");
                                                if (index > 0) {
                                                    t->joined.day = atoi(text.substr(0, index).c_str());
                                                    text = text.substr(index + 1);
                                                    index = text.find("$");
                                                    if (index > 0) {
                                                        t->education = atoi(text.substr(0, index).c_str());
                                                        text = text.substr(index + 1);
                                                        index = text.find("$");
                                                        if (index > 0) {
                                                            t->certification = atoi(text.substr(0, index).c_str());
                                                            text = text.substr(index + 1);
                                                            index = text.find("$");
                                                            if (index > 0) {
                                                                t->languages = atoi(text.substr(0, index).c_str());
                                                                text = text.substr(index + 1);
                                                                TStaff.push_back(t);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//Patient
Patient* AddPatient() {
    Patient* p = new Patient();

    cout << "Please Enter title" << endl;
    string t;
    t = cinS();
    p->title = t;

    cout << "Please Enter ID" << endl;
    string ID;
    cin >> ID;
    p->id = ID;

    cout << "Please Enter givenname" << endl;
    string gn;
    cin >> gn;
    p->givenname = gn;

    cout << "Please Enter middlename" << endl;
    string mn;
    cin >> mn;
    p->middlename = mn;

    cout << "Please Enter fmilyname" << endl;
    string fn;
    cin >> fn;
    p->familyname = fn;

    p->cinNAME();

    cout << "Please Enter Birthday" << endl;
    cout << "Please Enter The Of Your Birthday: ";
    int year;
    cin >> year;
    cout << endl;
    cout << "Please Enter The Month Of Birthday: ";
    int month;
    cin >> month;
    cout << endl;
    cout << "Please Enter The Day Of Birthday: ";
    int day;
    cin >> day;
    cout << endl;
    Date dt(day, month, year);
    p->birthDate = dt;

    cout << "Please Enter The Age: " << endl;
    int ag;
    cin >> ag;
    p->age = ag;

    cout << "What Is Gender (1= Female , 2= Male): " << endl;
    int g;
    cin >> g;
    if (g == 1) p->gender = "female";
    else p->gender = "male";

    cout << "please Enter Home Address: " << endl;
    string ha;
    ha = cinS();
    p->homeaddress = ha;

    cout << "Please Enter Phone number:" << endl;
    string pn;
    cin >> pn;
    p->phone = pn;

    cout << "Please Enter Acception Date: " << endl;
    cout << "Please Enter The Year Of Acception: ";
    int y;
    cin >> y;
    cout << endl;
    cout << "Please Enter The Month Of Acception: ";
    int m;
    cin >> m;
    cout << endl;
    cout << "Please Enter The Day Of Your Acception: ";
    int da;
    cin >> da;
    cout << endl;
    Date adt(da, m, y);
    p->accepted = adt;

    cout << "please Enter Sickness: " << endl;
    string sn;
    sn = cinS();
    p->sickness = sn;

    cout << "please Enter Allergies: " << endl;
    string A;
    A = cinS();
    p->allergies = A;

    cout << "please Enter Your specialReqs: " << endl;
    string sR;
    sR = cinS();
    p->specialreqs = sR;

    cout << "please Enter Your Prescriptions: " << endl;
    string pr;
    pr = cinS();
    p->prescriptions = pr;

    return p;
}

//Doctor
Doctor* AddDoctor() {
    Doctor* d = new Doctor();

    cout << "Please Enter title" << endl;
    string t;
    t = cinS();
    d->title = t;

    cout << "Please Enter givenname" << endl;
    string gn;
    cin >> gn;
    d->givenname = gn;

    cout << "Please Enter middlename" << endl;
    string mn;
    cin >> mn;
    d->middlename = mn;

    cout << "Please Enter fmilyname" << endl;
    string fn;
    cin >> fn;
    d->familyname = fn;

    d->cinNAME();

    cout << "Please Enter Birthday" << endl;
    cout << "Please Enter The Year Of Birthday: ";
    int year;
    cin >> year;
    cout << endl;
    cout << "Please Enter The Month Of Birthday: ";
    int month;
    cin >> month;
    cout << endl;
    cout << "Please Enter The Day Of Birthday: ";
    int day;
    cin >> day;
    cout << endl;
    Date dt(day, month, year);
    d->birthDate = dt;

    cout << "What Is Gender (1= Female 2= Male): " << endl;
    int g;
    cin >> g;
    if (g == 1) d->gender = "female";
    else d->gender = "male";

    cout << "please Enter Home Address: " << endl;
    string ha;
    ha = cinS();
    d->homeaddress = ha;

    cout << "Please Enter Phone number:" << endl;
    string pn;
    cin >> pn;
    d->phone = pn;

    cout << "please Enter Your Specialty: " << endl;
    string sp;
    sp = cinS();
    d->specialty = sp;

    cout << "please Enter Locations: " << endl;
    string L;
    L = cinS();
    d->locations = L;

    cout << "Please Enter The day Of joined" << endl;
    cout << "Please Enter The Year Of joined: ";
    int y;
    cin >> y;
    cout << endl;
    cout << "Please Enter The Month Of joined: ";
    int m;
    cin >> m;
    cout << endl;
    cout << "Please Enter The Day Of joined: ";
    int da;
    cin >> da;
    cout << endl;
    Date jdt(da, m, y);
    d->joined = jdt;

    cout << "please Enter Education: " << endl;
    string E;
    E = cinS();
    d->education = E;

    cout << "please Enter Certification: " << endl;
    string cf;
    cf = cinS();
    d->certification = cf;

    cout << "please Enter Languages: " << endl;
    string lg;
    lg = cinS();
    d->languages = lg;

    return d;
}

//surgeon
Surgeon* Addsurgeon() {

    Surgeon* s = new Surgeon();

    cout << "Please Enter title" << endl;
    string t;
    t = cinS();
    s->title = t;

    cout << "Please Enter givenname" << endl;
    string gn;
    cin >> gn;
    s->givenname = gn;

    cout << "Please Enter middlename" << endl;
    string mn;
    cin >> mn;
    s->middlename = mn;

    cout << "Please Enter fmilyname" << endl;
    string fn;
    cin >> fn;
    s->familyname = fn;

    s->cinNAME();

    cout << "Please Enter Birthday" << endl;
    cout << "Please Enter The Year Of Birthday: ";
    int year;
    cin >> year;
    cout << endl;
    cout << "Please Enter The Month Of Birthday: ";
    int month;
    cin >> month;
    cout << endl;
    cout << "Please Enter The Day Of Birthday: ";
    int day;
    cin >> day;
    cout << endl;
    Date dt(day, month, year);
    s->birthDate = dt;

    cout << "What Is Gender (1= Female 2= Male): " << endl;
    int g;
    cin >> g;
    if (g == 1) s->gender = "female";
    else s->gender = "male";

    cout << "please Enter Home Address: " << endl;
    string ha;
    ha = cinS();
    s->homeaddress = ha;

    cout << "Please Enter Phone number:" << endl;
    string pn;
    cin >> pn;
    s->phone = pn;

    cout << "please Enter Specialty: " << endl;
    string sp;
    sp = cinS();
    s->specialty = sp;

    cout << "please Enter Locations: " << endl;
    string L;
    L = cinS();
    s->locations = L;

    cout << "Please Enter The day Of joined" << endl;
    cout << "Please Enter The Year Of joined: ";
    int y;
    cin >> y;
    cout << endl;
    cout << "Please Enter The Month Of joined: ";
    int m;
    cin >> m;
    cout << endl;
    cout << "Please Enter The Day Of joined: ";
    int da;
    cin >> da;
    cout << endl;
    Date jdt(da, m, y);
    s->joined = jdt;

    cout << "please Enter Education: " << endl;
    string E;
    E = cinS();
    s->education = E;

    cout << "please Enter Certification: " << endl;
    string cf;
    cf = cinS();
    s->certification = cf;

    cout << "please Enter Languages: " << endl;
    string lg;
    lg = cinS();
    s->languages = lg;

    return s;
}

//nurse
Nurse* Addnurse() {

    Nurse* n = new Nurse();

    cout << "Please Enter title" << endl;
    string t;
    t = cinS();
    n->title = t;

    cout << "Please Enter givenname" << endl;
    string gn;
    cin >> gn;
    n->givenname = gn;

    cout << "Please Enter middlename" << endl;
    string mn;
    cin >> mn;
    n->middlename = mn;

    cout << "Please Enter fmilyname" << endl;
    string fn;
    cin >> fn;
    n->familyname = fn;

    n->cinNAME();

    cout << "Please Enter Birthday" << endl;
    cout << "Please Enter The Year Of Birthday: ";
    int year;
    cin >> year;
    cout << endl;
    cout << "Please Enter The Month Of Birthday: ";
    int month;
    cin >> month;
    cout << endl;
    cout << "Please Enter The Day Of Birthday: ";
    int day;
    cin >> day;
    cout << endl;
    Date dt(day, month, year);
    n->birthDate = dt;

    cout << "What Is Gender (1= Female 2= Male): " << endl;
    int g;
    cin >> g;
    if (g == 1) n->gender = "female";
    else n->gender = "male";

    cout << "please Enter Home Address: " << endl;
    string ha;
    ha = cinS();
    n->homeaddress = ha;

    cout << "Please Enter Phone number:" << endl;
    string pn;
    cin >> pn;
    n->phone = pn;

    cout << "Please Enter The day Joined" << endl;
    cout << "Please Enter The Year Of Joined: ";
    int y;
    cin >> y;
    cout << endl;
    cout << "Please Enter The Month Of Joined: ";
    int m;
    cin >> m;
    cout << endl;
    cout << "Please Enter The Day Of Joined: ";
    int da;
    cin >> da;
    cout << endl;
    Date jdt(da, m, y);
    n->joined = jdt;

    cout << "please Enter Education: " << endl;
    string E;
    E = cinS();
    n->education = E;

    cout << "please Enter Certification: " << endl;
    string cf;
    cf = cinS();
    n->certification = cf;

    cout << "please Enter Your Languages: " << endl;
    string lg;
    lg = cinS();
    n->languages = lg;

    return n;
}

//Receptionist
Receptionist* Addreceptionist() {

    Receptionist* r = new Receptionist();

    cout << "Please Enter title" << endl;
    string t;
    t = cinS();
    r->title = t;

    cout << "Please Enter givenname" << endl;
    string gn;
    cin >> gn;
    r->givenname = gn;

    cout << "Please Enter middlename" << endl;
    string mn;
    cin >> mn;
    r->middlename = mn;

    cout << "Please Enter fmilyname" << endl;
    string fn;
    cin >> fn;
    r->familyname = fn;

    r->cinNAME();

    cout << "Please Enter Birthday" << endl;
    cout << "Please Enter The Year Of  Birthday: ";
    int year;
    cin >> year;
    cout << endl;
    cout << "Please Enter The Month Of Birthday: ";
    int month;
    cin >> month;
    cout << endl;
    cout << "Please Enter The Day Of Birthday: ";
    int day;
    cin >> day;
    cout << endl;
    Date dt(day, month, year);
    r->birthDate = dt;

    cout << "What Is Gender (1= Female 2= Male): " << endl;
    int g;
    cin >> g;
    if (g == 1) r->gender = "female";
    else r->gender = "male";

    cout << "please Enter Home Address: " << endl;
    string ha;
    ha = cinS();
    r->homeaddress = ha;

    cout << "Please Enter Phone number:" << endl;
    string pn;
    cin >> pn;
    r->phone = pn;

    cout << "Please Enter The day Joined" << endl;
    cout << "Please Enter The Year Of Joined: ";
    int y;
    cin >> y;
    cout << endl;
    cout << "Please Enter The Month Of joined: ";
    int m;
    cin >> m;
    cout << endl;
    cout << "Please Enter The Day Of joined: ";
    int da;
    cin >> da;
    cout << endl;
    Date jdt(da, m, y);
    r->joined = jdt;

    cout << "please Enter Education: " << endl;
    string E;
    E = cinS();
    r->education = E;

    cout << "please Enter Certification: " << endl;
    string cf;
    cf = cinS();
    r->certification = cf;

    cout << "please Enter Languages: " << endl;
    string lg;
    lg = cinS();
    r->languages = lg;

    return r;
}

//TechnicalStaff
TechnicalStaff* AddTechnicalStaff() {

    TechnicalStaff* t = new TechnicalStaff();

    cout << "Please Enter title" << endl;
    string e;
    e = cinS();
    t->title = e;

    cout << "Please Enter givenname" << endl;
    string gn;
    cin >> gn;
    t->givenname = gn;

    cout << "Please Enter middlename" << endl;
    string mn;
    cin >> mn;
    t->middlename = mn;

    cout << "Please Enter fmilyname" << endl;
    string fn;
    cin >> fn;
    t->familyname = fn;

    t->cinNAME();

    cout << "Please Enter Birthday" << endl;
    cout << "Please Enter The Year Of Birthday: ";
    int year;
    cin >> year;
    cout << endl;
    cout << "Please Enter The Month Of Birthday: ";
    int month;
    cin >> month;
    cout << endl;
    cout << "Please Enter The Day Of Birthday: ";
    int day;
    cin >> day;
    cout << endl;
    Date dt(day, month, year);
    t->birthDate = dt;

    cout << "What Is Gender (1= Female 2= Male): " << endl;
    int g;
    cin >> g;
    if (g == 1) t->gender = "female";
    else t->gender = "male";

    cout << "please Enter Home Address: " << endl;
    string ha;
    ha = cinS();
    t->homeaddress = ha;

    cout << "Please Enter Phone number:" << endl;
    string pn;
    cin >> pn;
    t->phone = pn;

    cout << "Please Enter The day Joined" << endl;
    cout << "Please Enter The Year Of Joined: ";
    int y;
    cin >> y;
    cout << endl;
    cout << "Please Enter The Month Of joined: ";
    int m;
    cin >> m;
    cout << endl;
    cout << "Please Enter The Day Of joined: ";
    int da;
    cin >> da;
    cout << endl;
    Date jdt(da, m, y);
    t->joined = jdt;

    cout << "please Enter Education: " << endl;
    string E;
    E = cinS();
    t->education = E;

    cout << "please Enter Certification: " << endl;
    string cf;
    cf = cinS();
    t->certification = cf;

    cout << "please Enter Languages: " << endl;
    string lg;
    lg = cinS();
    t->languages = lg;

    return t;
}

/////print functions
void printPatient(Patient* p) {
    cout << "ID: " << p->id << endl;
    cout << "Name: " << coutS(p->name) << endl;
    cout << "Birthday: " << p->birthDate.year << "/" << p->birthDate.month << "/" << p->birthDate.day << endl;
    cout << "Age: " << p->age << endl;
    cout << "Gender: " << p->gender << endl;
    cout << "Home Address: " << coutS(p->homeaddress) << endl;
    cout << "Phone: " << p->phone << endl;
    cout << "Accepted Date: " << p->accepted.year << "/" << p->accepted.month << "/" << p->accepted.day << endl;
    cout << "Sickness: " << coutS(p->sickness) << endl;
    cout << "Allergies: " << coutS(p->allergies) << endl;
    cout << "Prescriptions: " << coutS(p->prescriptions) << endl;
    cout << "specialReqs: " << coutS(p->specialreqs) << endl;
}

void printDoctor(Doctor* d) {
    cout << "Name: " << coutS(d->name) << endl;
    cout << "Birthday: " << d->birthDate.year << "/" << d->birthDate.month << "/" << d->birthDate.day << endl;
    cout << "Gender: " << d->gender << endl;
    cout << "Home Address: " << coutS(d->homeaddress) << endl;
    cout << "Phone: " << d->phone << endl;
    cout << "Specialty: " << coutS(d->specialty) << endl;
    cout << "Education : " << coutS(d->education) << endl;
    cout << "Languages: " << coutS(d->languages) << endl;
    cout << "Locations: " << coutS(d->locations) << endl;
    cout << "Certification: " << coutS(d->certification) << endl;
    cout << "Joined Day: " << d->joined.year << "/" << d->joined.month << "/" << d->joined.day << endl;
}

void printSurgeon(Surgeon* s) {
    cout << "Name: " << coutS(s->name) << endl;
    cout << "Birthday: " << s->birthDate.year << "/" << s->birthDate.month << "/" << s->birthDate.day << endl;
    cout << "Gender: " << s->gender << endl;
    cout << "Home Address: " << coutS(s->homeaddress) << endl;
    cout << "Phone: " << s->phone << endl;
    cout << "Specialty: " << coutS(s->specialty) << endl;
    cout << "Education : " << coutS(s->education) << endl;
    cout << "Languages: " << coutS(s->languages) << endl;
    cout << "Locations: " << coutS(s->locations) << endl;
    cout << "Certification: " << coutS(s->certification) << endl;
    cout << "Joined Day: " << s->joined.year << "/" << s->joined.month << "/" << s->joined.day << endl;
}

void printNurse(Nurse* n) {
    cout << "Name: " << coutS(n->name) << endl;
    cout << "Birthday: " << n->birthDate.year << "/" << n->birthDate.month << "/" << n->birthDate.day << endl;
    cout << "Gender: " << n->gender << endl;
    cout << "Home Address: " << coutS(n->homeaddress) << endl;
    cout << "Phone: " << n->phone << endl;
    cout << "Education : " << coutS(n->education) << endl;
    cout << "Languages: " << coutS(n->languages) << endl;
    cout << "Certification: " << coutS(n->certification) << endl;
    cout << "Joined Day: " << n->joined.year << "/" << n->joined.month << "/" << n->joined.day << endl;
}

void printReceptionist(Receptionist* r) {
    cout << "Name: " << coutS(r->name) << endl;
    cout << "Birthday: " << r->birthDate.year << "/" << r->birthDate.month << "/" << r->birthDate.day << endl;
    cout << "Gender: " << r->gender << endl;
    cout << "Home Address: " << coutS(r->homeaddress) << endl;
    cout << "Phone: " << r->phone << endl;
    cout << "Education : " << coutS(r->education) << endl;
    cout << "Languages: " << coutS(r->languages) << endl;
    cout << "Certification: " << coutS(r->certification) << endl;
    cout << "Joined Day: " << r->joined.year << "/" << r->joined.month << "/" << r->joined.day << endl;
}

void printTechnicalStaff(TechnicalStaff* t) {
    cout << "Name: " << coutS(t->name) << endl;
    cout << "Birthday: " << t->birthDate.year << "/" << t->birthDate.month << "/" << t->birthDate.day << endl;
    cout << "Gender: " << t->gender << endl;
    cout << "Home Address: " << coutS(t->homeaddress) << endl;
    cout << "Phone: " << t->phone << endl;
    cout << "Education : " << coutS(t->education) << endl;
    cout << "Languages: " << coutS(t->languages) << endl;
    cout << "Certification: " << coutS(t->certification) << endl;
    cout << "Joined Day: " << t->joined.year << "/" << t->joined.month << "/" << t->joined.day << endl;
}

struct bimary {
    string sick;
    int count = 1;
    double persentage1;
    int persentage2;
};


int main() {
    LoadPatient();
    LoadDoctor();
    LoadSurgon();
    LoadNurse();
    LoadReceptionist();
    LoadTechnicalStaff();
    int d;
    while (1) {
        cout << "***********************************************************************************************************" << endl;
        cout << "1 :Add Patient." << endl;
        cout << "2 :Add Doctor." << endl;
        cout << "3 :Add Surgeon." << endl;
        cout << "4 :Add Nurse." << endl;
        cout << "5 :Add Receptionist." << endl;
        cout << "6 :Add Technician." << endl;
        cout << "7 :Add SurgicalTechnologist." << endl;
        cout << "8 :Delete Patient." << endl;
        cout << "9 :Delete Doctor." << endl;
        cout << "10 :Delete Surgeon." << endl;
        cout << "11 :Delete Nurse." << endl;
        cout << "12 :Delete Receptionist." << endl;
        cout << "13 :Delete Technician." << endl;
        cout << "14 :Delete SurgicalTechnologist." << endl;
        cout << "15 :Find Patient By Fullname." << endl;
        cout << "16 :Find Doctor By Fullname." << endl;
        cout << "17 :Find Surgeon By Fullname." << endl;
        cout << "18 :Find Nurse By Fullname." << endl;
        cout << "19 :Find Receptionist By Fullname." << endl;
        cout << "20 :Find Technician By Fullname." << endl;
        cout << "21 :Find SurgicalTechnologist By Fullname." << endl;
        cout << "22 :Find All Technical Staffs Who Have Been Sick Before A Specific Date." << endl;
        cout << "23 :Find All Doctors Who Are Also Patient." << endl;
        cout << "24 :Find All Surgeons." << endl;
        cout << "25 :Find All Nurses Who Are Also Patient." << endl;
        cout << "26 :Find All Patients Who Have Been Sick In Two Specific Dates." << endl;
        cout << "27 :Graph Of All Deases Type And Percentage Of Each Desease." << endl;
        cout << "28 :Getting Percentage Of People Infected By A Specific Desease." << endl;
        cout << "29 :Getting Percentage Of Doctors Infected By A Specific Desease." << endl;
        cout << "30 :Exit." << endl;
        cin >> d;
        if (d == 1) {
            Patient* p = AddPatient();
            bimar.push_back(p);
            ofstream PFile("PATIENT.txt", ios::app);
            if (!PFile) {
                cout << "cannot open the file!";
            }
            else {
                PFile << p->name << "$" << p->birthDate.year << "/" << p->birthDate.month << "/" << p->birthDate.day << "$" << p->age << "$" << p->gender << "$" << p->homeaddress << "$" << p->phone << "$" << p->accepted.year << "/" << p->accepted.month << "/" << p->accepted.day << "$" << p->sickness << "$" << p->allergies << "$" << p->specialreqs << "$" << p->prescriptions << "$" << p->id << "$" << endl;
                PFile.close();
            }
        }
        else if (d == 2) {
            Doctor* d = AddDoctor();
            doctor.push_back(d);
            ofstream DFile("DOCTOR.txt", ios::app);
            if (!DFile) {
                cout << "cannot open the file!";
            }
            else {
                DFile << d->name << "$" << d->birthDate.year << "/" << d->birthDate.month << "/" << d->birthDate.day << "$" << d->specialty << "$" << d->gender << "$" << d->homeaddress << "$" << d->phone << "$" << d->joined.year << "/" << d->joined.month << "/" << d->joined.day << "$" << d->education << "$" << d->certification << "$" << d->languages << "$" << d->locations << "$" << endl;
                DFile.close();
            }
        }
        else if (d == 3) {
            Surgeon* s = Addsurgeon();
            jarah.push_back(s);
            ofstream SFile("SURGON.txt", ios::app);
            if (!SFile) {
                cout << "cannot open the file!";
            }
            else {
                SFile << s->name << "$" << s->birthDate.year << "/" << s->birthDate.month << "/" << s->birthDate.day << "$" << s->specialty << "$" << s->gender << "$" << s->homeaddress << "$" << s->phone << "$" << s->joined.year << "/" << s->joined.month << "/" << s->joined.day << "$" << s->education << "$" << s->certification << "$" << s->languages << "$" << s->locations << "$" << endl;
                SFile.close();
            }
        }
        else if (d == 4) {
            Nurse* n = Addnurse();
            parastar.push_back(n);
            ofstream NFile("NURSE.txt", ios::app);
            if (!NFile) {
                cout << "cannot open the file!";
            }
            else {
                NFile << n->name << "$" << n->birthDate.year << "/" << n->birthDate.month << "/" << n->birthDate.day << "$" << n->gender << "$" << n->homeaddress << "$" << n->phone << "$" << n->joined.year << "/" << n->joined.month << "/" << n->joined.day << "$" << n->education << "$" << n->certification << "$" << n->languages << "$" << endl;
                NFile.close();
            }
        }
        else if (d == 5) {
            Receptionist* r = Addreceptionist();
            paziresh.push_back(r);
            ofstream NFile("RECEPTIONIST.txt", ios::app);
            if (!NFile) {
                cout << "cannot open the file!";
            }
            else {
                NFile << r->name << "$" << r->birthDate.year << "/" << r->birthDate.month << "/" << r->birthDate.day << "$" << r->gender << "$" << r->homeaddress << "$" << r->phone << "$" << r->joined.year << "/" << r->joined.month << "/" << r->joined.day << "$" << r->education << "$" << r->certification << "$" << r->languages << "$" << endl;
                NFile.close();
            }
        }
        else if (d == 6 || d == 7) {
            TechnicalStaff* t = AddTechnicalStaff();
            TStaff.push_back(t);
            ofstream TFile("TECHNICAL.txt", ios::app);
            if (!TFile) {
                cout << "cannot open the file!";
            }
            else {
                TFile << t->name << "$" << t->birthDate.year << "/" << t->birthDate.month << "/" << t->birthDate.day << "$" << t->gender << "$" << t->homeaddress << "$" << t->phone << "$" << t->joined.year << "/" << t->joined.month << "/" << t->joined.day << "$" << t->education << "$" << t->certification << "$" << t->languages << "$" << endl;
                TFile.close();
            }
        }
        else if (d == 8) {
            cout << "Please Enter The Patient's Full Name You Want To Delete: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchP(bimar, n);
            if (index == -1) cout << "not found" << endl;
            else {
                bimar.erase(bimar.begin() + index);
                ofstream PFile("PATIENT.txt", ios::out);
                if (!PFile) {
                    cout << "cannot open the file!";
                }
                else {
                    for (int i = 0; i < bimar.size(); i++) {
                        PFile << bimar[i]->name << "$" << bimar[i]->birthDate.year << "/" << bimar[i]->birthDate.month << "/" << bimar[i]->birthDate.day << "$" << bimar[i]->age << "$" << bimar[i]->gender << "$" << bimar[i]->homeaddress << "$" << bimar[i]->phone << "$" << bimar[i]->accepted.year << "/" << bimar[i]->accepted.month << "/" << bimar[i]->accepted.day << "$" << bimar[i]->sickness << "$" << bimar[i]->allergies << "$" << bimar[i]->specialreqs << "$" << bimar[i]->prescriptions << "$" << bimar[i]->id << "$" << endl;
                    }
                    PFile.close();
                    cout << "Removed successfully" << endl;
                }
            }
        }
        else if (d == 9) {
            cout << "Please Enter The Doctor's Full Name You Want To Delete: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchD(doctor, n);
            if (index == -1) cout << "not found" << endl;
            else {
                doctor.erase(doctor.begin() + index);
                ofstream DFile("DOCTOR.txt", ios::out);
                if (!DFile) {
                    cout << "cannot open the file!";
                }
                else {
                    for (int i = 0; i < doctor.size(); i++) {
                        DFile << doctor[i]->name << "$" << doctor[i]->birthDate.year << "/" << doctor[i]->birthDate.month << "/" << doctor[i]->birthDate.day << "$" << doctor[i]->specialty << "$" << doctor[i]->gender << "$" << doctor[i]->homeaddress << "$" << doctor[i]->phone << "$" << doctor[i]->joined.year << "/" << doctor[i]->joined.month << "/" << doctor[i]->joined.day << "$" << doctor[i]->education << "$" << doctor[i]->certification << "$" << doctor[i]->languages << "$" << doctor[i]->locations << "$" << endl;
                    }
                    DFile.close();
                    cout << "Removed successfully" << endl;
                }
            }
        }
        else if (d == 10) {
            cout << "Please Enter The Surgon's Full Name You Want To Delete: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchS(jarah, n);
            if (index == -1) cout << "not found" << endl;
            else {
                jarah.erase(jarah.begin() + index);
                ofstream SFile("SURGON.txt", ios::out);
                if (!SFile) {
                    cout << "cannot open the file!";
                }
                else {
                    for (int i = 0; i < jarah.size(); i++) {
                        SFile << jarah[i]->name << "$" << jarah[i]->birthDate.year << "/" << jarah[i]->birthDate.month << "/" << jarah[i]->birthDate.day << "$" << jarah[i]->specialty << "$" << jarah[i]->gender << "$" << jarah[i]->homeaddress << "$" << jarah[i]->phone << "$" << jarah[i]->joined.year << "/" << jarah[i]->joined.month << "/" << jarah[i]->joined.day << "$" << jarah[i]->education << "$" << jarah[i]->certification << "$" << jarah[i]->languages << "$" << jarah[i]->locations << "$" << endl;
                    }
                    SFile.close();
                    cout << "Removed successfully" << endl;
                }
            }
        }
        else if (d == 11) {
            cout << "Please Enter The Nurse's Full Name You Want To Delete: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchN(parastar, n);
            if (index == -1) cout << "not found" << endl;
            else {
                parastar.erase(parastar.begin() + index);
                ofstream NFile("NURSE.txt", ios::out);
                if (!NFile) {
                    cout << "cannot open the file!";
                }
                else {
                    for (int i = 0; i < parastar.size(); i++) {
                        NFile << parastar[i]->name << "$" << parastar[i]->birthDate.year << "/" << parastar[i]->birthDate.month << "/" << parastar[i]->birthDate.day << "$" << parastar[i]->gender << "$" << parastar[i]->homeaddress << "$" << parastar[i]->phone << "$" << parastar[i]->joined.year << "/" << parastar[i]->joined.month << "/" << parastar[i]->joined.day << "$" << parastar[i]->education << "$" << parastar[i]->certification << "$" << parastar[i]->languages << "$" << endl;
                    }
                    NFile.close();
                    cout << "Removed successfully" << endl;
                }
            }
        }
        else if (d == 12) {
            cout << "Please Enter The Receptionist's Full Name You Want To Delete: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchR(paziresh, n);
            if (index == -1) cout << "not found" << endl;
            else {
                paziresh.erase(paziresh.begin() + index);
                ofstream NFile("RECEPTIONIST.txt", ios::out);
                if (!NFile) {
                    cout << "cannot open the file!";
                }
                else {
                    for (int i = 0; i < paziresh.size(); i++) {
                        NFile << paziresh[i]->name << "$" << paziresh[i]->birthDate.year << "/" << paziresh[i]->birthDate.month << "/" << paziresh[i]->birthDate.day << "$" << paziresh[i]->gender << "$" << paziresh[i]->homeaddress << "$" << paziresh[i]->phone << "$" << paziresh[i]->joined.year << "/" << paziresh[i]->joined.month << "/" << paziresh[i]->joined.day << "$" << paziresh[i]->education << "$" << paziresh[i]->certification << "$" << paziresh[i]->languages << "$" << endl;
                    }
                    NFile.close();
                    cout << "Removed successfully" << endl;
                }
            }
        }
        else if (d == 13 || d == 14) {
            cout << "Please Enter The Technician's/SurgicalTechnologist's Full Name You Want To Delete: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchT(TStaff, n);
            if (index == -1) cout << "not found" << endl;
            else {
                TStaff.erase(TStaff.begin() + index);
                ofstream TFile("TECHNICAL.txt", ios::out);
                if (!TFile) {
                    cout << "cannot open the file!";
                }
                else {
                    for (int i = 0; i < TStaff.size(); i++) {
                        TFile << TStaff[i]->name << "$" << TStaff[i]->birthDate.year << "/" << TStaff[i]->birthDate.month << "/" << TStaff[i]->birthDate.day << "$" << TStaff[i]->gender << "$" << TStaff[i]->homeaddress << "$" << TStaff[i]->phone << "$" << TStaff[i]->joined.year << "/" << TStaff[i]->joined.month << "/" << TStaff[i]->joined.day << "$" << TStaff[i]->education << "$" << TStaff[i]->certification << "$" << TStaff[i]->languages << "$" << endl;
                    }
                    TFile.close();
                    cout << "Removed successfully" << endl;
                }
            }
        }
        else if (d == 15) {
            cout << "Please Enter Patient's Name: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchP(bimar, n);
            if (index == -1) cout << "not found" << endl;
            else {
                printPatient(bimar[index]);
                cout << endl;
            }
        }
        else if (d == 16) {
            cout << "Please Enter Doctor's Name: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchD(doctor, n);
            if (index == -1) cout << "not found" << endl;
            else {
                printDoctor(doctor[index]);
                cout << endl;
            }
        }
        else if (d == 17) {
            cout << "Please Enter Surgon's Name: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchS(jarah, n);
            if (index == -1) cout << "not found" << endl;
            else {
                printSurgeon(jarah[index]);
                cout << endl;
            }
        }
        else if (d == 18) {
            cout << "Please Enter Nurse's Name: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchN(parastar, n);
            if (index == -1) cout << "not found" << endl;
            else {
                printNurse(parastar[index]);
                cout << endl;
            }
        }
        else if (d == 19) {
            cout << "Please Enter Receptionist's Name: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchR(paziresh, n);
            if (index == -1) cout << "not found" << endl;
            else {
                printReceptionist(paziresh[index]);
                cout << endl;
            }
        }
        else if (d == 20 || d == 21) {
            cout << "Please Enter Technician's/SurgicalTechnologist's Name: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int index = searchT(TStaff, n);
            if (index == -1) cout << "not found" << endl;
            else {
                printTechnicalStaff(TStaff[index]);
                cout << endl;
            }
        }
        else if (d == 22) {
            cout << "Please Enter Date: year: ";
            int y;
            cin >> y;
            cout << "Month: ";
            int m;
            cin >> m;
            cout << "Day: ";
            int d;
            cin >> d;
            for (int i = 0; i < TStaff.size(); i++) {
                int index = searchP(bimar, TStaff[i]->name);
                if (index >= 0) {
                    Date dt;
                    dt.year = y;
                    dt.month = m;
                    dt.day = d;
                    if (difference(dt, bimar[index]->accepted) >= 0) {
                        cout << coutS(bimar[index]->name) << endl;
                    }
                }
            }
        }
        else if (d == 23) {
            for (int i = 0; i < doctor.size(); i++) {
                int index = searchP(bimar, doctor[i]->name);
                if (index >= 0) {
                    cout << coutS(bimar[index]->name) << endl;
                }
            }
        }
        else if (d == 24) {
        for (int i = 0; i < jarah.size(); i++)
            cout << coutS(jarah[i]->name) << endl;
        }
        else if (d == 25) {
            for (int i = 0; i < parastar.size(); i++) {
                int index = searchP(bimar, parastar[i]->name);
                if (index >= 0) {
                    cout << coutS(bimar[index]->name) << endl;
                }
            }
        }
        else if (d == 26) {
            cout << "Please Enter Date 1: year: ";
            int y1;
            cin >> y1;
            cout << "Month: ";
            int m1;
            cin >> m1;
            cout << "Day: ";
            int d1;
            cin >> d1;
            cout << endl;
            cout << "Please Enter Date 2: year: ";
            int y2;
            cin >> y2;
            cout << "Month: ";
            int m2;
            cin >> m2;
            cout << "Day: ";
            int d2;
            cin >> d2;
            cout << endl;
            Date dt1(d1, m1, y1);
            Date dt2(d2, m2, y2);
            for (int i = 0; i < bimar.size(); i++) {
                if (difference(bimar[i]->accepted, dt1) >= 0 && difference(dt2, bimar[i]->accepted) >= 0) {
                    cout << coutS(bimar[i]->name) << endl;
                }   
            }
        }
        else if (d == 27) {
            int j;
            vector<bimary*> b;
            for (int i = 0; i < bimar.size(); i++) {
                if (b.size() == 0) {
                    bimary* bi = new bimary;
                    bi->sick = coutS(bimar[i]->sickness);
                    b.push_back(bi);
                }
                else {
                    for (j = 0; j < b.size(); j++) {
                        if (b[j]->sick == bimar[i]->sickness) {
                            b[j]->count++;
                            break;
                        }
                    }
                    if (j == b.size()) {
                        bimary* bi = new bimary;
                        bi->sick = coutS(bimar[i]->sickness);
                        b.push_back(bi);
                    }
                }
            }
            int all = bimar.size();
            for (int k = 0; k < b.size(); k++) {
                double w = (double)b[k]->count / all;
                w *= 100;
                b[k]->persentage1 = w;
                double f = (double)b[k]->count / all;
                f = f * 10;
                b[k]->persentage2 = f;
            }
            ofstream CFile("CHAR.txt", ios::out);
            int highest = b[0]->persentage2;
            for (int check = 0; check < b.size(); check++) {
                if (b[check]->persentage2 > highest) highest = b[check]->persentage2;
            }
            for (int rows = highest; rows >= 1; rows--) {
                for (int cols = 0; cols < b.size(); cols++) {
                    if (b[cols]->persentage2 >= rows) {
                        cout << " * ";
                        CFile << " * ";
                    }
                    else {
                        cout << "   ";
                        CFile << "   ";
                    }
                }
                cout << endl;
                CFile << endl;
            }
            for (int cols = 0; cols < b.size(); cols++) {
                cout << "---";
                CFile << "---";
            }
            cout << endl;
            CFile << endl;
            for (int cols = 1; cols <= b.size(); cols++) {
                cout << " " << cols << " ";
                CFile << " " << cols << " ";
            }
            cout << endl;
            CFile << endl;
            for (int cols = 0; cols < b.size(); cols++) {
                cout << cols + 1 << " : " << b[cols]->sick << " = " << b[cols]->persentage1 << "%" << endl;
                CFile << cols + 1 << " : " << b[cols]->sick << " = " << b[cols]->persentage1 << "%" << endl;
            }
            CFile.close();
        }
        else if (d == 28) {
            cout << "Name Of Sickness: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int count = 0;
            for (int i = 0; i < bimar.size(); i++) {
                if (n == bimar[i]->sickness) count++;
            }
            double f = (double)count / bimar.size();
            f *= 100;
            double persentage = f;
            cout << "Persentage= " << persentage << "%" << endl;
        }
        else if (d == 29) {
            cout << "Name Of Sickness: ";
            string n;
            cin >> ws;
            getline(cin, n);
            size_t found = n.find_first_of(" ");
            while (found != string::npos) {
                n[found] = '%';
                found = n.find_first_of(" ", found + 1);
            }
            int count = 0;
            int count1 = 0;
            for (int i = 0; i < doctor.size(); i++) {
                int index = searchP(bimar, doctor[i]->name);
                if (index >= 0) {
                    count1++;
                    if (bimar[index]->sickness == n) {
                        count++;
                    }
                }
            }
            double f = (double)count / count1;
            f *= 100;
            double persentage = f;
            cout << "Persentage= " << persentage << "%" << endl;
        }
        else if (d == 30) break;
    }
}
