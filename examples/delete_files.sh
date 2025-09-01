
l=$(ls)

# echo "$l"


for i in $l;
do 
    if [[ "$i" == *.exe ]];
        then
        $(rm $i)
    fi
done
