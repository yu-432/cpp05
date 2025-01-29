/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:10:15 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/29 20:20:04 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void RobotomyRequestForm::executeAction(void) const {
  srand(time(NULL));
  std::cout << "*** Dril sound! ***\n";
  if (rand() % 2) {
    std::cout << _target << " failed robotomy." << std::endl;
    return;
    }
  std::cout << _target << " success Robotomy." << std::endl;
}
