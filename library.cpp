#include <iostream>
#include <vector>
#include <string>
#include <clocale>

using namespace std;

class book{
	public:
	string bookName;
	int ISBN;
	string authorName;
	void addBook();	
	void borrowBook();
	void bookList();
	bool status;
	void returnBook();
};

class members : public book{
	public: 
	string memberName;
	string memberSurname;
	void memberRegistration();
	void memberList();
};

vector<book> bookInformation;
vector<members> memberInformation;

void book::addBook(){
	
	book books;
	
	cout << "Kitap ismini giriniz: ";
	cin >> books.bookName;
	
	cout << "Yazar isimini giriniz: ";
	cin >> books.authorName;
	
	cout << "Kitab�n ISBN numaras�n� giriniz: ";
	cin >> books.ISBN;
	
	books.status = false;
	
	bookInformation.push_back(books);
	
}

void members::memberRegistration(){
	
	members member; 
	
	cout << "�sminizi giriniz: ";
	cin >> member.memberName;
	
	cout << "Soyismnizi giriniz: ";
	cin >> member.memberSurname;
	
	memberInformation.push_back(member);
	
}

void book::borrowBook(){
	
	string bookName;
	string memberName;
	string memberSurname;
	
	bookList();
	
	cout << "�sminiz: ";
	cin >> memberName;
	
	cout << "Soyisminiz: ";
	cin >> memberSurname;
	
	cout << "�d�n� almak istedi�iniz kitab�n ismini giriniz: ";
	cin >> bookName;
	
	bool isFind = false;
	
	
	for(int y = 0;y<memberInformation.size();y++){
		if(memberInformation[y].memberName == memberName && memberInformation[y].memberSurname == memberSurname){
			
				
	 for(int j = 0;bookInformation.size();j++){
		
		if(bookInformation[j].status == true){
			cout << "Bu kitap �d�n� al�nm��!" << endl;
			cout << endl;
			break;
		}
		
		if(bookInformation[j].bookName == bookName){
			if(bookInformation[j].status == false){
			isFind = true;
			bookInformation[j].status = true;
			
			cout << "Kitab�n�z� �d�n� alabilirsiniz.." << endl;
			cout << endl;
			
			break;
		}
	
		}
			
	}	
			
			break;
		}else{
     	cout << "Arad���n�z isim ve soyisimde �ye bulunamad�!" << endl;
		cout << endl;
		break;
	}
				
	}
	
	
	
	
	

	
		if(isFind == false)
		cout << "Arad���n�z isimde kitap bulunamad�!!";
	
}

void book::bookList(){
	
	cout << "------ K�TAP L�STES� ------" << endl;
	cout << endl;
	
	for(int i = 0;i<bookInformation.size();i++){
		cout << "Kitap ismi: " << bookInformation[i].bookName << endl;
		cout << "Yazar ismi: " << bookInformation[i].authorName << endl;
		cout << "ISBN no: " << bookInformation[i].ISBN << endl;
		if(	bookInformation[i].status == true)
		cout << "Durum: Mevcut de�il" << endl;
		else
		cout << "Durum: Mevcut" << endl;
		cout << endl;
	}
	
	cout << "---------------------------" << endl;
	cout << endl;
}

void members::memberList(){
	
	cout << endl;
	cout << "------ �YE L�STES� ------" << endl;
	cout << endl;
	
	for(int k = 0;k<memberInformation.size();k++){
		cout << "�ye ismi: " << memberInformation[k].memberName << endl;
		cout << "�ye soyismi: " << memberInformation[k].memberSurname << endl;
		cout << endl;
	}
	
	cout << "---------------------------" << endl;
	cout << endl;
	
}

void book::returnBook(){
	
	string bookName;
	
	cout << "�ade edece�iniz kitab�n ismi: ";
	cin >> bookName;
	
	bool find = false;
	
	for(int x = 0;x<bookInformation.size();x++){
	if(bookInformation[x].bookName == bookName){
		
		bookInformation[x].status = false;
		find = true;
		
		cout << "Kitab�n�z �ade edildi.." << endl;
		cout << endl;
	 }
	 
	 
	}
	
	if(find==false){
	cout << "Arad���n�z isimde kitap bulunamad�!" << endl;
	cout << endl;
}
}


void console(){
	
cout << endl;	
cout << "---------------------" << endl;	
cout <<	"1- Kitap Ekle" << endl;
cout <<	"2- �ye Kaydet" << endl;
cout <<	"3- Kitap �d�n� Al" << endl;
cout <<	"4- Kitap �ade Et" << endl;
cout <<	"5- Kitaplar� Listele" << endl;
cout <<	"6- �yeleri Listele" << endl;
cout <<	"7- ��k��" << endl;
cout << "---------------------" << endl;
cout << endl;
	
}





int main() {
	
setlocale(LC_ALL,"Turkish");	
	
members select;	
	
int selection = 0;



do{
	
console();

cout << "Yapmak istedi�iniz i�lemi se�iniz: ";
cin >> selection;


switch(selection){
	
	case 1:
		select.addBook();
	break;
	
	case 2:
		select.memberRegistration();
	break;
	
	case 3:
		select.borrowBook();
	break;

    case 4:
    	select.returnBook();
	break;
	
	case 5:
		select.bookList();
	break;
	
	case 6:
		select.memberList();
	break;
		
	case 7:
		cout << "��k�� yap�l�yor..." << endl;
		cout << endl;
	break;
		
    default: 
    cout << "Yanl�� se�im yapt�n�z!" << endl;
    cout << endl;
}
cout << endl;
}while(selection != 7);


	return 0;
}
