## Fundamentals

### Vector

### Templates

### Classes, Structs

#### Transaction struct
  [**SOURCE**](https://eosio.stackexchange.com/questions/102/can-someone-explain-the-transaction-struct?rq=1)

## EOSIO fundamentals
* #### use of single colon ':'
  The single colon could also signify class inheritance, if the class declaration is followed by : and a class name, it means the class derives from the class behind the single colon.
    ```
    class InheritedClass : public BaseClass    // In Java, ':' replaced by 'extends'
    {
        // code
    };
    ```
  In my example, **InheritedClass** would be able to use methods and properties from **BaseClass** freely, and so would objects created from **InheritedClass** be able to do as well.
  
  [**SOURCE**](http://www.cplusplus.com/forum/beginner/235722/)
  [**other usages**](http://www.cplusplus.com/forum/beginner/235722/#msg1056281)

* ```#pragma once``` - is a non-standard but widely supported preprocessor directive designed to cause the current source file to be included only once in a single compilation.

* #### extern "C"
  In short, we can say

  1. Declaration can be done any number of times but definition only once.
  2. “extern” keyword is used to extend the visibility of variables/functions().
  3. Since functions are visible through out the program by default. The use of extern is not needed in function declaration/definition. Its use is redundant.
  4. When extern is used with a variable, it’s only declared not defined.
  5. As an exception, when an extern variable is declared with initialization, it is taken as definition of the variable as well.

  [**In detail**](https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/)
  
  ```cpp
  #ifdef __cplusplus
  extern "C" {
  #endif
  ....
  ....
  ...

  #ifdef __cplusplus
  }
  #endif
  ```
  **Explanation:** [**Read this first**](https://www.geeksforgeeks.org/extern-c-in-c/) 
  
  [**SOURCE**](https://stackoverflow.com/questions/3789340/combining-c-and-c-how-does-ifdef-cplusplus-work)
  
* #### Name mangling
  Why do we use ```extern "C"```
  
  [**SOURCE**](https://www.quora.com/Why-do-we-use-extern-C)
  
  #### Note that "extern" and "extern "C" " are two distinct things...
  
  
