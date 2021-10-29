# Rock, Paper, Scissors in Python3.9

# Import Needed Modules.
import random, os

# Choices to pick.
choices = ["R", "P", "S"]

# Main Game Loop.
while True:

    # Get Users Choice.
    while True:
        userChoice = input("R | P | S >> ")

        if userChoice.upper() in choices:
            break

    # Get Computers Choice.
    compChoice = choices[random.randint(0, 2)]

    print(f"You picked {userChoice} and the Computer picked {compChoice}!\n")

    # Check userChoice against compChoice.
    compare = (userChoice, compChoice)
    
    if compare[0] == compare[1]:
        print("Tie!")
    elif compare in [('R', 'S'), ('P', 'R'), ('S', 'P')]:
        print("You win!")
    elif compare in [('R', 'P'), ('P', 'S'), ('S', 'R')]:
        print("Sorry, you lose!")
