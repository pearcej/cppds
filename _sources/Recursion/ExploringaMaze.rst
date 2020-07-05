..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Exploring a Maze
----------------

In this section we will look at a problem that has relevance to the
expanding world of robotics: How do you find your way out of a maze? If you have
a Roomba vacuum cleaner for your dorm room (don’t all college students?)
you will wish that you could reprogram it using what you have learned in
this section. The problem we want to solve is to find an exit to a virtual maze
when starting at a pre-defined location. The maze problem has roots as deep as the
Greek myth about Theseus who was sent into a maze to kill the minotaur.
Theseus used a ball of thread to help him find his way back out again
once he had finished off the beast. In our problem we will assume that
our starting position is dropped down somewhere into the middle of the maze,
a fair distance from any exit. Look at :ref:`Figure 2 <fig_mazescreen>` to get an idea of
where we are going in this section.

.. _fig_mazescreen:

.. video:: vis_maze
   :controls:
   :thumb: ../_static/vis_maze_thumb.png

    ../_static/vis_maze.webm


To make it easier for us we will assume that our maze is divided up into
“squares.” Each square of the maze is either open or occupied by a
section of wall. We can only pass through the open squares of
the maze. If we bump into a wall, we must try a different
direction. We will require a systematic procedure to find our
way out of the maze. Here is the procedure:

-  From our starting position we will first try going North one square
   and then recursively try our procedure from there.

-  If we are not successful by trying a Northern path as the first step
   then we will take a step to the South and recursively repeat our
   procedure.

-  If South does not work then we will try a step to the West as our
   first step and recursively apply our procedure.

-  If North, South, and West have not been successful then apply the
   procedure recursively from a position one step to our East.

-  If none of these directions works then there is no way to get out of
   the maze and we fail.

Now, that sounds pretty easy, but there are a couple of details to talk
about first. Suppose we take our first recursive step by going North. By
following our procedure our next step would also be to the North. But if
the North is blocked by a wall we must look at the next step of the
procedure and try going to the South. Unfortunately that step to the
south brings us right back to our original starting place. If we apply
the recursive procedure from there we will just go back one step to the
North and be in an infinite loop. So, we must have a strategy to
remember where we have been. In this case we will assume that we have a
bag of bread crumbs we can drop along our way. If we take a step in a
certain direction and find that there is a bread crumb already on that
square, we know that we should immediately back up and try the next
direction in our procedure. As we will see when we look at the code for
this algorithm, backing up is as simple as returning from a recursive
function call.

As we do for all recursive algorithms let us review the base cases. Some
of them you may already have guessed based on the description in the
previous paragraph. In this algorithm, there are four base cases to
consider:

#. We have run into a wall. Since the square is occupied by a
   wall no further exploration can take place.

#. We have found a square that has already been explored. We do
   not want to continue exploring from this position or we will get into
   a loop.

#. We have found an outside edge, not occupied by a wall. In other words
   we have found an exit from the maze.

#. We have explored a square unsuccessfully in all four directions.

For our program to work we will need to have a way to represent the
maze. In this instance, we will stick to a text-only representation (ASCII). 

-  ``__init__`` Initializes basic variables to default values, and calls ``readMazeFile``

-  ``readMazeFile`` Reads the text of the maze text file, and calls ``findStartPosition``.

-  ``findStartPosition`` Finds the row and column of the starting position.

-  ``isOnEdge`` Checks to see if the current position is on the edge, and therefore an exit.

-  ``print`` Prints the text of the maze to the screen.

The ``Maze`` class also overloads the index operator ``[]`` so that our
algorithm can easily access the status of any particular square.

Let’s examine the code for the search function which we call
``searchFrom``. The code is shown in :ref:`Listing 3 <lst_mazesearch>`. Notice
that this function takes three parameters: a maze object, the starting
row, and the starting column. This is important because as a recursive
function the search logically starts again with each recursive call.

.. _lst_mazesearch:

