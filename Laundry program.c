/*
	Proyek akhir semester 
  	Kelompok 10:
		1. Gilang Setyawan Yoga Pratama (2006577366)
		2. Valya Sandria Akiela (2006522650)
		3. Diva Hana Prilia (2006529543)
		4. Maulana Nurhendronoto (2006577542)
		
		PROGRAM LAUNDRY GDVM
*/

#include <stdio.h>		//library yang digunakan
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <omp.h>

struct data		//deklarasi data kiloan
{
	int diskon, harga, jenis, bayar, bon;
	float berat;
	char nama [30];
	struct data *next; 		//linked list
}*head = NULL, *tail, *baru, *cek, *temp;

struct ekstra 		//deklarasi Extra service
{	
	char namaCust[50] ;
	char alamat[50] ;
	char notelp[20] ;
	int bahan ; 	//pilihan laundry
	int beratLaundry ;
	int hargaSementara ;
	int ongkir ;
	int total ;
};

time_t local;		//menampilkan tanggal dan waktu akses program

int pilihan(int harga_kiloan[], struct ekstra *new);		//function prototype 
int tambah(int harga_kiloan[]);
int lihat(int harga_kiloan[], struct ekstra *new) ;
int hapus();
void laundryLain (int harga_kiloan[], struct ekstra *new) ;
int hitung(int harga_kiloan[], int pil, struct ekstra *new, int *j, int *s, int *k, int *b, int *t) ;
int lihatExtra (struct ekstra *new) ;


int main()			//main program
{					//pembuat Gilang Setyawan Yoga Pratama
	struct ekstra *new ;		//inisialisasi pointer struct
	new = (struct ekstra*)malloc(sizeof(struct ekstra));		//dynamic memory allocation untuk struct

	int harga_kiloan[3] = {0,5000,8000};		//array harga kiloan
	pilihan(harga_kiloan, new);		//function dengan parameter berupa array
}

int pilihan(int harga_kiloan[], struct ekstra *new)		//function untuk menampilkan menu dan memaanggil semua fungsi dalam program
{									//pembuat : Gilang Setyawan Yoga Pratama
	system("cls");
	time(&local);
	int a;
	printf("||=================================================================||\n");		//tampilan menu program
	printf("||==========                                             ==========||\n");
	printf("||===================     JASA LAUNDRY GDVM     ===================||\n");
	printf("||==========                                             ==========||\n");
	printf("||=================================================================||\n");
	printf("||                                                                 ||\n");
	printf("                 waktu : %s                       \n",ctime(&local));			//tammpilan waktu dan tanggal akses program
	printf("||=================================================================||\n");
	printf("||==========               MENU PILIHAN                  ==========||\n");
	printf("||               ===================================               ||\n");
	printf("||==========           1. TAMBAH DATA KILOAN             ==========||\n");
	printf("||==========           2. LIHAT DAN BAYAR KILOAN         ==========||\n");
	printf("||==========           3. HAPUS DATA KILOAN              ==========||\n");
	printf("||==========           4. EXTRA SERVICE                  ==========||\n");
	printf("||==========           5. HAPUS DATA EXTRA SERVICE       ==========||\n");  
	printf("||==========           6. KELUAR                         ==========||\n");
	printf("||=================================================================||\n");
	printf("\n Silahkan masukkan pilihan anda = ");		//input user memilih menu
	if(scanf("%d", &a)==1);
	else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
	system("cls");
	switch(a)		//switch case menu
	{
		case 1:
			tambah(harga_kiloan);		//call fungsi tambah kiloan
			break;
		case 2:
			lihat(harga_kiloan, new);		//call fungsi lihat data kiloan
			break;
		case 3:
			hapus();					//call fungsi hapus data kiloan
			break;
		case 4:
			laundryLain(harga_kiloan,new);		//call fungsi laundry extra atau laundry lain
			break;
		case 5:
			hapusExtra();				//call fungsi hapus data extra
			break;
		case 6:
			printf("||==========================================================================================||\n");		// end program
			printf("||==========                                                                      ==========||\n");
			printf("||===================     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI     ===================||\n");
			printf("||==========                                                                      ==========||\n");
			printf("||==========================================================================================||\n");
			exit(0);
			break;
	}
	return pilihan(harga_kiloan, new);		// jika user memilih menu selain angka 1-6
}

