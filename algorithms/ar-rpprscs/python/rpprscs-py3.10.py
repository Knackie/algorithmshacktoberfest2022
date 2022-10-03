# A Rock, Paper, Scissors Game in Python3.10

# Include Needed Modules.
import random, os

# Choices to pick.
choices = ["R", "P", "S"]

# Main Game loop.
while True:
    # Get userChoice.
    while True:
        userChoice = input("R | P | S >> ").upper()

        if userChoice in choices:
            break

    # Get compChoice.
    compChoice = choices[random.randint(0, 2)]

    print(f"You picked {userChoice} and the Computer chose {compChoice}!\n")

    # Compare userChoice to compChoice.
    compare = (userChoice, compChoice)
    
    match compare:
        case ('R', 'R') | ('P', 'P') | ('S', 'S'):
            print("Tie!")
        case ('R', 'S') | ('P', 'R') | ('S', 'P'):
            print("You win!")
        case ('R', 'P') | ('P', 'S') | ('S', 'R'):
            print("Sorry, you lose!")
