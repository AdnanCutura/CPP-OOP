# Templates

**Templates** are not actually a functions, they are just blueprints for creating a new functions. They are created or not depending on the template call. If there are no calls, the template will not be included after compiling in source code, it will not exist.

When we call it, based on how we call it it wil create a function, so it will copy this template and create separate functions for each types eg. int, string, float, const char* etc.

To prove previously claims, we can create a function and a template for logging.


```c++

//Method overloads
void Log(int value){ cout << value << endl;}
void Log(string value){ cout << value << endl;}

//Template
template<typename T> // or template<class T>
void LogTemplate(T value){ cout << value << endl;}

```

If we try to get the address of the templates and functions and templates above, we will get expected addresses from functions `Log`, but there will not be template address.

Template will actually create, for every different type used as parameter in template call, a new function.
```c++

// Implicitly calls
LogTemplate(5); // void LogTemplate(int value) will be created
LogTemplate("Log me this!"); // void LogTemplate(const char* value) will be created

// Explicitly calls
LogTemplate<float>(3.1); // void LogTemplate(float value) will be created
LogTemplate<string>("Log this warning."); // void LogTemplate(string value) will be created
```

Examples:
```c++
// Get max template
template <typename T>
T GetMax(T value1, T value2){
  return (a > b ? a : b);
}

// Get min template
template <typename T, typename U>
T GetMin(T value1, U value2){
  return (a > b ? a : b);
}

// Array class templated  
template <typename T, int N>
class Array {
private:
   T _array[N];
public:
   N GetSize {return N;}
}

```

https://www.fluentcpp.com/2019/05/14/3-types-of-macros-that-improve-c-code/