#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class Man;
class Girl;
//观察者模式，男人女人
class Action
{
private:
    /* data */
public:
    Action(/* args */){}
    virtual ~Action(){}
    virtual void manConclusion(Man* man) = 0;
    virtual void girlConclusion(Girl* girl) = 0;
};

class Success : public Action
{
private:
    /* data */
    string str = "Success";
public:
    Success(/* args */){}
    virtual ~Success(){}
    virtual void manConclusion(Man* man);
    virtual void girlConclusion(Girl* girl);
};


class Fail : public Action
{
private:
    /* data */
    string str = "Fail";
public:
    Fail(/* args */){}
    virtual ~Fail(){}
    virtual void manConclusion(Man* man);

    virtual void girlConclusion(Girl* girl);
};


class Person
{
private:
    /* data */
public:
    Person(/* args */){}
    virtual ~Person(){}
    virtual void Accept(Action* act) = 0;
};

class Man : public Person
{
private:
    /* data */
    string str;
public:
    Man() = default;
    virtual ~Man(){}
    virtual void Accept(Action* act){
        act->manConclusion(this);
    }
    void setstring(string st){
        str = st;
    }
    string getstring(){
        return str;
    }
};

class Girl : public Person
{
private:
    /* data */
    string str;
public:
    Girl() = default;
    virtual ~Girl(){}
    virtual void Accept(Action* act){
        act->girlConclusion(this);
    }
    void setstring(string st){
        str = st;
    }
    string getstring(){
        return str;
    }
};

void Success::manConclusion(Man* man){
    man->setstring("man");
    cout<<man->getstring()<<" "<<this->str<<" have a good girl"<<endl;
}

void Success::girlConclusion(Girl* girl){
    girl->setstring("girl");
    cout<<girl->getstring()<<" "<<this->str<<" have a good man"<<endl;
}

void Fail::manConclusion(Man* man){
    man->setstring("man");
    cout<<man->getstring()<<" "<<this->str<<" have a good girl"<<endl;
}

void Fail::girlConclusion(Girl* girl){
    girl->setstring("girl");
    cout<<girl->getstring()<<" "<<this->str<<" have a good man"<<endl;
}

//需要一个对象状态的管理者
class ObjectStruct
{
private:
    /* data */
    list<Person*> ls;
public:
    ObjectStruct(/* args */){}
    ~ObjectStruct(){}

    void attach(Person* element){
        ls.push_back(element);
    }
    void detch(){
        ls.pop_back();
    }

    void Display(Action* act){
        for(auto te:ls){
            te->Accept(act);
        }
    }
};








int main()
{
    ObjectStruct* obj = new ObjectStruct();
    Man* ma = new Man();
    Girl* g = new Girl();
    obj->attach(ma);
    obj->attach(g);

    Success* succ = new Success();
    Fail* fa = new Fail();

    obj->Display(succ);
    obj->Display(fa);

    // vector<int> re(5,1);
    // for(auto i : re){
    //     cout<<i<<endl;
    // }

    return 0;
}