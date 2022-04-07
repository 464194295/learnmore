#include <iostream>
#include <unordered_map>

using namespace std;
class User{
    public:
        User(string inname):name(inname){}
        string getString(){
            return name;
        }
    private:
        string name;
};

class website
{
//抽象类，用于网站使用方法的传递
public:
    website(/* args */){}
    ~website(){}
    virtual void Userpeople(User *us) = 0;
};

class ConcreteWebsite : public website
{
private:
    string myname;
public:
    ConcreteWebsite(string inputname):myname(inputname){}
    ~ConcreteWebsite(){}
    void Userpeople(User *us){
        cout<<"网站分类"<<myname<<" 用户:"<<us->getString()<<endl;
    }
};

//网站工厂，得到所有网站的分类和数量
class webFactory
{
private:
    unordered_map<string, ConcreteWebsite*> store;
public:
    webFactory(){}
    ~webFactory(){}
    
    website* getwebtype(string key){
        if(store.find(key) == store.end()){
            store.insert(make_pair(key,new ConcreteWebsite(key)));
        }
        return store[key];
    }

    int getwebcount(){
        return store.size();
    }
};



int main()
{
    string input = "张三";
    User my(input);

    webFactory* fac = new webFactory();

    website *f1 = fac->getwebtype("产品展示");
    User *xiaocai = new User("小菜");
    f1->Userpeople(xiaocai); 

    website *f2 = fac->getwebtype("产品展示");
    User *xiaohua = new User("小华");
    f2->Userpeople(xiaohua); 

    website *f3 = fac->getwebtype("博客");
    User *xiaolei = new User("小雷");
    f3->Userpeople(xiaolei); 

    website *f4 = fac->getwebtype("博客");
    User *xiaoye = new User("小叶");
    f4->Userpeople(xiaoye); 

    cout<<fac->getwebcount()<<endl;


    delete xiaocai;
    delete xiaohua;
    delete xiaolei;
    delete xiaoye;
    delete fac;
    

    return 0;
}

