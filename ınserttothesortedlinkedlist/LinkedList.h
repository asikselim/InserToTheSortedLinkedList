#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList {
public:
	Node* header;

	LinkedList(void);
	void AppendToLinkedList(int ogr_no, int ogr_notu);
	void PrintLinkedList(void);
	void AddToTheBeginning(int ogr_no, int ogr_notu);
	void AddToGivenIndex(int index, int ogr_no, int ogr_notu);
	void DeleteTheLastNode(void);
	void DeleteTheFirstNode(void);
	void DeleteTheNodeAtGivenIndex(int index);

	void InsertToTheSortedLinkedList(int ogr_no, int ogr_notu);

};

LinkedList::LinkedList( void ){
    header=0;
}

void LinkedList::InsertToTheSortedLinkedList(int ogr_no, int ogr_notu) {//InsertToTheSortedLinkedList adında bir fonksiyon tanımlıyoruz.

	Node* n1; //n1 adında bir Node tanımlıyoruz
	n1 = new Node();//yeni öğrenci tanımlyoruz
	n1->setOgrenciNo(ogr_no);//Öğrenci numarası veriyoruz
	n1->setOgrenciNotu(ogr_notu);//Öğrenci notu veriyoruz
	if (header == 0) {//ilk değer 0'a eşitse
		header = n1;//ilk değeri yeni değerimiz yapıyoruz
	}
	else {//değilse
		Node* temp;// temp adında bir Node oluşturuyoruz
		temp = header;// temp değerini header değerine eşitliyoruz
		while (temp->getNextPointer() != 0) {//temp değerimizin değeri temp'in bir sonraki değeri 0'a eşit olmayana kadar döngü dönüyor
			temp = temp->getNextPointer();//temp değerini temp'in bir sonraki değerine eşitliyoruz
		}
		temp->setNextPointer(n1);//temp'in içine n1 Node'unu aktarıyoruz

	}

	int tempMark, tempNum;// Geçiçi değerlerimizi tanımlıyoruz
	Node* temp = header;// temp değerini header'a eşitliyoruz
	for (int i = 0; i < 8; i++) {//döngümüzü 8 kere dönücek şekilde oluşturuyoruz
		temp = header;//temp değerini header değerine eşitliyoruz
		while (temp->getNextPointer() != NULL) {//temp değerinin bir sonraki değeri boş olana kadar dögümüz dönüyor
			if (temp->getOgrenciNotu() < temp->getNextPointer()->getOgrenciNotu()) {//temp'in öğrenci notu, temp'in birsonraki öğrenci notundan küçükse 
				tempMark = temp->getNextPointer()->getOgrenciNotu();//tempMark'ın içine temp'ten sonraki öğrenci notunu atıyoruz
				tempNum = temp->getNextPointer()->getOgrenciNo();//tempNum'ın içine temp'ten sonraki öğrenci numarasını atıyoruz
				temp->getNextPointer()->setOgrenciNotu(temp->getOgrenciNotu());//temp'in bir sonraki öğremci notunun içine, temp'in öğrenci notunu atıyoruz
				temp->getNextPointer()->setOgrenciNo(temp->getOgrenciNo());//temp'in bir sonraki öğremci numarasının içine, temp'in öğrenci numarasının atıyoruz
				temp->setOgrenciNotu(tempMark);//tempMark'ın içine temp'in öğrenci notunu atıyoruz
				temp->setOgrenciNo(tempNum);//tempNum'ın içine temp'in öğrenci numarasını atıyoruz
			}
			temp = temp->getNextPointer();//temp'in bir sonraki değerini çağırıyoruz
		}
	}
}





void LinkedList::DeleteTheNodeAtGivenIndex( int index ){

    if(index==0){
        this->DeleteTheFirstNode();
    }else{
        Node *temp;
        temp=header;
        for( int i=0; i<index-1; i++){
            temp = temp->getNextPointer();
            if(temp->getNextPointer()==0){
                cout<<"Girilen index değeri, listedeki eleman sayısından büyüktür!"<<endl;
                cout<<"Silme işlemi yapılamamıştır."<<endl;
                return;
            }

        }
        Node *temp2;
        temp2 = temp->getNextPointer()->getNextPointer();
        delete temp->getNextPointer();
        temp->setNextPointer( temp2 );

    }
    /*
    Eğer index 0 ise[
        DeleteTheFirstNode fonksiyonunu çağır
    ]Değilse[

        //temp adında bir Node adresi tanımla,
        //temp değerine header değerini ata.

        //temp index-1 deki Node'u gösterecek şekilde ilerlesin.
                //  (for döngüsü ile index-1 tane ilerleme olmalı)
            //Exception : index > numberOfNodes-1 (temp 0 ise)

        temp2 adında bir Node adresi tanımla,
        temp2 değerine temp'in next adresindeki Node'un next adresini ata.
        delete komutu ile temp'in next adresindeki Node'u sil.
        temp'in next adresine temp2 değerini ata.
    ]
    */

}

