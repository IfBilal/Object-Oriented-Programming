// M.Bilal Tahir
// 24i-3166
// SE-B

#include <iostream>
#include <vector>
using namespace std;
class Page
{
private:
    string text;
    int page_no;

public:
    Page(string text = "", int page_no = 0)
    {
        this->text = text;
        this->page_no = page_no;
    }
    void setText(string i)
    {
        text = i;
    }
    void setPageNo(int i)
    {
        page_no = i;
    }
    string getText() const
    {
        return text;
    }
    int getPageNo() const
    {
        return page_no;
    }
};
class Book
{
private:
    string title;
    string author;
    string ISBN;
    bool reservationStatus;
    int Time;
    Page P;

public:
    Book(string title = "", string author = "", string ISBN = "")
    {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        reservationStatus = 1;
        Time = 0;
    }

    bool getReservationStatus() const
    {
        return reservationStatus;
    }

    void setReservationStatus(bool status)
    {
        reservationStatus = status;
    }

    int getTime() const
    {
        return Time;
    }
    void setTime(int t)
    {
        Time = t;
    }

    void setTitle(string i)
    {
        title = i;
    }
    void setAuthor(string i)
    {
        author = i;
    }
    void setISBN(string i)
    {
        ISBN = i;
    }
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getISBN() const
    {
        return ISBN;
    }
    void ShowDueDate()
    {
        cout << "Due date is " << Time << " days" << endl;
    }
    void Renew_info(string title, string author, string ISBN)
    {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
    }
};

class LibraryDatabase
{
private:
    Book *List_of_Books;
    int size;
    int capacity;
    friend class Librarian; // giving librarian access to the database

public:
    LibraryDatabase()
    {
        size = 0;
        capacity = 1;
        List_of_Books = new Book[capacity];
    }

    int getSize() const
    {
        return size;
    }

    Book *getBookReference()
    {
        return List_of_Books;
    }

