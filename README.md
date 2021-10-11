# Git Crash Course designed for the ESU Software Engineering Course.

## This guide is meant to be followed step by step, please do not skip any part unless you know what you are doing.

#### *Please report all issues or suggestions by opening an issue or emailing Jiamingw29@gmail.com.*

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