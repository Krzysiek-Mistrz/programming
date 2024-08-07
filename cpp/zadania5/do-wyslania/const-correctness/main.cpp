#include <cstdlib>
 
class Cls {
public:
    Cls(int x, int y) : x_(x), y_(y) {}  // lista inicjalizacyjna konstruktora:
                                         //   przypisz wartość x do pola x_ (x_ = x;)
    int get_x() const { return x_; }
    int get_y() const { return y_; }    //uwaga -> bo atrybuty stalego obiektu musza byc stale :)
private:
    int x_;
    int y_;
};
 
void dont_modify(const Cls& c) {
    c.get_y();
}
 
int foo(const Cls& c) {
    // "Wiedza projektowa":
    //      foo() wystarczy dostęp do `c` w trybie "tylko do odczytu".
    return c.get_x();
}
 
int bar(const Cls& c) {
    // "Wiedza projektowa":
    //      bar() wystarczy dostęp do `c` w trybie "tylko do odczytu".
    return 2 * foo(c);
}
 
int main() {
    Cls c(1, 2);
    bar(c);
 
    return EXIT_SUCCESS;
}