int tambah(int harga_kiloan[])			//function menambahkan data pelanggan laundry baju kiloan biasa
{										//pembuat : Maulana Nurhendronoto
	int i;
	float c;
	baru = (struct data*)malloc(sizeof(struct data));		//dinamic memory allocation 
	printf("||=================================================================||\n");	//tampilan pilihan jenis laundry kiloan
	printf("||==========               JENIS LAUNDRY                 ==========||\n");
	printf("||                ==================================               ||\n");
	printf("||==========    1. BIASA   (Rp 5.000/kg) - 3 hari        ==========||\n");
	printf("||==========    2. EXPRESS (Rp 8.000/kg) - 1 hari        ==========||\n");
	printf("||=================================================================||\n");
	printf("\n Silahkan masukkan pilihan anda = "); 		//user memilih jenis laundry
	if(scanf ("%d", &baru->jenis)==1);
	else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
	while (baru->jenis<1 || baru->jenis>2)
	{
		printf("Input salah\nSilahkan ulangi");		//error handling jika user memilih selain di 1 atau 2
		getch();
		system("cls");
		printf("||=================================================================||\n");	//tampilan pilihan jenis laundry kiloan
		printf("||==========               JENIS LAUNDRY                 ==========||\n");
		printf("||                ==================================               ||\n");
		printf("||==========    1. BIASA   (Rp 5.000/kg) - 3 hari        ==========||\n");
		printf("||==========    2. EXPRESS (Rp 8.000/kg) - 1 hari        ==========||\n");
		printf("||=================================================================||\n");
		printf("\n Silahkan masukkan pilihan anda = ");		//user memilih jenis laundry
		if(scanf ("%d", &baru->jenis)==1);
		else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
		
	}
	printf(" Nama pelanggan\t\t: ");		//input data pelanggan
	fflush(stdin);
	gets(baru->nama);
	printf(" Berat laundry (kg)\t: ");
	if(scanf("%f", &baru->berat)==1);
	else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
	
	if(baru->jenis == 1)		//menghitung harga sesuai pilihan pada menu 
	{
		baru->harga = harga_kiloan[1]*baru->berat;
	}
    else if(baru->jenis==2)
    {
        baru->harga=harga_kiloan[2]*baru->berat;
    }
    baru->diskon=0;
    c=0;

    for(i=2;i<=baru->berat;i=i+2)		//menghitung diskon
    {
        if(i<=50)				//diskon maksimal untuk input dibawah 50 kg
        {
            c=(0.03+(0.01*i));
            baru->diskon=baru->harga*c;
        }
    }

    printf(" Harga\t\t= Rp %d\n", baru->harga);		//print harga sesuai hitungan		
    printf(" Diskon (%.0f%c)\t= Rp %d\n", c*100,37,baru->diskon);	
    baru->harga=baru->harga-baru->diskon;
    printf(" Total\t\t= Rp %d\n", baru->harga);		//print harga setelah diskon
    bayar:
    printf("\n Jenis bayar\t: 1. Lunas\n");
    printf("\t\t  2. Bon (min DP 30%c)\n", 37);
    printf("\n Silahkan masukkan pilihan anda\t\t: ");	//user memilih jenis pembayaran
    if(scanf("%d", &baru->bayar)==1);
    else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
    
    switch (baru->bayar) 		//swith case pembayaran
	{
    	case 1:
    	    baru->bayar=baru->bon=0;	//untuk pilihan bayar lunas
            printf(" Transaksi berhasil\n Sudah dibayar lunas");
			printf("\n\npress any key to continue . . . .");	
		break;
		case 2:
	        bon:		//untuk pilihan bayar Bon
        	printf("\n Wajib DP min 30%c\t\t= Rp %0.f\n", 37, baru->harga*0.3);	//print DP minimal 30%
        	printf(" Masukkan uang anda\t\t= Rp ");			//user memasukan input uang pelanggan
        	if(scanf("%d", &baru->bayar)==1);
        	else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
        	
			if(baru->bayar < (baru->harga*0.3)) {
	        	printf(" Uang kurang\n Masukkan kembali");		//jika uang pelanggan kurang dari DP minimal
	        	getch();
	        	goto bon;
	    	} 	
			else {
            	if(baru->bayar>=baru->harga)
            	{	
                	printf(" Kembalian\t= Rp %d\n", (baru->bayar-baru->harga));	//kembalian uang pelanggan
                	printf(" Bayar lunas");
                	printf("\n\npress any key to continue . . . .");
                	baru->bayar=baru->harga=baru->bon=0;
            	}
            	else
            	{
                	baru->bon=baru->harga-baru->bayar;
                	printf("\n Transaksi berhasil\n Sisa bon\t\t\t= Rp %d", baru->bon);	// sisa Bon pelanggan
                	printf("\n\npress any key to continue . . . .");
            	}	
        	}
        break;
		default:
	    printf(" Input salah\n Silakan masukkan sesuai pilihan jenis bayar");	//error handling jika memasukkan selian 1 atau 2
        getch();
        goto bayar;	
		break;		
	}

    getch();

    if(head==NULL)		//data yang  diinput disimpan ke linked list
    {
        head=tail=baru;	//jika data masi kosong data baru akan menjadi data awal
    }
    else
    {
      tail->next=baru;	//jika sudah ada data data baru menjadi data selanjutnya
      tail=baru;
    }
    FILE *out=fopen("Data.txt", "a");		//file handling membuat data txt
    fprintf(out, " Nama pelanggan: %s\n Berat laundry: %f kg\n Jenis laundry (1=biasa, 2=express): %d\n Pembayaran(0=lunas): %d\n Sisa bon: Rp %d\n\n", baru->nama, baru->berat, baru->jenis, baru->bayar, baru->bon);
    fclose(out);
}

