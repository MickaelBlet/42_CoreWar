/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 18:00:38 by mblet             #+#    #+#             */
/*   Updated: 2016/05/22 21:36:47 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRERROR_H
# define STRERROR_H

/*
** MAIN
*/
char	*ft_strerror(void);
char	*ft_strerr(int err);

/*
** CHILD
*/
void	ini_strerror(char ***at);

#endif
