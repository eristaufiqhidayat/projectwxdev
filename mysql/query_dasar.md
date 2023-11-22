<div class="row">
<div class="col-md-12 cols">
<pre class="line-numbers code-dark"><code class="language-sql">create database detik;
show databases;
+--------------------+
| Database           |
+--------------------+
| detik              |
+--------------------+
6 rows in set (0.00 sec)</code></pre>
</div>
</div>
<div class="row">
<div class="col-md-12 cols">
</div>
</div>
</form>
</div>
</header>
<div class="side_daftar_isi hidden"></div>

<main class="main-content">
<section class="section" id="bg-aliceblue">

<div class="container-sm text-justify">
<p class="lead"><a href="https://net.detik.org/docs/mysql/mysql/perintah-perintah-dasar-mysql.html">Perintah dasar MySQL</a> lengkap untuk pemula yang ingin belajar MySQL. Perintah dasar MySQL sederhana dan sangat mudah dipahami, sehingga MySQL menjadi sistem database (DBMS) yang sangat populer digunakan dikalangan personal hingga perusahaan. Selain itu, MySQL banyak digunakan dikarenakan menggunakan lisensi GNU, dan perfomance cukup baik untuk menangani database dari ukuran kecil hingga database kelas perusahaan.</p>
<p class="lead">Jika dilihat dari kebutuhan hardware juga tidak terlalu extrim, MySQL bisa dijalankan pada spek komputer yang rendah sekalipun. Berdasarkan pengalaman penulis, komputer/laptop dengan RAM 128 MySQL sudah bisa digunakan, apalagi di zaman sekarang teknologi komputer sudah sangat maju pesat, mungkin spek komputer Anda sudah 10x lebih tinggi dari spek yang dibutuhkan MySQL. </p>
<p class="lead">Saat ini, MySQL salah satu DBMS yang menjadi pilihan para pelajar, pengembang perangkat lunak, kampus, hingga perusahaan.</p>
<p class="alert alert-info">Perintah dasar MySQL ini dijalankan di console MySQL, pada kasus ini login ke MySQL melalui terminal.</p>
<hr class="hr-dash my-7">
<h2 id="daftar_isi">7 Perintah dasar MySQL</h2>
<ul class="daftar_isi">
<li><a href="#database">Create Database</a></li>
<li><a href="#table">Create Table</a></li>
<li><a href="#insert">Insert</a></li>
<li><a href="#select">Select</a></li>
<li><a href="#update">Update</a></li>
<li><a href="#delete">Delete</a></li>
<li><a href="#procedure">Procedure</a></li>
</ul>
<hr class="hr-dash my-7">
<h2 id="database">Perintah MySQL Create Database</h2>
<p>Perintah dasar MySQL untuk membuat database.</p>
<pre class="line-numbers code-light"><code class="language-sql">create database detik;
</code></pre>
<p>Jika perintah suskses dijalankan maka akan muncul pesan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
</code></pre>
<p>Lihat database yang sudah dibuat dengan perintah berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">show databases;
</code></pre>
<p>Anda akan melihat nama-nama database yang ada di server MySQL, sesuai hak akses user Anda:</p>
<pre class="line-numbers code-light"><code class="language-sql">+--------------------+
| Database           |
+--------------------+
| detik              |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| platform           |
+--------------------+
6 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="table">Perintah MySQL Create Table</h2>
<p>Untuk membuat tabel pada database, Anda harus memilih/berada di database tersebut terlebih dahulu. Berikut perintah untuk berpindah database :</p>
<p>Perintah menggunakan database <mark>use nama_database</mark>, lihat contoh berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">use detik;
</code></pre>
<p>Berikut kita akan membuat tabel dengan nama <mark>Pengguna</mark> dan dua field <mark>PenggunaId,PenggunaNama</mark>. Dalam sebuah tabel harus memiliki field kunci, dimana field kunci ini akan diisi dengan data unik dengan kata lain value nya tidak boleh sama. </p>
<p><strong>Mengapa harus ada field kunci?</strong></p>
<p>Karena field kunci digunakan untuk memastikan record data pada tabel tidak ada yang sama dalam artian lain setiap record data memiliki identitas unik/pembeda dari record data yang lain.</p>
<pre class="line-numbers code-light"><code class="language-sql">CREATE TABLE Pengguna (
PenggunaId INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
PenggunaNama VARCHAR(30) NOT NULL);
</code></pre>
<p>Jalankan perintah berikut untuk melihat tabel yang sudah dibuat pada database tersebut:</p>
<pre class="line-numbers code-light"><code class="language-sql">show tables;
</code></pre>
<p>Anda akan melihat hasil seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">+-----------------+
| Tables_in_detik |
+-----------------+
| Pengguna        |
+-----------------+
1 row in set (0.00 sec)
</code></pre>
<p>Untuk melihat struktur tabel dan field tabel yang Anda buat, jalankan perintah berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">describe Pengguna;
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">+--------------+-----------------+------+-----+---------+----------------+
| Field        | Type            | Null | Key | Default | Extra          |
+--------------+-----------------+------+-----+---------+----------------+
| PenggunaId   | int(6) unsigned | NO   | PRI | NULL    | auto_increment |
| PenggunaNama | varchar(30)     | NO   |     | NULL    |                |
+--------------+-----------------+------+-----+---------+----------------+
2 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="insert">Perintah MySQL Insert Data</h2>
<p>Database dan tabel sudah sukses kita buat, sekarang saat nya kita mencoba melakukan insert data ke tabel tersebut.</p>
<h5>Single data</h5>
<p>Untuk memasukan data ke tabel kita menggunakan perintah <mark>Insert Into</mark> dilanjutkan <mark>Nama Tabel</mark> selanjutnya <mark>Nama kolom</mark>, selanjutnya <mark>Nilai</mark>. Penrintah berikut artinya kita memasukan data ke tabel <mark>Pengguna</mark> dengan velue <mark>PenggunaId=1, PenggunaNama=Zaki</mark>. Urutan penulisan field/kolom dengan urutan Nilai/Value harus sesuai, tidak boleh terbalik.</p>
<pre class="line-numbers code-light"><code class="language-sql">insert into Pengguna (PenggunaId,PenggunaNama) values("1","Zaki");
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
</code></pre>
<p>Setiap tabel memiliki field kunci, dan pada field kunci tidak boleh ada nilai yang sama. Pada contoh ini kita menggunakan <mark>PenggunaId</mark> sebagai field kunci, maka value PenggunaId tidak boleh ada nilai yang sama. Contoh Nilai 1 sudah digunakan, maka untuk memasukan data baru, nilai 1 tidak boleh lagi digunakan/di masukan kedalam field kunci. Jika kita memasukan nilai yang sama maka database otomatis akan menolaknya.</p>
<h5>Multi data</h5>
<p>Berikut contoh insert data multi record, artinya dalam satu query kita bisa memasukan banyak record data.</p>
<pre class="line-numbers code-light"><code class="language-sql">insert into Pengguna (PenggunaId,PenggunaNama) values("2","Jhoni"),("3","Roni"),("4","Eka"),("5","Yono");
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 4 rows affected (0.00 sec)
Records: 4  Duplicates: 0  Warnings: 0
</code></pre>
<hr class="hr-dash my-7">
<h2 id="select">Perintah MySQL Select Data</h2>
<p>Sekarang kita melakukan select data dari tabel Pengguna,berikut contoh perintah select data</p>
<p>Perintah <mark>select *</mark> artinya menampilkan semua kolom dari tabel Pengguna:</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna;
</code></pre>
<p>Anda akan melihat hasil berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          1 | Zaki         |
|          2 | Jhoni        |
|          3 | Roni         |
|          4 | Eka          |
|          5 | Yono         |
+------------+--------------+
5 rows in set (0.00 sec)
</code></pre>
<p>Jika ingin menampilkan kolom tertentu saja maka ganti tanda (*) menjadi nama field. Lihat contoh berikut kita akan menampilkan kolom nama saja.</p>
<pre class="line-numbers code-light"><code class="language-sql">select PenggunaNama from Pengguna;
</code></pre>
<p>Hasil query akan terlihat seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">+--------------+
| PenggunaNama |
+--------------+
| Zaki         |
| Jhoni        |
| Roni         |
| Eka          |
| Yono         |
+--------------+
5 rows in set (0.00 sec)
</code></pre>
<p>Untuk menampilkan data tertentu/filter menggunkan <mark>where</mark>. Misal kita akan menampilkan informasi pengguna yang memiliki Id 2.</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna where PenggunaId=2;
</code></pre>
<p>Maka hasilnya akan terlihat seperti berikut. Pengguna yang memiliki Id 2 bernama Jhoni.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          2 | Jhoni        |
+------------+--------------+
1 row in set (0.00 sec)
</code></pre>
<p>Membatasi jumlah record data menggunakan <mark>limit</mark>, misal kita hanya ingin menampilkan jumlah data sebanyak 2 record saja.</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna limit 2;
</code></pre>
<p>Maka hasilnya akan terlihat seperti berikut. Data hanya ditampilkan sebanyak 2 record.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          1 | Zaki         |
|          2 | Jhoni        |
+------------+--------------+
2 rows in set (0.00 sec)
</code></pre>
<p>Mengurut data menggunakan perintah <mark>order by</mark>, Mengurutkan data ada 2 jenis <mark>asc=A-Z (kecil ke besar)</mark> dan <mark>desc = Z-A (besar ke kecil)</mark>. Misal kita mengurutkan data berdasarkan PenggunaId secara DESC.</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna order by PenggunaId DESC;
</code></pre>
<p>Maka hasilnya akan terlihat seperti berikut. Data diurutkan berdasarkan PenggunaId secara DESC.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          5 | Yono         |
|          4 | Eka          |
|          3 | Roni         |
|          2 | Jhoni        |
|          1 | Zaki         |
+------------+--------------+
5 rows in set (0.00 sec)
</code></pre>
<p>Silahkan Anda melakukan latihan dengan kasus-kasus lain, supaya lebih lancar dan mahir dalam menggunakan <a href="https://net.detik.org/docs/mysql/mysql/perintah-perintah-dasar-mysql.html">perintah-perintah dasar MySQL</a>.</p>
<hr class="hr-dash my-7">
<h2 id="update">Perintah MySQL Update Data</h2>
<p>Data yang sudah tersimpan suatu saat akan dibutuhkan perubahan/update data. Berikut perintah melakukan update data.</p>
<p>Misal kita akan melakukan update/perubahan nama pengguna dengan Id 2.</p>
<pre class="line-numbers code-light"><code class="language-sql">update Pengguna set PenggunaNama="Jnoni Doang" where PenggunaId=2
</code></pre>
<p>Anda akan melihat tampilan seperti berikut.</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0
</code></pre>
<p>Jika Anda lakukan select ke tabel Pengguna maka nama pengguna dengan Id=2 sudah berubah menjadi <mark>Jhoni Doang</mark>.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          1 | Zaki         |
|          2 | Jnoni Doang  |
|          3 | Roni         |
|          4 | Eka          |
|          5 | Yono         |
+------------+--------------+
5 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="delete">Perintah MySQL Delete Data</h2>
<p>Perintah hapus data sangat sederhana, oleh karena nya Anda harus berhati-hati sebelum melakukan hapus data, sebab data yang sudah terhapus tidak dapat dikembalikan.<p>
<p>Misal kita akan melakukan hapus data dengan Id 5.</p>
<pre class="line-numbers code-light"><code class="language-sql">delete from Pengguna where PenggunaId=5
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
</code></pre>
<p>Jika Anda lakukan select ke tabel Pengguna maka nama pengguna dengan Id=5 sudah hilang dari tabel pengguna.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          1 | Zaki         |
|          2 | Jnoni Doang  |
|          3 | Roni         |
|          4 | Eka          |
+------------+--------------+
4 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="procedure">Perintah MySQL Create Procedure</h2>
<p>Berikut adalah perintah untuk membuat procedur dengan nama <mark>Pro_SelectPengguna</mark>, isi procedure ini hanya melakukan query select pada tabel Pengguna .</p>
<pre class="line-numbers code-light"><code class="language-sql">DROP PROCEDURE `Pro_SelectPengguna`;
CREATE DEFINER=`root`@`localhost` PROCEDURE `Pro_SelectPengguna`() NOT DETERMINISTIC NO SQL SQL SECURITY DEFINER 
BEGIN
select * from Pengguna;
END
</code></pre>
<p>Berikut adalah perintah untuk menjalankan procedur.</p>
<pre class="line-numbers code-light"><code class="language-sql">CALL `Pro_SelectPengguna`();
</code></pre>
<hr class="hr-dash my-7">
<p>Demikian artikel tentang perintah-perintah dasar MySQL, silahkan dikembangkan lebih banyak kasus sesuai kebutuhan Anda.</p> </div>
</section>
</main>

