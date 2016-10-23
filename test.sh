# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 12:09:53 by mblet             #+#    #+#              #
#    Updated: 2016/10/23 12:32:35 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

dump=14118

champion1=./champions/examples/turtle.cor
champion2=./champions/examples/helltrain.cor
champion3=./champions/examples/turtle.cor
champion4=./champions/examples/helltrain.cor

champions/corewar/corewar \
	-v 4 \
	-d $dump \
	$champion1 $champion2 $champion3 $champion4 > "test_dump_zaz.test"

./corewar \
	--ops \
	-d $dump \
	$champion1 $champion2 $champion3 $champion4 > "test_dump_me.test"

diff -s --speed-large-files "test_dump_zaz.test" "test_dump_me.test" | sed "s/^</me :/" | sed "s/^>/zaz:/"
