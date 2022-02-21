# Sudoku game
The application generates sudoku grid to be solved by user. 

User can choose the level:

:gem: Too easy

:gem: Easy peasy

:gem: Easy

:gem: Medium

:gem: Hard 

:gem: Expert

which determines how many fields on the sudoku board are blank.

User can see solved sudoku whenever they want by clicking SOLVE button. 

<img src="https://github.com/PaulinaGacek/Sudoku/blob/master/photos/Sudoku.jpg" width="250" height="260">

### How to run application ###
1. Make sure You have QT 6 installed on your PC
2. Go to the the directory where you have cloned the project `cd <some_path>/GameOfLife`
3. Set a path to your qt cmake
   - `cmake DCMAKE_PREFIX_PATH="path/to/Qt/lib/cmake"` on windows
   - `cmake DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/` on Ubuntu
4. `mkdir -p cmake-build && cd cmake-build`
5. `cmake .. -G"Unix Makefiles"`
6. `make`