<footer class="footer">
<div class="container">
<div class="row gap-y align-items-center">
<div class="col-md-9">
<div class="nav justify-content-center justify-content-md-start">
<a class="nav-link" href="/index">Home</a>
<a class="nav-link" href="/docs/">Dokumentasi</a>
<a class="nav-link" href="https://www.detik.org/laman/kebijakan.html" target="_blank">Kebijakan dan privasi</a>
<a class="nav-link" href="/contact">Hubungi</a>
<a class="nav-link" href="/faq">FAQ</a>
</div>
</div>
<div class="col-md-3 text-center text-md-right">
<a href="http://detik.org">© 2023 detik.org</a>
</div>
</div>
</div>
</footer>
<script async src="https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client=ca-pub-7837432819299975" crossorigin="anonymous" type="ef3b3ff7884258cb48b20ef9-text/javascript"></script>

<script src="https://net.detik.org/assets/js/page.min.js" type="ef3b3ff7884258cb48b20ef9-text/javascript"></script>
<script src="https://net.detik.org/assets/js/script.js" type="ef3b3ff7884258cb48b20ef9-text/javascript"></script>
<script src="https://apps.detik.org/assets/template/AdminLTE-2.4.3/bower_components/bootstrap-datepicker/dist/js/bootstrap-datepicker.min.js" type="ef3b3ff7884258cb48b20ef9-text/javascript"></script>

<div class="modal fade" id="modalPromo" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
<div class="modal-dialog" role="document">
<div class="modal-content">
<div class="modal-header">
<h5 class="modal-title" id="exampleModalLabel">Kuliah Online</h5>
<button type="button" class="close" data-dismiss="modal" aria-label="Close">
<span aria-hidden="true">&times;</span>
</button>
</div>
<div class="modal-body">
<h3>Kuliah Online GRATIS</h3>
<p>Ikuti kuliah online secara live streaming, info lengkap bisa lihat di <a target="_blank" href="https://online.sti.ac.id">online.sti.ac.id</a></p>
<p> </p>
</div>
