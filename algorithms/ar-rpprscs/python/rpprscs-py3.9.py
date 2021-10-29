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

    print(f"You picked {userChoice} and the Computer picked {compChoice}!")

    # Check userChoice against compChoice.
    if userChoice == compChoice:
        print("Tie!")
    elif userChoice == "R" and compChoice == "S":
        print("Rock beats Scissors, you win!")
    elif userChoice == "P" and compChoice == "R":
        print("Paper beats Rock, you won!")
    elif userChoice == "S" and compChoice == "P":
        print("Scissors beats Paper, you win!")
    else:
        print("Sorry, computer wins!")
