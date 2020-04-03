#!/bin/bash

#!/bin/bash
size=10
for i in 4 8 10 20 100 200 400 800 1000
do
    # echo $number
    yes="words-${i}-3.txt"
    echo $yes
    ./main $yes
    # ((number++))

done
