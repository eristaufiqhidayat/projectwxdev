#include <cstdlib>
#include <iostream>

using namespace std;

int fdx(int c1, int c2,int c3, int b1,int b2,int b3,int d1,int d2,int d3)
{
    int dx;
    dx = (d1*b2*c3)+(b1*c2*c3)+(c1*d2*b3)-(c1*b2*d3)-(b1*d2*c3);
    return dx;
}
int fdy(int c1, int c2, int a1,int a2)
{
    int dy;
    dy = (a1*c2)-(c1*a2);
    return dy;
}
int fd(int a1, int a2,int a3, int b1,int b2,int b3,int c1,int c2,int c3)
{
    int fd;
    fd = (a1*b2*c3)+(b1*c2*a3)+(c1*a2*b3)-(c1*b2*a3)-(a1*c2*b3)-(b1*a2*c3);
    return fd;
}
int main()
{
    int a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,d,dx,dy,dz,x,y,z;

    cout <<"Masukan Nilai a1 = "<<endl;
    cin >> a1;
    cout <<"Masukan Nilai a2 = "<<endl;
    cin >> a2;
    cout <<"Masukan Nilai a3 = "<<endl;
    cin >> a3;
    cout <<"Masukan Nilai b1 = "<<endl;
    cin >> b1;
    cout <<"Masukan Nilai b2 = "<<endl;
    cin >> b2;
    cout <<"Masukan Nilai b3 = "<<endl;
    cin >> b3;
    cout <<"Masukan Nilai c1 = "<<endl;
    cin >> c1;
    cout <<"Masukan Nilai c2 = "<<endl;
    cin >> c2;
    cout <<"Masukan Nilai c3 = "<<endl;
    cin >> d1;
        cout <<"Masukan Nilai d1 = "<<endl;
    cin >> d1;
        cout <<"Masukan Nilai d2 = "<<endl;
    cin >> d2;
        cout <<"Masukan Nilai d3 = "<<endl;
    cin >> d3;
    dx = fdx(c1,c2,c3,b1,b2,b3,d1,d2,d3);
    //dy = fdy(c1,c2,a1,a2);
    d= fd(a1,a2,a3,b1,b2,b3,c1,c2,c3);
    //x = dx/d;
    //y = dy/d;
    cout <<"dx = "<<dx<<endl;
    //cout <<"dy = "<<dy<<endl;
    cout <<"d = "<<d<<endl;
    //cout <<"x = "<<x<<endl;
    //cout <<"y = "<<y<<endl;
    system("PAUSE");
    return 0;
}
