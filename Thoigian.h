#include <iostream>
using namespace std;
class Date{
    int day,month,year;
	static bool  kiemtranamnhuan(int y);	
	static int dayinmonth(int month,int year);
	void chuanhoangay();
    public:
    	Date(int ngay=1,int thang=1,int nam=2000);
		friend istream& operator >>(istream &in,Date &d);
		friend ostream& operator <<(ostream &out,const Date &d);
        Date &operator++();
        Date &operator--();
};
class Time{
    protected:
    int second,minute,hour;
   void chuanhoathoi();
   public:
   Time(int s,int m,int h);
   Time();
  friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
   Time &operator ++();
   Time &operator --();


};
class DateTime : public Date, public Time {
public:
    DateTime(int d=1, int m=1, int y=2000, int h=0, int mi=0, int s=0);
    friend istream& operator>>(istream& in, DateTime& dt);
    friend ostream& operator<<(ostream& out, const DateTime& dt);
    DateTime& operator++();  // tăng 1 giây
    DateTime& operator--();  // giảm 1 giây
};