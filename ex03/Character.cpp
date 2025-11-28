/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 by sarherna                  #+#    #+#             */
/*   Updated: 2025/11/27 by sarherna                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("unnamed") {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        // Delete old materias before copying new ones
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        // Copy new materias
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    // Inventory is full, do nothing
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx] = NULL;  // Don't delete, just remove from inventory
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}
