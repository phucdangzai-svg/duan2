#ifndef MANHDAT_H
#define MANHDAT_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14159265358979323846;

class Manh_dat {
    string ten;
public:
    Manh_dat(const string &t) : ten(t){}
    virtual double Tinhchuvi() const = 0;
    virtual double Tinhdientich() const = 0;

    virtual void Inthongtin() const;
    virtual ~Manh_dat(){}
};

class Manh_dat_hinh_vuong : public Manh_dat{
    private:
        double canh;
    public:
        Manh_dat_hinh_vuong(double a);
        double Tinhchuvi() const override;
        double Tinhdientich() const override;
};

class Manh_dat_hinh_tam_giac_deu : public Manh_dat{
    private:
        double canh;
    public:
        Manh_dat_hinh_tam_giac_deu(double a);
        double Tinhchuvi() const override;
        double Tinhdientich() const override;
        void Inthongtin() const override;
};

class Manh_dat_hinh_tron : public Manh_dat{
    private:
        double ban_kinh;
    public:
        Manh_dat_hinh_tron(double r);
        double Tinhchuvi() const override;
        double Tinhdientich() const override;
};

#endif