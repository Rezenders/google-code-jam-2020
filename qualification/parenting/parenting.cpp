#include <iostream>
#include <utility>
#include <vector>

bool isOverlap(std::pair<int,int> task, std::vector<std::pair<int,int>> person_tasks){
  for (auto it = person_tasks.begin(); it != person_tasks.end(); ++it) {
    if((task.first >= it->first && task.first < it->second) ||
        (task.second > it->first && task.second <= it->second) ||
        (task.first <= it->first && task.second > it->second)){
      return true;
    }
  }
  return false;
}

int main(){
  //enter number of tests T
  int n_cases = 0;
  std::cin>>n_cases;

  std::vector<std::string> outputs;
  for (size_t i = 0; i < n_cases; i++) {
    int n_tasks = 0;
    std::cin>>n_tasks;

    std::vector<std::pair<int,int>> task_vector;
    for (size_t t = 0; t < n_tasks; t++) {
      std::pair <int, int> task;
      std::cin>>task.first>>task.second;
      task_vector.push_back(task);
    }

    std::vector<std::pair<int,int>> c_tasks;
    std::vector<std::pair<int,int>> j_tasks;

    std::string output;
    for (auto it = task_vector.begin(); it != task_vector.end(); ++it) {
      if(!isOverlap(*it,c_tasks)){
        c_tasks.push_back(*it);
        output.push_back('C');
      }else if(!isOverlap(*it,j_tasks)){
        j_tasks.push_back(*it);
        output.push_back('J');
      }else{
        output = "IMPOSSIBLE";
        break;
      }
    }
    outputs.push_back("Case #"+std::to_string(i+1)+": "+output);
  }

  for (size_t i = 0; i < outputs.size(); i++) {
    std::cout<<outputs.at(i)<<std::endl;
  }
}
