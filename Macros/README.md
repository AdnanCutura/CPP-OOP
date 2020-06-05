# Macros

Part of the Preprocessor directives. Difference from templates is that templates get compiled later in compile-time depending on their calls.
Macros will replace the name with it's implementation right before compilation, since it's preprocessor directive.

Useful cases:
- The macro that bridges a gap between two C++ features
- The macro that shortens a redundant expression
- The macro that brings low-level polymorphism

```c++
#ifndef _DEBUG
#define Print(value) cout << value << endl
#else
#define Print(value)
#endif

int main(){

    Print(5);
    Print("My message");
}
```