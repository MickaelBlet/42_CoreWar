# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 12:09:53 by mblet             #+#    #+#              #
#    Updated: 2017/01/03 19:24:20 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/sh

dump=-1

champion1="./champions/new_line.cor"
champion2="./champions/examples/helltrain.cor"
champion3="./champions/examples/zork.cor"
champion4="./champions/examples/turtle.cor"

#./corewar -g $champion1 $champion2 $champion3 $champion4

#exit

#champion4="" #"./champions/examples/helltrain.cor"

#if [ -n ${BASH_ARGV[0]} ]; then
	#./corewar \
		#-g \
		#-d $dump \
		#$champion1 $champion2 $champion3 $champion4;
	#exit
#fi

lives=1
cycles=2
ops=4
deaths=8
moves=16

./corewar \
	-g \
	$champion1 $champion2 $champion3 $champion4

#sleep 4

#zaz_corewar/corewar \
	#-n \
	#-v $(($lives + $cycles + $moves + $ops + $deaths)) \
	#-d $dump \
	#$champion1 $champion2 $champion3 $champion4

#diff -s "/tmp/test_dump_me.test" "/tmp/test_dump_zaz.test" \
	#| sed "s/^</me  :	/" \
	#| sed "s/^>/zaz :	/" | more