int lihat(int harga_kiloan[], struct ekstra *new) 	//fungsi display untuk data kiloan 
{													//pembuat Diva Hana dan Gilang Setyawan Yoga Pratama
	
	head=NULL;			
	fflush(stdin);
	FILE *in=fopen("Data.txt","r");		//file handling membuka data yang sudah dibuat di fungsi tambah
	if (!in)
  	{
		printf("||=================================================================||\n");		
		printf("||==========                                             ==========||\n");
		printf("||===================     DATA MASIH KOSONG     ===================||\n");		//jika data belum diisi
		printf("||==========                                             ==========||\n");
		printf("||=================================================================||\n");
		printf("\n\npress any key to continue . . . .");		 
		fclose(in);
		getch();
	}
	else 
	{
		while (!feof(in)) 
    	{
			fflush(stdin);
			baru = (struct data*)malloc(sizeof(struct data));		//dinamic memory allocation
			fscanf (in, " Nama pelanggan: %s\n Berat laundry: %f kg\n Jenis laundry (1=biasa, 2=express): %d\n Pembayaran(0=lunas): %d\n Sisa bon: Rp %d\n\n", &baru->nama, &baru->berat, &baru->jenis, &baru->bayar, &baru->bon);
			if (head==NULL) 	//mengambil data pelanggan dari linked list input dari fungsi tambah
      		{
				head=tail=baru;		//jika data masi kosong data baru akan menjadi data awal
			}
			else 
      		{
				tail->next=baru;	//jika sudah ada data data baru menjadi data selanjutnya
				tail=baru;
				tail->next=NULL;
			}
		}
		fclose(in);				//menutup file jika sudah selesai input dari linked list
		cek=head;
		int i = 1, a, b;
		printf ("\n\t\t\t DATA PELANGGAN LAUNDRY KILOAN\n\n");
		printf("||======================================================================================||");	
		printf ("\n||%-5s||%-20s||%-20s||%-10s||%-23s%-20s\n", " No.", " Nama", " Berat(Kg)","Jenis","Status","||");	//display data kiloan dengan tabel
		printf("||======================================================================================||\n");	
		
		while (cek!=tail->next)
		{
			printf("||%-5d||%-20s||%-20lf%",i, cek->nama, cek->berat);
			if (cek->jenis==1) 				//display jenis laundry kiloan
	    	{
				printf ("||%-10s", "Biasa");
			}
			else 
	    	{
				printf ("||%-10s", "Express");
			}
			
			if (cek->bayar == 0) 		//display jenis pembayaran	
	    	{
				printf ("||%-23s%-20s", "Lunas", "||");
			}
			else 
	    	{
				printf ("||Bon %d \t\t||" ,cek->bon );
			}
			printf ("\n");
			i++ ;
			cek=cek->next;
		}
		printf("||======================================================================================||");
		printf ("\n\n Menu pelunasan BON \n 1.Bayar\n");			//pilihan menu pelunasan bon
		printf (" 2.Kembali ke menu\n");
		printf ("\n Silahkan masukkan pilihan anda : ");		//user memilih menu
		if(scanf ("%d", &a)==1);
		else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
		
		switch (a) 	//switch case manu pelunasan
	  	{
			case 1 :
				printf (" Melunasi nomor : ");		//User ingin membayar tagihan salah satu pelanggan
				if(scanf ("%d", &a)==1);
				else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
				
				if(a)
				cek=head;
				
				#pragma omp parallel num_threads(1)		//inisiasi pararel for
				{
					#pragma omp for
					for (b = 1; b < a; b++) 		//mencari nomor pelanggan
		      		{
						cek=cek->next;
					}
				}
				kurang :
				system ("cls");
				printf ("\n\n Data pelanggan nomor %d :\n", a);		//menampilkan data pelanggan yang ingin melakukan pelunasan
				printf (" Nama\t\t= %s\n", cek->nama);
				printf (" Jenis\t\t= ");
				if (cek->jenis==1) 			//tampilan jenis
		     	{ 
		   			printf("Biasa\n");	
				}
				else if(cek->jenis==2)
				{
	    			printf("Express\n");
				}
				printf(" Berat\t\t= %.0f kg\n",cek->berat);	 //tampilan berat
				
				if(cek->bayar<=0)
				{
		    		printf(" Pelanggan atas nama %s sudah LUNAS",cek->nama);
					printf("\n\npress any key to continue . . . .");		//jika sudah melakukan pelunasan
				}
				else if(cek->bayar>0)
				{
		    		printf(" Bon\t\t= Rp %d\n",cek->bon);
		    		printf("\n Bayar (wajib lunas)\t= Rp ");
		    		if(scanf("%d",&b)==1);
		    		else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); return 0;}		//error handling jika user memasukkan huruf
		    		
		    		if(b<cek->bon)
					{
				        printf(" Maaf uang anda kurang \n Silahkan masukkan uang kembali sesuai sisa BON");			//error handling jika user memasukkan uang kurang dario sisan bon 
				        goto kurang;
		    		}
		    		else
					{
		        		printf(" Kembalian anda\t\t= Rp %d\n",b-cek->bon);		//menampilkan kembalian pelanggan
		        		printf(" Transaksi Berhasil!");
		        		printf("\n\npress any key to continue . . . .");
		        		cek->bayar=cek->bon=0;
		        		FILE *in=fopen("Data.txt","w");		//file handling update data dengan menulis jika ada perubahan data
		        		cek=head;
		        		
		        		while(cek!=tail->next)
						{
		            		fflush(stdin);
		            		fprintf(in," Nama pelanggan: %s\n Berat laundry: %f kg\n Jenis laundry (1=biasa, 2=express): %d\n Pembayaran(0=lunas): %d\n Sisa bon: Rp %d\n\n",cek->nama,cek->berat,cek->jenis,cek->bayar,cek->bon);
		            		cek=cek->next;		
		            	}
						fclose(in);		//menutup data txt
		    		}
				}
				break;
			case 2:
	    		return pilihan(harga_kiloan, new);	//kembali ke menu awal
	    		break;
			default:
		    printf("\n Input Salah\n Silahkan Ulangi!");		//error handling jika user memasukkan angka selain 1 dan 2
		    getch();
		    system("cls");
		    return lihat(harga_kiloan, new);		//kembali ke fungsi lihat 
		    break;
	    }
		getch();
    }
}

