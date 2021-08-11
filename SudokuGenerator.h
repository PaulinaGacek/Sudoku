#ifndef SUDOKUGENERATOR_SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_SUDOKUGENERATOR_H
#include <iostream>
#include <random>
#include <vector>
#include <set>

class SudokuGenerator {
    constexpr static size_t size = 9;
    size_t missing_fields = 28;
public:
    std::vector<std::vector<size_t>> board = {};
    std::vector<std::vector<size_t>> solved_board = {};
    SudokuGenerator(){
        generate_board();
    }
    SudokuGenerator(size_t missing_fields_){
        set_new_missing_fields(missing_fields_);
        generate_board();
    }
    void set_new_missing_fields(size_t new_m_f){
        if(new_m_f > size*size)
            throw std::invalid_argument("Number of missing fields cannot be higher than the number of fields");
        missing_fields = new_m_f;
    }
    size_t generate_number_from_range(size_t lower_bond, size_t upper_bond);
    void generate_board();
    void fill_board();
    void shuffle_rows();
    void switch_rows(size_t square, size_t row1, size_t row2);
    void shuffle_columns();
    void switch_columns(size_t square, size_t col1, size_t col2);
    void delete_fields();
    bool is_solvable();
    void display_board();
    inline bool linear_search_row(size_t row, size_t value);
    inline bool linear_search_col(size_t col, size_t value);
    inline bool linear_search_square(size_t start_x, size_t start_y, size_t value);
    inline bool is_full();

};

#endif //SUDOKUGENERATOR_SUDOKUGENERATOR_H
