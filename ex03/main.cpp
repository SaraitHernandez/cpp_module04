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

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== Subject's Required Test ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n=== Additional Test: Full Inventory ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* hero = new Character("hero");

        // Fill inventory
        hero->equip(src->createMateria("ice"));
        hero->equip(src->createMateria("cure"));
        hero->equip(src->createMateria("ice"));
        hero->equip(src->createMateria("cure"));

        // Try to equip when full (should do nothing)
        AMateria* extra = src->createMateria("ice");
        hero->equip(extra);
        delete extra;  // Must delete manually since it wasn't equipped

        ICharacter* enemy = new Character("enemy");
        
        std::cout << "\nUsing all 4 materias:" << std::endl;
        hero->use(0, *enemy);
        hero->use(1, *enemy);
        hero->use(2, *enemy);
        hero->use(3, *enemy);

        delete enemy;
        delete hero;
        delete src;
    }

    std::cout << "\n=== Additional Test: Unequip ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());

        ICharacter* player = new Character("player");
        ICharacter* target = new Character("target");

        AMateria* ice = src->createMateria("ice");
        player->equip(ice);

        std::cout << "\nBefore unequip:" << std::endl;
        player->use(0, *target);

        std::cout << "\nUnequipping slot 0..." << std::endl;
        player->unequip(0);

        std::cout << "\nAfter unequip (should do nothing):" << std::endl;
        player->use(0, *target);

        // Clean up the unequipped materia
        delete ice;

        delete target;
        delete player;
        delete src;
    }

    std::cout << "\n=== Additional Test: Deep Copy of Character ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        Character* original = new Character("original");
        original->equip(src->createMateria("ice"));
        original->equip(src->createMateria("cure"));

        std::cout << "\nCreating copy of character..." << std::endl;
        Character* copy = new Character(*original);

        ICharacter* target = new Character("target");

        std::cout << "\nOriginal character using materias:" << std::endl;
        original->use(0, *target);
        original->use(1, *target);

        std::cout << "\nCopied character using materias:" << std::endl;
        copy->use(0, *target);
        copy->use(1, *target);

        delete target;
        delete copy;
        delete original;
        delete src;
    }

    std::cout << "\n=== Additional Test: Unknown Materia Type ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());

        AMateria* unknown = src->createMateria("fire");
        if (unknown == NULL) {
            std::cout << "Correctly returned NULL for unknown type 'fire'" << std::endl;
        }

        delete src;
    }

    std::cout << "\n=== Additional Test: MateriaSource Full ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        
        std::cout << "Learning 5 materias (only 4 should be stored):" << std::endl;
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());  // This one won't be stored

        std::cout << "\nCreating materias from source:" << std::endl;
        AMateria* m1 = src->createMateria("ice");
        AMateria* m2 = src->createMateria("cure");
        
        std::cout << "Created: " << m1->getType() << std::endl;
        std::cout << "Created: " << m2->getType() << std::endl;

        delete m1;
        delete m2;
        delete src;
    }

    return 0;
}
