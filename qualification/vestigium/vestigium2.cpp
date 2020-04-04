#include <iostream>
#include <vector>

int main(){
  int n_cases = 0;
  std::cin>>n_cases;

  std::vector<std::string> outputs;
  for (size_t i = 0; i < n_cases; i++) {
    int matrix_size = 0;
    std::cin>>matrix_size;

    std::vector<int> matrix;
    for (size_t k = 0; k < matrix_size*matrix_size; k++) {
      int aux;
      std::cin>>aux;
      matrix.push_back(aux);
    }

    int trace = 0;
    int n_rows = 0;
    int n_cols = 0;
    for (size_t k = 0; k < matrix_size; k++) {
      trace += matrix.at(k*matrix_size +k);

      for (size_t z = 0; z < matrix_size; z++) {
        for (size_t j = 0; j < matrix_size; j++) {
          if(z!=j && (matrix.at(k*matrix_size + z) == matrix.at(k*matrix_size + j))){
            ++n_rows;
            z = matrix_size;
            j = matrix_size;
          }
        }
      }

      for (size_t z = 0; z < matrix_size; z++) {
        for (size_t j = 0; j < matrix_size; j++) {
          if(z!=j && (matrix.at(k + matrix_size*z) == matrix.at(k+ matrix_size*j))){
            ++n_cols;
            z = matrix_size;
            j = matrix_size;
          }
        }
      }
    }


    std::cout<<"Case #"+std::to_string(i+1)+": "+std::to_string(trace) + " " +std::to_string(n_rows)+ " " +std::to_string(n_cols)<<std::endl;
  }
}
