# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 12:09:53 by mblet             #+#    #+#              #
#    Updated: 2016/10/28 11:42:09 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#make && ./corewar -g -dump 21000 -n 42 ./champions/examples/helltrain.cor ./champions/examples/helltrain.cor ./champions/examples/helltrain.cor ./champions/examples/helltrain.cor
#
#exit

dump=-1

champion1="./champions/examples/helltrain.cor"
champion2="./champions/examples/helltrain.cor"
champion3="./champions/examples/helltrain.cor"
champion4="./champions/examples/helltrain.cor"
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

champions/corewar/corewar \
	-v $(($lives + $cycles + $moves + $deaths)) \
	-d $dump \
	$champion1 $champion2 $champion3 $champion4 > "test_dump_zaz.test" &

./corewar \
	--lives --cycles --deaths --moves \
	-dump $dump \
	$champion1 $champion2 $champion3 $champion4 > "test_dump_me.test"

diff -s "test_dump_me.test" "test_dump_zaz.test" \
	| sed "s/^</me  :	/" \
	| sed "s/^>/zaz :	/" | more
