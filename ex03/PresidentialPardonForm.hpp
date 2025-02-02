/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:35:11 by yooshima          #+#    #+#             */
/*   Updated: 2025/02/02 13:11:13 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& src);
  ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

  void executeAction(void) const;

 private:
  const std::string _target;
  static const int signGrade;
  static const int executeGrade;
};

#endif