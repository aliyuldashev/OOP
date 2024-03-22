#include <iostream>
using namespace std;
class Secure {
    string m_m;
    string m_p;
    int m_a;
public:
    Secure(const char* m, const char* p, int a) :  m_a { a }
        {
        m_m = m;
        m_m += "\n";

        m_p = p;
    }
    string read(const char* p) {
        if (m_a = 0) {
            string out = "Can't try anymore. Message and Password have been reset.";
            m_p = "_";
            m_m = "_";
        }
        string out = "Password does not match. You have " + to_string(m_a);
        out += " more time(s) to try\n";
        if (p == m_p) {
            return m_m;
            m_m += "\n";

        }
        else { 
            m_a--;
            return out;
        }
    }
    void updateMessage(const char* m, const char* p) {
        if (p == m_p) {
            m_m = m;
        }
    }
    void changePassword(const char* p1, const char* p) {
        if (p == m_p) {
            m_p = p1;
        }
    }

};
int main() {
    int i;
    // Secure{message, password, maximum # of attempts}
    //   message: "Welcome Inha University"
    //   password: "2022Fall"
    //   maximum # of attempts: 3 
    //    <- the stored message and password will be destroyed if wrong password used 3 times
    Secure secuMessage{ "Welcome Inha University", "2022Fall", 3 };

    for (i = 0; i < 2; ++i) {
        // Secure::read(password) <- function to read the stored message
        // return the stored message if the password matched, otherwise return ""
        cout << secuMessage.read("2022Spring"); // wrong password
    }
    // The maximum # of attempts(3) will be recovered if the password is correct
    cout << secuMessage.read("2022Fall") << endl; // correct password
    // Secure::updateMessage(newMessage, password) <- function to change the message
    // the 'newMessage' will be stored if the password matched
    secuMessage.updateMessage("Welcome Incheon Korea", "2022Fall"); // correct password
    cout << secuMessage.read("2022Fall") << endl; // correct password
    // Secure::changePassword(old_password, new_password) <- function to change the password
    // The old password will be replaced with the 'new_password' if the password matched 
    secuMessage.changePassword("2022Fall", "EasyPass");
    cout << secuMessage.read("EasyPass") << endl; // correct password

    for (i = 0; i < 3; ++i) {
        cout << secuMessage.read("2022Fall"); // wrong password
    }
    cout << "After the password and message are reset..." << endl;
    cout << secuMessage.read("EasyPass"); // password reset, old password(==wrong password)
    cout << "End of the program";

    return 0;
}
