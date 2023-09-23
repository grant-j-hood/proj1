[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Iqju0K0v)

# Project 1

Please read these instructions carefully before starting the project.

## Honor Code

You must work independently on this assignment. Please review the statement in
the syllabus.

## Objectives

The main goals of this assignment are to gain familiarity with Abstract Data
Types and to get experience with unit testing of code.

Before you begin, make sure you complete exercises 1 and 2. If you experienced
difficulty with the Github classroom and autograder, it is best to seek help
before continuing with this assignment.

Clone project 1's starter codes into your local repository from the GitHub Classroom.
The starter code  will contain several files that will be familiar to you.
Associated with these projects are
`BagInterface.h`,
`ArrayBag.h`,
`catch.hpp`,
`project1_main.cpp` and
`student_tests.cpp`.
Because of the way that templates are handled, the implementation file
`ArrayBag.cpp` must not be associated as a source file;
it will show up automatically under external dependencies.
The source file `project1_main.cpp` is primarily for you to use in
experimenting with the code.

You should not modify `catch.hpp` or `CMakeLists.txt`.
You should modify any of the other files, as needed, to satisfy the project
specification.

## Project Specification

1.  Modify the `ArrayBag` module to add a new public method called `flatten`.
    The prototype and description for BagInterface.h are as follows:

    ```c++
    /** Modify this bag so that all items in the bag
        have a “frequency” (count) value of 1.

    @return  True if the bag was changed; otherwise return false. */

    virtual bool flatten() = 0;
    ```

    As an example, suppose that bag b contains the integers
    `{2, 9, 17, 9, 17, 9, 2, 2, 2}`. The call

    ```c++
    b.flatten();
    ```

    will return true and will cause b to contain `{2, 9, 17}`.

2.  Modify the ArrayBag module to add a new public method called `reduce`.
    The prototype and description for BagInterface.h are as follows:

    ```c++
    /** Finds the item in this bag with the smallest “frequency”,
       and removes all occurrences of that item.
       In case of a tie for smallest frequency, select any one of
       those items and remove all occurrences of that item.
       @return  True if at least one item was removed;
       otherwise return false. */

    virtual bool reduce() = 0;
    ```

    As an example, suppose that bag c contains the integers
    `{2, 9, 17, 9, 17, 9, 2, 2, 2}`. The call

    ```c++
    c.reduce();
    ```

    will return true and will cause c to contain
    `{2, 9, 9, 9, 2, 2, 2}`.

3.  Modify the ArrayBag module to add a new public method called `replace`.
    The prototype and description for BagInterface.h are as follows:

    ```c++
    /** Replaces all occurrences of anEntry in this bag with the
       user-provided newEntry. If anEntry is not present, makes
       no changes to the bag and returns false.
    @param anEntry  The entry to be replaced, if already present
       in the bag.
    @param newEntry A new value that will replace all
       occurrences of anEntry in the bag.
    @return  True if at least one occurrence was replaced;
       otherwise return false. */

    virtual bool replace(const ItemType& anEntry,
                         const ItemType& newEntry) = 0;
    ```

    As an example, suppose that bag b contains the integers
    `{2, 9, 17, 9, 17, 9}`. The call

    ```c++
    b.replace(17, 30);
    ```

    will return true and will cause b to contain
    `{2, 9, 30, 9, 30, 9}`. The call

    ```c++
    b.replace(5, 6);
    ```

    will return false and will make no changes to `b`, because `b`
    does not contain any occurrences of 5.

4.  Modify the ArrayBag module to add a parameterized constructor that creates
    a bag from a given array of entries.
    The prototype of this new constructor is as follows:

    ```c++
    ArrayBag(const ItemType arr[], int size);
    ```

5.  Modify the ArrayBag module to add a new public method called `bagUnion`.
    Your new method should implement the union operation, which is described
    in Chapter 1 of the textbook, Exercise 6.
    The prototype and description are as follows:

    ```c++
    /** Creates a new bag and returns it. The new bag is the union
       of the current bag and the parameter bag2.
       The current bag is not modified, and bag2 is not modified.
    @param bag2  A bag providing input for the union operation.
    @return      A bag that results from the union operation. */
    ArrayBag<ItemType> bagUnion(const ArrayBag<ItemType>& bag2) const;
    ```

    For example, if `bag1` contains items `{a,b,c}` and `bag2` contains items
    `{b,b,d,e}`, the the union of `bag1` and `bag2` is
    `{a,b,b,b,c,d,e}`.

    This prototype should not appear in `BagInterface.h` because the return
    type is an instance of a derived class.
    Place the prototype in `ArrayBag.h`.


## Additional requirements

The autograder will assume that `DEFAULT_CAPACITY==6`,
which is the value given in the starter code.
(You can change this value temporarily if helps you develop your code, but you
must change the value back to 6 before submitting your project.
The autograder will use this value to test operations involving a full bag).

You should also add appropriate comments to any changes that you make to the
other files.

Online testing:  We will use the [autograder](https://grader.ece.vt.edu)
to determine
part of your grade for this assignment. To use the autograder, commit and push
the following C++ source files to Github classroom:
`BagInterface.h`,
`ArrayBag.h`,
`ArrayBag.cpp`, and
`student_tests.cpp` to your Github classroom
repository.

Submit the commit hash to the autograder.
It will compile and run the tests that you have
formulated in `student_tests.cpp`, and the autograder will also run some
"instructor" tests, as described in a recent lecture. A grade will be reported
to you, proportional to the number of tests that have executed correctly.

You can submit to the autograder as many times as you like, but it will limit
you to 5 submissions per hour. (This limit is to prevent the server from being
overloaded, and to prevent people from using it as their only compiler, and to
encourage students to develop good testing strategies.)  An advantage of
autograding is that you will have peace of mind concerning the major portion
of your grade for this assignment.

Be careful to verify that you have pushed the correct files to Github
classroom repository.  After you have uploaded your files, it is suggested
that you also open them on the Github website to verify that they are correct.

## Grading

This assignment is worth 100 points, and the grade will be determined by the autograder.

  * **16 points**: The autograder is able to compile your code
  * **24 points** (proportional): Your tests pass when the autograder runs your program
  * **8 points**: Instructor's tests compile with your code
  * **32 points** (proportional): Instructor's tests pass
  * **20 points**: No memory leaks, as checked by the autograder using valgrind

Please note that your most recent submission to INGInious determines the
autograded portion of your grade.