void LinkedList::DeleteTheFirstNode( void ){

    if( header==0 ){
        cout<<"Listeden eleman yoktur, silme işlemi uygulanmamıştır."<<endl;
    }else{
        Node *temp;
        temp = header->getNextPointer();
        delete header;
        header=temp;
    }

    /*
    Eğer header değeri 0 ise[
        "Listeden eleman yoktur, silme işlemi uygulanmamıştır."
    ]Değilse[
        temp adında bir Node adresi tanımla.
        temp değerine headerin next adresini ata.
        delete komutu ile header Node'unu sil.
        header değerine temp değerini ata.
    ]
    */


}

void LinkedList::DeleteTheLastNode(void){


    if( header==0 ){
        cout<<"Listeden eleman yoktur, silme işlemi uygulanmamıştır."<<endl;
    }else if(header->getNextPointer()==0){
        delete header;
        header = 0;
    }else{
        Node *temp;
        temp = header;

        while(temp->getNextPointer()->getNextPointer()!=0){
            temp = temp->getNextPointer();
        }

        delete temp->getNextPointer();
        temp->setNextPointer( 0 );

    }


    /*
    Eğer header değeri 0 ise[
        "Listeden eleman yoktur, silme işlemi uygulanmamıştır."
    ]Değilse Eğer header Node'unun next değeri 0 ise[
        delete komutu ile header Node'unu sil.
        header değerine 0'ı ata.
    ]Değilse[

        temp adında bir Node adresi tanımla,
        temp değerine header değerini ata.

        temp'in next adresinin next adresi 0 olmadığı müddetçe[
            temp değerine temp'in next değerini ata.
        ]

        delete komutu ile temp'in next adresindeki Node'u sil.
        temp'in next adresine 0 değerini ata.

    ]
    */

}
void LinkedList::AddToGivenIndex(int index, int ogr_no, int ogr_notu){


    if( index==0 ){ //Eğer index değeri 0 ise[
        this->AddToTheBeginning(ogr_no, ogr_notu);	//ListeninBasinaElemanEkleme fonksiyonunu ogr_no ve
                            //ogr_notu değerlerini göndererek çalıştır.
    }else {   //]Değilse[



        Node *temp;  //temp adında bir Node adresi tanımla,
        temp = header;  //temp değerine header değerini ata.

        for( int i=0; i<index-1; i++ ){	//temp index-1 deki Node'u gösterecek şekilde ilerlesin.
                        //  (for döngüsü ile index-1 tane ilerleme olmalı)
            temp = temp->getNextPointer();
            if( temp==0 ){ // Exception: Eğer döngü içerisinde temp 0'a eşit hale gelirse.[
                this->AppendToLinkedList( ogr_no, ogr_notu ); // AppendToLinkedList(int ogr_no, int ogr_notu)
                                    //fonksiyonunu kullanarak yeni Node'u listenin sonuna ekle.
                return; //return
            } //]

        }

        Node *yeni; //yeni adında bir Node adresi oluştur.
        yeni = new Node(); //new komutu ile bir Node oluştur, yeni değerine oluşan adres atansın.
        yeni->setOgrenciNo( ogr_no ); //yeni Node'un ogrenci nosu ogr_no olsun.
        yeni->setOgrenciNotu( ogr_notu ); //yeni Node'un ogrenci notu ogr_notu olsun.

        yeni->setNextPointer( temp->getNextPointer() );   // yeni Node'un next değerine temp'in next değeri atansın.
        temp->setNextPointer( yeni ); 			//temp'in next değerine yeni Node'un adresi atansın.

    } //]


}

void LinkedList::AddToTheBeginning(int ogr_no, int ogr_notu){
    Node *yeni;
    yeni = new Node(ogr_no, ogr_notu);
    //    yeni->setOgrenciNo( ogr_no );
    //    yeni->setOgrenciNotu( ogr_notu );

    Node *temp;
    temp=header;
    header = yeni;
    header->setNextPointer( temp );


}


void LinkedList::AppendToLinkedList(int ogr_no, int ogr_notu){

    Node *n1;
    n1 = new Node();
    n1->setOgrenciNo( ogr_no );
    n1->setOgrenciNotu( ogr_notu );
    if( header==0 ){
        header = n1;
    }else{
        Node *temp;
        temp = header;
        while( temp->getNextPointer() !=0 ){
            temp = temp->getNextPointer();
        }
        temp->setNextPointer( n1 );

    }

}
void LinkedList::PrintLinkedList(void){

    Node *temp;
    temp = header;
    cout<<"-----------------The linked list-------------------"<<endl;
    while( temp !=0 ){
        cout<<temp->getOgrenciNo()<<":\t"<<temp->getOgrenciNotu()<<endl;
        temp = temp->getNextPointer();
    }
    cout<<"-------------The end---------------"<<endl;

}

#endif // LINKEDLIST_H
