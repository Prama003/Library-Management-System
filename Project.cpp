#include<iostream>
#include<vector>
using namespace std;
class Book
{
    public:
    string title;
    string author;
    int bookId;
//constructor
    Book(string t, string a, int b)
    {
        title =t;
        author=a;
        bookId=b;
    }
    void displayBooks()
    {
        cout<<"book"<<title<<endl;
        cout<<"author"<<author<<endl;
        cout<<"Book Id"<<bookId<<endl;
    }
};
class Library
{
    private:
    vector<Book> books;
    public:
    void addbook(string title, string author, int bookId)
    {
        books.push_back(Book(title,author,bookId));
        cout<<"book added successfully"<<endl;
    }
    void displayBooks()
    {
        if(books.empty())
        {
            cout<<"no books in the library"<<endl;
            return;
        }
        cout<<"list of books"<<endl;
        for(Book &b: books)
        b.displayBooks();
    }

    void searchBook(int id) {
        for (Book &b : books) {
            if (b.bookId == id) {
                cout <<"Book Found:"<<endl;
                b.displayBooks();
                return;
            }
        }
        cout << "Book not found!\n";
    }
};
int main()
{
    Library lib;
    int choice,id;
    string title, author;
do{
    cout<<"library management system"<<endl;
    cout<<"1.Add book"<<endl;
    cout<<"2.Display all books"<<endl;
    cout<<"3.Search a book by Id"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
            cout<<"enter the book"<<endl;
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Book ID: ";
            cin >> id;
            lib.addbook(title, author, id);
            break;
        case 2:
            lib.displayBooks();
            break;
        case 3:
            cout<<"enter book Id to search"<<endl;
            cin>>id;
            lib.searchBook(id);
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
    }
    }while(choice!=4);
    return 0;
}
    