int hapus()		//function untuk menghapus file
{             //pembuat Maulana Nurhendronoto
    char a;
    FILE *in=fopen("Data.txt","r");		//membuka file
    if(!in)		//mengecek apabila file belum ada
    {
        printf("||=================================================================||\n");		
		printf("||==========                                             ==========||\n");
		printf("||===================     DATA MASIH KOSONG     ===================||\n");		//jika data belum diisi
		printf("||==========                                             ==========||\n");
		printf("||=================================================================||\n");
		printf("\n\npress any key to continue . . . .");
        getch();
    }
	else
    {
    	printf("||================================================================================||\n");		//konfirmasi untuk menghapus file
		printf("||==========          APAKAH ANDA YAKIN INGIN MENGHAPUS DATA ?          ==========||\n");
		printf("||               =================================================                ||\n");
		printf("||==========                    Masukkan Y / y untuk YA                 ==========||\n");
		printf("||==========                    Masukkan T / t untuk TIDAK              ==========||\n");
		printf("||================================================================================||\n");
		printf("\n Silahkan masukkan pilihan anda = ");
        fflush(stdin);
        a=getchar();		//input untuk menghapus/tidak menghapus
        if(a=='y' || a=='Y')
		{
            fclose(in);
            remove("Data.txt");		//menghapus file
            printf(" Data berhasil dihapus!");
            printf("\n\npress any key to continue . . . .");
        }
        else if(a=='t' || a=='T')
		{
            printf(" Data tidak jadi dihapus");
            printf("\n\npress any key to continue . . . .");
        }
		else
        {
			return hapus();
	        printf(" Input yang anda masukkan salah, silakan masukkan ulang");		//error handling
    	}
    }
	getch();
}

