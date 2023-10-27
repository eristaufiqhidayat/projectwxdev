### Bahan Ajar : Materi Matriks

### Kelas : 6

### Pengajar : Eris Taufiq H, ST, MT

Penggunaan Matriks
Ada beberapa cara untuk mencari solusi atau penyelesaian dari suatu sistem persamaan linear. Salah satu cara yang akan kita bahas di materi ini dikenal dengan Aturan Cramer atau Kaidah Cramer, diambil dari nama penemunya yakni Gabriel Cramer (1704–1752).

Aturan Cramer digunakan untuk menyelesaikan sistem persamaan linear dengan n persamaan dalam n variabel. Dasar metode ini adalah matriks dan determinan, sehingga kita perlu memahami kedua konsep tersebut terlebih dahulu untuk dapat menerapakan Aturan Cramer dalam mencari solusi suatu sistem persamaan linear.

Agar lebih jelas, kita akan menerapkan Aturan Cramer untuk menyelesaikan sistem persamaan linear dua variabel (SPLDV) dan sistem persamaan linear tiga variabel (SPLTV). Sekarang, perhatikanlah sistem persamaan linear dua variabel berikut.

#

<img src='image.png' width='200'>

#

Dengan menggunakan rumus aturan cramer, nilai x akan di peroleh seperti ini

#

<img src='image-1.png' width='200'>

#

Dan untuk nilai y akan di peroleh seperti ini

#

<img src='image-2.png' width='200'>

#

Contoh :

Selesaikan sistem persamaan linear dua variabel (SPLDV) berikut dengan menggunakan Aturan Cramer.

#

<img src='image-3.png' width='200'>

#

Pembahasan:

SPLDV dalam soal di atas dapat dinyatakan dalam bentuk matriks, yakni

#

<img src='image-5.png' width='400'>

#

Berdasarkan Aturan Cramer, kita peroleh hasil berikut.

#

<img src='image-6.png' width='200'>

#

Jadi, nilai x dan y yang memenuhi SPLDV di atas yaitu
x = −2 dan y = 3
.

Praktek :
1.Buatlah program menghitung determinan memakai wxdev

jawab :

```
#include <cstdlib>
#include <iostream>

using namespace std;

int fdx(int c1, int c2, int b1,int b2)
{
    int dx;
    dx = (c1*b2)-(c2*b1);
    return dx;
}
int fdy(int c1, int c2, int a1,int a2)
{
    int dy;
    dy = (a1*c2)-(c1*a2);
    return dy;
}
int fd(int a1, int a2, int b1,int b2)
{
    int d;
    d = (a1*b2)-(b1*a2);
    return d;
}
int main()
{
    int a1,a2,b1,b2,c1,c2,dx,dy,d,x,y;
    a1 = 2;
    a2 = 1;
    b1=-3;
    b2=2;
    c1=-13;
    c2=4;

    dx = fdx(c1,c2,b1,b2);
    dy = fdy(c1,c2,a1,a2);
    d= fd(a1,a2,b1,b2);
    x = dx/d;
    y = dy/d;

    cout <<"dx = "<<dx<<endl;
    cout <<"dy = "<<dy<<endl;
    cout <<"d = "<<d<<endl;
    cout <<"x = "<<x<<endl;
    cout <<"y = "<<y<<endl;
    system("PAUSE");
    return 0;
}
```
