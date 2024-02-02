/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:54:10 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 15:07:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat();
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
	virtual ~Cat();

	void makeSound() const;
};

#endif
