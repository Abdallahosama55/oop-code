# oop-code
#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
using namespace std;
int main()
{
    UserList l(0);//userlist
    BookList l2(0);//booklist
    string s;//search by name
    int x;
    User u;//user
    Book b;//book
    int choose;//any cin from user
    int capBook = 0, capUser=0;//capacity of user and book
    while (true)
    {
        cout << "Select one of the following choices:\n1- Books Menu\n2- User Menu\n3- Exit\n";
        cin >> choose;
         if (choose==1)
         {
             cout << "How many books will be added?\n";
             cin >> capBook;
              l2.setCap(capBook);
             while (true)
             {
                 cout << "BOOKS MENU\n1- Create a book and add it to the list\n2- Search for a book\n3- Display all books (with book rating)\n4- Get the highest rating book\n5- Get all books of a user\n6- Copy the current Book list to a new Book list and switch to it\n7- Back to the main menu\n";
                 cin >> choose;
                 if (choose==1)
                 {
                     cout << "Enter the book information in this order\nTitle   ISBN    Category(Space Separated)\n";
                     cin >> b;
                     l2.addBook(b);
                     while (true)
                     {
                         cout << "1- Assign author\n2- Continue\n";
                         cin >> choose;
                         if (choose == 1)
                         {
                                cout << "Enter author(user) id:\n";
                                int userid;
                                 cin >> userid;
                                 l.searchUser(userid);

                                 if (l.searchUser(userid).getName() == "")
                                 {

                                     cout << "No author found with id = " << userid << endl;

                                 }

                                 else
                                 {
                                     l2[l2.GetbooksCount() - 1].setAuthor(l.searchUser(userid));
                                     break;
                                 }

                         }
                         else if (choose == 2)
                         {
                            break;
                         }
                     }

                 }
                 else if (choose == 2)
                 {
                     cout << "1- Search by Name\n2- Search by Id\n3- Return to Books Menu\n";
                     cin >> choose;

                     if (choose==1)
                     {

                         cout << "Enter Name\n";
                         cin >> s;
                         cout<<l2.searchBook(s);

                         while (true)
                         {
                             cout << "1- Update Auther\n2- Update Name\n3- Update Category\n4- Delete book\n5- Rate book\n6- Get back to book menu\n";
                             cin >> choose;
                             if (choose == 1)
                             {
                                 while (true)
                                 {
                                     cout << "Enter author(user) id\n";
                                     int userid;
                                     cin >> userid;
                                     l.searchUser(userid);

                                     if (l.searchUser(userid).getName() == "")
                                     {

                                         cout << "no author found with id" << userid << endl;
                                     }

                                     else
                                     {
                                         l2[l2.GetbooksCount() - 1].setAuthor(l.searchUser(userid));
                                         break;
                                     }
                                 }
                             }
                             else if (choose == 2)
                             {
                                 cout << "Enter new Name:\n";
                                 string name;
                                 cin >> name;
                                 cout << "\n";
                                 l2.searchBook(s).setTitle(name);
                                 s = name;
                             }
                             else if (choose == 3)
                             {
                                 cout << "Enter new Category:\n";
                                 string name;
                                 cin >> name;
                                 cout << "\n";
                                 l2.searchBook(s).setCategory(name);
                             }
                             else if (choose == 4)
                             {
                                 l2.deleteBook(l2.temp);
                             }
                             else if (choose == 5)
                             {
                                 float y;//new rate
                                 cout << "Enter rating value:\n";
                                 cin >> y;
                                 l2.searchBook(s).rateBook(y);
                             }
                             else if (choose == 6)
                             {
                                 break;
                             }
                         }

                     }
                     else if (choose==2)
                     {

                         cout << "Enter Id\n";
                         cin >> x;
                         cout << l2.searchBook(x);

                         while (true)
                         {
                             cout << "1- Update Auther\n2- Update Name\n3- Update Category\n4- Delete book\n5- Rate book\n6- Get back to book menu\n";
                             cin >> choose;
                             if (choose == 1)
                             {
                                 while (true)
                                 {
                                     cout << "Enter author(user) id\n";
                                     int userid;
                                     cin >> userid;
                                     l.searchUser(userid);

                                     if (l.searchUser(userid).getName() == "")
                                     {

                                         cout << "no author found with id" << userid << endl;
                                     }

                                     else
                                     {
                                         l2[l2.GetbooksCount() - 1].setAuthor(l.searchUser(userid));
                                         break;
                                     }
                                 }
                             }
                             else if (choose == 2)
                             {
                                 cout << "Enter new Name:\n";
                                 string name;
                                 cin >> name;
                                 cout << "\n";
                                 l2.searchBook(x).setTitle(name);
                             }
                             else if (choose == 3)
                             {
                                 cout << "Enter new Category:\n";
                                 string name;
                                 cin >> name;
                                 cout << "\n";
                                 l2.searchBook(x).setCategory(name);
                             }
                             else if (choose == 4)
                             {
                                 l2.deleteBook(l2.temp);
                             }
                             else if (choose == 5)
                             {
                                 float y;//new rate
                                 cout << "Enter rating value:\n";
                                 cin >> y;
                                 l2.searchBook(x).rateBook(y);
                             }
                             else if (choose == 6)
                             {
                                 break;
                             }
                         }

                     }
                     else if (choose == 3)
                     {

                     }
                 }
                 else if (choose==3)
                 {
                     cout << l2;
                 }
                 else if (choose==4)
                 {
                 cout<<l2.getTheHighestRatedBook();
                 }
                 else if (choose == 5)
                 {
                 cout << "Enter user ID\n";
                 cin >> choose;
                 l2.getBooksForUser(l.searchUser(choose));
                 }
                 else if (choose==6)
                 {
                 cout << "copied current list(" << l2.GetbooksCount() << " books)to a new list and switched to it\n";

                 }
                 else if (choose == 7)
                 {
                 cout << "===============================================\n";
                 break;
                 }
             }
             }

        if (choose == 2)
        {
            cout << "How many users will be added?\n";
            cin >> capUser;
            l.setCap(capUser);
            while (true)
            {
                cout << "USER MENU\n1- Create a USER and add it to the list\n2- Search for a user\n3- Display all users\n4- Back to Main Menu\n";
                cin >> choose;
                if (choose == 1)
                {
                    cout << "Enter the user information in this order\nName Age Email Password(Space Separated)\n";
                    cin >> u;
                    l.addUser(u);
                }
                else if (choose == 2)
                {
                    while (true)
                    {
                        cout << "SEARCH FOR A USER\n";
                        cout << "1- Search by Name\n2- Serch by Id\n3- Return to Users Menu\n";
                        cin >> choose;
                        if (choose == 1)
                        {
                            cout << "Enter Name\n";
                            cin >> s;
                            l.searchuser(s);
                            cout << "\n";
                            cout << "1- Delete user\n2- Return to Users Menu\n";
                            cin >> choose;
                            if (choose==1)
                            {
                                l.deleteUser(l.temp);
                            }
                            else if (choose == 2)
                            {
                                break;
                            }

                        }
                        else if (choose == 2)
                        {
                            cout << "Enter Id\n";
                            cin >> choose;
                            l.searchuser(choose);
                            cout << "1- Delete user\n2- Return to Users Menu\n";
                            cin >> choose;
                            if (choose == 1)
                            {
                                l.deleteUser(l.temp);
                            }
                            else if (choose == 2)
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }

                    }

                }
                else if (choose==3)
                {
                    cout << l;

                }
                else if (choose == 4)
                {


                    cout << "===============================================\n";
                    break;
                }

            }
        }

        else if (choose == 3)
        {
            break;
        }


    }
}

