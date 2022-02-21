#include "../include/SudokuGenerator.h"

size_t SudokuGenerator::generate_number_from_range(size_t lower_bond, size_t upper_bond) {
    std::random_device dev;
    std::mt19937 engine3(dev());
    std::uniform_int_distribution<int> distribution(lower_bond,upper_bond);
    return distribution(engine3);
}

void SudokuGenerator::generate_board() {
    fill_board();
    delete_fields();
}

void SudokuGenerator::fill_board() {
    std::vector<size_t> temp(size);
    for(size_t i = 0; i < size; ++i){
        board.push_back(temp);
    }
    std::set<size_t> available_x;
    for(size_t i = 0; i < size; ++i){
        available_x.insert(i);
    }
    for(size_t i = 0; i < size/3; ++i){
        //row by row
        size_t x = generate_number_from_range(0,2)*3 + i;
        while(available_x.find(x)==available_x.end()){
            x+=3;
        }
        available_x.erase(x%9);
        available_x.erase((x+3)%9);
        available_x.erase((x+6)%9);
        size_t shift = generate_number_from_range(0,1);
        size_t i2 = (x + 3) % 9,i3 = (x + 6) % 9;
        if(shift == 1){
            size_t temp_ = i3;
            i3 = i2;
            i3 = temp_;
        }
        for(size_t j = 1; j <= size; ++j){
            board[i*3][x%9] = j;
            board[i*3+1][i2%9] = j;
            board[i*3+2][i3%9]= j;
            ++x;++i2;++i3;
        }
    }
    shuffle_rows();
    shuffle_columns();
    solved_board = board;
}
void SudokuGenerator::shuffle_rows() {
    size_t nr_of_shuffles = generate_number_from_range(0,size);
    for(size_t i = 0; i < nr_of_shuffles; ++i){
        size_t square = generate_number_from_range(0,2);
        size_t row_left = generate_number_from_range(0,3);
        switch(row_left){
            case 0:
                switch_rows(square,1,2);
                break;
            case 1:
                switch_rows(square,0,2);
                break;
            default:
                switch_rows(square,1,0);
                break;
        }
    }
}
void SudokuGenerator::switch_rows(size_t square, size_t row1, size_t row2) {
    std::vector<size_t> temp = std::move(board[square*3+row1]);
    board[square*3+row1] = std::move(board[square*3+row2]);
    board[square*3+row2] = std::move(temp);
}
void SudokuGenerator::shuffle_columns() {
    size_t nr_of_shuffles = generate_number_from_range(0,size);
    for(size_t i = 0; i < nr_of_shuffles; ++i) {
        size_t square = generate_number_from_range(0,2);
        size_t col_left = generate_number_from_range(0,3);
        switch(col_left){
            case 0:
                switch_columns(square,1,2);
                break;
            case 1:
                switch_columns(square,0,2);
                break;
            default:
                switch_columns(square,1,0);
                break;
        }

    }
}
void SudokuGenerator::switch_columns(size_t square, size_t col1, size_t col2) {
    for(size_t i = 0; i < size; ++i){
        size_t temp = board[i][square*3 + col1];
        board[i][square*3 + col1] = board[i][square*3 + col2];
        board[i][square*3 + col2] = temp;
    }
}


void SudokuGenerator::display_board() {
    for(size_t i = 0; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            std::cout << board[i][j]<< " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
}

void SudokuGenerator::delete_fields() {
    for(size_t i = 0; i < missing_fields; ++i){
        size_t x = generate_number_from_range(0,size-1),
                y = generate_number_from_range(0,size-1);
        while(board[y][x]==0){
            x = (x+1)%9;
            if(x==y){
                y = (y+1)%9;
            }
        }
        size_t value = board[y][x];
        //make copy
        std::vector<std::vector<size_t>> copied_board = {};
        for(size_t j = 0; j < size; ++j){
            copied_board.push_back(board[j]);
        }

        board[y][x] = 0;
        if(!is_solvable()){
            board[y][x] = value;
            std::cout<< "not solvable" <<i << " ";
            --i;
            board = copied_board;
        }
        else{
            board = copied_board;
            board[y][x] = 0;
        }
    }
}

bool SudokuGenerator::is_solvable() {
    //make copy
    std::vector<std::vector<size_t>> copied_board = {};
    for(size_t i = 0; i < size; ++i){
        copied_board.push_back(board[i]);
    }

    size_t row = 0, col = 0;
    static size_t solutions = 0;
    for(size_t i = 0; i < size*size; ++i){
        row = i/size, col = i%size;
        if(board[row][col]==0){
            for(size_t value = 1; value <= size; ++value){
                // check that this value has not already be used on this row
                if (!linear_search_row(row, value)){
                    // check that given value has not already be used on this column
                    if(!linear_search_col(col,value)){
                        // check that given value has not already be used on the square
                        size_t start_x = 0, start_y = 0;
                        if(row >= 2 && row < 6){
                            start_y = 1;
                        }
                        else if(row >= 6){
                            start_y = 2;
                        }
                        if(col >= 2 && col < 6){
                            start_x = 1;
                        }
                        else if(col >= 6){
                            start_x = 2;
                        }
                        if(!linear_search_square(start_x,start_y,value)){
                            board[row][col] = value;
                            if(is_full()) {
                                solutions++;
                                break;
                            }
                            else{
                                if(is_solvable())
                                    return true;
                            }
                        }
                    }
                }
            }
            break;
        }
    }
    board[row][col] = 0;
    return true;
}

bool SudokuGenerator::linear_search_row(size_t row, size_t a){
    for (const auto& i : board[row]){
        if (i == a)
            return true;
    }
    return false;
}

bool SudokuGenerator::linear_search_col(size_t col, size_t value) {
    for(size_t i = 0; i < size; ++i){
        if(board[i][col]==value)
            return true;
    }
    return false;
}

bool SudokuGenerator::linear_search_square(size_t start_x, size_t start_y, size_t value) {
    for(size_t i = 0; i < size/3; ++i){
        for(size_t j =0; j < size/3; ++j){
            if(board[start_y*3+i][start_x*3+j]==value)
                return true;
        }
    }
    return false;
}

bool SudokuGenerator::is_full() {
    for(size_t i = 0; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            if(board[i][j]==0)
                return false;
        }
    }
    return true;
}


