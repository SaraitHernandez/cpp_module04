/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 by sarherna                  #+#    #+#             */
/*   Updated: 2025/11/27 by sarherna                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unknown") {
}

AMateria::AMateria(std::string const & type) : type(type) {
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
}

AMateria& AMateria::operator=(const AMateria& other) {
    // Type should not be copied according to subject
    (void)other;
    return *this;
}

AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
