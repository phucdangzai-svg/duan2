#include "Thoigian.h"
#include <iostream>
using namespace std;
 bool Date :: kiemtranamnhuan(int y){
		return (y%400==0) || (y%4==0 && y%100!=0);
	} 
	int Date:: dayinmonth(int month,int year){
		int mngay[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		if (month==2)
		return kiemtranamnhuan(year) ? 29:28;
		return mngay[month-1];
		
	}
	void  Date::  chuanhoangay() {
    while (day> dayinmonth(month, year)) {
        day -= dayinmonth(month, year);
        month++;
        if (month > 12) {  
            month= 1;
            year++;
        }
    }

    
    while (day <= 0) {
        month--;
        if (month < 1) {  
            month = 12;
            year--;
        }
        day += dayinmonth(month, year); 
    }
}

	

Date ::	Date(int day,int month,int year){
			this->day=day;
			this->month=month;
			this->year=year;
			
			chuanhoangay();
		}
 Date& Date::operator++(){
	this->day++;
	chuanhoangay();
	return *this;
	
}
Date& Date::operator--(){
	this->day--;
	 chuanhoangay();
	return *this;
	

  
}
 void Time::chuanhoathoi() {
    while (second >= 60) {
        second -= 60;
        minute++;
    }
    while (second < 0) {
        second += 60;
        minute--;
    }

    while (minute >= 60) {
        minute -= 60;
        hour++;
    }
    while (minute < 0) {
        minute += 60;
        hour--;
    }
    while (hour >= 24) {
        hour -= 24;
    }
    while (hour < 0) {
        hour += 24;
    }
}
Time:: Time() {
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
    chuanhoathoi();
}


istream& operator>>(istream& in, Time& t) {
    cout << "Nhap giay: "; in >> t.second;
    cout << "Nhap phut: "; in >> t.minute;
    cout << "Nhap gio: "; in >> t.hour;
    t.chuanhoathoi();
    return in;
}
ostream& operator<<(ostream& out, const Time& t) {
    out << (t.second < 10 ? "0" : "") << t.second << ":"
        << (t.minute < 10 ? "0" : "") << t.minute << ":"
        << (t.hour   < 10 ? "0" : "") << t.hour;
    return out;
}
Time& Time::operator++() {
    second++;
    chuanhoathoi();
    return *this;
}


Time& Time::operator--() {
    second--;
    chuanhoathoi();
    return *this;
}
DateTime::DateTime(int d,int m,int y,int h,int mi,int s)
    : Date(d,m,y), Time(h,mi,s) {}

istream& operator>>(istream& in, DateTime& dt) {
    in >> static_cast<Date&>(dt);
    in >> static_cast<Time&>(dt);
    return in;
}
ostream& operator<<(ostream& out, const DateTime& dt) {
    out << static_cast<const Date&>(dt) << " " << static_cast<const Time&>(dt);
    return out;
}
DateTime& DateTime::operator++() {
    ++second;
    if (second == 60) { second = 0; ++minute; }
    if (minute == 60) { minute = 0; ++hour; }
    if (hour == 24) { hour = 0; ++Date(*this); }
    return *this;
}
DateTime& DateTime::operator--() {
    --second;
    if (second < 0) { second = 59; --minute; }
    if (minute < 0) { minute = 59; --hour; }
    if (hour < 0) { hour = 23; --Date(*this); }
    return *this;
}