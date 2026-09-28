# C++ Practice

My C++ learning exercises and projects.

## 01 Functions

- Parameters and arguments
- Return values
- Forward declarations
- Pass by value
- Pass by reference

## 02 Control Flow

- if / else
- switch
- while
- for
- break
- continue

## 03 Enum and Struct

- enum
- enum class
- struct
- aggregate initialization
- passing structs
- const references

## 04_Pointers

Current topics:

- Address and address-of operator `&`
- Pointers
- Dereference operator `*`
- `nullptr`
- Pointer to const
- Const pointer
- Pass by address
- Return by address
- Array-to-pointer decay
- Pointer arithmetic
- Array-pointer relationship

### Enemy Target Scanner

`Pointer_EnemyTargetScanner.cpp`

A small pointer practice challenge using an enemy HP array.

Features:

- Traverse an array using pointers
- Find the first alive enemy
- Return the address of an array element
- Modify HP through a pointer
- Handle `nullptr`
- Find the strongest enemy
- Use `const int*` for read-only access
- Practice pointer arithmetic

Example:

```cpp
int enemyHP[]{ 100, 75, 0, 40, 120 };