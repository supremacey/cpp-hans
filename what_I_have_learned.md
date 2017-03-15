## C++ Lab 
This is a small collection of thouhts I have after task assessment. Mostly about bugs and how to prevent them.

### Lab 01
- nope, nothing at all :P

### Lab 02
- Don't try to be smart and check the rational number sign by (denum * enum) < 0 -> this may lead to int overflow
- GCD with module can handle the numbers no mather their order

### Lab 03
- Look carefully what functions does inside them (if you can), or what is complexity of those things. This can save you from duplicationg work by your own or using the better solution (like `ensure_capacity` function which was not the best sollution)
- Whatch out when you call new and delete and when you access the memory. Though it sounds painfully obvious, you cannot access the memory before you allocate it.
- When you declare friend functions you can either inline them in header file or declare them in CPP file. In the first case use keyword 'inline' when defining them outside class bodu. In CPP file don't include class access specifier -> you don't need it, since the function is not clas method.
