#pragma once
class MATRIX {
public:
    
    int get_row();
    int get_col();
    void set_array(int row, int col, int n);
    int (*get_p_array())[4];
    int get_array(int row, int col);
    MATRIX();
    MATRIX(int row, int col);
    MATRIX(int row, int col, int n);
private:
    int array[4][4] = {};
    int row = 0;
    int col = 0;
};
MATRIX::MATRIX() {
    row = 0;
    col = 0;
    array[0][0] = { 0 };
}
MATRIX::MATRIX(int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = 0;
        }
    }

    this->row = row;
    this->col = col;
}
MATRIX::MATRIX(int row, int col, int n) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = n++;
        }
    }

    this->row = row;
    this->col = col;

}

int MATRIX::get_row() {
    return this->row;
}
int MATRIX::get_col() {
    return col;
}
void MATRIX::set_array(int row, int col, int n) {
    array[row][col] = n;
}
int MATRIX::get_array(int row, int col) {
    return array[row][col];
}
int(*MATRIX::get_p_array())[4]{
    return array;
}