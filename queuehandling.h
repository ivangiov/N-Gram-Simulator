/*
Programmer : Dhanurangga Al Fadh (13218005)
Tester : Sarah Alyaa Tsaabitah (13218011)
Deskripsi Header : Berisi deklarasi fungsi untuk mengolah queue. Terdapat dua fungsi yaitu enqueue untuk menambah data dan dequeue untuk mengeluarkan data
*/


void enqueue(queue *Q, char *text);
//Fungsi untuk menambah data pada struktur data queue
//Input : pointer tipe data queue Q dan pointer char text
//Output : queue Q yang sudah terisi data baru yaitu text

void dequeue(queue *Q);
//Fungsi untuk mengeluarkan satu buah data pada bagian front queue
//Input : pointer queue Q
//Output : queue Q yang data pada front telah dihapus