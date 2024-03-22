#include <iostream>
#include <string>

using namespace std;

class Book
{
protected:
    string title;
    string ISBN;
    double price;

public:
    Book(const string &t, const string &i, double p) : title(t), ISBN(i), price(p) {}

    void ShowBookInfo() const
    {
        cout << "Title: " << title << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price(USD): " << price << endl;
    }
};

class EBook : public Book
{
private:
    string DRMKey;
    string format;

public:
    EBook(const string &t, const string &i, double p, const string &dk, const string &f)
        : Book(t, i, p), DRMKey(dk), format(f) {}

    void ShowEBookInfo() const
    {
        ShowBookInfo(); // Reuse the base class function

        cout << "DRMKey: " << DRMKey << endl;
        cout << "Format: " << format << endl;
    }
};

int main()
{
    Book book("Modern C++ Programming Cookbook", "1800208987", 49.99);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Modern C++ Programming Cookbook (ebook)", "1800208987", 34.99, "dkb34x!@*~", "Kindle");
    ebook.ShowEBookInfo();

    return 0;
}
