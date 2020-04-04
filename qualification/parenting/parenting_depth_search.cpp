#include <iostream>
#include <utility>
#include <vector>
#include <stack>

class State{
public:
  std::vector<std::pair<int,int>> c_tasks;
  std::vector<std::pair<int,int>> j_tasks;
  std::string task_string;
  int depth = 0;
};

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

    State initial_state;
    initial_state.c_tasks.push_back(task_vector.at(0));
    initial_state.task_string.push_back('C');
    initial_state.depth = 1;

    std::stack<State> states_stack;
    states_stack.push(initial_state);

    bool foundSolution = false;
    State state;
    while (!states_stack.empty()) {
      state = states_stack.top();
      states_stack.pop();
      if(state.depth == n_tasks){
        foundSolution = true;
        break;
      }
      if(!isOverlap(task_vector.at(state.depth),state.c_tasks)){
        State new_state;
        new_state = state;

        new_state.c_tasks.push_back(task_vector.at(state.depth));
        new_state.task_string.push_back('C');
        new_state.depth +=1;
        states_stack.push(new_state);
      }
      if(!isOverlap(task_vector.at(state.depth),state.j_tasks)){
        State new_state2;
        new_state2 = state;
        new_state2.j_tasks.push_back(task_vector.at(state.depth));
        new_state2.task_string.push_back('J');
        new_state2.depth +=1;
        states_stack.push(new_state2);
      }
    }

    if(foundSolution){
      outputs.push_back("Case #"+std::to_string(i+1)+": "+state.task_string);
    }else{
      outputs.push_back("Case #"+std::to_string(i+1)+": "+"IMPOSSIBLE");
    }

  }
  for (size_t i = 0; i < outputs.size(); i++) {
    std::cout<<outputs.at(i)<<std::endl;
  }
}