    void setSize(int s)
    {
        size = s;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void setCapacity(int c)
    {
        capacity = c;
    }

    void AddBook(const Book B)
    {
        for (int i = 0; i < size; i++)
        {
            if (List_of_Books[i].getISBN() == B.getISBN())
            {
                cout << "Book with same ISBN exists " << endl;
                return;
            }
        }
        if (size == capacity)
        {
            capacity *= 2;
            Book *temp = new Book[capacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = List_of_Books[i];
            }
            delete[] List_of_Books;
            List_of_Books = temp;
            temp = nullptr;
        }
        List_of_Books[size] = B;
        size++;
    }

    void swapBooks(Book &A, Book &B)
    {
        if (&A != &B)
        {
            string temp;
            temp = A.getAuthor();
            A.setAuthor(B.getAuthor());
            B.setAuthor(temp);

            temp = A.getISBN();
            A.setISBN(B.getISBN());
            B.setISBN(temp);

            temp = A.getTitle();
            A.setTitle(B.getTitle());
            B.setTitle(temp);
        }
    }
    void DeleteBook(string ISBN)
    {
        bool check = 0;
        for (int i = 0; i < size; i++)
        {
            if (List_of_Books[i].getISBN() == ISBN)
            {
                if (List_of_Books[i].getReservationStatus() == 0)
                {
                    cout << "Book already issued \nCan't be deleted\n";
                    return;
                }
                swapBooks(List_of_Books[i], List_of_Books[size - 1]);
                size--;
                check = 1;
            }
        }
        if (check == 0)
            cout << "Book not found" << endl;
        else
            cout << "Book deleted" << endl;
    }

    void UpdateBook(const Book &B, string ISBN)
    {
        bool check = 0;
        for (int i = 0; i < size; i++)
        {
            if (List_of_Books[i].getISBN() == ISBN)
            {
                check = 1;
                List_of_Books[i] = B;
            }
        }
        if (check == 0)
            cout << "Book not found to be updated " << endl;
        else
            cout << "Book updated " << endl;
    }
    void DisplayBook(string ISBN)
    {
        bool check = 0;
        for (int i = 0; i < size; i++)
        {
            if (List_of_Books[i].getISBN() == ISBN)
            {
                check = 1;
                cout << "ISBN : " << List_of_Books[i].getISBN() << endl;
                cout << "Title : " << List_of_Books[i].getTitle() << endl;
                cout << "Author name : " << List_of_Books[i].getAuthor() << endl;
                (List_of_Books[i].getReservationStatus()) ? cout << "Available\n " : cout << "Not Available\n";
            }
        }
        if (check == 0)
            cout << "Book not found " << endl;
    }

    Book SearchBook(string ISBN)
    {
        for (int i = 0; i < size; i++)
        {
            if (List_of_Books[i].getISBN() == ISBN)
                return List_of_Books[i];
        }
        cout << "No book found " << endl;
        return Book();
    }

    ~LibraryDatabase()
    {
        delete[] List_of_Books;
    }
};

class Librarian
{
private:
    string name;
    int ID;
    string password;

public:
    Librarian(string name = "", int ID = 0, string password = "")
    {
        this->name = name;
        this->ID = ID;
        this->password = password;
    }
    void setName(string i)
    {
        name = i;
    }
    void setID(int i)
    {
        ID = i;
    }
    void setPassword(string i)
    {
        password = i;
    }
    string getName() const
    {
        return name;
    }
    int getID() const
    {
        return ID;
    }
    string getPassword() const
    {
        return password;
    }
    bool verifyLibrarian(int ID, string password)
    {
        bool check = 1;
        if (this->ID != ID)
            check = 0;
        if (this->password != password)
            check = 0;
        return check;
    }
    Book SearchBook(LibraryDatabase L, string ISBN) // search for a book in database by ISBN and return the whole book
    {
        for (int i = 0; i < L.size; i++)
        {
            if (L.List_of_Books[i].getISBN() == ISBN)
                return L.List_of_Books[i];
        }
        cout << "No book found " << endl;
        return Book();
    }
    LibraryDatabase *AccessDB(LibraryDatabase &DB)
    {

        return &DB;
    }
};

class LibrarySystem // admin class and admin has a librarian , admin creates librarian
{
private:
    int userType;
    string username;
    string Password;
    Librarian *L;

public:
    LibrarySystem(string username = "", string Password = "", int userType = 0)
    {
        this->userType = userType;
        this->username = username;
        this->Password = Password;
        L = nullptr;
    }
    void setUserType(int i)
    {
        userType = i;
    }
    void setUsername(string i)
    {
        username = i;
    }
    void SetPassword(string i)
    {
        Password = i;
    }
    int getUserType() const
    {
        return userType;
    }
    Librarian *getLibrarian() const
    {
        return L;
    }
    string getUsername() const
    {
        return username;
    }
    string getPassword() const
    {
        return Password;
    }
    void registerAdmin()
    {
        cin.ignore();
        cout << "Register Admin \n";
        cout << "Enter username for admin : ";
        getline(cin, username);
        cout << "Enter password for admin : ";
        getline(cin, Password);
    }
    void loginAdmin()
    {
        if (username == "" && Password == "")
        {
            cout << "No admin exists" << endl;
            return;
        }
        string temp_username, temp_pass;
        cin.ignore();
        while (true)
        {
            cout << "Enter username of Admin : ";
            getline(cin, temp_username);
            cout << "Enter password of Admin : ";
            getline(cin, temp_pass);
            if (temp_username == username && temp_pass == Password)
            {
                cout << "Admin Logged in \n";
                return;
            }
            cout << "Wrong data \n";
        }
    }
    void loginLibrarian()
    {
        if (!L)
        {
            cout << "No librarian exists ";
            return;
        }
        int temp_ID;
        string temp_pass;
    again:
        cout << "Enter ID of librarian : ";
        cin >> temp_ID;
        while (temp_ID <= 0)
        {
            cout << "\nInvalid\nEnter ID of librarian : ";
            cin >> temp_ID;
        }
        cout << "Enter password of librarian : ";
        cin.ignore();
        getline(cin, temp_pass);

        if (!L->verifyLibrarian(temp_ID, temp_pass))
        {
            cout << "Invalid data" << endl;
            goto again;
        }
    }

