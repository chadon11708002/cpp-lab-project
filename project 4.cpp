#include<iostream>

#include<string>
#include<algorithm>

using namespace std;

class ProblemSet
{
    public:
    string problem, solution;
    ProblemSet(){}
    ProblemSet(string a, string b)
    {
        problem  = a;
        solution = b;
    }
    void show();

};
void ProblemSet:: show()
    {

        cout<<"Problem       : "<<problem<<endl;
        cout<<"Solution      : "<<solution<<endl;
        cout<<endl;
        cout<<endl;
    }
class Person
{
public:
    string name, dob;
    void getdata(string a, string b)
    {
        name = a;
        dob = b;
    }
    void putdata();
};
void Person :: putdata()
    {
        cout<<"Name          : "<<name<<endl;
        cout<<"Date of birth : "<<dob<<endl;
    }

class Student : public Person
{
public:
    string ID;
    int solved = 0;
    ProblemSet prblmst;
    bool finalist = 0;
    void setInfo(string a,string b, string c, int d, bool f )
    {
        getdata(a,b);
        ID = c;
        solved = d;
        finalist = f;
    }
    void putInfo()
    {
        putdata();
        cout<<"ID            : "<<ID<<endl;
        cout<<"solved        : "<<solved<<endl;
        prblmst.show();
    }
    int getsolved()
    {
        return solved;
    }
    void setProblem(ProblemSet s)
    {
        prblmst = s;
    }
    bool ifFinal()
    {
        return finalist;
    }
    bool operator<(Student A)
    {
        return solved<A.solved;
    }
};

int main()
{
    Student st[5];
    st[0].setInfo("habib","22-9-1996", "1308019", 650, false);
    st[1].setInfo("joni","17-2-1995", "1308011", 440, false);
    st[2].setInfo("rabbi","10-12-1994", "1308034", 900, true);
    st[3].setInfo("Sumon","2-7-1996", "1308016", 400, false);
    st[4].setInfo("sonjoy","1-5-1994", "1308010", 200, false);
    st[0].setProblem(ProblemSet("Problem", "solution")) ;
    st[0].setProblem(ProblemSet("Problem2", "solution2")) ;
    st[0].setProblem(ProblemSet("Problem3", "solution3")) ;
    st[1].setProblem(ProblemSet("Problem4", "solution4")) ;
    st[1].setProblem(ProblemSet("Problem6", "solution6")) ;
    st[2].setProblem(ProblemSet("Problem7", "solution7")) ;
    st[2].setProblem(ProblemSet("Problem8", "solution8")) ;
    st[3].setProblem(ProblemSet("Problem9", "solution9")) ;
    st[4].setProblem(ProblemSet("Problem10", "solution10")) ;
    st[4].setProblem(ProblemSet("Problem11", "solution11")) ;
    int prbno[5] = {0}, n=0;
    Student ob[2];
    sort(st, st + 5);
    ///Select world finalist
    for(int i = 0; i < 5 && n < 2; i++)
    {
        if(st[i].ifFinal()==true)
        {
            ob[n++] = st[i];
        }
    }
    ///Select non-finalist
    for(int i = 0; i < 5 && n < 2; i++)
    {
        if(st[i].ifFinal()==false)
        {
            ob[n++] = st[i];
        }
    }
    ob[0].putInfo();
    ob[1].putInfo();
    return 0;
}