void laundryLain (int harga_kiloan[], struct ekstra *new) 		//function pilihan laundry selain pakaian biasa
{																//pembuat: Valya Sandria Akiela
	int pil ;				
	int jas = 20000 ;		//inisialisasi harga /kg
	int selimut = 22000 ;
	int karpet = 24000 ;
	int boneka = 15000 ;
	int tirai = 25000 ;
	
	printf("||======================================================================================||\n");	//tampilan pilihan jenis laundry selain kiloan
	printf("||==========                  PILIHAN LAUNDRY SELAIN KILOAN                   ==========||\n");
	printf("||                     ======== ====================================                    ||\n");
	printf("||==========    1. JAS / KEBAYA / BAHAN KHUSUS LAIN (Rp 20.000/kg) - 1 hari   ==========||\n");
	printf("||==========    2. SELIMUT / BED COVER              (Rp 22.000/kg) - 1 hari   ==========||\n");
	printf("||==========    3. KARPET                           (Rp 24.000/kg) - 1 hari   ==========||\n");
	printf("||==========    4. BONEKA / SEPATU                  (Rp 15.000/kg) - 1 hari   ==========||\n");
	printf("||==========    5. TIRAI / GORDEN                   (Rp 25.000/kg) - 1 hari   ==========||\n");
	printf("||======================================================================================||\n");
		
	printf ("\n Silahkan masukkan pilihan anda : ") ;
	if(scanf ("%d", &pil)==1);
	else{printf("\n Hanya boleh memasukkan angka, silahkan masukkan kembali\n\n"); exit(0);}		//error handling jika user memasukkan huruf
	
	hitung(harga_kiloan, pil, new, &jas, &selimut, &karpet, &boneka, &tirai) ;		//call function menghitung harga dengan parameter address
}

