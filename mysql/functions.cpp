#include <cstdlib>
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;



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
           cout <<row<<endl; 
        }
        mysql_close(obj);
    }
}

