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

Macro lasts until `#undef MACRO_NAME` preprocessor directive.
Function macro definitions accept two special operators (# and ##) in the replacement sequence
 - \## for concatination
 - \# for displaying string literal



Examples
```c++
#define getmax(a,b) a>b?a:b

#define ARRAY_SIZE 100

#define glue(a,b) a ## b // ## will concatinate two parameters
glue(c,out) << "test";

#define str(x) #x
cout << str(test);
cout << "test";

```

Predefined macro names
```c++
__LINE__	Integer value representing the current line in the source code file being compiled.
__FILE__	A string literal containing the presumed name of the source file being compiled.
__DATE__	A string literal in the form "Mmm dd yyyy" containing the date in which the compilation process began.
__TIME__	A string literal in the form "hh:mm:ss" containing the time at which the compilation process began. 
```

http://www.cplusplus.com/doc/tutorial/preprocessor/