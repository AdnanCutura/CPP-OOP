# Polymorphism

## Virutal constructors
**Virutal constructors** are used when we instantiate a pointer of class `Base` to `Derived` class. In this scenario when we delete the object, if we don't declare the destructor to virutal, the `Derived` destructor will not be called. Eventually there will be a **memory leak** problem.
```c++
virtual ~Base(){/*dealocating*/}
```
**Call stack without** virtual constructor
- Entity Constructor
- Player Constructor
- Entity Destructor

In the next line is presented the situation when we need a virtual constructor. The base class is `Entity` and derived class is `Player`. `Entity` must have a virtual constructor.
```c++
Entity* polyBase = new Player("Adnan");
```
`!` Virtual destructor do not behave like a virtual functions. Derived destructor will not override Base destructor, after executing the Derived destructor, the Base destructor will also be executed.

**Call stack with** virtual constructor
- Entity Constructor
- Player Constructor
- Player Destructor
- Entity Destructor

Classic `C` casts make no distinction between what we call `static_cast<>()`, `reinterpret_cast<>()`, `const_cast<>()`, and `dynamic_cast<>()`

## Dynamic cast

**Dynamic_cast** ensuring that cast is valid. Evaluated in runtime and does like a function rather that only a cast, because it also validating casting.
Cast from dereived to base type, or from derived to base class.

``` c++
dynamic_cast <new-type> ( expression ) 		
```
**New-type** could be
- pointer to complete class tpye,
- reference to complete class type
- pointer to void

If cast is successful, `dynamic_cast` will **return** a *value of type new-type*, otherwise it will return *null pointer* of that type. If cast fails, and the New-type was reference, it will throw an exception that match a handler of type `std::bad_cast`.

How does it know derived type?
Stores Run-Time Type Information (RTTI) https://en.wikipedia.org/wiki/Run-time_type_information
It is useful when the dynamic type is not known, so we have to do runtime check to ensure valid casting.

https://en.cppreference.com/w/cpp/language/dynamic_cast
## Static cast


**Static_cast** is unary operator. It forces the converstion from one data type to another. This cast is the simpliest type of cast and it's **compile-time** cast.
c++

It does casting like implicit conversions between types (int to float, ptr to void**), and for implicitly/explicitly function conversion. Static cast doesn't perform runtime checks, it should be used if those checks are unnecessary.


```c++
static_cast <new_type> (expression) 		
```
**Returns** a value of type *new_type*.

Examples
```c++
// Float to int conversion
int n = static_cast<int>(3.14); 

// int to vector conversion, this will allocate vector with size 10
vector<int> v = static_cast<vector<int>>(10);

// static downcast
Derived d;
Base& b = d;
D& d1 = static_cast<D&>(br);_
```

# Reinterpret cast

**Reinterpret_cast** is used when we need to cast pointers to objects whose have not any relations
Uses when we need to interact with some datasource on which we can not affect with implementation, but we only need to adapt to it.
```c++
struct S { int x; int y; };
struct T { int x; int y; int f(); };

S* s = new S();
s->x = 5;
s->y = 8;

T* t = reinterpret_cast<T*>(s);
cout << t->x << t->y << endl; //this will print 5 and 8 
```
# Const cast

**Const_cast** is used in cases when we need to cas a constant value, where we ignoring the constant behaviour.
```c++
const int j = 3; // j is declared const

//static_cast cannot cast away const or other type qualifiers
int* pj = const_cast<int*>(&j); 
```