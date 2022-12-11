#include<iostream>
#include<conio.h>
using namespace std;

struct NPass{
	char Isi;
	NPass *next;
	NPass *prev;
};

NPass *head, *tail, *cur, *node, *del;

// Function membuat password
void Input(char elemen){
	node = new NPass();
	node->Isi = elemen;
	node->prev = NULL;
	node->next = NULL;
	if(head == NULL){
		head = node;
		node->next = NULL;
		tail = head;
	}else{
		cur = head;
		while(cur->next != NULL)
			cur = cur->next;
		cur->next = node;
		node->prev = cur;
	}
}

// Proses perpindahan node terakhir ke depan
void MoveNode(){
	if(head == NULL || head->next == NULL){
		return;	
	}
	
	tail = NULL;
	cur = head;
	
	while(cur->next != NULL){
		tail = cur;
		cur = cur->next;
	}
	tail->next = NULL;
	cur->next = head;
	head = cur;
}

// Perpindahan 3 node terakhir ke depan
void MoveFull(){
	MoveNode();
	MoveNode();
	MoveNode();	
}

// Function Enkripsi password
void Encrypt(char elemen1){
  node = new NPass();
  node->Isi = '@';
  cur = head;
  int nomor = 1;
  while(nomor < 3){
		cur = cur->next;
		nomor++;
	}
	node->next = cur->next;
	cur->next = node;
}

// Function menghapus semua karakter password
void Clear(){
	cur = head;
	while(cur != NULL){
		del = cur;
		cur = cur->next;
		delete del;
	}
	head = NULL;
}

// Function menampilkan password 
void PrintNode(){
	cur = head;
	while(cur->next != NULL){
		cout<<cur->Isi;
		cur=cur->next;
	}
	cout<<cur->Isi;
}

// Function menampilkan semua data
void PrintFull(){
	char karPas;
	
	cout<<"\n+--------------------------------------------------------+"<<endl;
	cout<<"|Password Original: ";PrintNode();
	cout<<"\t\t\t\t |";
	cout<<"\n|--------------------------------------------------------+"<<endl;
	cout<<"|Perpindahan 3 karakter dari belakang ke depan: ";MoveFull();PrintNode();
	cout<<"\t |";
	cout<<"\n|--------------------------------------------------------+"<<endl;
	cout<<"|Password setelah di Enkripsi: ";Encrypt(karPas);PrintNode();
	cout<<"\t\t\t |";
	cout<<"\n+--------------------------------------------------------+"<<endl;
}

void by(){
	cout<<"=======================================================\n";
    cout<<"| Nama  : Marwah Nur Shafira                          |\n";
    cout<<"| NIM   : 2107411008                                  |\n";
    cout<<"| Kelas : TI 2A                                       |\n";
    cout<<"| Project UAS Mata Kuliah Algoritma dan Struktur Data |\n";
	cout<<"======================================================="<<endl;
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	
	cout<<"\t\t\t+-------------------------------------------------------+\n";
    cout<<"\t\t\t|      PROGRAM ENKRIPSI PASSWORD DENGAN LINKED LIST     |\n";
    cout<<"\t\t\t+-------------------------------------------------------+\n\n\n\n";
}

int main(){
	char karPas, choose;
	string uss;
	int i;
	
	utama:
	
	by();
	cout<<"Masukkan username: "; cin>>uss;
	cout<<"\nNote: \n";
	cout<<"Masukkan Password dengan 6 karakter, jika lebih dari 6 karakter. Maka karakter berikutnya tidak akan diproses!!"<<endl;
	cout<<"\nMasukkan Password: ";
	for(i=1; i<7; i++) {
		cin>>karPas;
		Input(karPas);
	}
	getch();
	system("cls");
	
	by();
	cout<<"  Username: "<<uss;
	PrintFull();
	
	cout<<endl<<endl;
	Clear();
	system("pause");
	
	cout<<"\nIngin mencoba lagi [Y/T] ? "; cin>>choose;
	switch(choose){
		case 'Y' : case 'y':
			system("cls");
			goto utama;
			break;
		case 'T' : case 't':
			cout<<"\n\n---------------------------EXIT-------------------------"<<endl;
			exit(0);
			break;
		default :
			cout<<"\n\n---------------------------EXIT-------------------------"<<endl;
			exit(0);
			break;
	}
}
