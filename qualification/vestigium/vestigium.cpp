#include <iostream>
#include <vector>

int main(){
  //enter number of tests T
  int n_cases = 0;
  std::cin>>n_cases;

  std::vector<std::string> answers;

  for (size_t i = 0; i < n_cases; i++) {
    int m_size=0;
    std::cin>>m_size;

    std::string matrix;
    for (size_t j = 0; j < m_size*m_size; j++) {
      std::string aux;
      std::cin>>aux;
      matrix.append(aux);
    }
    int trace = 0;
    int r =0;
    int c =0;

    for (size_t i = 0; i < m_size; i++) {
      trace += (int)matrix.at(i*m_size +i)-48;

      for (size_t j = 0; j < m_size; j++) {
        for (size_t k = 0; k < m_size; k++) {
          if((int)matrix.at(i*m_size + j) == (int)matrix.at(i*m_size + k) && k!=j){
            ++r;
            j = m_size;
            k = m_size;
          }
        }
      }
      for (size_t j = 1; j < m_size; j++) {
        for (size_t k = 0; k < m_size; k++) {
          if((int)matrix.at(i + j*m_size) == (int)matrix.at(i + k*m_size) && k!=j){
            ++c;
            j = m_size;
            k = m_size;
          }
        }
      }
    }
    answers.push_back("Case #"+std::to_string(i+1)+": "+std::to_string(trace)+" "+std::to_string(r)+" "+std::to_string(c));
  }

  for (size_t i = 0; i < answers.size(); i++) {
    std::cout<<answers.at(i)<<std::endl;
  }
}
