/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 by sarherna                  #+#    #+#             */
/*   Updated: 2025/11/27 by sarherna                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.templates[i]) {
            templates[i] = other.templates[i]->clone();
        } else {
            templates[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        // Delete old templates
        for (int i = 0; i < 4; i++) {
            if (templates[i]) {
                delete templates[i];
                templates[i] = NULL;
            }
        }
        // Copy new templates
        for (int i = 0; i < 4; i++) {
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (templates[i]) {
            delete templates[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = m->clone();
            delete m;  // Delete the original after cloning
            return;
        }
    }
    // No space left, delete the passed materia
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return NULL;
}
