#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//实现一个音乐解释器

class playContent
{
private:
    string text;
public:
    playContent(string text){
        this->text = text;
    }
    ~playContent(){}
    string getText(){
        return text;
    }
    void setText(string text){
        this->text = text;
    }
};

class Expression
{
private:
    /* data */
public:
    Expression(/* args */){}
    virtual ~Expression(){}
    void interpret(playContent* music){
        if(music->getText().length() <= 2){
            return ;
        }

        string music_string = music->getText();
        string playkey = music_string.substr(0,1); //从0开始，拷贝一个字符
        int palyvalue = atoi(music_string.substr(2,1).c_str());

        //music_string = music_string.substr(4);

        Execute(playkey,palyvalue);
    }

    virtual void Execute(string playkey, int palyvalue) = 0;
};


//解析音符类
class terminalExpression : public Expression
{
private:
    /* data */
public:
    terminalExpression(/* args */){}
    virtual ~terminalExpression(){}

    void Execute(string playkey, int palyvalue){
        int note = 0;
        char temp = playkey[0];
        switch (temp)
        {
        case 'C':
            note = 1;
            break;
        case 'D':
            note = 2;
            break;
        case 'E':
            note = 3;
            break;
        case 'F':
            note = 4;
            break;
        case 'G':
            note = 5;
            break;
        
        default:
            break;
        }

        cout<<note<<" ";
    }
};

class Scale : public Expression
{
private:
    /* data */
public:
    Scale(/* args */){}
    virtual ~Scale(){}

    void Execute(string playkey, int palyvalue){
        string proprity;
        switch ((int)palyvalue)
        {
        case 1:
            proprity = "低音";
            break;
        case 2:
            proprity = "中音";
            break;
        case 3:
            proprity = "高音";
            break;
        
        default:
            break;
        }

        cout<<proprity<<" ";
    }
};





int main()
{
    string music = "O 2 E 0.5 G 0.5 A 3 E 0.5 D 3";
    playContent* palyC = new playContent(music);

    //这里使用了自己做的HASH函数，方便快捷，但不够安全
    


    Expression* exp = nullptr;

    while(palyC->getText().length() > 0 ){
        string str = palyC->getText();
        char temp = str[0];
        switch (temp)
        {
        case 'O':
            exp = new Scale();
            break;
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
            exp = new terminalExpression();
            break;       
        default:
            break;
        }

        exp->interpret(palyC);
        string temp2 = palyC->getText();
        if(temp2.length()>3){
            temp2.erase(0,2);
        }else{
            break;
        }
        palyC->setText(temp2);
    }



    return 0;
}