.. highlight:: python
    :linenothreshold: 5

**Listing 3**

::
    
    def searchFrom(maze, startRow, startColumn):
        #  Check for base cases (Steps 1, 2, and 3):

        #  1. We have run into an obstacle, return false
        if maze[startRow][startColumn] == MAZE_OBSTACLE:
            return False
        #  2. We have found a square that has already been explored
        if maze[startRow][startColumn] == MAZE_TRIED:
            return False

        # 3. Success, an outside edge not occupied by an obstacle
        if maze.isOnEdge(startRow, startColumn):
            maze[startRow][startColumn] = MAZE_PATH
            return True

        # 4. Indicate that the currently visited space has been tried.
        # Refer to step two.
        maze[startRow][startColumn] = MAZE_TRIED

        # 5. Otherwise, check each cardinal direction (North, south, east, and west).
        # We are checking one space in each direction, thus the plus or minus one below.
        found = searchFrom(maze, startRow - 1, startColumn) or \
                searchFrom(maze, startRow + 1, startColumn) or \
                searchFrom(maze, startRow, startColumn - 1) or \
                searchFrom(maze, startRow, startColumn + 1)
        
        # 6. Mark the location as either part of the path or a dead end,
        # depending on whether or not an exit has been found. 
        if found:
            maze[startRow][startColumn] = MAZE_PATH
        else:
            maze[startRow][startColumn] = MAZE_DEAD_END

        return found

As you look through the algorithm you will see that the first thing the
code does (steps 1 and 2) is determine if the space *should be visited*.
This is done by checking if the spot is an obstacle (:code:`MAZE_OBSTACLE`),
or has already been visited (:code:`MAZE_TRIED`). The algorithm then
determines if it has found an exit (step 3). If none of these cases
are true, it continues the search recursively.

You will notice that in the recursive step there are four recursive
calls to ``searchFrom``. It is hard to predict how many of these
recursive calls will be used since they are all connected by ``or``
statements. If the first call to ``searchFrom`` returns ``True`` then
none of the last three calls would be needed. You can interpret this as
meaning that a step to ``(row-1,column)`` (or North if you want to think
geographically) is on the path leading out of the maze. If there is not
a good path leading out of the maze to the North then the next recursive
call is tried, this one to the South. If South fails then try West, and
finally East. If all four recursive calls return false then we have
found a dead end. You should download or type in the whole program and
experiment with it by changing the order of these calls.

The code for the ``Maze`` class is shown in :ref:`Listing 4 <lst_maze>`, :ref:`Listing 5 <lst_maze1>`, and :ref:`Listing 6 <lst_maze2>`.
The ``__init__`` method takes the name of a file as its
only parameter. This file is a text file that represents a maze by using
“+” characters for walls, spaces for open squares, and the letter “S” to
indicate the starting position. :ref:`Figure 3 <fig_exmaze>` is an example of a
maze data file. The internal representation of the maze is a list of
lists. Each row of the ``mazeList`` instance variable is also a list.
This secondary list contains one character per square using the
characters described above. For the data file in :ref:`Figure 3 <fig_exmaze>` the
internal representation looks like the following:

.. highlight:: python
    :linenothreshold: 500

::

     [['+','+','+','+',...,'+','+','+','+','+','+','+'],
      ['+',' ',' ',' ',...,' ',' ',' ','+',' ',' ',' '],
      ['+',' ','+',' ',...,'+','+',' ','+',' ','+','+'],
      ['+',' ','+',' ',...,' ',' ',' ','+',' ','+','+'],
      ['+','+','+',' ',...,'+','+',' ','+',' ',' ','+'],
      ['+',' ',' ',' ',...,'+','+',' ',' ',' ',' ','+'],
      ['+','+','+','+',...,'+','+','+','+','+',' ','+'],
      ['+',' ',' ',' ',...,'+','+',' ',' ','+',' ','+'],
      ['+',' ','+','+',...,' ',' ','+',' ',' ',' ','+'],
      ['+',' ',' ',' ',...,' ',' ','+',' ','+','+','+'],
      ['+','+','+','+',...,'+','+','+',' ','+','+','+']]

