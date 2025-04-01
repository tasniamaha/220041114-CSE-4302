#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<fstream>
#include<sstream>
using namespace std;
class Book{
    private:
    string title,author,isbn;
    public:
    Book(string t,string a,string i):title(t),author(a),isbn(i){}
    string get_title()const{
        return title;
    }
    string get_author(){
        return author;
    }
    string get_isbn(){
        return isbn;
    }
    void display(){
        cout<<"Title: "<<title<<", Author: "<<author<<", ISBN: "<<isbn<<endl;
    }
    string file_format()const{
        return title+','+author+','+isbn+"\n";
    }
};
class Library{
    private:
    vector<Book> inventory;
    deque<Book>borrowedBooks;
    list<Book>archivedBooks;
    public:
    void addbook(string t,string a,string i){
        inventory.emplace_back(t,a,i);
        cout<<"Book added successfully\n";
    }
    void borrow(){
        cout<<"Available :\n";
        cout<<"Inventory Books:\n";
        for(auto it=inventory.begin();it!=inventory.end();it++){
            it->display();  
        }
        cout<<"Borrowed Books:\n";
        for(auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            it->display();  
        }
        cout<<"Archived Books:\n";
        for(auto it=archivedBooks.begin();it!=archivedBooks.end();it++){
            it->display();  
        }
        string i;
        cout<<"Enter ISBN:";
        getline(cin,i);
        for(auto it=inventory.begin();it!=inventory.end();it++){
            if(it->get_isbn()==i){
                borrowedBooks.push_back(*it);
                inventory.erase(it);
                cout<<"Book borrowed successfully\n";
                return;
            }
            
        }
        cout << "Book not found\n";
    }
    void returnbook(){
        cout<<"Available :\n";
        cout<<"Inventory Books:\n";
        for(auto it=inventory.begin();it!=inventory.end();it++){
            it->display();  
        }
        cout<<"Borrowed Books:\n";
        for(auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            it->display();  
        }
        cout<<"Archived Books:\n";
        for(auto it=archivedBooks.begin();it!=archivedBooks.end();it++){
            it->display();  
        }
        string i;
        cout<<"Enter ISBN:";
        getline(cin,i);
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {
            if (it->get_isbn() == i) {
                inventory.push_back(*it);
                borrowedBooks.erase(it);
                cout << "Book returned successfully\n";
                return;
            }
        }
        cout << "Book not found\n";
        
    }
    void archive(){
        cout<<"Available :\n";
        cout<<"Inventory Books:\n";
        for(auto it=inventory.begin();it!=inventory.end();it++){
            it->display();  
        }
        cout<<"Borrowed Books:\n";
        for(auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            it->display();  
        }
        cout<<"Archived Books:\n";
        for(auto it=archivedBooks.begin();it!=archivedBooks.end();it++){
            it->display();  
        }
        string i;
        cout<<"Enter ISBN:";
        getline(cin,i);
        for(auto it=inventory.begin();it!=inventory.end();it++){
            if(it->get_isbn()==i){
                archivedBooks.push_back(*it);
                inventory.erase(it);
                cout<<"Book archived successfully\n";
                return;
            }
           
        }
        cout << "Book not found\n";
    }
    void displaybooks(){
        cout<<"Inventory Books:\n";
        for(auto it=inventory.begin();it!=inventory.end();it++){
            it->display();  
        }
        cout<<"Borrowed Books:\n";
        for(auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            it->display();  
        }
        cout<<"Archived Books\n";
        for(auto it=archivedBooks.begin();it!=archivedBooks.end();it++){
            it->display();  
        }
    }
    void savedata(){
        ofstream invfile("inventory.txt"),borrfile("borrowed.txt"),archfile("archived.txt");
        for (const auto& it : inventory) invfile << it.file_format();
        for (const auto& it : borrowedBooks) borrfile << it.file_format();
        for (const auto& it : archivedBooks) archfile << it.file_format();
        invfile.close();
        borrfile.close();
        archfile.close();
        cout<<"Data saved successfully\n";
    }
    void loaddata(){
        ifstream invfile("inventory.txt"),borrfile("borrowed.txt"),archfile("archived.txt");
        inventory.clear();
        borrowedBooks.clear();
        archivedBooks.clear();
        string line,t,a,i;
        while(getline(invfile,line)){
            stringstream ss(line);
            getline(ss,t,',');
            getline(ss,a,',');
            getline(ss,i,',');
            inventory.emplace_back(t,a,i);
        }
        while(getline(borrfile,line)){
            stringstream ss(line);
            getline(ss,t,',');
            getline(ss,a,',');
            getline(ss,i,',');
            borrowedBooks.emplace_back(t,a,i);
        }
        while(getline(archfile,line)){
            stringstream ss(line);
            getline(ss,t,',');
            getline(ss,a,',');
            getline(ss,i,',');
            archivedBooks.emplace_back(t,a,i);
        }
        invfile.close();
        borrfile.close();
        archfile.close();
        cout<<"Data archived successfully\n";
    }
};
int main(){
    Library lib;
    while(true){
        cout<<"1.Add Book\n";
        cout<<"2.Borrow Book\n";
        cout<<"3.Return Book\n";
        cout<<"4.Archive Book\n";
        cout<<"5.Display Book\n";
        cout<<"6.Save Data\n";
        cout<<"7.Load Data\n";
        cout<<"8.Exit\n";
        int choice;
        cout<<"Enter your choice:";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            string t,a,i;
            cout<<"Enter title:";
            getline(cin,t);

            cout<<"Enter author:";
            getline(cin,a);
            cout<<"Enter ISBN:";
            getline(cin,i);
            lib.addbook(t,a,i);
        }
        else if(choice==2){
            lib.borrow();
        }
        else if(choice==3){
            lib.returnbook();
        }
        else if(choice==4){
            lib.archive();
        }
        else if(choice==5){
            lib.displaybooks();
        }
        else if(choice==6){
            lib.savedata();
        }
        else if(choice==7){
            lib.loaddata();
        }
        else{
            break;
        }
    }
}
