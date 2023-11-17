#include <cstdlib>
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;

char HOST[]="localhost";
char USER[]="root";
char PASS[]="";
char DB[]="kasir";
MYSQL *obj;
MYSQL *conection;
MYSQL_RES *result;
MYSQL_ROW row;

using namespace std;

void tambahdata(){
    if(!(obj = mysql_init(0))){
         cout <<"error";   
    }else{
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,"INSERT INTO `pengguna` (`id`, `username`, `password`, `nama`, `role`) VALUES (NULL, '222', 'dd333d', 'ccc', '');");
        result = mysql_use_result(obj);
        mysql_close(obj);
    } 
}
void selectdata(){
    if(!(obj = mysql_init(0))){
         cout <<"error";   
    }else{
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,"select * from pengguna");
        result = mysql_use_result(obj);
        while(row = mysql_fetch_row(result)){
           cout <<row[2]<<endl;   
        }
        mysql_close(obj);
    }
}
int main()
{
    int tambah;  
    selectdata();
    cout << "Tambah Data ?";
    cin >>tambah;
    if(tambah == 1){
        tambahdata();
    }
    system("PAUSE");
}
