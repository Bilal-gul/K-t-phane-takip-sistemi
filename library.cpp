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

class members{
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
	
	cout << "Kitabýn ISBN numarasýný giriniz: ";
	cin >> books.ISBN;
	
	books.status = false;
	
	bookInformation.push_back(books);
	
}

void members::memberRegistration(){
	
	members member; 
	
	cout << "Ýsminizi giriniz: ";
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
	
	cout << "Ýsminiz: ";
	cin >> memberName;
	
	cout << "Soyisminiz: ";
	cin >> memberSurname;
	
	cout << "Ödünç almak istediðiniz kitabýn ismini giriniz: ";
	cin >> bookName;
	
	bool isFind = false;
	
	
	for(int y = 0;y<memberInformation.size();y++){
		if(memberInformation[y].memberName == memberName && memberInformation[y].memberSurname == memberSurname){
			
				
	 for(int j = 0;j<bookInformation.size();j++){
		
		if(bookInformation[j].status == true){
			cout << "Bu kitap ödünç alýnmýþ!" << endl;
			cout << endl;
			break;
		}
		
		if(bookInformation[j].bookName == bookName){
			if(bookInformation[j].status == false){
			isFind = true;
			bookInformation[j].status = true;
			
			cout << "Kitabýnýzý Ödünç alabilirsiniz.." << endl;
			cout << endl;
			
			break;
		}
	
		}
			
	}	
			
			break;
		}else{
     	cout << "Aradýðýnýz isim ve soyisimde üye bulunamadý!" << endl;
		cout << endl;
		break;
	}
				
	}
	
	
	
	
	

	
		if(isFind == false)
		cout << "Aradýðýnýz isimde kitap bulunamadý!!";
	
}

void book::bookList(){
	
	cout << "------ KÝTAP LÝSTESÝ ------" << endl;
	cout << endl;
	
	for(int i = 0;i<bookInformation.size();i++){
		cout << "Kitap ismi: " << bookInformation[i].bookName << endl;
		cout << "Yazar ismi: " << bookInformation[i].authorName << endl;
		cout << "ISBN no: " << bookInformation[i].ISBN << endl;
		if(	bookInformation[i].status == true)
		cout << "Durum: Mevcut deðil" << endl;
		else
		cout << "Durum: Mevcut" << endl;
		cout << endl;
	}
	
	cout << "---------------------------" << endl;
	cout << endl;
}

void members::memberList(){
	
	cout << endl;
	cout << "------ ÜYE LÝSTESÝ ------" << endl;
	cout << endl;
	
	for(int k = 0;k<memberInformation.size();k++){
		cout << "Üye ismi: " << memberInformation[k].memberName << endl;
		cout << "Üye soyismi: " << memberInformation[k].memberSurname << endl;
		cout << endl;
	}
	
	cout << "---------------------------" << endl;
	cout << endl;
	
}

void book::returnBook(){
	
	string bookName;
	
	cout << "Ýade edeceðiniz kitabýn ismi: ";
	cin >> bookName;
	
	bool find = false;
	
	for(int x = 0;x<bookInformation.size();x++){
	if(bookInformation[x].bookName == bookName){
		
		bookInformation[x].status = false;
		find = true;
		
		cout << "Kitabýnýz Ýade edildi.." << endl;
		cout << endl;
	 }
	 
	 
	}
	
	if(find==false){
	cout << "Aradýðýnýz isimde kitap bulunamadý!" << endl;
	cout << endl;
}
}


void console(){
	
cout << endl;	
cout << "---------------------" << endl;	
cout <<	"1- Kitap Ekle" << endl;
cout <<	"2- Üye Kaydet" << endl;
cout <<	"3- Kitap Ödünç Al" << endl;
cout <<	"4- Kitap Ýade Et" << endl;
cout <<	"5- Kitaplarý Listele" << endl;
cout <<	"6- Üyeleri Listele" << endl;
cout <<	"7- Çýkýþ" << endl;
cout << "---------------------" << endl;
cout << endl;
	
}





int main() {
	
setlocale(LC_ALL,"Turkish");	
	
members select;	
	
int selection = 0;



do{
	
console();

cout << "Yapmak istediðiniz iþlemi seçiniz: ";
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
		cout << "Çýkýþ yapýlýyor..." << endl;
		cout << endl;
	break;
		
    default: 
    cout << "Yanlýþ seçim yaptýnýz!" << endl;
    cout << endl;
}
cout << endl;
}while(selection != 7);


	return 0;
}
