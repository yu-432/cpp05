/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:10:15 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 10:37:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void RobotomyRequestForm::executeAction(void) const {
  std::srand(std::time(NULL));
  std::cout << "*** Dril sound! ***\n";
  if (std::rand() % 2) {
    std::cout << _target << " failed robotomy." << std::endl;
    return;
  }
  std::cout << _target << " success Robotomy." << std::endl;
}
