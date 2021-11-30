#include <iostream>
#include <conio.h>

using namespace std;

//dekralasi struct sebuah tree
struct n{
	int data;
	n *kiri;
	n *kanan;
};

n *tree =NULL;

//fungsi untuk menambahkan data baru
void tambah(n **root, int data1){
	//jika root masih kosong 
	if((*root)== NULL){
		//pembuatan n baru
		n  *a;
		//alokasikan memori dari n yang dibuat
		a= new n;
		//inisialisai awal n yang baru dibuat
		a->	data =data1;
		a-> kiri = NULL;
		a->kanan= NULL;
		(*root) = a;
 		(*root) -> kiri = NULL;
 		(*root) -> kanan = NULL;
 		cout<<"Data Bertambah";	
 		
	//jika data yang akan dimasukkan lebih kecil daripada elemen root, 
	//maka akan diletakkan di node sebelah kiri.	
	}else if (data1<(*root)->data) 
		tambah(&(*root)->kiri, data1);
	else if (data1>(*root)->data)
 		tambah(&(*root)->kanan, data1);
 	else if (data1==(*root)->data)
		cout<<"Data Tersedia!";
}

//fungsi yang digunakan untuk mencetak tree secara preOrder
void preOrder(n *root){
	if(root!=NULL)
	{
 		if(root->data!=NULL)
 		{
 			cout<<root->data;
 		}
		preOrder(root->kiri);
		preOrder(root->kanan);
 	}
}

//fungsi yang digunakan untuk mencetak tree secara inOrder
void inOrder(n *root){
	if(root!=NULL){
		inOrder(root->kiri);
 	if(root->data!=NULL){
 		cout<<root->data;
 	}
 	inOrder(root->kanan);
	}	
}
//fungsi yang digunakan untuk mencetak tree secara postOrder
void postOrder(n *root){
 	if(root!=NULL) {
 		postOrder(root->kiri);
 		postOrder(root->kanan);
 		if(root->data!=NULL){
 			cout<<root->data; 
		}
 	}
}

//fungsi utama
int main()
{
	//deklarasikan variabel
	char pil;
	while (true)
	{ 
		system("cls"); //bersihkan layar
		 char data;
		 cout<<"\t#PROGRAM TREE Dev C++#";
		 cout<<"\n\t=================";
		 cout<<"\nMENU";
		 cout<<"\n----\n";
		 cout<<"[1] Tambah Data\n";
		 cout<<"[2] Lihat Pre-Order\n";
		 cout<<"[3] Lihat In-Order\n";
		 cout<<"[4] Lihat Post-Order\n";
		 cout<<"[X] Keluar\n";
		 cout<<"Pilihan Anda : ";
		 cin>>pil;
		 fflush(stdin); //mengosongkan buffering
		 
 	switch(pil)
	{
		//jika pil bernilai '1'
		case '1':
			cout<<"\nINPUT : ";
			cout<<"\n-------";
			cout<<"\nMasukkan data: ";
			cin>>data;
			//panggil fungsi untuk menambah node yang berisi data pada tree
			tambah(&tree,data1);
			getch(); 
			break;
			
	 	//jika pil bernilai '2'
	 	case '2':
	 		cout<<"\nOUTPUT PRE ORDER : ";
	 		cout<<"\n------------------\n";
	 		if(tree!=NULL)
	 			//panggil fungsi untuk mencetak data secara preOrder
	 			preOrder(tree);
	 		else
	 			cout<<"Masih Kosong!!!";
			getch();
			break;
			
	 	//jika pil bernilai '3'
	 	case '3':
			cout<<"\nOUTPUT IN ORDER : ";
	 		cout<<"\n------------------\n";
	 		if(tree!=NULL)
	 			//panggil fungsi untuk mencetakdata secara inOrder
	 			inOrder(tree);
 			else
 				cout<<"Masih Kosong!!!";
			getch(); 
			break;
 		//jika pil bernilai '4'
 		case '4':
			cout<<"\nOUTPUT POST ORDER: ";
			cout<<"\n------------------\n";
			if(tree!=NULL)
				//panggil fungsi untuk mencetak data secara postOrder
				postOrder(tree);
			else
				cout<<"Masih Kosong!!!";
			getch();
 			break;
		//jika pil bernilai 'X' atau 'x'
		case 'X'|'x':
			exit(0);
			break;
 	}				

}
}
