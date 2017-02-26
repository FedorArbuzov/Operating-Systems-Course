

#!/bin/bash
# App: timer
# Author: Arbuzov Fedor
# ------------------------------------------------------
 
# global var

# time for learning
learningTime=0

# time for rest
restTime=0

# can I beep or not
beep=true


# show message
messageSend(){
    notify-send -t 10000 "Learning timer" "$1"
}

# Display text at given row and column 
show(){
        local x=$1
        local y=$2
        local txt="$3"
        # Set cursor position on screen
        tput cup $x $y
        echo "$txt"
}

# loop for menu
while [ : ]
do
        clear
        # Get the system time
        now="$(date +"%r")"
        # Show main - menu, server name and time
        show 10 10 "MAIN MENU for $HOSTNAME - $now"
        show 11 10 "1 - App info"
        show 12 10 "2 - 20 minutes learning, 2 minute rest"
        show 13 10 "3 - 30 minutes learning, 3 minute rest"
        show 14 10 "4 - 40 minutes learning, 4 minute rest"
        show 15 10 "5 - Exit"
        tput cup 16 10; read -t 2 -p "Choice [1-5] ? " usrch
        # do something
        case $usrch in
                1)
                	read -t 2 -p "This app is created to systematize and improve the learning process" 
                	;;
                2)
                	echo "Start learning!!"
                	learningTime=20
                	restTime=2
                	break
                	;;
                3) 
					echo "Start learning!!"
                	learningTime=30
                	restTime=3 
					break
					;;
                4) 
					echo "Start learning!!"
                	learningTime=40
                	restTime=4 
					break
					;;
                5) 
					echo "Bye."
					# stop program
					exit 1
					;;
        esac
done
while [ : ]
do
	clear
	#statements
	messageSend "Start learning! You will have break after $learningTime minutes"
	echo "Start learning! You will have break after $learningTime minutes"
	sleep ${learningTime}m
	messageSend "Relax! You have over $restTime minutes"
	echo "Relax! You have over $restTime minutes"
	sleep ${restTime}m
done
echo "Bye!"