    void logoutAdmin()
    {
        userType = 0;
        cout<<"Admin Logged out"<<endl;
    }

    void createLibrarian()
    {
        int temp_ID;
        string temp_password;
        string temp_name;
        cout << "Enter ID for Librarian : ";
        cin >> temp_ID;
        while (temp_ID <= 0)
        {
            cout << "\nInvalid\nEnter ID for Librarian : ";
            cin >> temp_ID;
        }
        cin.ignore();
        cout << "Enter name of Librarian : ";
        getline(cin, temp_name);
        cout << "Enter password for Librarian : ";
        getline(cin, temp_password);
        if (L != nullptr)
            delete L;
        L = new Librarian(temp_name, temp_ID, temp_password);
    }
    ~LibrarySystem()
    {
        delete L;
    }
};

class Account
{
private:
    int no_borrowed_books;
    int no_lost_books;
    int no_reserved_books;
    float fine_amount;

public:
    Account(int no_borrowed_books = 0, int no_lost_books = 0, int no_reserved_books = 0, float fine_amount = 0)
    {
        this->no_borrowed_books = no_borrowed_books;
        this->no_lost_books = no_lost_books;
        this->no_reserved_books = no_reserved_books;
        this->fine_amount = fine_amount;
    }

    void setBorrowedBooks(int i)
    {
        no_borrowed_books = i;
    }

    void setLostBooks(int i)
    {
        no_lost_books = i;
    }

    void setReservedBooks(int i)
    {
        no_reserved_books = i;
    }

    void setFineAmount(float i)
    {
        fine_amount = i;
    }

    int getBorrowedBooks() const
    {
        return no_borrowed_books;
    }

    int getLostBooks() const
    {
        return no_lost_books;
    }

    int getReservedBooks() const
    {
        return no_reserved_books;
    }

    float getFineAmount() const
    {
        return fine_amount;
    }
};
class User
{
protected:
    string name;
    int ID;

public:
    User(string name = "", int ID = 0)
    {
        this->name = name;
        this->ID = ID;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setID(int ID)
    {
        this->ID = ID;
    }

    string getName() const
    {
        return name;
    }

    int getID() const
    {
        return ID;
    }

    bool verify(string n, int id)
    {
        if (n != name || id != ID)
            return false;
        return true;
    }
};
class Staff : public User
{
private:
    string Dept;
    string Designation;
    Account A;
    vector<Book> B;

public:
    Staff(string Dept = "", string Designation = "", string name = "", int ID = 0) : User(name, ID)
    {
        this->Dept = Dept;
        this->Designation = Designation;
    }

    void IssueBook(string ISBN, LibraryDatabase &DB)
    {
        bool check = 0;
        for (int i = 0; i < DB.getSize(); i++)
        {
            if (ISBN == DB.getBookReference()[i].getISBN())
            {
                check = 1;
                if (DB.getBookReference()[i].getReservationStatus() == 0)
                {
                    cout << "Book not available to be issued " << endl;
                }
                else
                {

                    DB.getBookReference()[i].setReservationStatus(0);
                    DB.getBookReference()[i].setTime(112);
                    B.push_back(DB.getBookReference()[i]);
                    cout << "Book ISSUED" << endl;
                    A.setBorrowedBooks(A.getBorrowedBooks() + 1);
                }
            }
        }
        if (check == 0)
            cout << "Book not found in Database" << endl;
    }

    int DisplayReturndate()
    {
        return rand() % 113;
    }
    void showBook(string ISBN) // get book info
    {
        bool check = 0;
        for (int i = 0; i < B.size(); i++)
        {
            if (B[i].getISBN() == ISBN)
            {
                check = 1;
                cout << "ISBN : " << B[i].getISBN() << endl;
                cout << "Title : " << B[i].getTitle() << endl;
                cout << "Author name : " << B[i].getAuthor() << endl;
            }
        }
        if (check == 0)
            cout << "Book not found" << endl;
    }

