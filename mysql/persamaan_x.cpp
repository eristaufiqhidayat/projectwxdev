#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int a, b, c;
    float x1, x2, d;
    
    //mengambil masukan pengguna
    cout << "Masukkan nilai a : " ;
    cin >> a;
    cout << "Masukkan nilai b : " ;
    cin >> b;
    cout << "Masukkan nilai c : " ;
    cin >> c;
    
    //hitung nilai determinan
    d = b*b - (4*a*c);
    
if (d>0) {
    //menghitung nilai x1 dan x2
    x1 = (b + sqrt (d))/(2*a);
    x2 = (b - sqrt (d))/(2*a);
    
    //menampilkan nilai akar 
    cout  << "akar x1 = " << x1 << endl;
    cout  << "akar x2 = " << x2 << endl;
    
    }else if (d == 0){
        //menghitung nilai x1 dan x2
        x1 = b /(2*a);
        x2 = x1;
 
} else if (d == 0){      
    //menampilkan nilai akar kembar
    cout << "persamaan memiliki akar kembar" << endl;
    cout << "akar x1 = x2 = " << x1 << endl;
}
else {
    //menampilkan pesan akar imaginer 
    cout << "akar x1 adalah angka bilangan imaginer" << endl; 
    cout << "akar x2 adalah angka bilangan imaginer" << endl;
}
    
    system ("PAUSE");
    return 0;
}
