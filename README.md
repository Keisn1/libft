![](cover-libft-bonus.png)

# What is libft

`Libft` is the continuiation of what students learned in their
[42piscine](https://github.com/Keisn1/C-piscine-42), the initial
qualification phase for the school.

`Libft` is a project where students build their very first C library.
The students learn more about the infrastructure and organization of C.
They learn about **static libraries**, what they are, how they are
compiled, and how others can use them. Furthermore, the students gain
hands-on experience with Makefiles in order to build their library.

The library itself is a collection of functionality mostly focused on
input/output operations, but it also includes memory manipulation and an
implementation of a `linked list`. Throughout the course, it will serve
as a replacement for `stdio`, and the students are required to use it
and expand it for further use
([ft\_printf](https://github.com/Keisn1/ft_printf),
[get-next-line](https://github.com/Keisn1/get-next-line)).

Moreover, the students are exposed to extensive testing and are required
to test their code at a very early stage. In that sense, it is just a
continuation of what they were already exposed to during the piscine.
The moulinette is a very meticulous program that every student needs to
submit their code to. This teaches the students to be extremely rigorous
and attentive to detail at a very early stage.

The most important aspect of `libft` is that it is the first project at
the school. Students get to know their peers and will perform peer
evaluations from day one. This exposure to other people's code and
discussions about code and ideas is what makes the school special. They
learn to discuss their code so that others can understand them, forcing
them to think about the other' perpective. They learn to formulate their
ideas concisely and comprehensibly from the first day. Moreover, they
develop the habit to ask their peers for help if they are not able to
advance by themselves, which in turn teaches everybody to teach code and
make it understandable.

# Makefile and GoogleTests

During this project, I've begun to familiarize myself with GoogleTest.
It is essential for 42 students to test their code, and since I really
like Test Driven Development methodologies, I was eager to get to know
and use a testing framework for `C/C++`. I've already gained a lot of
experience in Test Driven Development through courses and books
([3.1](#TestDriven.io),\[\[\#\*[Learn go with
tests](https://quii.gitbook.io/learn-go-with-tests)\]\[3.2\]\]) and
personal projects
(\[\[\#\*[nand-to-tetris-in-go](https://github.com/Keisn1/nand-to-tetris-in-go)\]\[3.3\]\]).
In fact, I think that completing the 42 cursus is a perfect opportunity
to become proficient with a testing framework and at testing in general.

# References

## TestDriven.io

  - [Building Your Own Python Web
    Framework](https://testdriven.io/courses/python-web-framework/)
  - [Test-Driven Development with Django, Django REST Framework, and
    Docker](https://testdriven.io/courses/tdd-django/)
  - [Developing a Real-Time Taxi App with Django Channels and
    React](https://testdriven.io/courses/taxi-react/)
  - [Creating an HTTP Load Balancer in
    Python](https://testdriven.io/courses/http-load-balancer/)

## [Learn go with tests](https://quii.gitbook.io/learn-go-with-tests)

## [nand-to-tetris-in-go](https://github.com/Keisn1/nand-to-tetris-in-go)

# Mandatory part

| **Program name**   | libft.a                                                                                      |
| ------------------ | -------------------------------------------------------------------------------------------- |
| Turn in files      | Makefile, libft.h, ft\_\*.c                                                                  |
| Makefile           | <span class="underline">NAME</span>, all, clean, fclean, re                                  |
| External Functions | write, malloc, free                                                                          |
| Description        | Write your own library: a collection of functions that will be a useful tool for your cursus |
| Library            |                                                                                              |
| stdlib             | ft\_isalpha, ft\_isdigit, ft\_isalnum, ft\_isascii, ft\_isprint, ft\_toupper,                |
|                    | ft\_tolower, ft\_itoa, ft\_atoi                                                              |
| string             | ft\_strlen, ft\_strlcpy, ft\_strlcat, ft\_strncmp, ft\_strnstr                               |
|                    | ft\_strchr, ft\_strrchr, ft\_bzero                                                           |
|                    | ft\_memset, ft\_memchr, ft\_memcpy, ft\_memcmp, ft\_memmove                                  |
|                    | ft\_substr, ft\_strjoin, ft\_strtrim, ft\_strmapi, ft\_striteri, ft\_split                   |
|                    |                                                                                              |
| stdio              | ft\_putchar\_fd, ft\_putstr\_fd, ft\_putendl\_fd, ft\_putnbr\_fd                             |
|                    |                                                                                              |
| list               | ft\_lstnew, ft\_lstadd\_front, ft\_lstsize, ft\_lstlast                                      |
|                    | ft\_lstadd\_back, ft\_lstdelone, ft\_lstclear, ft\_lstiter, ft\_lstmap                       |
