#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
enum CoverType{Hardcover, Paperback};
class LibraryResource{
    protected:
    string title;
    string author;
    double price;
    int no_of_copies=1;
    public:
    LibraryResource(string t,string a,double p):title(t),author(a),price(p){}
    virtual void resourceDetails() const=0;
   
    double getPrice(){
        return price;
    }
    void set_no_of_copies(int copy){
        no_of_copies=copy;
    }
    int getcopies(){
        return no_of_copies;
    }
    
};
class Book:public LibraryResource{
    private:
    CoverType cover;
    public:
    Book(string title,string author,double price,CoverType c): LibraryResource(title,author,price),cover(c){}
    void resourceDetails()const override{
        cout<<"Title:  "<<title<<endl;
        cout<<"Author:  "<<author<<endl;
        cout<<"Price:  "<<price<<endl;
        cout<<"Covertype:  "<<(cover==CoverType::Hardcover?"Hardcover":"Paperback")<<endl;
    }
};
class EBook:public LibraryResource{
    private:
    double fileSize;
    public:
    EBook(string title,string author,double price,double Size):LibraryResource(title,author,price),fileSize(Size){}
    void resourceDetails()const override{
        cout<<"Title:  "<<title<<endl;
        cout<<"Author:  "<<author<<endl;
        cout<<"Price:  "<<price<<endl;
        cout<<"Filse Size:  "<<fileSize<<endl;
    }
};
class Audiobook:public LibraryResource{
    private:
    double duration;
    public:
    Audiobook(string title,string author,double price,double min):LibraryResource(title,author,price),duration(min){}
    void resourceDetails()const override{
        cout<<"Title:  "<<title<<endl;
        cout<<"Author:  "<<author<<endl;
        cout<<"Price:  "<<price<<endl;
        cout<<"Duration:  "<<duration<<endl;
    }
};
void sort_resources_price(LibraryResource** resource,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(resource[i]->getPrice()>resource[j]->getPrice()){
                LibraryResource* temp=resource[i];
                resource[i]=resource[j];
                resource[j]=temp;
            }
        }
    }
}
int main() {
    LibraryResource* resource_list[100];

    /** TASK 1:
        So that the following lines execute without errors
    */
    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500,CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);

    /** TASK 2: Display details */
    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceDetails();
    }

    /** TASK 3: Setting ISBN for Book */
    resource_list[0]->set_no_of_copies(50);
    resource_list[1]->set_no_of_copies(5);
    resource_list[2]->set_no_of_copies(1);

   

    /** TASK 4: Sorting resources by price 
    Created 7 more objects.*/

    resource_list[3] = new Book("Sapiens", "Yuval Noah Harari", 1000, CoverType::Paperback);
    resource_list[4] = new EBook("Digital Minimalism", "Cal Newport", 400, 3.2);
    resource_list[5] = new Audiobook("Atomic Habits", "James Clear", 1200, 180);
    resource_list[6] = new Book("Dune", "Frank Herbert", 800, CoverType::Hardcover);
    resource_list[7] = new EBook("The Subtle Art of Not Giving a F*ck", "Mark Manson", 350, 1.8);
    resource_list[8] = new Audiobook("Educated", "Tara Westover", 600, 150);
    resource_list[9] = new Book("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 450, CoverType::Paperback);


    sort_resources_price(resource_list, 10);
   
    /** Display sorted resources */
    for (int i = 0; i < 10; i++) {
        resource_list[i]->resourceDetails();
    }

    return 0;
}


