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
    std::cout << "=== Basic Test from Subject ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;
    
    std::cout << "\n=== Array Test ===" << std::endl;
    const int size = 10;
    Animal* animals[size];
    
    // Fill half with Dogs
    std::cout << "\n--- Creating Dogs ---" << std::endl;
    for (int idx = 0; idx < size / 2; idx++) {
        animals[idx] = new Dog();
    }
    
    // Fill half with Cats
    std::cout << "\n--- Creating Cats ---" << std::endl;
    for (int idx = size / 2; idx < size; idx++) {
        animals[idx] = new Cat();
    }
    
    // Test sounds
    std::cout << "\n--- Testing Sounds ---" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    // Delete all
    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        delete animals[idx];
    }
    
    std::cout << "\n=== Deep Copy Test for Dog ===" << std::endl;
    {
        Dog originalDog;
        originalDog.getBrain()->setIdea(0, "Chase the cat");
        originalDog.getBrain()->setIdea(1, "Eat food");
        
        std::cout << "\nCreating copy of Dog..." << std::endl;
        Dog copiedDog(originalDog);
        
        std::cout << "\nOriginal Dog Brain address: " << originalDog.getBrain() << std::endl;
        std::cout << "Copied Dog Brain address: " << copiedDog.getBrain() << std::endl;
        std::cout << "Are they different? " << (originalDog.getBrain() != copiedDog.getBrain() ? "YES (Deep Copy)" : "NO (Shallow Copy)") << std::endl;
        
        std::cout << "\nOriginal Dog ideas:" << std::endl;
        std::cout << "  Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "  Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;
        
        std::cout << "\nCopied Dog ideas:" << std::endl;
        std::cout << "  Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "  Idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;
        
        std::cout << "\nModifying copied dog's ideas..." << std::endl;
        copiedDog.getBrain()->setIdea(0, "Play with ball");
        
        std::cout << "\nAfter modification:" << std::endl;
        std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied Dog Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "(They should be different)" << std::endl;
    }
    
    std::cout << "\n=== Deep Copy Test for Cat ===" << std::endl;
    {
        Cat originalCat;
        originalCat.getBrain()->setIdea(0, "Hunt mice");
        originalCat.getBrain()->setIdea(1, "Sleep all day");
        
        std::cout << "\nCreating copy of Cat..." << std::endl;
        Cat copiedCat(originalCat);
        
        std::cout << "\nOriginal Cat Brain address: " << originalCat.getBrain() << std::endl;
        std::cout << "Copied Cat Brain address: " << copiedCat.getBrain() << std::endl;
        std::cout << "Are they different? " << (originalCat.getBrain() != copiedCat.getBrain() ? "YES (Deep Copy)" : "NO (Shallow Copy)") << std::endl;
        
        std::cout << "\nOriginal Cat ideas:" << std::endl;
        std::cout << "  Idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "  Idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
        
        std::cout << "\nCopied Cat ideas:" << std::endl;
        std::cout << "  Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
        std::cout << "  Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
    }
    
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    {
        Dog dog1;
        dog1.getBrain()->setIdea(0, "Original idea");
        
        Dog dog2;
        dog2.getBrain()->setIdea(0, "Second idea");
        
        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "Dog1 Brain: " << dog1.getBrain() << " - Idea: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2 Brain: " << dog2.getBrain() << " - Idea: " << dog2.getBrain()->getIdea(0) << std::endl;
        
        dog2 = dog1;
        
        std::cout << "\nAfter assignment (dog2 = dog1):" << std::endl;
        std::cout << "Dog1 Brain: " << dog1.getBrain() << " - Idea: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2 Brain: " << dog2.getBrain() << " - Idea: " << dog2.getBrain()->getIdea(0) << std::endl;
        std::cout << "Are brains different? " << (dog1.getBrain() != dog2.getBrain() ? "YES" : "NO") << std::endl;
    }
    
    return 0;
}
