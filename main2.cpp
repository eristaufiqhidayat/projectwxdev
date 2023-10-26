#include <cstdlib>
#include <iostream>

using namespace std;

int volumebalok(int panjang, int lebar, int tinggi)
{
    int volume;
    volume = panjang*lebar*tinggi;
    return volume;
}

int main()
{
    int panjang,lebar,tinggi;
    cout << "Masukan Panjang : ";
    cin >> panjang;
    cout << "Masukan lebar : ";
    cin >> lebar;
    cout << "Masukan Tinggi : ";
    cin >> tinggi;
    cout <<"Volume Balok : "<<volumebalok(panjang,lebar,tinggi)<<endl;
    system("PAUSE");
    return 0;
}
