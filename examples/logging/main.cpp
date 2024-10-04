/**
 * Example of how to redirect std::cout to write to both the terminal and a log file.
 */

#include <iostream>
#include <fstream>
#include <streambuf>

// Custom streambuf that writes to two streambufs (one for cout and one for a file)
class dual_streambuf : public std::streambuf {
public:
    dual_streambuf(std::streambuf* buf1, std::streambuf* buf2)
        : m_buf1(buf1), m_buf2(buf2) {}

protected:
    virtual int overflow(int c) override {
        if (c == EOF) {
            return !EOF;
        } else {
            // Send the character to both streambufs
            int result1 = m_buf1->sputc(c);
            int result2 = m_buf2->sputc(c);
            return (result1 == EOF || result2 == EOF) ? EOF : c;
        }
    }

    virtual int sync() override {
        int result1 = m_buf1->pubsync();
        int result2 = m_buf2->pubsync();
        return (result1 == 0 && result2 == 0) ? 0 : -1;
    }

private:
    std::streambuf* m_buf1;
    std::streambuf* m_buf2;
};

int main() {
    // Open a log file
    std::ofstream log_file("log.txt");

    // Save the original streambuf of std::cout
    std::streambuf* cout_buf = std::cout.rdbuf();

    // Create a dual streambuf to write to both cout and the log file
    dual_streambuf dual_buf(cout_buf, log_file.rdbuf());

    // Redirect std::cout to use the dual streambuf
    std::cout.rdbuf(&dual_buf);

    // Now anything sent to std::cout will go to both the terminal and the log file
    std::cout << "This will appear in both the terminal and the log file!" << std::endl;

    // Restore the original streambuf for std::cout
    std::cout.rdbuf(cout_buf);

    return 0;
}
