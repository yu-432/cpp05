/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:11:18 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 12:58:43 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::signGrade = 25;
const int PresidentialPardonForm::executeGrade = 5;

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", signGrade, executeGrade),
      _target("defaultPresidential") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", signGrade, executeGrade),
      _target(target) {}

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
