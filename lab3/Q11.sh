#/bin/bash
echo "Enter file name"
read filename
while ((1)); do

	echo "1.search the pattern"
	echo "2.delete all occurences"
	echo "3.Exit from the shell script"
	echo "enter your option"
	read option
	case $option in
		1)
		echo "you selected option one"
		for i in $@;do
			grep $i $filename
		done
		;;

		2)
		echo "you selected otion two"
		for i in $@;do
			sed -i -e "s/$i//g" $filename
		done
		;;
		3)	
		echo "you selected option three"
		break;;
	esac
done