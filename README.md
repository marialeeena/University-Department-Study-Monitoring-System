# University Department Study Monitoring System

An object-oriented C++ program developed as part of a programming assignment, designed to manage and monitor the records of members within a university department (students, professors, and the secretary's office).

## Key Features

* **`Person` Class:**
  * Implementation of encapsulation for common personal attributes (name, last name, age, ID/registration number).
  * Implementation of Constructors, Copy Constructor, and Destructor.
  * Static counter (`static int count`) to track the total number of `Person` objects created.
  * Overloading of output (`<<`), input (`>>`), and equality (`==`) operators.

* **`Secretary` Class:**
  * Management of department data using a dynamic data structure (`std::map`) and pointers to `Person` objects.
  * Overloading of the addition operator (`+=`) for dynamic memory allocation and addition of new persons.
  * Implementation of Copy Constructor and overloading of the assignment operator (`=`) for safe memory management.
  * Search function (`containsperson`) to check if a specific person exists.
  * Overloading of output (`<<`) and input (`>>`) operators for direct reading/printing of department records.

## Technical Specifications

* **Memory Management:** Prevention of memory leaks through proper Destructors that deallocate dynamically bound objects.
* **No External Libraries:** Relies exclusively on standard C++ libraries (`<iostream>`, `<string>`, `<map>`).

## Compilation and Execution


g++ -o department firstpart.cpp

./department