int hitung(int harga_kiloan[], int pil, struct ekstra *new, int *j, int *s, int *k, int *b, int *t)		//fungsi untuk menghitung harga laundry extra
{																										//pembuat: Valya Sandria Akiela
	new->hargaSementara = 0 ;		//inisiasi harga awal
	
	#pragma omp parallel num_threads(1)		//inisiasi parallel programming
	{
		#pragma omp critical		//menghindari race condition dan mempercepat perhitungan
		switch (pil) {		//menghitung harga laundry per kg
		case 1:
			printf (" Berat laundry: ") ;
			scanf ("%d", &new->beratLaundry) ;
			new->hargaSementara = *j * new->beratLaundry;	//penghitungan berat dikali harga barang yang dipilih 	
			break ;
		case 2:		
			printf (" Berat laundry: ") ;
			scanf ("%d", &new->beratLaundry) ;
			new->hargaSementara = *s * new->beratLaundry;
			break ;
		case 3:
			printf (" Berat laundry: ") ;
			scanf ("%d", &new->beratLaundry) ;
			new->hargaSementara = *k * new->beratLaundry;
			break ;
		case 4:
			printf (" Berat laundry: ") ;
			scanf ("%d", &new->beratLaundry) ;
			new->hargaSementara = *b * new->beratLaundry;
			break ;
		case 5:
			printf (" Berat laundry: ") ;
			scanf ("%d", &new->beratLaundry) ;
			new->hargaSementara = *t * new->beratLaundry;
			break ;
		default:
			printf(" Pilihan yang anda masukan salah");
			printf ("\n Silahkan pilih menu yang sesuai\n") ;		//error handling
			laundryLain (harga_kiloan,new) ;
			break ;
		}

		#pragma omp task
		jasaKirim (harga_kiloan, new) ;		//call function jasa kirim dengan parameter address struct	
	}
}

int jasaKirim (int harga_kiloan[],struct ekstra *new)		//fungsi menghitung ongkos kirim
{	                                                      //pembuat Valya Sandria Akiela dan Gilang Setyawan Yoga Pratama
	int back;
	
	printf ("\n Jasa Pengiriman Laundry\n") ;
	printf (" Kurang dari 10 kg GRATIS!\n") ;
	printf (" Lebih dari 10 kg : Rp2000/kg\n") ;
	
	new->total = 0 ;		//inisiasi harga awal
	#pragma omp parallel num_threads(1)		//inisiasi parallel programming
	{
		#pragma omp single		//menghindari race condition dan mempercepat perhitungan
		if (new->beratLaundry <= 10) {		//perhitungan ongkir jika berat < 10 kg
		new->ongkir = 0 ;
		}
		else {
		new->ongkir = 2000 * (new->beratLaundry-10) ;		//perhitungan ongkir jika berat > 10 kg
		}
		#pragma omp taskwait
		new->total = new->hargaSementara + new->ongkir ;	//menghitung total harga yang perlu dibayar customer
	}
	
	#pragma omp parallel num_threads(1)
	{
		printf ("\n Masukkan data pelanggan\n") ;		//memasukkan data pelanggan
		printf (" Nama : ") ;
		scanf (" %[^\n]s", &new->namaCust) ;
		printf (" Alamat : Jl. ") ;
		scanf (" %[^\n]s", &new->alamat) ;
		printf (" Nomor Telp : (+62)") ;
		scanf ("%s", &new->notelp) ;
		
		#pragma omp barrier
		lihatExtra(new);		//call fungsi untuk menampilkan nota 
	}
	
	FILE *out=fopen("DataEkstra.txt", "a");		//file handling untuk membuat file data extra
    fprintf(out, "\n Nama Pelanggan: %s\n Alamat Pelanggan: %d\n Nomor Telepon: (+62) %s\n Berat Laundry: %d kg\n TOTAL: Rp %d\n", new->namaCust, new->alamat, new->notelp, new->beratLaundry, new->total);		//print data pada file
    fclose(out);
	printf ("\n Tekan 1 untuk kembali ke menu atau selain 1 untuk keluar\n") ;
	scanf ("%d", &back) ;
	if (back == 1) {
		pilihan(harga_kiloan, new); //kembali ke menu awal
	}
	else{ //keluar program
		system("cls");
		#pragma omp parallel num_threads(1)		//inisiasi parallel programming (menampilkan terima kasih 1 thread)
		{
			system ("cls") ;
			printf("||==========================================================================================||\n");		// end program
			printf("||==========                                                                      ==========||\n");
			printf("||===================     TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI     ===================||\n");
			printf("||==========                                                                      ==========||\n");
			printf("||==========================================================================================||\n");
		}
		exit(0) ;
	}
	
}

