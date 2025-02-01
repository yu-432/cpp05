/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:11:18 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 10:17:44 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void PresidentialPardonForm::executeAction(void) const {
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
