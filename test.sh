# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 12:09:53 by mblet             #+#    #+#              #
#    Updated: 2016/10/24 00:46:14 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

dump=-1

champion1="./champions/examples/helltrain.cor"
champion2="./champions/examples/helltrain.cor"
champion3="./champions/examples/helltrain.cor"
champion4="./champions/examples/helltrain.cor"

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
	-v $(($lives + $cycles + $ops + $deaths + $moves)) \
	-d $dump \
	$champion1 $champion2 $champion3 $champion4 > "test_dump_zaz.test" &

./corewar \
	--lives --cycles --ops --deaths --moves \
	-d $dump \
	$champion1 $champion2 $champion3 $champion4 > "test_dump_me.test"

diff -s "test_dump_me.test" "test_dump_zaz.test" \
	| sed "s/^</me  :	/" \
	| sed "s/^>/zaz :	/" | more
