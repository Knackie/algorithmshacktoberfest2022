""" Rock Paper Scissors in Python2
----------------------------------------
"""

# Import Needed Modules.
import random
import os
import re

# Clear The Screen.
os.system('cls' if os.name=='nt' else 'clear')

# Main Game Loop.
while (1 < 2):
    print "\n"
    print "Rock, Paper, Scissors - Shoot!"

    userChoice = raw_input("Choose your weapon [R]ock], [P]aper, or [S]cissors: ")

    # Check if userChoice is valid.
    if not re.match("[SsRrPp]", userChoice):
        print "Please choose a letter:"
        print "[R]ock, [S]cissors or [P]aper."
        continue
    
    # Print the user's choice.
    print "You chose: " + userChoice

    choices = ['R', 'P', 'S']
    opponentChoice = random.choice(choices)

    print "I chose: " + opponentChoice

    # Check opponentChoice against userChoice.
    if opponentChoice == str.upper(userChoice):
        print "Tie! "
    elif opponentChoice == 'R' and userChoice.upper() == 'S':      
        print "Scissors beats rock, I win! "
        continue
    elif opponentChoice == 'S' and userChoice.upper() == 'P':      
        print "Scissors beats paper! I win! "
        continue
    elif opponentChoice == 'P' and userChoice.upper() == 'R':      
        print "Paper beat rock, I win! "
        continue
    else:       
        print "You win!"