int lihatExtra (struct ekstra *new) 		//function untuk menampilkan nota pembayaran
{                                       	//pembuat Diva Hana
	printf ("\n===========================================\n") ;	
	printf (" NOTA LAUNDRY\n") ;
	printf (" Nama : %s\n", new->namaCust) ;
	printf (" Alamat : Jl. %s\n", new->alamat) ;
	printf (" Nomor telepon : (+62)%s\n",new->notelp) ;
	printf (" Berat laundry : %d kg\n", new->beratLaundry) ;
	printf (" Tarif laundry : Rp%d\n", new->hargaSementara) ;
	printf (" Ongkos kirim : Rp%d\n", new->ongkir) ;
	printf ("===========================================\n") ;
	printf (" TOTAL : Rp%d\n", new->total) ;
	printf ("===========================================\n") ;
}	

int hapusExtra()		//function untuk menghapus file data extra
{                   //pembuat Maulana Nurhendronoto
    char a;
    FILE *in=fopen("DataEkstra.txt","r");		//membuka file 
    if(!in)		//mengecek apabila data masih kosong
    {
        printf(" Data masih kosong\n");
        getch();
    }
	else
    {
    	printf("||================================================================================||\n");		//konfirmasi ingin menghapus file atau tidak
		printf("||==========          APAKAH ANDA YAKIN INGIN MENGHAPUS DATA ?          ==========||\n");
		printf("||               =================================================                ||\n");
		printf("||==========                    Masukkan Y / y untuk YA                 ==========||\n");
		printf("||==========                    Masukkan T / t untuk TIDAK              ==========||\n");
		printf("||================================================================================||\n");
		printf("\n Silahkan masukkan pilihan anda = ");
        fflush(stdin);//membersihkan memori dari output sebelumnya
        a=getchar();
        if(a=='y' || a=='Y') //jika menjawab Ya (Y/y)
		{
            fclose(in);
            remove("DataEkstra.txt");
            printf(" Data berhasil dihapus!");
            printf("\n\npress any key to continue . . . .");
        }
        else if(a=='t' || a=='T') //jika menjawab Tidak (T/t)
		{
            printf(" Data tidak jadi dihapus");
            printf("\n\npress any key to continue . . . .");
        }
		else //user memasukkan selain huruf Y/y/T/t
        {
			return hapus(); //kembali ke menu hapus, input kembali
	        printf(" Input Salah\n Silahkan Ulang");
    	}
    }
	getch(); //press any key to continue
}
