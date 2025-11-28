/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 by sarherna                  #+#    #+#             */
/*   Updated: 2025/11/27 by sarherna                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria(other) {
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
