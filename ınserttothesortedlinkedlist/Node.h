#ifndef NODE_H
#define NODE_H

class Node{
private:
    int ogrenci_no;
    int ogrenci_notu;
    Node *next;

public:
    Node(void);
    Node(int ogr_no, int ogr_notu);
    void setOgrenciNo( int ogr_no );
    int getOgrenciNo( void );
    void setOgrenciNotu( int ogr_notu );
    int getOgrenciNotu( void );
    void setNextPointer( Node *next_ );
    Node *getNextPointer( void );

};

Node::Node(void){
    ogrenci_no = -1;
    ogrenci_notu = 0;
    next=0;
}
Node::Node(int ogr_no, int ogr_notu){
    ogrenci_no=ogr_no;
    ogrenci_notu = ogr_notu;
    next=0;
}
void Node::setOgrenciNo(int ogr_no){
    ogrenci_no = ogr_no;
}
int Node::getOgrenciNo(void){
    return ogrenci_no;
}
void Node::setOgrenciNotu(int ogr_notu){
    ogrenci_notu = ogr_notu;
}
int Node::getOgrenciNotu(void){
    return ogrenci_notu;
}
void Node::setNextPointer(Node *next_){
    next = next_;
}
Node *Node::getNextPointer(void){
    return next;
}









#endif // NODE_H
