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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing Animal Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n=== Type Testing ===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\n=== Sound Testing ===" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\n=== Cleanup ===" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Testing Wrong Classes (No Polymorphism) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\n=== Wrong Type Testing ===" << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    std::cout << "\n=== Wrong Sound Testing ===" << std::endl;
    wrongCat->makeSound(); // will output WrongAnimal sound (no polymorphism!)
    wrongMeta->makeSound();
    
    std::cout << "\n=== Wrong Cleanup ===" << std::endl;
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== Additional Tests: Stack Objects ===" << std::endl;
    {
        Dog dog;
        Cat cat;
        std::cout << "\nMaking sounds:" << std::endl;
        dog.makeSound();
        cat.makeSound();
    }
    
    std::cout << "\n=== Additional Tests: Copy Constructor ===" << std::endl;
    {
        Dog originalDog;
        Dog copiedDog(originalDog);
        std::cout << "Original: " << originalDog.getType() << std::endl;
        std::cout << "Copy: " << copiedDog.getType() << std::endl;
    }
    
    return 0;
}