    void BookLost()
    {
        A.setLostBooks(A.getLostBooks() + 1);
        A.setFineAmount(A.getFineAmount() + 500); // 500 dollar fine for losing a book
    }

    void reserveBook()
    {
        A.setReservedBooks(A.getReservedBooks() + 1);
    }

    void decreaseReserveBook()
    {
        A.setReservedBooks(A.getReservedBooks() - 1);
    }

    void Check_Account()
    {
        cout << "No of borrowed books are : " << A.getBorrowedBooks() << endl;
        cout << "No of lost books are : " << A.getLostBooks() << endl;
        cout << "No of reserved books are : " << A.getReservedBooks() << endl;
    }

    void returnBook(string ISBN, LibraryDatabase &DB)
    {
        bool check = 0;
        for (int i = 0; i < B.size(); i++)
        {
            if (ISBN == B[i].getISBN())
            {
                check = 1;
                B.erase(B.begin() + i);
                A.setBorrowedBooks(A.getBorrowedBooks() - 1);
                for (int j = 0; j < DB.getSize(); j++)
                {
                    if (DB.getBookReference()[j].getISBN() == ISBN)
                    {
                        DB.getBookReference()[j].setReservationStatus(!DB.getBookReference()[j].getReservationStatus());
                        DB.getBookReference()[i].setTime(0);
                    }
                }
                int temp;
                cout << "After how many days u are returning the book : ";
                cin >> temp;
                while (temp < 0)
                {
                    cout << "\nInvalid\nAfter how many days u are returning the book : ";
                    cin >> temp;
                }
                if (temp > 112)
                {
                    A.setFineAmount(A.getFineAmount() + (temp - 112) * 10); // 10 dollar fine for every one day late return
                    cout << "You got fine of " << (temp - 112) * 10 << "$ for returning the book late " << endl;
                }
            }
        }
        if (check == 0)
            cout << "Book not found " << endl;
        else
            cout << "Book returned" << endl;
    }

    void setDept(string Dept)
    {
        this->Dept = Dept;
    }

    void setDesignation(string Designation)
    {
        this->Designation = Designation;
    }

    string getDept() const
    {
        return Dept;
    }

    string getDesignation() const
    {
        return Designation;
    }
};

class Student : public User
{
private:
    string Batch;
    string Designation;
    Account A;
    vector<Book> B;

public:
    Student(string Batch = "", string Designation = "", string name = "", int ID = 0) : User(name, ID)
    {
        this->Batch = Batch;
        this->Designation = Designation;
    }

    // void CheckStudent()
    // {
    //     cout <<
    // }

    void IssueBook(string ISBN, LibraryDatabase &DB)
    {
        bool check = 0;
        for (int i = 0; i < DB.getSize(); i++)
        {
            if (ISBN == DB.getBookReference()[i].getISBN())
            {
                check = 1;
                if (DB.getBookReference()[i].getReservationStatus() == 0)
                    cout << "Book not available to be issued " << endl;
                else
                {
                    DB.getBookReference()[i].setReservationStatus(0);
                    DB.getBookReference()[i].setTime(14);
                    B.push_back(DB.getBookReference()[i]);
                    cout << "Book ISSUED" << endl;
                    A.setBorrowedBooks(A.getBorrowedBooks() + 1);
                }
            }
        }
        if (check == 0)
            cout << "Book not found in Database" << endl;
    }

    int DisplayReturndate()
    {
        return rand() % 15;
    }

    void showBook(string ISBN) // get book info
    {
        bool check = 0;
        for (int i = 0; i < B.size(); i++)
        {
            if (B[i].getISBN() == ISBN)
            {
                check = 1;
                cout << "ISBN : " << B[i].getISBN() << endl;
                cout << "Title : " << B[i].getTitle() << endl;
                cout << "Author name : " << B[i].getAuthor() << endl;
            }
        }
        if (check == 0)
            cout << "Book not found" << endl;
    }

    void Check_Account()
    {
        cout << "No of borrowed books are : " << A.getBorrowedBooks() << endl;
        cout << "No of lost books are : " << A.getLostBooks() << endl;
        cout << "No of reserved books are : " << A.getReservedBooks() << endl;
    }

