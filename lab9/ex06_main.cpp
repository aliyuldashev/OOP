#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOK = 100;

class EBook
{
private:
    string title;
    string ISBN;
    double price;
    string DRMKey;
    string format;

public:
    EBook(const string &t, const string &i, double p, const string &dk = "", const string &f = "Kindle")
        : title(t), ISBN(i), price(p), DRMKey(dk), format(f) {}

    void ShowBookInfo() const
    {
        cout << "Title: " << title << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price(USD): " << price << endl;
        if (!DRMKey.empty())
        {
            cout << "DRMKey: " << DRMKey << endl;
            cout << "Format: " << format << endl;
        }
    }
};

class EBookLibrary
{
private:
    EBook *m_books[MAX_BOOK];
    int m_cnt;

public:
    EBookLibrary() : m_cnt(0) {}

    ~EBookLibrary()
    {
        for (int i = 0; i < m_cnt; ++i)
        {
            delete m_books[i];
        }
    }

    void AddBook(EBook *book)
    {
        if (m_cnt < MAX_BOOK)
        {
            m_books[m_cnt++] = book;
        }
    }

    void ShowAllBooks() const
    {
        for (int i = 0; i < m_cnt; ++i)
        {
            m_books[i]->ShowBookInfo();
            cout << endl;
        }
    }
};

int main()
{
    EBookLibrary elib;
    elib.AddBook(new EBook{"Book1", "1234567890", 10.99, "AAAAAA", "ePub"});
    elib.AddBook(new EBook{"Book2", "2345678901", 20.99, "BBBBBB"});
    elib.AddBook(new EBook{"Book3", "3456789012", 30.99, "CCCCCC", "ePub"});
    elib.AddBook(new EBook{"Book4", "4567890123", 40.99, "DDDDDD"});
    elib.ShowAllBooks();

    return 0;
}