The ``searchFrom`` method uses this internal representation to traverse
throughout the maze.

.. _fig_exmaze:


Figure 3: An Example Maze Data File

.. datafile:: maze1.txt

    ++++++++++++++++++++++
    +   +   ++ ++     +   ‏‏‎ ‎
    + +   +       +++ + ++
    + + +  ++  ++++   + ++
    +++ ++++++    +++ +  +
    +          ++  ++    +
    +++++ ++++++   +++++ +
    +     +   +++++++  + +
    + +++++++      S +   +
    +                + +++
    ++++++++++++++++++ +++

Finally, the ``isOnEdge`` method uses our current position
to test for an exit condition. An exit condition occurs whenever we
have navigated to the edge of the maze, either row zero or column zero,
or the far right column or the bottom row.

.. _lst_maze:

**Listing 4**

.. highlight:: python
    :linenothreshold: 500

::

    MAZE_OBSTACLE = '+'
    MAZE_START = 'S'
    MAZE_PATH = 'O'
    MAZE_DEAD_END = '-'
    MAZE_TRIED = '.'

    class Maze:
        def __init__(self, mazeFileName):
            # Initialize all of our default variables.
            self.mazeList = []
            self.totalRows = 0
            self.totalColumns = 0

            self.startRow = 0
            self.startColumn = 0
            
            # And read the maze file.
            self.readMazeFile(mazeFileName)

        def readMazeFile(self, mazeFileName):
            # The maze list is a list of strings.
            # Components of the maze are indicated by specific characters.
            # These characters are listed at the top of the file.
            
            # The line below says the following:
            # For every line of text in our maze text file, add every single character to a list.
            # The final result is a list of lists, where each element is a single character.
            self.mazeList = [[char for char in line] for line in open(mazeFileName).read().split("\n")]

            # The total number of rows is the total number of strings in the list.
            self.totalRows = len(self.mazeList)

            # The total number of columns is the length of a single line.
            # We can assume all lines of text for the maze are the same length.
            self.totalColumns = len(self.mazeList[0])

            # Lastly, find the start position.
            self.findStartPosition()

        def findStartPosition(self):
            # Iterate through every individual character in the maze list.
            # If we come across the MAZE_START character ('S'),
            # we save the row and column of where it was found, and stop looking.

            # enumerate(...) is very much like using a typical list,
            # except it gives you two pieces of information instead of one.
            # It assumes the format of (index_of_item, item).
            for (row, text) in enumerate(self.mazeList):
                for(column, component) in enumerate(text):
                    if component == MAZE_START:
                        self.startRow = row
                        self.startColumn = column
                        return
        
        def isOnEdge(self, row, column):
            return (row == 0 or
                    row == self.totalRows - 1 or
                    column == 0 or
                    column == self.totalColumns - 1)

        # This allows us to use the Maze class like a list, e.g, maze[index]
        def __getitem__(self, index):
            return self.mazeList[index]

.. _lst_maze1:

The complete program is shown in ActiveCode 1.  This program uses the data file ``maze1.txt`` shown above.
Feel free to also attempt to use ``maze2.txt`` from up above.
Note that it is a much more simple example file in that the exit is very close to the starting position.

.. datafile:: maze2.txt

    ++++++++++++++++++++++
    +   +   ++ ++        +
    +     ++++++++++      ‏‏‎ ‎‎‏‏‎ 
    + +    ++  ++++ +++ ++
    + +   + + ++    +++  +
    +          ++  ++  + +
    +++++ + +      ++  + +
    +++++ +++  + +  ++   +
    +          + + S+ +  +
    +++++ +  + + +       +
    ++++++++++++++++++++++