    void BookLost()
    {
        A.setLostBooks(A.getLostBooks() + 1);
        A.setFineAmount(A.getFineAmount() + 500); // 500 dollar fine for losing a book
    }

    void reserveBook()
    {
        A.setReservedBooks(A.getReservedBooks() + 1);
    }

    void decreaseReserveBook()
    {
        A.setReservedBooks(A.getReservedBooks() - 1);
    }

    void returnBook(string ISBN, LibraryDatabase &DB)
    {
        bool check = 0;
        for (int i = 0; i < B.size(); i++)
        {
            if (ISBN == B[i].getISBN())
            {
                check = 1;
                B.erase(B.begin() + i);
                A.setBorrowedBooks(A.getBorrowedBooks() - 1);
                for (int j = 0; j < DB.getSize(); j++)
                {
                    if (DB.getBookReference()[j].getISBN() == ISBN)
                    {
                        DB.getBookReference()[j].setReservationStatus(!DB.getBookReference()[j].getReservationStatus());
                        DB.getBookReference()[i].setTime(0);
                    }
                }
                int temp;
                cout << "After how many days u are returning the book : ";
                cin >> temp;
                while (temp < 0)
                {
                    cout << "\nInvalid\nAfter how many days u are returning the book : ";
                    cin >> temp;
                }
                if (temp > 14)
                {
                    A.setFineAmount(A.getFineAmount() + (temp - 14) * 10); // 10 dollar fine for every one day late return
                    cout << "You got fine of " << (temp - 14) * 10 << "$ for returning the book late " << endl;
                }
            }
        }
        if (check == 0)
            cout << "Book not found " << endl;
        else
            cout << "Book returned" << endl;
    }

    void setBatch(string Batch)
    {
        this->Batch = Batch;
    }

    void setDesignation(string Designation)
    {
        this->Designation = Designation;
    }

    string getBatch() const
    {
        return Batch;
    }

