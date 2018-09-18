#ifndef __boss_hpp__
#define __boss_hpp__
#include"menboss.hpp"
#include"../basic/fileprocess.hpp"

Queue<int> cBoss::strings_to_int(Queue<string> date)
{
    Queue<int>date_int;
    for(int i = 0;i<date.size();i++){
        date_int.push_back(stoi(date[i]));
    }
    return date_int;
}

void cBoss::readCalendar()
{
    sData data;
    sData package;
    data = reading("../main-dir/files/calendar.csv",1);
    string name;
    for(unsigned int i = 0;i<data.data.size();i++){
        name = data.data[i][0];
        package = cBoss::package(data.data[i],data);
        cout<<"package.date[0] = "<<package.date[0]<<endl;
        labors[name].getCalendar(package);
    }
}

sData cBoss::package(Queue<string>attr,sData data)
{
    sData pac;
    pac.data.enqueue(attr);
    pac.day_amount = data.day_amount;
    pac.date = data.date;
    pac.day = data.day;
    return pac;
}

void cBoss::readSchedule()
{
    sData data;
    sData package;
    data = reading("../main-dir/files/schedule.csv",2);
    string name;
    for(unsigned int i = 0;i<data.data.size(); i++){
        name = data.data[i][0];

        package = cBoss::package(data.data[i],data);

        labors[name].getSchedule(package);

        // package.data.clear();

    }
}
void cBoss::readNextCalendar()
{
    sData data;
    sData package;
    data = reading("../main-dir/files/next.csv",1);
    string name;
    for(unsigned int i = 0;i<data.data.size(); i++){
        name = data.data[i][0];
        package = cBoss::package(data.data[i],data);
        labors[name].getNextCalendar(package);
    }
}

void cBoss::readRule()
{
    Queue<Queue<string> > data;
    data = FileProcess("../main-dir/files/rule.csv");
    data.dequeue();
    string name;
    for (int i = 0; i < data.size(); i++)
    {
        name = data[i].dequeue();
        labors[name].getRule(data[i], name);
    }
}

sData cBoss::reading(const char *FileName,int num)
{
    Queue<Queue<string> > data;
    Queue<string> string_date;
    Queue<string> days;
    Queue<int> date;
    sData day_info;

    data = FileProcess(FileName);

    string_date = data.dequeue();
    days = data.dequeue();

    days.dequeue(num);
    string_date.dequeue(num);
    date = strings_to_int(string_date);

    day_info.data = data;
    day_info.date = date;
    day_info.day = days;
    day_info.day_amount = date.size();

    return day_info;
}

void cBoss::ReadFiles(){
    readRule();
    readSchedule();
    readCalendar();
    readNextCalendar();
}

#endif