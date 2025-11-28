# C++ Module 04 - Subtype Polymorphism, Abstract Classes, and Interfaces

This module contains 4 exercises demonstrating advanced C++ OOP concepts: polymorphism, abstract classes, and interfaces.

## Structure

```
cpp_module04/
├── ex00/  - Basic Polymorphism
├── ex01/  - Deep Copy with Brain class
├── ex02/  - Abstract Classes
└── ex03/  - Interfaces (Pure Abstract Classes)
```

## Exercise 00: Polymorphism

**Files**: Animal, Dog, Cat, WrongAnimal, WrongCat

**Concepts**:
- Virtual functions for runtime polymorphism
- Base and derived classes
- Demonstration of polymorphism vs non-polymorphism (Wrong classes)

**Compile & Run**:
```bash
cd ex00
make
./polymorphism
```

**Key Features**:
- `Animal` base class with virtual `makeSound()`
- `Dog` and `Cat` inherit from `Animal` and override `makeSound()`
- `WrongAnimal` and `WrongCat` demonstrate what happens WITHOUT virtual functions
- Complete tests including copy constructors and assignment operators

## Exercise 01: I don't want to set the world on fire

**Files**: Animal, Dog, Cat, Brain

**Concepts**:
- Deep copy vs shallow copy
- Dynamic memory management
- Proper destructor implementation to prevent memory leaks

**Compile & Run**:
```bash
cd ex01
make
./brain
```

**Key Features**:
- `Brain` class with 100 ideas (strings)
- `Dog` and `Cat` each have a private `Brain*` member
- Deep copy implementation in copy constructor and assignment operator
- Comprehensive tests for memory leaks and deep copy verification
- Array of Animals (half Dogs, half Cats) with proper cleanup

## Exercise 02: Abstract class

**Files**: Animal (abstract), Dog, Cat, Brain

**Concepts**:
- Pure virtual functions
- Abstract base classes
- Preventing instantiation of base classes

**Compile & Run**:
```bash
cd ex02
make
./abstract
```

**Key Features**:
- `Animal::makeSound()` is now pure virtual (`= 0`)
- Cannot instantiate `Animal` directly (compile error if attempted)
- Everything else works as in ex01
- Deep copy still implemented correctly

## Exercise 03: Interface & recap

**Files**: AMateria, Ice, Cure, ICharacter, Character, IMateriaSource, MateriaSource

**Concepts**:
- Interfaces (pure abstract classes in C++)
- Complex memory management
- Inventory system with slots
- Factory pattern (MateriaSource)

**Compile & Run**:
```bash
cd ex03
make
./interface
```

**Key Features**:
- **AMateria**: Abstract base class for all materias
  - Pure virtual `clone()` method
  - Virtual `use(ICharacter&)` method

- **Ice & Cure**: Concrete materia types
  - Ice: "* shoots an ice bolt at <name> *"
  - Cure: "* heals <name>'s wounds *"

- **ICharacter**: Interface for characters
  - Inventory of 4 materia slots
  - `equip()`, `unequip()`, `use()` methods

- **Character**: Implementation of ICharacter
  - Deep copy with proper memory management
  - Deletes old materias before copying new ones
  - Unequip does NOT delete (caller must manage)

- **IMateriaSource**: Interface for materia factory
  - Learns up to 4 materia templates
  - Creates new materias by type

- **MateriaSource**: Implementation of IMateriaSource
  - Stores clones of learned materias
  - Returns NULL for unknown types

**Memory Management**:
- All tests check for proper memory cleanup
- Deep copy for Characters and MateriaSource
- Unequipped materias must be manually deleted
- Full inventory handling (doesn't crash, just ignores new items)

## Compilation

All exercises use:
- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`
- Make commands: `make`, `make clean`, `make fclean`, `make re`

## Testing

Each exercise includes comprehensive tests beyond the subject requirements:
- Constructor/destructor messages
- Copy constructors and assignment operators
- Memory leak prevention
- Edge cases (full inventory, NULL pointers, etc.)
- Deep copy verification with address comparison

## Key C++98 Features Demonstrated

1. **Virtual Functions**: Runtime polymorphism
2. **Pure Virtual Functions**: Abstract classes and interfaces
3. **Virtual Destructors**: Proper cleanup in polymorphic hierarchies
4. **Deep Copy**: Copy constructor and assignment operator
5. **Dynamic Memory**: new/delete, arrays of pointers
6. **Protected Members**: Inheritance access control
7. **NULL Pointers**: Safe handling and checking

## Author Notes

All exercises follow the 42 School coding standards:
- Orthodox Canonical Form (when applicable)
- No forbidden functions used
- Comprehensive testing
- Memory leak prevention
- Clear constructor/destructor messages
