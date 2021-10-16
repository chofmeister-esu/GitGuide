# Git Crash Course designed for the ESU Software Engineering Course.

## This guide is meant to be followed step by step, please do not skip any part unless you know what you are doing.

#### You can reach me at Jiamingw29@gmail.com for any questions, issues, or suggestions.

## Starting Out

### Start the guide by forking the sample rock paper scissor game that can be found [here](https://duckduckgo.com). You can accomplish this by clicking on the fork button found top right of the repository. By forking a project, you have received a copy of the project. However, any change you make to your fork will not affect the original project.

# Git Clone

Cloning a library will download the repository onto your computer with one extra detail: the downloaded folder will also
contain the git information that declares the folder as a git repository. If you simply just download the git
repository, you will only receive the files. You can clone your forked repository by typing git clone *

fork repository url* in the command line or use sourcetree.

# Git Commit

You can think of a commit as a snapshot. Everytime you make a commit, git saves that version of the file somewhere. Open
the rock paper scissor game you cloned in the previous step in Visual Studio, and you will notice the code does not
compile. Add the following to line 3-5.

```c++
char ROCK = 'r';
char PAPER = 'p';
char SCISSORS = 's';
```

Now run git status in your command line, and you can see the file RockPaperScissors.cpp has been marked. You can run git
status at anytime to print out the files you have changed. Now commit the file, first run ```git add .```. Adding a file
will cause it to be put into the staging area which is where git stores all the files that wil be in the next commit.
The dot simply means add every file, you can use the file name instead to add separate files. Next
run ```git commit -m "Declared values for ROCK,PAPER, and SCISSORS"```. The -m tells git that you want to include a
message to describe what you did in this commit. While there is no absolute rule on how you should write a commit
message, it should be short yet descriptive. Now you can run ```git status``` again and git will report no change since
you just committed your last change.

# Branching

Now let's say that you would like to add a feature that counts how many times the computer has won and how many times
the player has won. You could just start editing the code you have right now. But what happens if you run into an issue
and need to go back to the last working version? This is where branches come in. Much like a tree branch, a git branch
starts off from a point and "branches" off. When you create a branch, git essentially creates a copy of your code for
you to edit. This way you can make changes without affecting the last working version. In the command line,
type ```git checkout -B score-counter```. The ```-B``` means you are creating a branch with the name ```score-counter```
. Make sure you capitalize the B, a lower case b will create the branch but not move you onto the branch while an upper
case B will create the branch and move you onto the branch. Now in Visual Studio, create ScoreCounter.h and add the
following code.

```c++
#pragma
once

class ScoreCounter {
private:
int computerScore = 0;
int playerScore = 0;
public:
int getComputerScore();

void increaseComputerScore();

int getPlayerScore();

void increasePlayerScore();

void printScores();
};
```

Add the following to ScoreCounter.cpp

```c++
#include
"iostream"
#include
"ScoreCounter.h"

int ScoreCounter::getComputerScore() {
return computerScore;
}

void ScoreCounter::increaseComputerScore() {
computerScore++;
}

int ScoreCounter::getPlayerScore() {
return playerScore;
}

void ScoreCounter::increasePlayerScore() {
playerScore++;
}

void ScoreCounter::printScores() {
std::cout << "Player Score: " << getPlayerScore() << std::endl;
std::cout << "Computer Score: " << getComputerScore() << std::endl;
}
```

In RockPaperScissors.cpp include the header file, declare an instance of ScoreCounter named scoreCounter, and change the
chooseWinner function to

```c++
char chooseWinner(char uChoice, char cChoice) {
char winner = 'C';
if (uChoice == ROCK && cChoice == PAPER) {
    std::cout << "Computer Wins! Paper wraps Rock." << std::endl;
} else if (uChoice == PAPER && cChoice == SCISSORS) {
    std::cout << "Computer Wins! Scissors cut Paper." << std::endl;
} else if (uChoice == SCISSORS && cChoice == ROCK) {
    std::cout << "Computer Wins! Rock smashes Scissors." << std::endl;
} else if (uChoice == ROCK && cChoice == SCISSORS) {
    std::cout << "You Win! Paper wraps Rock." << std::endl;
    winner = 'P';
} else if (uChoice == PAPER && cChoice == ROCK) {
    std::cout << "You Win! Paper wraps Rock." << std::endl;
    winner = 'P';
} else if (uChoice == SCISSORS && cChoice == PAPER) {
    std::cout << "You Win! Scissors cut Paper." << std::endl;
    winner = 'P';
} else {
    std::cout << "Tie. Play again win the Game." << std::endl;
    winner = 'T';
}
return winner;
}
```

Replace the line

```c++
chooseWinner(userChoice, computerChoice);
```

with

```c++
char result = chooseWinner(userChoice, computerChoice);
if (result=='C') {
    scoreCounter.increaseComputerScore();
} else if (result=='P') {
    scoreCounter.increasePlayerScore();
}
scoreCounter.printScores();
```
Now, run ```git status``` look at the files changed, add them to be committed, and commit them.
<details>
  <summary>Click here for the answer</summary>
  git status<br>
  git add .<br>
  git commit -m "added score counter feature"
</details>