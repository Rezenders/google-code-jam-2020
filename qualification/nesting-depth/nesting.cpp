#include <iostream>
#include <vector>

std::string addLeft(int n){
  std::string aux;
  for (size_t i = 0; i < n; i++) {
    aux.push_back('(');
  }
  return aux;
}

std::string addRight(int n){
  std::string aux;
  for (size_t i = 0; i < n; i++) {
    aux.push_back(')');
  }
  return aux;
}

std::string calcNesting(std::string s){
  std::string new_s;

  if(s.at(0)>'0'){
    new_s.append(addLeft(s.at(0)-'0'));
  }
  new_s.push_back(s.at(0));

  for (size_t i = 1; i < s.size(); i++) {
    if(s.at(i-1)>s.at(i)){
      new_s.append(addRight(s.at(i-1)-s.at(i)));
    }

    if(s.at(i)>s.at(i-1)){
      new_s.append(addLeft(s.at(i)-s.at(i-1)));
    }
    new_s.push_back(s.at(i));
  }
  if(s.back()>'0'){
    new_s.append(addRight(s.back()-'0'));
  }

  return new_s;
}

int main(){
  //enter number of tests T
  int n_cases = 0;
  std::cin>>n_cases;

  std::vector<std::string> outputs;
  for (size_t i = 0; i < n_cases; i++) {
    std::string s;
    std::cin>>s;
    outputs.push_back("Case #"+std::to_string(i+1)+": "+calcNesting(s));
  }

  for (size_t i = 0; i < outputs.size(); i++) {
    std::cout<<outputs.at(i)<<std::endl;
  }
}
