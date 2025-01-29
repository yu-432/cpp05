/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:55:08 by yooshima          #+#    #+#             */
/*   Updated: 2025/01/29 20:19:51 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_tree = "    *\n\
   ***\n\
  *****\n\
 *******\n\
*********\n\
   ### \n";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

void ShrubberyCreationForm::executeAction(void) const {
  std::ofstream ofs(_target + "_shrubbery");
  if (!ofs) {
    std::cerr << "Can't open file" << std::endl;
    return;
  }
  ofs << _tree << std::endl;
}
