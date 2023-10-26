#include <cstdlib>
#include <iostream>
// test

using namespace std;
int luassegitiga(int x, int y);
int luassegiempat(int z);

int main()
{
    int x, y;
    cout << "Masukan Nilai x : ";
    cin >> x;
    cout << "Masukan Nilai y : ";
    cin >> y;
    cout << "luas segitiga = " << luassegitiga(x, y) << endl;
    cout << "luas segiempat = " << luassegiempat(x) << endl;
    cin.get();
    system("PAUSE");
    return 0;
}
int luassegitiga(int x, int y)
{
    int luas;
    // proses
    luas = x * y / 2;
    // output
    return luas;
}
int luassegiempat(int z)
{
    int luas;
    luas = z * z;
    return luas;
}
