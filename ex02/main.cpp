/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 by sarherna                  #+#    #+#             */
/*   Updated: 2025/11/27 by sarherna                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Testing Abstract Class ===" << std::endl;
    std::cout << "Note: Cannot instantiate Animal directly (it's abstract)" << std::endl;
    // const Animal* meta = new Animal(); // This would NOT compile!
    
    std::cout << "\n=== Creating Dog and Cat (derived classes) ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n=== Testing polymorphism ===" << std::endl;
    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;
    
    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    j->makeSound();
    i->makeSound();
    
    std::cout << "\n=== Cleanup ===" << std::endl;
    delete j; // should not create a leak
    delete i;
    
    std::cout << "\n=== Array Test ===" << std::endl;
    const int size = 6;
    Animal* animals[size];
    
    std::cout << "\n--- Creating Dogs ---" << std::endl;
    for (int idx = 0; idx < size / 2; idx++) {
        animals[idx] = new Dog();
    }
    
    std::cout << "\n--- Creating Cats ---" << std::endl;
    for (int idx = size / 2; idx < size; idx++) {
        animals[idx] = new Cat();
    }
    
    std::cout << "\n--- Testing Sounds ---" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        delete animals[idx];
    }
    
    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    {
        Dog* dog1 = new Dog();
        dog1->getBrain()->setIdea(0, "Chase squirrels");
        
        Dog* dog2 = new Dog(*dog1);
        
        std::cout << "\nDog1 Brain: " << dog1->getBrain() << std::endl;
        std::cout << "Dog2 Brain: " << dog2->getBrain() << std::endl;
        std::cout << "Different addresses? " << (dog1->getBrain() != dog2->getBrain() ? "YES (Deep Copy)" : "NO") << std::endl;
        
        std::cout << "\nDog1 Idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2 Idea 0: " << dog2->getBrain()->getIdea(0) << std::endl;
        
        dog2->getBrain()->setIdea(0, "Play fetch");
        
        std::cout << "\nAfter modifying dog2:" << std::endl;
        std::cout << "Dog1 Idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2 Idea 0: " << dog2->getBrain()->getIdea(0) << std::endl;
        
        delete dog1;
        delete dog2;
    }
    
    return 0;
}