.. activecode:: completemaze
    :caption: Complete Maze Solver
    :timelimit: off
    :optional:

    MAZE_OBSTACLE = '+'
    MAZE_START = 'S'
    MAZE_PATH = 'O'
    MAZE_DEAD_END = '-'
    MAZE_TRIED = '.'

    class Maze:
        def __init__(self, mazeFileName):
            # Initialize all of our default variables.
            self.mazeList = []
            self.totalRows = 0
            self.totalColumns = 0

            self.startRow = 0
            self.startColumn = 0
            
            # And read the maze file.
            self.readMazeFile(mazeFileName)

        def readMazeFile(self, mazeFileName):
            # The maze list is a list of strings.
            # Components of the maze are indicated by specific characters.
            # These characters are listed at the top of the file.
            
            # The line below says the following:
            # For every line of text in our maze text file, add every single character to a list.
            # The final result is a list of lists, where each element is a single character.
            self.mazeList = [[char for char in line] for line in open(mazeFileName).read().split("\n")]

            # The total number of rows is the total number of strings in the list.
            self.totalRows = len(self.mazeList)

            # The total number of columns is the length of a single line.
            # We can assume all lines of text for the maze are the same length.
            self.totalColumns = len(self.mazeList[0])

            # Lastly, find the start position.
            self.findStartPosition()

        def findStartPosition(self):
            # Iterate through every individual character in the maze list.
            # If we come across the MAZE_START character ('S'),
            # we save the row and column of where it was found, and stop looking.

            # enumerate(...) is very much like using a typical list,
            # except it gives you two pieces of information instead of one.
            # It assumes the format of (index_of_item, item).
            for (row, text) in enumerate(self.mazeList):
                for(column, component) in enumerate(text):
                    if component == MAZE_START:
                        self.startRow = row
                        self.startColumn = column
                        return

        def isOnEdge(self, row, column):
            return (row == 0 or
                    row == self.totalRows - 1 or
                    column == 0 or
                    column == self.totalColumns - 1)
        
        def print(self):
            for row in self.mazeList:
                # "join" every character in the row into a single string.
                rowText = "".join(row)
                print(rowText)

        # This allows us to use the Maze class like a list, e.g, maze[index]
        def __getitem__(self, index):
            return self.mazeList[index]

    def searchFrom(maze, startRow, startColumn):
        #  Check for base cases:
        #  1. We have run into an obstacle, return false
        if maze[startRow][startColumn] == MAZE_OBSTACLE:
            return False
        #  2. We have found a square that has already been explored
        if maze[startRow][startColumn] == MAZE_TRIED:
            return False

        # 3. Success, an outside edge not occupied by an obstacle
        if maze.isOnEdge(startRow, startColumn):
            maze[startRow][startColumn] = MAZE_PATH
            return True

        maze[startRow][startColumn] = MAZE_TRIED

        # Otherwise, check each cardinal direction (North, south, east, and west).
        # We are checking one space in each direction, thus the plus or minus one below.
        found = searchFrom(maze, startRow - 1, startColumn) or \
                searchFrom(maze, startRow + 1, startColumn) or \
                searchFrom(maze, startRow, startColumn - 1) or \
                searchFrom(maze, startRow, startColumn + 1)

        if found:
            maze[startRow][startColumn] = MAZE_PATH
        else:
            maze[startRow][startColumn] = MAZE_DEAD_END

        return found

    def main():
        maze = Maze("maze1.txt")
        print("Before:")
        maze.print()
        searchFrom(maze, maze.startRow, maze.startColumn)
        print("After:")
        maze.print()

    main()

.. admonition:: Self Check

    Now that you're familiar with this simple maze exploring algorithm, use what you've learned about file handling, classes, and IO to implement this in C++!
    To visualize the exploration, print out the characters using ``cout`` to create an ASCII representation of your cave. For example, your program should be able to read and operate from a file formatted as follows:
    You can also use CTurtle to visualize the traversal throughout the maze.

::

        7 5

        +++++++
        +  + S+
        +  +  +
             ++
        +++++++
