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

* ```#pragma once``` - is a non-standard but widely supported preprocessor directive designed to cause the current source file to be included only once in a single compilation.
