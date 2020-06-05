# lvalues
Variables with storage.
lvalue reference can only take lvalues.
```c++
// lvalue reference as a argument
void PrintName(string& name){cout << name << endl;}
```

# rvalues
Temporary values
rvalue reference can only take rvalues.
```c++
// rvalue reference as a argument
void PrintName(string&& name){cout << name << endl;}
```

----
# Additional
```c++
// can contain lvalues and also rvalues
void PrintName(const string& name){cout << name << endl;}
```
