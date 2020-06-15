## Basic functions
Symbol that we call when we want something to happened.
Could not be passed as parameter and couldn't be assinged as variables.

## Function pointers
Could be used as parameters.

## Lambda
Anonymous function. Quick disposable function, treated more like variable than like a function.
-
```c++
[captures](params){body}
```
With lambda we are defining a function that we are going to call later. If we want to put variables that are outside lambda function we have to capture them.

`[captures]` - a comma-separated list of zero or more captures

**Capture list**:
- [a, &b] - a is captured by copy, b is captured by reference
- [this] - captures the current object (*this) by reference
- [&] - captures all variables used in the body of the lambda by reference and current object by reference if exists
- [=] - captures all variables used in the body of the lambda by copy and current object by reference if exist
- [] -  captures nothing