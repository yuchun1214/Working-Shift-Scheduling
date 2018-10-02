#ifndef __basicmenber_hpp__
#define __basicmenber_hpp__
#include"DataStructure.hpp"

class cDay
{
  public:
    string attribute;
    int date;
    string day;
    int month;
    void get(int dt, string str, string attr);
    void Show();
    void ShowDay();
};
void cDay::ShowDay(){
    printf("%d %s %s\n",date,day.c_str(),attribute.c_str());
}

void cDay::get(int dt,string str,string attr){
    /*
    Get the attribute of Day

    Prameter : 
    dt : date,
    str : day,
    attr : attribute
    */
    date = dt;
    day = str;
    attribute = attr;
    month = 0;
}

void cDay::Show(){
    cout<<"Day : "<<day<<endl;
    cout<<"Date : "<<date<<endl;
    cout<<"Attreibute : "<<attribute<<endl<<endl;
}

struct sData
{
    int day_amount;
    Queue<Queue<string> > data;
    Queue<int> date;
    Queue<string> day;
};

class Schedule{
    // basic data
private:
    int __amount;
    Queue<string> __names;
    Map<string,Queue<string> > __data;

    // return basic data
public:
    int amount();
    Queue<string> Names();
    Map<string,Queue<string> > data();
    void Record();
};

int Schedule::amount(){
    return __amount;
}

Queue<string> Schedule::Names(){
    return __names;
}

Map<string,Queue<string> > Schedule::data(){
    return __data;
}

#endif