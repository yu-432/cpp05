/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:21:15 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/29 20:28:23 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
  return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
  return new PresidentialPardonForm(target);
}

Intern::FormType Intern::_FormType[] = {
  {"shrubbery request", &createShrubbery},
  {"robotomy request", &createRobotomy},
  {"presidental request", &createPresidential},
  {NULL, NULL}
};

Intern::Intern() {}

Intern::Intern(const Intern& src) {(void)src;}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& src) {
  (void)src;
  return *this;
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget) {
  for (int i = 0; _FormType[i].formName; i++) {
    if (formName == _FormType[i].formName) {
      AForm* temp = _FormType[i].createForm(formTarget);
      return (temp);
    }
  }
  std::cout << "failed make form" << std::endl;
  return NULL;
}