    string getDesignation() const
    {
        return Designation;
    }
};

int main()
{
    // sir's test case
    //  LibraryDatabase DB;
    //  LibrarySystem L;
    //  L.createLibrarian();
    //  L.loginLibrarian();
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Titannic", "John", "1"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Inception", "Nolan", "2"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("1984", "Orwell", "3"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Hamlet", "Shakespeare", "4"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("The Alchemist", "Coelho", "5"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Sapiens", "Harari", "6"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("The Hobbit", "Tolkien", "7"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Dune", "Herbert", "8"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Frankenstein", "Shelley", "9"));
    //  L.getLibrarian()->AccessDB(DB)->AddBook(Book("Moby Dick", "Melville", "10"));

    // Student S1;
    // Student S2;
    // Staff S;
    // S1.IssueBook("1", DB);
    // S1.IssueBook("2", DB);
    // S2.IssueBook("3", DB);
    // S2.IssueBook("4", DB);
    // S2.IssueBook("5", DB);
    // S.IssueBook("6", DB);
    // S.IssueBook("7", DB);
    // cout << "Days Left to return the first book is :" << S1.DisplayReturndate() << endl;
    // cout << "Days Left to return the second book is :" << S1.DisplayReturndate() << endl;
    // S2.returnBook("4", DB);
    // S2.returnBook("5", DB);
    LibraryDatabase DB;
    LibrarySystem L;
    vector<Student> S;
    vector<Staff> staff;
    L.registerAdmin();
    L.loginAdmin();
    cout << "Now Create Librarian\n";
    L.createLibrarian();
    system("CLS");
    L.logoutAdmin();
    int choice;
    while (true)
    {
        cout << "1.Add Book\n2.IssueBook\n3.Return Book\n4.Display Book\n5.Delete Book\n6.Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 6)
        {
            cout << "Invalid \nEnter your choice again : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
        {
            L.loginLibrarian();
            cin.ignore();
            string title, author, ISBN;
            cout << "Enter Book title : ";
            getline(cin, title);
            cout << "Enter Book author : ";
            getline(cin, author);
            cout << "Enter Book ISBN : ";
            cin >> ISBN;
            while (ISBN[0]=='-')
            {
                cin.ignore();
                cout << "Invalid\nEnter Book ISBN : ";
                getline(cin, ISBN);
            }
            L.getLibrarian()->AccessDB(DB)->AddBook(Book(title, author, ISBN));
        }
        break;
        case 2:
        {
            int temp_choice;
            cout << "Press 1 to Issue book for student and 2 for Staff\n";
            cin >> temp_choice;
            while (temp_choice < 1 || temp_choice > 2)
            {
                cout << "Invalid \nEnter your choice again : ";
                cin >> temp_choice;
            }
            if (temp_choice == 1)
            {
                int NewOrOld;
                cout << "Issue Book for a new Student or an existing student (1 for new 2 for existing): ";
                cin >> NewOrOld;
                while (NewOrOld < 1 || NewOrOld > 2)
                {
                    cout << "Invalid \nEnter your choice again : ";
                    cin >> NewOrOld;
                }
                if (NewOrOld == 1)
                {
                    cin.ignore();
                    string batch, designation, name;
                    int ID;
                    cout << "Enter name of student : ";
                    getline(cin, name);
                    cout << "Enter batch of student : ";
                    getline(cin, batch);
                    while (batch[0]=='-')
                    {
                        cin.ignore();
                        cout << "Invalid\nEnter batch again : ";
                        getline(cin, batch);
                    }
                    
                    cout << "Enter designation of student : ";
                    getline(cin, designation);
                SameID:
                    cout << "Enter ID of student : ";
                    cin >> ID;
                    while (ID < 1)
                    {
                        cout << "Invalid \nEnter ID again :";
                        cin >> ID;
                    }
                    for (int i = 0; i < S.size(); i++)
                    {
                        if (ID == S[i].getID())
                        {
                            cout << "ID same as another Student : ";
                            goto SameID;
                        }
                    }
                    S.push_back(Student(batch, designation, name, ID));
                    string temp_ISBN;

                    cout << "Enter ISBN of Book to issue : ";
                    cin >> temp_ISBN;
                    while (temp_ISBN[0]=='-')
                    {
                        cin.ignore();
                        cout << "Invalid\nEnter Book ISBN : ";
                        getline(cin, temp_ISBN);
                    }
                    S[S.size() - 1].IssueBook(temp_ISBN, DB);
                }
                if (NewOrOld == 2)
                {
                    cin.ignore();
                    string temp_ISBN;
                    cout << "Enter ISBN of Book to issue : ";
                    cin >> temp_ISBN;
                    while (temp_ISBN[0]=='-')
                    {
                        cin.ignore();
                        cout << "Invalid\nEnter Book ISBN : ";
                        getline(cin, temp_ISBN);
                    }
                    int ID;
                    bool check = 0;
                    cout << "Enter ID of student to issue Book : ";
                    cin >> ID;
                    while (ID < 1)
                    {
                        cout << "Invalid \nEnter ID again :";
                        cin >> ID;
                    }
                    for (int i = 0; i < S.size(); i++)
                    {
                        if (ID == S[i].getID())
                        {
                            S[i].IssueBook(temp_ISBN, DB);
                            check = 1;
                        }
                    }
                    if (check == 0)
                        cout << "Student Not Found\n";
                }
            }
            if (temp_choice == 2)
            {
                int NewOrOld;
                cout << "Issue Book for a new Staff or an existing staff (1 for new 2 for existing): ";
                cin >> NewOrOld;
                while (NewOrOld < 1 || NewOrOld > 2)
                {
                    cout << "Invalid \nEnter your choice again : ";
                    cin >> NewOrOld;
                }
                if (NewOrOld == 1)
                {
                    cin.ignore();
                    string dept, designation, name;
                    int ID;
                    cout << "Enter name of staff : ";
                    getline(cin, name);
                    cout << "Enter dept of staff : ";
                    getline(cin, dept);
                    cout << "Enter designation of staff : ";
                    getline(cin, designation);
                SAMEID:
                    cout << "Enter ID of staff : ";
                    cin >> ID;
                    while (ID < 1)
                    {
                        cout << "Invalid \nEnter ID again :";
                        cin >> ID;
                    }
                    for (int i = 0; i < staff.size(); i++)
                    {
                        if (ID == staff[i].getID())
                        {
                            cout << "ID same as another Staff : ";
                            goto SAMEID;
                        }
                    }
                    staff.push_back(Staff(dept, designation, name, ID));
                    string temp_ISBN;
                    cout << "Enter ISBN of Book to issue : ";
                    cin >> temp_ISBN;
                    while (temp_ISBN[0]=='-')
                    {
                        cin.ignore();
                        cout << "Invalid\nEnter Book ISBN : ";
                        getline(cin, temp_ISBN);
                    }
                    staff[staff.size() - 1].IssueBook(temp_ISBN, DB);
                }
                if (NewOrOld == 2)
                {
                    cin.ignore();
                    string temp_ISBN;
                    cout << "Enter ISBN of Book to issue : ";
                    cin >> temp_ISBN;
                    while (temp_ISBN[0]=='-')
                    {
                        cin.ignore();
                        cout << "Invalid\nEnter Book ISBN : ";
                        getline(cin, temp_ISBN);
                    }
                    int ID;
                    bool check = 0;
                    cout << "Enter ID of staff to issue Book : ";
                    cin >> ID;
                    while (ID < 1)
                    {
                        cout << "Invalid \nEnter ID again :";
                        cin >> ID;
                    }
                    for (int i = 0; i < staff.size(); i++)
                    {
                        if (ID == staff[i].getID())
                        {
                            staff[i].IssueBook(temp_ISBN, DB);
                            check = 1;
                        }
                    }
                    if (check == 0)
                        cout << "Staff Not Found\n";
                }
            }
        }
        break;
        case 3:
            int temp_choice;
            cout << "Press 1 to return book for student and 2 for Staff\n";
            cin >> temp_choice;
            while (temp_choice < 1 || temp_choice > 2)
            {
                cout << "Invalid \nEnter your choice again : ";
                cin >> temp_choice;
            }
            if (temp_choice == 1)
            {
                int ID;
                bool check = 0;
                cout << "Enter ID of student to return Book : ";
                cin >> ID;
                while (ID < 1)
                {
                    cout << "Invalid \nEnter ID again :";
                    cin >> ID;
                }
                for (int i = 0; i < S.size(); i++)
                {
                    if (ID == S[i].getID())
                    {
                        check = 1;
                        string temp;
                        cout << "Enter ISBN of book to return : ";
                        cin >> temp;
                        S[i].returnBook(temp, DB);
                    }
                }
                if (check == 0)
                    cout << "Student with the given ID not found " << endl;
            }
            if (temp_choice == 2)
            {
                int ID;
                bool check = 0;
                cout << "Enter ID of staff to return Book : ";
                cin >> ID;
                while (ID < 1)
                {
                    cout << "Invalid \nEnter ID again :";
                    cin >> ID;
                }
                for (int i = 0; i < staff.size(); i++)
                {
                    if (ID == staff[i].getID())
                    {
                        check = 1;
                        string temp;
                        cout << "Enter ISBN of book to return : ";
                        cin >> temp;
                        staff[i].returnBook(temp, DB);
                    }
                }
                if (check == 0)
                    cout << "Staff with the given ID not found " << endl;
            }
            break;
        case 4:
        {
            L.loginLibrarian();
            cin.ignore();
            string temp;
            cout << "Enter ISBN of book to display : ";
            cin >> temp;
            L.getLibrarian()->AccessDB(DB)->DisplayBook(temp);
        }
        break;
        case 5:
        {
            L.loginLibrarian();
            cin.ignore();
            string temp;
            cout << "Enter ISBN of book to delete : ";
            cin >> temp;
            L.getLibrarian()->AccessDB(DB)->DeleteBook(temp);
        }
        break;
        case 6:
        {
            system("CLS");
            cout << "Thanks for using the system! ";
            exit(0);
        }
        break;
        }
    }
}
