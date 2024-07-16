# C++ Basic Input/Output

When you embark on your C++ programming journey, it's advisable to initially focus on grasping the big picture and building a strong foundation. In this guide, we'll walk you through the basic skeleton of a C++ program and the essential components you need to know to get started.

## Including Libraries

C++ is a versatile language that relies on libraries to access various functionalities. To perform tasks like input and output, we include specific libraries at the beginning of our code. For instance, `#include<iostream>` is used for input and output operations.

## The Generic Skeleton

The generic skeleton of a C++ program consists of two main components: the library inclusion and the main function. After including the necessary libraries, you declare the main function using `int main() { /* Your code here */ return 0; }`. This serves as the entry point for your program.

```cpp
#include<iostream>

int main() {
    // Your code here
    return 0;
}
```

## Output with `cout`

To display output in C++, you'll commonly use the `cout` function from the `iostream` library. However, you need to specify that it belongs to the `std` (standard) namespace. For instance, `std::cout << "Hey, Onkar!";` will print "Hey, Onkar!" to the console. You enclose the text you want to display within double quotation marks.

```cpp
#include<iostream>

int main() {
    std::cout << "Hey, Onkar!";
    return 0;
}
```

**Output**:

```cpp
Hey, Onkar!
```

If you want to print **"Hey, Onkar!"** twice in 2 lines using C++, you can achieve this by using the `cout` function along with the newline character (`\n`).

```cpp
#include<iostream>

int main() {
    std::cout << "Hey, Onkar!" << "\n";
    std::cout << "Hey, Onkar!";
    return 0;
}
```

## Printing "Hey, Onkar!" Twice in 2 Lines

IFf we want to print Hey, Onkar! twice in 2 lines and we write `std::cout << "Hey, Onkar!";` again and again then it will print it consecutively on the same line.

```cpp
#include<iostream>

int main() {
    std::cout << "Hey,
Onkar!";
    std::cout << "Hey,
Onkar!";
    return 0;
}
```

**Output**:

```cpp
Hey,Onkar!Hey,Onkar!
```

If you want to print "Hey, Onkar!" twice in 2 lines using C++, you can achieve this by using the `cout` function along with the newline character (`\n`).

```cpp
#include<iostream>

int main() {
    std::cout << "Hey, Onkar!" << "\n";
    std::cout << "Hey, Onkar!";
    return 0;
}
```

**Output**:

```cpp
Hey, Onkar!
Hey, Onkar!
```

In this example, `std::cout` is used to output the string **"Hey, Onkar!"** followed by a newline (`\n`) to move to the next line, and then output it again on the subsequent line.

## Using std::endl for Line Breaks

You can also use std::endl to insert a newline character and flush the output buffer. Here's the code and its corresponding terminal output:

```cpp
#include<iostream>

int main() {
std::cout << "Hey, Onkar!" << std::endl;
std::cout << "Hey, Onkar!";
return 0;
}
```

**Output**:

```cpp
Hey, Onkar!
Hey, Onkar!
```

## Efficiency of Line Breaks in C++ Output

## Efficiency of Line Breaks in C++ Output

- Using `\n` for line breaks in C++ is a common and efficient way to achieve the desired output. It's a simple and straightforward approach, and it's typically faster than other methods for adding line breaks, such as using `std::endl`.

- The reason for this efficiency is that `\n` is a simple escape sequence that inserts a newline character. This operation is low-level and directly moves the cursor to the beginning of the next line in the output.

- On the other hand, `std::endl` not only adds a newline character but also flushes the output buffer. Flushing the buffer can be a more costly operation in terms of performance, especially when you're printing a large amount of text.

In summary, using `\n` is preferred for most cases where you simply need to insert a line break in your output, as it provides a faster and efficient way to achieve this without the overhead of buffer flushing.

## Using using namespace std

By adding `using namespace std;` at the beginning of your program, you're telling the compiler that you want to use all the names from the std namespace without explicitly specifying `std::` each time. This can make your code cleaner and more concise.

```cpp
Copy code
#include<iostream>
using namespace std;

int main() {
cout << "Hey, Onkar!" << "\n";
cout << "Hey, Onkar!";
return 0;
}
```

**Output**:

```cpp
Hey, Onkar!
Hey, Onkar!
```

Using `using namespace std;` is a useful shortcut for simplifying your C++ code, especially when you're learning the language and writing smaller programs. It helps **_reduce clutter_** and makes your **_code more readable_**. However, as your programming projects grow in complexity, consider using it sparingly to avoid potential naming conflicts.

## Taking User Input using cin

One of the fundamental aspects of programming is taking input from the user. In C++, this is achieved with the help of the cin stream, which allows you to receive input from the user via the terminal or console.

CODE:

```cpp
#include<iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    cout << "Value of x: " << x;
    return 0;
}
```

**Input**:

```cpp
10
```

**Output**:

```cpp
Value of x: 10
```

When you run this program and enter a value (e.g., 10) in the terminal, cin captures that value, stores it in the variable x, and then displays it using cout.Here's how it works:

- The program waits for user input.
- You enter a value (e.g., 10) and press Enter.
- cin reads the entered value and stores it in the variable x.
- cout then displays the value of x.

To accept multiple inputs, you can use the `>>` operator with cin for each variable you want to receive input for. Let's demonstrate this by taking two variables, x and y, as input and displaying their values:

```cpp
#include<iostream>
using namespace std;

int main() {
    int x;
    int y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
    return 0;
}
```

**Input**:

```cpp
10 20
```

**Output**:

```cpp
Value of x: 10 and y: 20
```

When you run this program, it waits for two separate inputs from the user, which should be entered one after the other, separated by spaces or Enter key presses. Here's how it works:

- The program waits for the first input (for x).
- You enter a value (e.g., 10) and press Enter.
- cin reads and stores the value in x.
- The program then waits for the second input (for y).
- You enter another value (e.g., 20) and press Enter.
- cin reads and stores this value in y.

## Including All Standard Libraries with #include<bits/stdc++.h>

To include almost all standard libraries at once, you can use `#include<bits/stdc++.h>`. This header is a shortcut that includes a vast number of standard C++ libraries, making it easier to access a wide range of functions and classes without specifying each library individually.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    int y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
    return 0;
}
```

**Input**:

```cpp
10 20
```

**Output**:

```cpp
Value of x: 10 and y: 20
```
