using System;
using System.Collections.Generic;
using System.Threading;

namespace RockPaperAndScizor
{
    class Program
    {
        static void Main(string[] args)
        {
            Game();
        }

        public static void Game()
        {
            //Players Choice
            Console.WriteLine("Hey, let's play Rock, Scizor and Paper!");
            Console.WriteLine("Choose your weapon: \n 1 - Rock \n 2 - Scizor \n 3 - Paper");
            var player_choice = Console.ReadLine();
            var errorMessage = "Hey, That's not fair! Let's do it again!";
            var possible_weapons = new List<string>() {"1", "2", "3"};
            if (!possible_weapons.Contains(player_choice))
            {
                Console.WriteLine(errorMessage);
                Thread.Sleep(1500);
                Game();
            }
            
            //Oponent Choice
            var randomizer = new Random();
            var oponent_choice = randomizer.Next(3);
            if (oponent_choice == 0)
            {
                oponent_choice++;
            }
            
            //Result
            var victoryMessage = "Congratulations, you won! You're so cool!";
            var defeatMessage = "Oh, i Won! Don't be Sad, i'm just too amazing!";
            var tuple = (player_choice, oponent_choice.ToString());
            
            if (player_choice == oponent_choice.ToString())
            {
                Console.WriteLine("Oh, it's a Tie! Guess we're both pro players!");
            }
            
            else if(tuple == ("1","3") || tuple == ("2","1") || tuple == ("3","2"))
            {
                Console.WriteLine(defeatMessage);
            }

            else
            {
                Console.WriteLine(victoryMessage);
            }
            
            //Stop or play again
            Console.WriteLine("Wanna play again? \n N for no \n Y for yes");
            
            if (Console.ReadLine().ToLower() == "n")
            {
                return;
            }
            
            Game();

        }
    }
}