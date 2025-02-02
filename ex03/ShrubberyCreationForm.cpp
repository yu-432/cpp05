/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:55:08 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 13:12:32 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_tree =
    "    *\n\
   ***\n\
  *****\n\
 *******\n\
*********\n\
   ### \n";

const int ShrubberyCreationForm::signGrade = 145;
const int ShrubberyCreationForm::executeGrade = 137;

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", signGrade, executeGrade),
      _target("defaultShrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreation", signGrade, executeGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void ShrubberyCreationForm::executeAction(void) const {
  std::ofstream ofs((_target + "_shrubbery").c_str());
  if (!ofs) {
    std::cerr << "Can't open file" << std::endl;
    return;
  }
  ofs << _tree << std::endl;
}
