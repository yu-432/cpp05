/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:10:15 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/01 13:59:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

const int signGrade = 72;
const int executeGrade = 45;

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", signGrade, executeGrade), _target("defaultRobotomy") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", signGrade, executeGrade), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

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
