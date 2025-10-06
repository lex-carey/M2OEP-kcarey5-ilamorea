# Video Game Stats Tracker
All code for this project was authored by Alexis Carey and Issac Lamorea for the M2OEP.

## Project Summary
This program was built off the Minesweeper Stats tracker Alexis built for the M1OEP, but has been expanded to track stats for Balatro games along with Minesweeper games. When the program is run, the user is met with a menu where they can either choose to log a new game or view stats for each game. The program guides the user through the process of both.

We used all the concepts in the M2OEP concepts menu:
* Inheritance Class Relationship
  * This program features one parent class, Game, that has two child classes, Minesweeper and Balatro. The child classes inherit 5 variables from Game along with all methods in the class. Both child classes have their own additional methods that aid the user in the creation of a game of each type. Minesweeper has one additional variable and Balatro has four.
* Component Class Relationship
  * Both Minesweeper and Balatro are component classes of the Stats class. Stats creates vectors of each game type which it uses to calculate game statistics.
* File Input/File Output
  * Both file input and file output are featured in this program. This program utilizes four CSV files (balatro_log.csv, balatro_top_games.csv, minesweeper_log.csv, and minesweeper_top_games.csv) that act as long-term storage for game information. Data from these files is loaded into vectors when a new Stats object is created, and data is loaded into the files when games are logged through either the logMinesweeperGame() or logBalatroGame() methods, depending on the game type. 

If there had been more time to dedicate to this project, it would have been nice to expand upon Balatro's setScore() method. Though very hard to achieve, Balatro hands have the capacity to reach a score so high that the game is forced to use scientific notation to track them. There wasn't time to figure out a way for scientific notation scores to be accepted by the current setScore() method, but if it's possible it'll definitely be something that will get implemented in the future. Something else that was mentioned in the M1OEP README that still holds is the desire to expand on the Minesweeper statistics. There wasn't time to implement that for this rendition of the project, but it's on the to-do list.

## Bugs
We currently know of no unresolved bugs. Everything found during testing was able to be fixed. Please let us know if you find something if you end up running this program!

## Grading
We believe we have met every expectation for this project. Our main program is interactive and thoroughly complex. It requires user input to guide its functions and all input is validated. Many of our non-trivial methods require user input for them to function so they are not included in the testing class, but they are utilized in main and run as intended (even when the user inputs an unacceptable value) so we believe that is proof enough of their functionality. All non-trivial methods which do not require user input are tested in the testing class and have multiple test cases. We believe this project has the potential to score at least full marks.